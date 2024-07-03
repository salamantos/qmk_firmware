#include QMK_KEYBOARD_H
#include <stdio.h>

#define TP(kc) LT(0, kc)  // Tap Press
#define K_PRTSC LGUI(LSFT(KC_4))  // Screenshot
#define K_LOCK LGUI(LCTL(KC_Q))  // Lock screen

enum SystemLang {
    EN,
    RU,
};

enum LayerNames {
    BASE,
    CODE,
    FUNC,
    ADJUST,
};

enum SystemLang system_lang = EN;

const uint16_t US_only_keycodes[] = {KC_DOT,  KC_COMMA};

uint16_t international_mapping[1000];
//international_mapping[KC_DOT] = LSFT(KC_7);


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                            ,--------------------------------------------------------.
      TP(KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,  TP(KC_T),                             KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+-----------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                              KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|                            |--------+--------+--------+--------+--------+-----------|
      KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,   TP(KC_M), KC_COMMA, KC_DOT, KC_QUOTE, TP(KC_CAPS_LOCK),
  //|--------+--------+--------+--------+--------+--------+--------|          |--------+--------+--------+--------+--------+--------+-----------|
                         LT(FUNC, KC_DEL),   LT(CODE,KC_SPC), KC_LGUI,         KC_LALT, LT(CODE, KC_SPC), LT(FUNC, KC_BSPC)
                                      //`--------------------------'          `--------------------------'

  ),

  [CODE] = LAYOUT_split_3x6_3(
  //|----------+------+-------------+---------+---------+--------------|        |------------+---------+---------------+-----------------+-------------+------------|
      KC_GRAVE, KC_1,  KC_2,         KC_3,     KC_4,     KC_5,                   KC_6,        KC_7,     KC_8,           KC_9,             KC_0,         XXXXXXX,
  //|----------+------+-------------+---------+---------+--------------|        |------------+---------+---------------+-----------------+-------------+------------|
      KC_TILDE, KC_LT, KC_AMPERSAND, KC_EQUAL, KC_MINUS, KC_QUOTE,               KC_QUESTION, KC_COMMA, KC_LEFT_PAREN,  KC_LEFT_BRACKET,  KC_SEMICOLON, KC_SLASH,
  //|----------+------+-------------+---------+---------+--------------|        |------------+---------+---------------+-----------------+-------------+------------|
      _______,  KC_GT, KC_ASTERISK,  KC_PLUS,  KC_UNDS,  KC_DOUBLE_QUOTE,        KC_EXCLAIM,  KC_DOT,   KC_RIGHT_PAREN, KC_RIGHT_BRACKET, KC_COLON,     KC_BACKSLASH,
  //|----------+------+-------------+---------+---------+--------------|        |------------+---------+---------------+-----------------+-------------+------------|
                                          KC_DEL, KC_SPC,  _______,    _______, KC_SPC, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [FUNC] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      K_PRTSC, XXXXXXX, XXXXXXX, KC_MPLY, KC_VOLU, KC_BRMU,                      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TG(ADJUST), XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_BRMD,                      KC_HOME, KC_END, XXXXXXX, XXXXXXX, XXXXXXX, K_LOCK,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_DEL, KC_SPC,  _______,    _______, KC_SPC, KC_BSPC
                                      //`--------------------------'  `--------------------------'
  ),

  [ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      XXXXXXX, XXXXXXX, RGB_MODE_SWIRL, RGB_MODE_RAINBOW, RGB_MODE_BREATHE, RGB_MODE_PLAIN,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, RGB_VAI, RGB_SAI, RGB_HUI, RGB_MODE_FORWARD, RGB_TOG,                      RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TG(ADJUST), RGB_VAD, RGB_SAD, RGB_HUD, RGB_MODE_REVERSE, XXXXXXX,                      RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXXXXXX, XXXXXXX,  XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    // uprintf("default_layer_state %s", default_layer_state);
    // uprintf("layer_state %s", layer_state);
    // uprintf("highest_layer %s", get_highest_layer(layer_state));
    // char layer_state_str[24];
    // snprintf(layer_state_str, sizeof(layer_state_str), "%u", layer_state);
    // oled_write_P(PSTR("Layer: "), false);
    // oled_write_ln_P(layer_state_str, false);
    switch (system_lang) {
        case EN:
            oled_write_P(PSTR("ENGLISH "), false);
            break;
        case RU:
            oled_write_P(PSTR("RUSSIAN "), false);
            break;
    }
    switch (get_highest_layer(layer_state)) {
        case BASE:
            oled_write_ln_P(PSTR(""), false);
            break;
        case CODE:
            oled_write_ln_P(PSTR("code"), false);
            break;
        case FUNC:
            oled_write_ln_P(PSTR("func"), false);
            break;
        case ADJUST:
            oled_write_ln_P(PSTR("adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR(""), false);
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

#endif // OLED_ENABLE



bool process_CODE_keycode_on_RUS_lang(uint16_t keycode) {
    switch (keycode) {
        case KC_QUOT:
        case KC_DQUO:
            register_code(KC_LSFT);
            tap_code(KC_2);
            unregister_code(KC_LSFT);
            return false;
        case KC_COMMA:
            register_code(KC_LSFT);
            tap_code(KC_6);
            unregister_code(KC_LSFT);
            return false;
        case KC_DOT:
            register_code(KC_LSFT);
            tap_code(KC_7);
            unregister_code(KC_LSFT);
            return false;
        case KC_LPRN:
            register_code(KC_LSFT);
            tap_code(KC_9);
            unregister_code(KC_LSFT);
            return false;
        case KC_RPRN:
            register_code(KC_LSFT);
            tap_code(KC_0);
            unregister_code(KC_LSFT);
            return false;
        case KC_SEMICOLON:
            register_code(KC_LSFT);
            tap_code(KC_8);
            unregister_code(KC_LSFT);
            return false;
        case KC_COLON:
            register_code(KC_LSFT);
            tap_code(KC_5);
            unregister_code(KC_LSFT);
            return false;
        case KC_QUESTION:
            register_code(KC_LSFT);
            tap_code(KC_SLASH);
            unregister_code(KC_LSFT);
            return false;
        case KC_EXCLAIM:
            register_code(KC_LSFT);
            tap_code(KC_1);
            unregister_code(KC_LSFT);
            return false;
        case KC_LEFT_BRACKET:
            register_code(KC_LSFT);
            tap_code(KC_GRAVE);
            unregister_code(KC_LSFT);
            return false;
        case KC_RIGHT_BRACKET:
            tap_code(KC_GRAVE);
            return false;
        case KC_LT:
            register_code(KC_LSFT);
            tap_code(KC_NUBS);
            unregister_code(KC_LSFT);
            return false;
        case KC_GT:
            tap_code(KC_NUBS);
            return false;
        default:
            return true;
    }
}

short lang_switched_keys_count = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef OLED_ENABLE
        if (record->event.pressed) {
            set_keylog(keycode, record);
        }
    #endif

    switch (keycode) {
        case TP(KC_CAPS_LOCK):
            if (record->event.pressed) {
                switch (system_lang) {
                    case EN:
                        system_lang = RU;
                        break;
                    case RU:
                        system_lang = EN;
                        break;
                }

                // Intercept tap function
                if (record->tap.count) {
                    tap_code(KC_CAPS_LOCK);
                }

                return false;
            }
            return true;

        case TP(KC_TAB):
            if (!record->tap.count && record->event.pressed) {
                tap_code(KC_ESC);
                return false;
            }
            return true;

        case TP(KC_M):
            if (!record->tap.count && record->event.pressed) {
                tap_code(KC_RBRC);
                return false;
            }
            return true;

        case TP(KC_T):
            if (!record->tap.count && record->event.pressed) {
                tap_code(KC_BSLS);
                return false;
            }
            return true;

        case TP(KC_P):
            if (!record->tap.count && record->event.pressed) {
                tap_code(KC_LBRC);
                return false;
            }
            return true;
    }



    if (system_lang == RU && get_highest_layer(layer_state) == CODE && record->event.pressed) {
        return process_CODE_keycode_on_RUS_lang(keycode);
    }

    return true;
}

// void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (system_lang == RU && get_highest_layer(layer_state) == CODE && !record->event.pressed && (keycode == KC_DOT || keycode == KC_COMMA)) {
//         lang_switched_keys_count--;
//         if (lang_switched_keys_count <= 0) {
//             tap_code(KC_CAPS_LOCK);
//             // SEND_STRING(SS_LCMD(" "));
//             lang_switched_keys_count = 0;
//         }
//     }
// }

void keyboard_post_init_user(void) {
    // rgblight_enable_noeeprom(); // enables Rgb, without saving settings
    // rgblight_sethsv_noeeprom(0, 0, 75);
    // rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgb_matrix_mode(RGB_MATRIX_PIXEL_FLOW);
}
