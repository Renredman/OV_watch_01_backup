#ifndef OV_PROJECT_LOG_H
#define OV_PROJECT_LOG_H

#include <stdio.h>

#include "Config/ov_project_config.h"

#if OV_LOG_ENABLE
#define OV_LOG_IMPL(level, tag, fmt, ...) \
    do { \
        printf("[%s][%s] " fmt "\r\n", level, tag, ##__VA_ARGS__); \
    } while (0)
#else
#define OV_LOG_IMPL(level, tag, fmt, ...) \
    do { \
    } while (0)
#endif

#define OV_LOGI(tag, fmt, ...) OV_LOG_IMPL("INFO", tag, fmt, ##__VA_ARGS__)
#define OV_LOGW(tag, fmt, ...) OV_LOG_IMPL("WARN", tag, fmt, ##__VA_ARGS__)
#define OV_LOGE(tag, fmt, ...) OV_LOG_IMPL("ERR", tag, fmt, ##__VA_ARGS__)

#endif /* OV_PROJECT_LOG_H */
