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

// Tap Dance declarations
enum {
    TD_M_HARD_SIGN,
    TD_P_HA,
    TD_G_ESC,
    TD_B_TAB,
    TD_E_LANG_CHANGE,
    TD_QUES_EXCL,
    TD_PARENS,
    TD_COL_SEMICOL,
    TD_BRACKETS,
    TD_BRASES,
    TD_SLASHES,
    TD_QUOTES,
    TD_EQ_PLUS,
    TD_AMP_AST,
    TD_LT_TD,
    TD_GR_TILD,

};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_M_HARD_SIGN] = ACTION_TAP_DANCE_DOUBLE(KC_M, KC_RBRC),
    [TD_P_HA] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_LBRC),
    [TD_G_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_G, KC_ESC),
    [TD_B_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_B, KC_TAB),
    [TD_E_LANG_CHANGE] = ACTION_TAP_DANCE_DOUBLE(KC_QUESTION, KC_CAPS_LOCK),
    [TD_QUES_EXCL] = ACTION_TAP_DANCE_DOUBLE(KC_QUESTION, KC_EXCLAIM),
    [TD_PARENS] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_PAREN, KC_RIGHT_PAREN),
    [TD_COL_SEMICOL] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SEMICOLON),
    [TD_BRACKETS] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_BRACKET, KC_RIGHT_BRACKET),
    [TD_BRASES] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE),
    [TD_SLASHES] = ACTION_TAP_DANCE_DOUBLE(KC_SLASH, KC_BACKSLASH),
    [TD_QUOTES] = ACTION_TAP_DANCE_DOUBLE(KC_DOUBLE_QUOTE, KC_QUOTE),
    [TD_EQ_PLUS] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_PLUS),
    [TD_AMP_AST] = ACTION_TAP_DANCE_DOUBLE(KC_AMPERSAND, KC_ASTERISK),
    [TD_LT_TD] = ACTION_TAP_DANCE_DOUBLE(KC_LT, KC_GT),
    [TD_GR_TILD] = ACTION_TAP_DANCE_DOUBLE(KC_GRAVE, KC_TILDE),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_split_3x6_3(
  //|--------+-------------+-------------+-----------------+-----------------+-----------|        |-------+-------------------+------------+------------+---------------+-----------------|
     XXXXXXX, KC_Q,         KC_W,         KC_E,             KC_R,             TP(KC_T),            KC_Y,   KC_U,               KC_I,        KC_O,        TD(TD_P_HA),    XXXXXXX,
  //|--------+-------------+-------------+-----------------+-----------------+-----------|        |-------+-------------------+------------+------------+---------------+-----------------|
     XXXXXXX, CTL_T(KC_A),  ALT_T(KC_S),  GUI_T(KC_D),      SFT_T(KC_F),      TD(TD_G_ESC),        KC_H,   RSFT_T(KC_J),       GUI_T(KC_K), ALT_T(KC_L), CTL_T(KC_SCLN), XXXXXXX,
  //|--------+-------------+-------------+-----------------+-----------------+-----------|        |-------+-------------------+------------+------------+---------------+-----------------|
     XXXXXXX, KC_Z,         KC_X,         KC_C,             KC_V,             TD(TD_B_TAB),        KC_N,   TD(TD_M_HARD_SIGN), KC_COMMA,    KC_DOT,      KC_QUOTE,       TP(KC_CAPS_LOCK),
  //|--------+-------------+-------------+-----------------+-----------------+-----------|        |-------+-------------------+------------+------------+---------------+-----------------|
                                          LT(FUNC, KC_DEL), LT(CODE, KC_SPC), KC_LGUI,             KC_ENT, LT(CODE, KC_SPC),   LT(FUNC, KC_BSPC)
  //                                     |-----------------+-----------------+-----------|        |-------+-------------------+------------------|

  ),

  [CODE] = LAYOUT_split_3x6_3(
  //|--------+-------------+---------------+---------------+----------------+--------------|        |-----------------+----------------+--------------+-------------------+----------------+--------|
     XXXXXXX, KC_1,         KC_2,           KC_3,           KC_4,            KC_5,                   KC_6,             KC_7,            KC_8,          KC_9,               KC_0,            XXXXXXX,
  //|--------+-------------+---------------+---------------+----------------+--------------|        |-----------------+----------------+--------------+-------------------+----------------+--------|
     XXXXXXX, TD(TD_LT_TD), TD(TD_AMP_AST), TD(TD_EQ_PLUS), SFT_T(KC_MINUS), TD(TD_QUOTES),          TD(TD_QUES_EXCL), SFT_T(KC_COMMA), TD(TD_PARENS), TD(TD_COL_SEMICOL), TD(TD_BRACKETS), XXXXXXX,
  //|--------+-------------+---------------+---------------+----------------+--------------|        |-----------------+----------------+--------------+-------------------+----------------+--------|
     XXXXXXX, XXXXXXX,      XXXXXXX,        XXXXXXX,        KC_UNDS,         TD(TD_GR_TILD),         KC_AT,            KC_DOT,          XXXXXXX,       TD(TD_SLASHES),     TD(TD_BRASES),   XXXXXXX,
  //|--------+-------------+---------------+---------------+----------------+--------------|        |-----------------+----------------+--------------+-------------------+----------------+--------|
                                            KC_DEL,         KC_SPC,          _______,                _______,          KC_SPC,          KC_BSPC
  //                                       |---------------+----------------+--------------|        |-----------------+----------------+--------------|
  ),

  [FUNC] = LAYOUT_split_3x6_3(
  //|-----------+---------+---------------+---------+---------+-----------|        |--------------+--------+-------+----------------+--------+--------|
     XXXXXXX,    KC_F1,    KC_F2,          KC_F3,    KC_F4,    KC_F5,               KC_F6,         KC_F7,   KC_F8,  KC_F9,           KC_F10,  K_LOCK,
  //|-----------+---------+---------------+---------+---------+-----------|        |--------------+--------+-------+----------------+--------+--------|
     XXXXXXX,    K_PRTSC,  KC_LALT,        KC_MPLY,  KC_VOLU,  KC_BRMU,             KC_LEFT,       KC_DOWN, KC_UP,  ALT_T(KC_RIGHT), KC_F11,  XXXXXXX,
  //|-----------+---------+---------------+---------+---------+-----------|        |--------------+--------+-------+----------------+--------+--------|
     TG(ADJUST), XXXXXXX,  LGUI(KC_SLASH), KC_MUTE,  KC_VOLD,  KC_BRMD,             LALT(KC_LEFT), KC_HOME, KC_END, LALT(KC_RIGHT),  KC_F12,  XXXXXXX,
  //|-----------+---------+---------------+---------+---------+-----------|        |--------------+--------+-------+----------------+--------+--------|
                                           KC_DEL,   KC_SPC,   _______,             _______,       KC_SPC,  KC_BSPC
  //                                      |---------+---------+-----------|        |--------------+--------+-------|
  ),

  [ADJUST] = LAYOUT_split_3x6_3(
  //|-----------+--------+--------+--------+-----------------+----------|        |--------+--------+--------+--------+--------+--------|
     XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-----------+--------+--------+--------+-----------------+----------|        |--------+--------+--------+--------+--------+--------|
     KC_LSFT,    RGB_VAI, RGB_SAI, RGB_HUI, RGB_MODE_FORWARD, RGB_TOG,            RGB_SPI, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-----------+--------+--------+--------+-----------------+----------|        |--------+--------+--------+--------+--------+--------|
     TG(ADJUST), RGB_VAD, RGB_SAD, RGB_HUD, RGB_MODE_REVERSE, EE_CLR,             RGB_SPD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|-----------+--------+--------+--------+-----------------+----------|        |--------+--------+--------+--------+--------+--------|
                                   XXXXXXX, XXXXXXX,          XXXXXXX,            XXXXXXX, XXXXXXX, XXXXXXX
  //                              |--------+-----------------+----------|        |--------+--------+--------|
  )
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
        case TD(TD_M_HARD_SIGN):
        case TD(TD_P_HA):
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(CODE, KC_SPC):
        case LT(FUNC, KC_DEL):
        case LT(FUNC, KC_BSPC):
            // Immediately select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return OLED_ROTATION_270;
}

void oled_render_layer_state(void) {
    static const char PROGMEM ru_logo[] = {
        0x95, 0x96, 0x97, 0x98, 0x99,
        0xB5, 0xB6, 0xB7, 0xB8, 0xB9,
        0xD5, 0xD6, 0xD7, 0xD8, 0xD9,
        0,
    };
    static const char PROGMEM en_logo[] = {
        0x9A, 0x9B, 0x9C, 0x9D, 0x9E,
        0xBA, 0xBB, 0xBC, 0xBD, 0xBE,
        0xDA, 0xDB, 0xDC, 0xDD, 0xDE,
        0,
    };

    switch (system_lang) {
        case EN:
            oled_write_P(en_logo, false);
            break;
        case RU:
            oled_write_P(ru_logo, false);
            break;
    }

    oled_write_ln_P(PSTR(""), false);

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
            oled_write_ln_P(PSTR("led"), false);
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
        // oled_render_keylog();
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
        case SFT_T(KC_COMMA):
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
        case KC_2:  // @
            if (get_mods() == MOD_BIT(KC_LSFT)) {
                unregister_code(KC_LSFT);
                register_code(KC_LALT);
                tap_code(KC_2);
                unregister_code(KC_LALT);
                register_code(KC_LSFT);
                return false;
            }
            return true;
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

        case KC_CAPS_LOCK:
            switch (system_lang) {
                case EN:
                    system_lang = RU;
                    break;
                case RU:
                    system_lang = EN;
                    break;
            }
            return true;
    }



    if (system_lang == RU && get_highest_layer(layer_state) == CODE && record->event.pressed) {
        return process_CODE_keycode_on_RUS_lang(keycode);
    }

    return true;
}
