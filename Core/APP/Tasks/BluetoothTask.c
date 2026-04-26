#include "cmsis_os2.h"
#include "FreeRTOS.h"
#include "main.h"
#include "usart.h"
#include "dma.h"
#include "string.h"
#include "custom.h"
#include "events_init.h"
#include "stdio.h"
#include "task.h"
#include "lcd_init.h"
#include "Config/ov_project_config.h"
#include "Services/ProjectLog.h"
#include "Services/SystemStatus.h"

void chat_update_from_bluetooth(void *data);

static size_t bluetooth_message_length(const char *buffer, size_t max_len)
{
    size_t length = 0U;

    while (length < max_len && buffer[length] != '\0') {
        length++;
    }

    return length;
}

void BluetoothTxTask(void *argument)
{
    char buffer[OV_BLUETOOTH_TX_MESSAGE_SIZE];

    (void)argument;

    for (;;) {
        if (osMessageQueueGet(BluetoothTxQueueHandle, buffer, NULL, osWaitForever) == osOK) {
            size_t message_length = bluetooth_message_length(buffer, sizeof(buffer));
            if (message_length == 0U) {
                continue;
            }

            if (HAL_UART_Transmit_DMA(&huart1, (uint8_t *)buffer, message_length) != HAL_OK) {
                SystemStatus_SetModule(OV_MODULE_BLUETOOTH, OV_MODULE_STATUS_ERROR);
                OV_LOGW("bt", "tx dma busy or failed");
            }
        }
    }
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart->Instance == USART1)
    {
        uint32_t data_length = Size;

        for (uint32_t i = 0; i < data_length; i++)
        {
            if (rx_buffer[i] == '\r' || rx_buffer[i] == '\n')
            {
                rx_buffer[i] = '\0';
                data_length = i;
                break;
            }
        }

        if (data_length > 0)
        {
            g_received_data_length = data_length;
            SystemStatus_SetModule(OV_MODULE_BLUETOOTH, OV_MODULE_STATUS_OK);
            SystemStatus_SetLastBluetoothRxLength(data_length);

            BaseType_t xHigherPriorityTaskWoken = pdFALSE;
            vTaskNotifyGiveFromISR(BluetoothRxtaskHandle, &xHigherPriorityTaskWoken);
            portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
        }

        if (HAL_UARTEx_ReceiveToIdle_DMA(&huart1, rx_buffer, RX_BUFFER_SIZE) != HAL_OK) {
            SystemStatus_SetModule(OV_MODULE_BLUETOOTH, OV_MODULE_STATUS_ERROR);
        }
        __HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);
    }
}

void BluetoothRxTask(void *argument)
{
    (void)argument;

    for (;;)
    {
        uint32_t data_length = 0;
        char local_buffer[RX_BUFFER_SIZE] = {0};

        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        data_length = g_received_data_length;
        g_received_data_length = 0;

        if (data_length > 0 && data_length < RX_BUFFER_SIZE)
        {
            char *msg_copy;

            memcpy(local_buffer, rx_buffer, data_length);
            local_buffer[data_length] = '\0';

            msg_copy = pvPortMalloc(data_length + 1U);
            if (msg_copy != NULL)
            {
                memcpy(msg_copy, local_buffer, data_length);
                msg_copy[data_length] = '\0';
                lv_async_call(chat_update_from_bluetooth, msg_copy);
            } else {
                OV_LOGW("bt", "failed to allocate rx payload");
            }
        }
    }
}

void chat_update_from_bluetooth(void *data)
{
    char *msg = (char *)data;
    if (msg == NULL) {
        vPortFree(msg);
        return;
    }

    custom_chat_append_message("<", msg, LV_ANIM_ON);
    vPortFree(msg);
}
