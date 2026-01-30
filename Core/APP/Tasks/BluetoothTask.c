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

void chat_update_from_bluetooth(void *data);

void BluetoothTxTask(void *argument) {
    char buffer[64];
    for (;;) {
        if (osMessageQueueGet(BluetoothTxQueueHandle, buffer, NULL, osWaitForever) == osOK) {
            HAL_UART_Transmit(&huart1,(uint8_t *)buffer, strlen(buffer), 100);
        }
    }
}

// 全局变量（接收缓冲区）

// USART1 空闲中断回调
// void HAL_UART_RxIdleCpltCallback(UART_HandleTypeDef *huart) {
//     if (huart->Instance == USART1) {
//         // 【关键】使用正确的 DMA 句柄
//
//         uint32_t data_length = RX_BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
//         LCD_Set_Light(5);
//         if (data_length > 0 && data_length < RX_BUFFER_SIZE) {
//             // 过滤回车换行
//             for (uint32_t i = 0; i < data_length; i++) {
//                 if (rx_buffer[i] == '\r' || rx_buffer[i] == '\n') {
//                     rx_buffer[i] = '\0';
//                     data_length = i;
//                     break;
//                 }
//             }
//             rx_buffer[data_length] = '\0';
//
//             if (data_length > 0) {
//                 // ISR 安全唤醒任务
//                 BaseType_t xHigherPriorityTaskWoken = pdFALSE;
//                 vTaskNotifyGiveFromISR(BluetoothRxtaskHandle, &xHigherPriorityTaskWoken);
//                 portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
//             }
//         }
//
//         // 重新启动 DMA
//         HAL_UARTEx_ReceiveToIdle_DMA(&huart1, rx_buffer, RX_BUFFER_SIZE);
//     }
// }

void BluetoothRxTask(void *argument) {
    for (;;) {
        ulTaskNotifyTake(pdTRUE, portMAX_DELAY);

        // 【关键】使用正确的 DMA 句柄和缓冲区
        uint32_t data_length = RX_BUFFER_SIZE - __HAL_DMA_GET_COUNTER(&hdma_usart1_rx);
        if (data_length > 0 && data_length < RX_BUFFER_SIZE) {
            char *msg_copy = pvPortMalloc(data_length + 1);
            if (msg_copy != NULL) {
                memcpy(msg_copy, rx_buffer, data_length);
                msg_copy[data_length] = '\0';
                lv_async_call(chat_update_from_bluetooth, msg_copy);
            }
        }
    }
}

void chat_update_from_bluetooth(void *data) {
    char *msg = (char *)data;
    if (msg == NULL || guider_ui.chat_win_1_label == NULL) {
        vPortFree(msg);
        return;
    }

    // 1. 构造接收消息格式：< 收到的内容
    char new_line[MAX_LINE_LENGTH];
    snprintf(new_line, sizeof(new_line), "< %s", msg);

    // 2. 更新聊天历史（FIFO，最多10条）
    if (history_count < MAX_CHAT_LINES) {
        strcpy(chat_history[history_count], new_line);
        history_count++;
    } else {
        // 移除最旧消息（第0条）
        for (int i = 0; i < MAX_CHAT_LINES - 1; i++) {
            strcpy(chat_history[i], chat_history[i + 1]);
        }
        strcpy(chat_history[MAX_CHAT_LINES - 1], new_line);
    }

    // 3. 拼接完整文本
    static char full_text[1024] = {0};
    full_text[0] = '\0';
    for (int i = 0; i < history_count; i++) {
        strcat(full_text, chat_history[i]);
        strcat(full_text, "\n");
    }

    // 4. 更新 Label
    lv_label_set_text(guider_ui.chat_win_1_label, full_text);

    // 5. 滚动到底部（LVGL v8 兼容）
    lv_obj_t *content = lv_win_get_content(guider_ui.chat_win_1);
    lv_coord_t content_h = lv_obj_get_content_height(content);
    lv_coord_t win_h = lv_obj_get_height(guider_ui.chat_win_1);
    lv_coord_t scroll_y = (content_h > win_h) ? (content_h - win_h) : 0;
    lv_obj_scroll_to_y(content, scroll_y, LV_ANIM_ON);

    // 6. 释放内存
    vPortFree(msg);
}

