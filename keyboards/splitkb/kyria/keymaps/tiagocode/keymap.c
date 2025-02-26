/* Copyright 2022 Santiago Marulanda <santiagomm1997@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

enum layers {
    _QWERTY,
    _NAVIGATION,
    _NUMPAD,
    _SYMBOLS,
    _FUNCTIONS,
    _ADJUST,
};

// Aliases for changing layers
#define NAV MO(_NAVIGATION)
#define NUMS MO(_NUMPAD)
#define SYMBS MO(_SYMBOLS)
#define FUNCS MO(_FUNCTIONS)
#define ADJS MO(_ADJUST)
#define NUM_TAB LT(_NUMPAD, KC_TAB)
#define QUO_FUN LT(_FUNCTIONS, KC_QUOT)

// Aliases for modifiers
#define LCAPS SFT_T(KC_CAPS)
#define RCAPS RSFT_T(KC_CAPS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * 1st layer -> QWERTY
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * | ESC    |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  | BACKSP |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |NUM_TAB |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : | ' "    |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | LCAPS  |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? | RCAPS  |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |LCTRL |LCTRL | NUM  | NAV  |SPACE |  |ENTER | SYMB |FUNCS | LALT | LALT |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_QWERTY] = LAYOUT(
          KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
         NUM_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                            KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, QUO_FUN,
           LCAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   RCAPS,
                                    KC_LCTL,    NUMS,     NAV,  KC_SPC,  KC_SPC,      KC_ENT,  KC_ENT,   SYMBS,   FUNCS, KC_LALT
    ),

    /*
     * 2nd layer -> Navigation
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * | ESC    |      |      |      |      |PSCR  |                              |      |      |   ↑  |      |      | BACKSP |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |NUM_TAB |      |LCTRL | LALT |LSHIFT|      |                              | HOME |  ←   |   ↓  |  ->  | END  | DEL    |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * |        |      |      | META | MENU |      |      |      |  |      |      |      |      |      |      |      |        |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        | ADJS |      |      |      |SPACE |  |ENTER |      |DEL   |BACKSP|      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
    [_NAVIGATION] = LAYOUT(
          KC_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                                         XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, _______,
         _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                                         KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,  KC_DEL,
         _______, XXXXXXX, XXXXXXX, KC_LGUI,  KC_APP, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                       ADJS, XXXXXXX, _______, XXXXXXX, _______,     _______, XXXXXXX,  KC_DEL, KC_BSPC, _______
    ),

    /*
     * 3rd layer -> Numpad
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * | ESC    |      |      |    - |    + |    = |                              |      |    7 |    8 |    9 |      | BACKSP |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |NUM_TAB |      |      |    * |    / |    % |                              |      |    4 |    5 |    6 |      | DEL    |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | LCAPS  |      |      |    ^ |    , |    . |      |      |  |      |      |      |    1 |    2 |    3 |      | RCAPS  |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      | NAV  |SPACE |SPACE |  |ENTER |ENTER |    0 |    . |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
     [_NUMPAD] = LAYOUT(
         _______, XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS,  KC_EQL,                                         XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
         _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_PSLS, KC_PERC,                                         XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,  KC_DEL,
         _______, XXXXXXX, XXXXXXX, KC_CIRC, KC_COMM,  KC_DOT, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, _______,
                                    XXXXXXX, XXXXXXX, XXXXXXX, _______, _______,     _______, _______,    KC_0,  KC_DOT, XXXXXXX
     ),


    /*
     * 4rd layer -> Symbols
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * | ESC    |      |      |    ( | )    |    # |                              |    ! |    & |    | |    / |    \ | BACKSP |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |NUM_TAB |      |      |    { |    } |    @ |                              |    $ |    = |    - |    _ |    ` | DEL    |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | LShift |      |      |    [ | ]    |      |      |      |  |      |      |    + |    - |    < |    > |    ~ |      ? |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |SPACE |SPACE |  |ENTER |ENTER |    0 |    . |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
     [_SYMBOLS] = LAYOUT(
         _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_HASH,                                         KC_EXLM, KC_AMPR, KC_PIPE, KC_PSLS, KC_PSCR, _______,
         _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,   KC_AT,                                          KC_DLR,  KC_EQL, KC_PMNS, KC_UNDS,  KC_GRV,  KC_DEL,
         _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_PLUS,KC_MINUS, KC_LABK, KC_RABK, KC_TILD, KC_QUES,
                                    _______, XXXXXXX, XXXXXXX, _______, _______,     _______, _______, XXXXXXX, XXXXXXX, _______
     ),

    /*
     * 5th layer -> Functions
     *
     * ,-------------------------------------------.                              ,-------------------------------------------.
     * | ESC    |      |      |      |      |      |                              |      |   F9 |  F10 |  F11 |  F12 |BACKSP  |
     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
     * |NUM_TAB |      |LCTRL |LALT  |LSHIFT|      |                              |   F5 |   F6 |   F7 |   F8 |   F9 | DEL    |
     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
     * | LCAPS  |      |      |      |      |      |      |      |  |      |      |      |   F1 |   F2 |   F3 |   F4 | RCAPS  |
     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
     *                        |      |      |      |SPACE |SPACE |  |ENTER |ENTER |      |      |      |
     *                        |      |      |      |      |      |  |      |      |      |      |      |
     *                        `----------------------------------'  `----------------------------------'
     */
     [_FUNCTIONS] = LAYOUT(
         _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
         _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                                         XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
         _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
                                    _______, XXXXXXX, XXXXXXX, _______, _______,     _______, _______, XXXXXXX, XXXXXXX, _______
     ),


     /*
      * 6th layer -> Adjust
      *
      * ,-------------------------------------------.                              ,-------------------------------------------.
      * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
      * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
      * |        |      |      |      |      |      |                              |      |      |RGB ON| HUE+ | SAT+ | VAL+   |
      * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
      * |        |      |      |      |      |      |      |      |  |      |      |      |      |MODE  | HUE- | SAT- | VAL-   |
      * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
      *                        |      |      |      |      |      |  |      |      |      |      |      |
      *                        |      |      |      |      |      |  |      |      |      |      |      |
      *                        `----------------------------------'  `----------------------------------'
      */
      [_ADJUST] = LAYOUT(
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU,
          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, UG_NEXT, UG_HUED, UG_SATD, UG_VALD,
                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
      ),

    //    /*
    //     * Layer template
    //     *
    //     * ,-------------------------------------------.                              ,-------------------------------------------.
    //     * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    //     * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
    //     * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
    //     * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
    //     * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
    //     * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
    //     *                        |      |      |      |      |      |  |      |      |      |      |      |
    //     *                        |      |      |      |      |      |  |      |      |      |      |      |
    //     *                        `----------------------------------'  `----------------------------------'
    //     */
    //     [_LAYERINDEX] = LAYOUT(
    //         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    //     ),
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("\n"), false);
        oled_write_P(PSTR("Santiago's Kyria\n"), false);
        oled_write_P(PSTR("Layer: "), false);

        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("Qwerty\n"), false);
                break;
            case _NAVIGATION:
                oled_write_P(PSTR("Navigation\n"), false);
                break;
            case _NUMPAD:
                oled_write_P(PSTR("Numpad\n"), false);
                break;
            case _SYMBOLS:
                oled_write_P(PSTR("Symbols\n"), false);
                break;
            case _FUNCTIONS:
                oled_write_P(PSTR("Functions\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        led_t led_usb_state = host_keyboard_led_state();

        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

