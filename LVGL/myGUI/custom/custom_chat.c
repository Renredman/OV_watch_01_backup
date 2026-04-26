#include <stdio.h>
#include <string.h>

#include "custom.h"

char chat_history[MAX_CHAT_LINES][MAX_LINE_LENGTH] = {0};
uint8_t history_count = 0;

static void custom_chat_render_history(lv_anim_enable_t anim)
{
    char full_text[OV_CHAT_RENDER_BUFFER_SIZE];
    lv_obj_t *content;
    lv_coord_t content_h;
    lv_coord_t win_h;
    lv_coord_t scroll_y;
    uint8_t i;
    size_t used;

    if (guider_ui.chat_win_1_label == NULL || guider_ui.chat_win_1 == NULL) {
        return;
    }

    full_text[0] = '\0';
    if (history_count == 0U) {
        (void)snprintf(full_text, sizeof(full_text), "123");
    } else {
        for (i = 0; i < history_count; ++i) {
            used = strlen(full_text);
            if (used >= (sizeof(full_text) - 1U)) {
                break;
            }

            (void)snprintf(
                full_text + used,
                sizeof(full_text) - used,
                "%s\n",
                chat_history[i]
            );
        }
    }

    lv_label_set_text(guider_ui.chat_win_1_label, full_text);

    content = lv_win_get_content(guider_ui.chat_win_1);
    content_h = lv_obj_get_content_height(content);
    win_h = lv_obj_get_height(guider_ui.chat_win_1);
    scroll_y = (content_h > win_h) ? (content_h - win_h) : 0;
    lv_obj_scroll_to_y(content, scroll_y, anim);
}

void custom_chat_append_message(const char *prefix, const char *message, lv_anim_enable_t anim)
{
    char new_line[MAX_LINE_LENGTH];
    uint8_t i;

    if (message == NULL) {
        return;
    }

    (void)snprintf(new_line, sizeof(new_line), "%s %s", prefix, message);

    if (history_count < MAX_CHAT_LINES) {
        (void)snprintf(chat_history[history_count], sizeof(chat_history[history_count]), "%s", new_line);
        history_count++;
    } else {
        for (i = 0; i < (MAX_CHAT_LINES - 1U); ++i) {
            (void)snprintf(chat_history[i], sizeof(chat_history[i]), "%s", chat_history[i + 1U]);
        }
        (void)snprintf(chat_history[MAX_CHAT_LINES - 1U], sizeof(chat_history[MAX_CHAT_LINES - 1U]), "%s", new_line);
    }

    custom_chat_render_history(anim);
}

void chat_screen_loaded_handler(lv_event_t *e)
{
    (void)e;
    custom_chat_render_history(LV_ANIM_OFF);
}
