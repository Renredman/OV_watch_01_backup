/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: --bpp 1 --size 24 --no-compress --stride 1 --align 1 --font icomoon.ttf --symbols  --format lvgl -o lv_font_icomoon_24.c
 ******************************************************************************/

#ifdef __has_include
    #if __has_include("lvgl.h")
        #ifndef LV_LVGL_H_INCLUDE_SIMPLE
            #define LV_LVGL_H_INCLUDE_SIMPLE
        #endif
    #endif
#endif

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif



#ifndef LV_FONT_ICOMOON_24
#define LV_FONT_ICOMOON_24 1
#endif

#if LV_FONT_ICOMOON_24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+E902 "" */
    0x0, 0x0, 0x0, 0x0, 0xf0, 0x0, 0x3f, 0x0,
    0x7, 0xe0, 0x1, 0xfe, 0x38, 0x3f, 0xdf, 0x87,
    0xfb, 0xf8, 0x7f, 0xff, 0xf, 0xdf, 0xe1, 0xfb,
    0xfc, 0xf, 0x7f, 0x80, 0xf, 0xe0, 0xc1, 0xfc,
    0x3f, 0x1f, 0x87, 0xe0, 0x0, 0x78, 0x0, 0x2,
    0xf, 0x80, 0x1, 0xf0, 0x0, 0x3e, 0x0, 0x3,
    0x80, 0x0,

    /* U+E905 "" */
    0x2, 0x0, 0x10, 0x1, 0xc0, 0xe, 0x0, 0xf8,
    0x7, 0xc0, 0x7f, 0x3, 0xf8, 0x3f, 0xe1, 0xff,
    0x1f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfb, 0xff, 0x8f, 0xf8, 0x3f,
    0x80, 0x20, 0x0,

    /* U+E909 "" */
    0x0, 0x78, 0x0, 0x66, 0x3f, 0x21, 0x1f, 0x90,
    0x80, 0x8, 0x41, 0xe5, 0xa0, 0xf2, 0xd0, 0x1,
    0x68, 0xc, 0xb4, 0x6, 0x5a, 0x0, 0x2d, 0x0,
    0x16, 0x80, 0xb, 0x40, 0x9, 0xb0, 0x8, 0xc4,
    0x8, 0xe3, 0x4, 0xf8, 0x82, 0x7c, 0x41, 0x3e,
    0x20, 0xce, 0x30, 0x20, 0x10, 0xc, 0x30, 0x1,
    0xf0,

    /* U+E927 "" */
    0x0, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0, 0xf,
    0x0, 0x0, 0x3e, 0x0, 0x0, 0xee, 0x0, 0x1,
    0x8c, 0x0, 0x6, 0x1c, 0x4, 0x1c, 0x18, 0x1c,
    0x70, 0x30, 0x3d, 0xc0, 0x70, 0xff, 0x0, 0x61,
    0x9c, 0x0, 0xe7, 0x18, 0x0, 0xcc, 0x18, 0x1,
    0xb8, 0x38, 0x3, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xff, 0xe7, 0xff, 0xff, 0xc0, 0x0, 0x0, 0x7,
    0xff, 0xfc, 0xf, 0xff, 0xf8,

    /* U+E928 "" */
    0x1, 0xfc, 0x0, 0x3f, 0xf8, 0x3, 0xc1, 0xe0,
    0x38, 0x3, 0x83, 0x0, 0x6, 0x38, 0x0, 0x39,
    0x80, 0x38, 0xdc, 0x7, 0xc7, 0xc0, 0xe6, 0x1e,
    0x6, 0x20, 0xf0, 0x6b, 0x7, 0x82, 0x30, 0x3c,
    0x33, 0x81, 0xf1, 0xf0, 0x1d, 0x9e, 0x0, 0xce,
    0xc0, 0xe, 0x30, 0x0, 0x60, 0xe0, 0xe, 0x3,
    0xc1, 0xe0, 0xf, 0xfe, 0x0, 0x1f, 0xc0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 384, .box_w = 19, .box_h = 21, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 50, .adv_w = 384, .box_w = 13, .box_h = 21, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 384, .box_w = 17, .box_h = 23, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 134, .adv_w = 384, .box_w = 23, .box_h = 24, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 203, .adv_w = 384, .box_w = 21, .box_h = 21, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x3, 0x7, 0x25, 0x26
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 59650, .range_length = 39, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 5, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif

};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t lv_font_icomoon_24 = {
#else
lv_font_t lv_font_icomoon_24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 24,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = 0,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if LV_FONT_ICOMOON_24*/
