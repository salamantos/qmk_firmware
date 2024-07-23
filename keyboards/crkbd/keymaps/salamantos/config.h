#pragma once

// Select hand configuration
#define EE_HANDS

#define TAPPING_TERM 200  // 200 is default
#define QUICK_TAP_TERM 100  // Enable rapid switch from tap to hold, disables double tap hold auto-repeat
// #define PERMISSIVE_HOLD  // skip tapping term if another key tapped while this key pressed
#define PERMISSIVE_HOLD_PER_KEY

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */
#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#ifdef RGBLIGHT_ENABLE
    // #define RGBLIGHT_EFFECT_BREATHING
    // #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    // #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    // #define RGBLIGHT_EFFECT_SNAKE
    // #define RGBLIGHT_EFFECT_KNIGHT
    // #define RGBLIGHT_EFFECT_CHRISTMAS
    // #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    // #define RGBLIGHT_EFFECT_RGB_TEST
    // #define RGBLIGHT_EFFECT_ALTERNATING
    // #define RGBLIGHT_EFFECT_TWINKLE
    // #define RGBLIGHT_LIMIT_VAL 120
    // #define RGBLIGHT_HUE_STEP 10
    // #define RGBLIGHT_SAT_STEP 17
    // #define RGBLIGHT_VAL_STEP 17
    // #define RGBLIGHT_SPLIT
#endif

#ifdef RGB_MATRIX_ENABLE
    // #define ENABLE_RGB_MATRIX_BREATHING
    // #define ENABLE_RGB_MATRIX_PIXEL_FLOW
    // #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
    // #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
    // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE
    // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
    // #define ENABLE_RGB_MATRIX_SPLASH
    // #define ENABLE_RGB_MATRIX_SOLID_SPLASH
    // #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_HUE
    // #define ENABLE_RGB_MATRIX_STARLIGHT_DUAL_SAT
    #define ENABLE_RGB_MATRIX_RIVERFLOW

    #define RGB_MATRIX_SLEEP
    #define RGB_MATRIX_DEFAULT_ON true
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_RIVERFLOW
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200
    #define RGB_MATRIX_DEFAULT_HUE 210
    #define RGB_MATRIX_DEFAULT_SAT 220
    #define RGB_MATRIX_DEFAULT_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
    #define RGB_MATRIX_DEFAULT_SPD 127
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
// #define OLED_FONT_WIDTH 12
// #define OLED_FONT_HEIGHT 16

#define UNICODE_SELECTED_MODES UNICODE_MODE_MACOS
// #define TAP_HOLD_CAPS_DELAY 0
