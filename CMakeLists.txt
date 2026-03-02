cmake_minimum_required(VERSION 3.22)

#
# This file is generated only once,
# and is not re-generated if converter is called multiple times.
#
# User is free to modify the file as much as necessary
#

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME OV_watch_01)

# Include toolchain file
include("cmake/gcc-arm-none-eabi.cmake")

# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)


# Core project settings
project(${CMAKE_PROJECT_NAME})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

message("Build type: " ${CMAKE_BUILD_TYPE})

# LVGL 全量文件（GUI核心 + porting + UI应用 + Screens）
file(GLOB_RECURSE LVGL_SRCS
        "LVGL_porting/**/*.c"
        "LVGL_src/**/*.c"
)

file(GLOB_RECURSE ALL_SOURCES
        "LVGL/myGUI/*.c"
        "LVGL/myGUI/*.h"
)
#add_executable(YourProjectName ${ALL_SOURCES})

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME}
        BSP/LCD/lcd.h
        BSP/MPU6050/eMPL/inv_mpu.c
        SYSTEM/delay.c
        BSP/LCD/lcd.c
        BSP/LCD/lcd_init.c
        BSP/LCD/pic.h
        BSP/KEY/key.c
        BSP/KT6328/KT6328.c
        BSP/OWDG/WDOG.c
        BSP/AHT21/AHT21.c
        BSP/IIC/iic_hal.c
        BSP/EM7028/em70x8.c
        BSP/EM7028/HrAlgorythm.c
        BSP/EM7028/user_Queue.c
        BSP/POWER/power.c
        BSP/SPL06_001/spl06_001.c
        BSP/LSM303DLH/LSM303.c
        LVGL_porting/lv_port_disp.c
        LVGL_porting/lv_port_indev.c
        LVGL_porting/lv_port_indev.h
        LVGL_src/lv_hal_disp.c
        LVGL_src/lv_hal_indev.c
        LVGL_src/gifdec.c
        LVGL_src/lodepng.c
        LVGL_src/lv_anim.c
        LVGL_src/lv_anim_timeline.c
        LVGL_src/lv_animimg.c
        LVGL_src/lv_arc.c
        LVGL_src/lv_font_loader.c
        LVGL_src/lv_area.c
        LVGL_src/lv_async.c
        LVGL_src/lv_mem.c
        LVGL_src/lv_bar.c
        LVGL_src/lv_bidi.c
        LVGL_src/lv_bmp.c
        LVGL_src/lv_btn.c
        LVGL_src/lv_btnmatrix.c
        LVGL_src/lv_calendar.c
        LVGL_src/lv_calendar_header_arrow.c
        LVGL_src/lv_chart.c
        LVGL_src/lv_calendar_header_dropdown.c
        LVGL_src/lv_canvas.c
        LVGL_src/lv_checkbox.c
        LVGL_src/lv_color.c
        LVGL_src/lv_colorwheel.c
        LVGL_src/lv_disp.c
        LVGL_src/lv_draw.c
        LVGL_src/lv_draw_arc.c
        LVGL_src/lv_draw_img.c
        LVGL_src/lv_draw_label.c
        LVGL_src/lv_draw_layer.c
        LVGL_src/lv_draw_line.c
        LVGL_src/lv_draw_mask.c
        LVGL_src/lv_draw_pxp.c
        LVGL_src/lv_draw_pxp_blend.c
        LVGL_src/lv_draw_rect.c
        LVGL_src/lv_draw_sdl.c
        LVGL_src/lv_draw_sdl_arc.c
        LVGL_src/lv_draw_sdl_bg.c
        LVGL_src/lv_draw_sdl_composite.c
        LVGL_src/lv_draw_sdl_label.c
        LVGL_src/lv_draw_sdl_img.c
        LVGL_src/lv_draw_sdl_layer.c
        LVGL_src/lv_draw_sdl_line.c
        LVGL_src/lv_draw_sdl_mask.c
        LVGL_src/lv_draw_sdl_polygon.c
        LVGL_src/lv_draw_sdl_rect.c
        LVGL_src/lv_draw_sdl_stack_blur.c
        LVGL_src/lv_draw_sdl_texture_cache.c
        LVGL_src/lv_draw_sdl_utils.c
        LVGL_src/lv_draw_sw_blend.c
        LVGL_src/lv_draw_sw.c
        LVGL_src/lv_draw_sw_arc.c
        LVGL_src/lv_draw_sw_dither.c
        LVGL_src/lv_draw_sw_gradient.c
        LVGL_src/lv_draw_sw_img.c
        LVGL_src/lv_draw_sw_layer.c
        LVGL_src/lv_draw_sw_letter.c
        LVGL_src/lv_draw_sw_line.c
        LVGL_src/lv_draw_sw_polygon.c
        LVGL_src/lv_draw_sw_rect.c
        LVGL_src/lv_draw_sw_transform.c
        LVGL_src/lv_draw_vglite_arc.c
        LVGL_src/lv_draw_triangle.c
        LVGL_src/lv_draw_transform.c
        LVGL_src/lv_draw_vglite.c
        LVGL_src/lv_draw_vglite_rect.c
        LVGL_src/lv_draw_vglite_line.c
        LVGL_src/lv_draw_vglite_blend.c
        LVGL_src/lv_event.c
        LVGL_src/lv_flex.c
        LVGL_src/lv_dropdown.c
        LVGL_src/lv_extra.c
        LVGL_src/lv_ffmpeg.c
        LVGL_src/lv_font.c
        LVGL_src/lv_font_fmt_txt.c
        LVGL_src/lv_font_dejavu_16_persian_hebrew.c
        LVGL_src/lv_font_montserrat_30.c
        LVGL_src/lv_font_montserrat_36.c
        LVGL_src/lv_font_montserrat_8.c
        LVGL_src/lv_font_montserrat_32.c
        LVGL_src/lv_font_montserrat_28.c
        LVGL_src/lv_font_montserrat_34.c
        LVGL_src/lv_font_montserrat_20.c
        LVGL_src/lv_font_montserrat_12.c
        LVGL_src/lv_font_montserrat_18.c
        LVGL_src/lv_font_montserrat_12_subpx.c
        LVGL_src/lv_font_montserrat_16.c
        LVGL_src/lv_font_montserrat_26.c
        LVGL_src/lv_font_montserrat_24.c
        LVGL_src/lv_font_montserrat_22.c
        LVGL_src/lv_font_montserrat_28_compressed.c
        LVGL_src/lv_font_montserrat_10.c
        LVGL_src/lv_font_montserrat_14.c
        LVGL_src/lv_png.c
        LVGL_src/lv_gpu_d2_ra6m3.c
        LVGL_src/lv_math.c
        LVGL_src/lv_gpu_d2_draw_label.c
        LVGL_src/lv_gpu_stm32_dma2d.c
        LVGL_src/lv_win.c
        LVGL_src/lv_led.c
        LVGL_src/lv_menu.c
        LVGL_src/lv_gpu_nxp_pxp.c
        LVGL_src/lv_printf.c
        LVGL_src/lv_rlottie.c
        LVGL_src/lv_textarea.c
        LVGL_src/lv_list.c
        LVGL_src/lv_gpu_swm341_dma2d.c
        LVGL_src/lv_img.c
#        LVGL_src/lv_font_montserrat_42.c
        LVGL_src/tjpgd.c
        LVGL_src/lv_obj_scroll.c
        LVGL_src/lv_grid.c
        LVGL_src/lv_timer.c
        LVGL_src/lv_theme_default.c
        LVGL_src/lv_group.c
        LVGL_src/lv_obj_class.c
        LVGL_src/lv_slider.c
        LVGL_src/lv_fragment.c
#        LVGL_src/lv_font_montserrat_44.c
        LVGL_src/lv_sjpg.c
        LVGL_src/lv_obj.c
        LVGL_src/lv_tiny_ttf.c
        LVGL_src/lv_obj_style.c
        LVGL_src/lv_gif.c
        LVGL_src/lv_font_montserrat_46.c
        LVGL_src/lv_templ.c
        LVGL_src/lv_refr.c
        LVGL_src/lv_font_simsun_16_cjk.c
        LVGL_src/lv_indev_scroll.c
        LVGL_src/lv_switch.c
        LVGL_src/lv_fs_littlefs.c
        LVGL_src/lv_qrcode.c
        LVGL_src/lv_obj_draw.c
        LVGL_src/lv_span.c
        LVGL_src/lv_theme_basic.c
        LVGL_src/lv_monkey.c
        LVGL_src/lv_txt.c
        LVGL_src/lv_objx_templ.c
        LVGL_src/lv_indev.c
        LVGL_src/lv_spinbox.c
        LVGL_src/lv_theme.c
        LVGL_src/lv_imgbtn.c
        LVGL_src/lv_msg.c
        LVGL_src/lv_log.c
        LVGL_src/lv_freetype.c
        LVGL_src/lv_obj_tree.c
        LVGL_src/lv_fs_win32.c
        LVGL_src/lv_fragment_manager.c
        LVGL_src/lv_ll.c
        LVGL_src/lv_gridnav.c
        LVGL_src/lv_meter.c
        LVGL_src/lv_lru.c
        LVGL_src/qrcodegen.c
        LVGL_src/lv_fs_fatfs.c
        LVGL_src/lv_img_cache.c
        LVGL_src/lv_img_buf.c
        LVGL_src/lv_ime_pinyin.c
        LVGL_src/lv_msgbox.c
        LVGL_src/lv_utils.c
        LVGL_src/lv_vglite_utils.c
        LVGL_src/lv_table.c
        LVGL_src/lv_txt_ap.c
        LVGL_src/lv_theme_mono.c
        LVGL_src/lv_hal_tick.c
        LVGL_src/lv_imgfont.c
        LVGL_src/lv_gc.c
        LVGL_src/lv_vglite_buf.c
        LVGL_src/lv_gpu_arm2d.c
        LVGL_src/lv_fs.c
        LVGL_src/lv_snapshot.c
        LVGL_src/lv_img_decoder.c
        LVGL_src/lv_font_unscii_16.c
        LVGL_src/lv_spinner.c
        LVGL_src/lv_font_montserrat_48.c
        LVGL_src/lv_tileview.c
        LVGL_src/lv_line.c
        LVGL_src/lv_keyboard.c
        LVGL_src/lv_style_gen.c
        LVGL_src/lv_fs_posix.c
        LVGL_src/lv_style.c
        LVGL_src/lv_roller.c
        LVGL_src/lv_font_montserrat_38.c
        LVGL_src/lv_font_unscii_8.c
        LVGL_src/lv_tlsf.c
        LVGL_src/lv_label.c
        LVGL_src/lv_obj_pos.c
        LVGL_src/lv_gpu_nxp_pxp_osa.c
        LVGL_src/lv_fs_stdio.c
        LVGL_src/lv_obj_style_gen.c
        LVGL_src/lv_font_montserrat_40.c
        LVGL_src/lv_tabview.c
        LVGL_conf/lv_conf.h
        LVGL_conf/lvgl.h
        Core/APP/Tasks/KeyTask.c
        Core/APP/Tasks/PageTask.c
        Core/APP/Tasks/WdogFeedTask.c
        Core/APP/Tasks/SensorDataTask.c
        Core/APP/Tasks/DataUpdateTask.c
        Core/APP/Tasks/TimeUpdateTask.c
        Core/APP/Tasks/TimeUpdateTask.h
        Core/APP/Tasks/SensorDataTask.h
        LVGL/myGUI/generated/setup_scr_about_watch.c
        LVGL/myGUI/generated/setup_scr_heart.c
        LVGL/myGUI/generated/setup_scr_game.c
        LVGL/myGUI/generated/setup_scr_game_2048.c
        LVGL/myGUI/generated/setup_scr_story.c
        Core/APP/Tasks/AppState.c
        Core/APP/Tasks/AppState.h
        Core/APP/Tasks/user_PowerManager.c
        Core/APP/Tasks/user_PowerManager.h
        LVGL/myGUI/generated/setup_scr_chat.c
        Core/APP/Tasks/BluetoothTask.c
        LVGL/myGUI/generated/setup_scr_compass.c
        LVGL/myGUI/generated/setup_scr_time_date.c
        LVGL/myGUI/generated/setup_scr_secret.c
        LVGL/myGUI/generated/setup_scr_secret_change.c
        LVGL/myGUI/generated/guider_fonts/lv_font_icomoon_48.c
)

# Add STM32CubeMX generated sources
add_subdirectory(cmake/stm32cubemx)

# Link directories setup
target_link_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined library search paths

)

# BSP 所有外设驱动（覆盖 AHT21/BL24C02 等所有子目录）
file(GLOB_RECURSE BSP_SRCS
        "BSP/AHT21/**/*.c"
        "BSP/BL24C02/**/*.c"
        "BSP/EM7028/**/*.c"
        "BSP/IIC/**/*.c"
        "BSP/KEY/**/*.c"
        "BSP/KT6328/**/*.c"
        "BSP/LCD/**/*.c"
        "BSP/LSM303DLH/**/*.c"
        "BSP/MPU6050/**/*.c"  # 包含 eMPL 子目录
        "BSP/MPU6050/eMPL/**/*.c"
        "BSP/OWDG/**/*.c"
        "BSP/POWER/**/*.c"
        "BSP/SPL06_001/**/*.c"
        "BSP/TOUCH/**/*.c"
)

file(GLOB_RECURSE SYSTEM_SRCS
        "SYSTEM/**/*.c"
)



# Add sources to executable
target_sources(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user sources here
        ${BSP_SRCS}
        ${SYSTEM_SRCS}
        ${LVGL_SRCS}
        LVGL_porting/lv_port_disp.c
        LVGL_porting/lv_port_indev.c
        BSP/TOUCH/CST816.c
        BSP/IIC/iic_hal.c

        ${ALL_SOURCES}
)

# Add include paths
target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined include paths
        ./BSP/AHT21
        ./BSP/BL24C02
        ./BSP/EM7028
        ./BSP/IIC
        ./BSP/KEY
        ./BSP/KT6328
        ./BSP/LCD
        ./BSP/LSM303DLH
        ./BSP/MPU6050
        ./BSP/OWDG
        ./BSP/POWER
        ./BSP/SPL06_001
        ./BSP/TOUCH

        ./SYSTEM

        ./LVGL
        ./LVGL/src

        ./LVGL_porting
        ./LVGL_myGUI
        ./LVGL_conf
        ./LVGL_src
        ./LVGL/src/core
        ./LVGL/src/draw
        ./LVGL/src/draw/arm2d
        ./LVGL/src/draw/nxp
        ./LVGL/src/draw/nxp/pxp
        ./LVGL/src/draw/nxp/vglite
        ./LVGL/src/draw/renesas
        ./LVGL/src/draw/sdl
        ./LVGL/src/draw/stm32_dma2d
        ./LVGL/src/draw/sw
        ./LVGL/src/draw/swm341_dma2d
        ./LVGL/src/extra
        ./LVGL/src/extra/layouts
        ./LVGL/src/extra/layouts/flex
        ./LVGL/src/extra/layouts/grid
        ./LVGL/src/extra/libs
        ./LVGL/src/extra/libs/bmp
        ./LVGL/src/extra/libs/ffmpeg
        ./LVGL/src/extra/libs/freetype
        ./LVGL/src/extra/libs/fsdrv
        ./LVGL/src/extra/libs/gif
        ./LVGL/src/extra/libs/png
        ./LVGL/src/extra/libs/qrcode
        ./LVGL/src/extra/libs/rlottie
        ./LVGL/src/extra/libs/sjpg
        ./LVGL/src/extra/libs/tiny_ttf
        ./LVGL/src/extra/others/fragment
        ./LVGL/src/extra/others
        ./LVGL/src/extra/others/gridnav
        ./LVGL/src/extra/others/ime
        ./LVGL/src/extra/others/imgfont
        ./LVGL/src/extra/others/monkey
        ./LVGL/src/extra/others/msg
        ./LVGL/src/extra/others/snapshot
        ./LVGL/src/extra/themes
        ./LVGL/src/extra/themes/basic
        ./LVGL/src/extra/themes/default
        ./LVGL/src/extra/themes/mono
        ./LVGL/src/extra/widgets
        ./LVGL/src/extra/widgets/animimg
        ./LVGL/src/extra/widgets/calendar
        ./LVGL/src/extra/widgets/chart
        ./LVGL/src/extra/widgets/colorwheel
        ./LVGL/src/extra/widgets/imgbtn
        ./LVGL/src/extra/widgets/keyboard
        ./LVGL/src/extra/widgets/led
        ./LVGL/src/extra/widgets/list
        ./LVGL/src/extra/widgets/menu
        ./LVGL/src/extra/widgets/meter
        ./LVGL/src/extra/widgets/msgbox
        ./LVGL/src/extra/widgets/span
        ./LVGL/src/extra/widgets/spinbox
        ./LVGL/src/extra/widgets/spinner
        ./LVGL/src/extra/widgets/tabview
        ./LVGL/src/extra/widgets/tileview
        ./LVGL/src/extra/widgets/win
        ./LVGL/src/font
        ./LVGL/src/hal
        ./LVGL/src/misc
        ./LVGL/src/widgets
        ./LVGL/examples/porting

        ./LVGL/myGUI/custom
        ./LVGL/myGUI/generated
        ./LVGL/myGUI/generated/guider_customer_fonts
        ./LVGL/myGUI/generated/guider_fonts
        ./LVGL/myGUI/generated/images
        Core/APP

)

# Add project symbols (macros)
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE
    # Add user defined symbols

)

# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    stm32cubemx

    # Add user defined libraries
)
