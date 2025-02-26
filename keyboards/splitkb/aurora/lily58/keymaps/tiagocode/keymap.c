/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

#if __has_include("keymap.h")
#    include "keymap.h"
#endif

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
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BACKSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | TAB  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LCAPS |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RCAPS |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LCTRL | NUMS | NAV  | /SPACE  /       \ENTER \  |SYMBS |FUNCS | RAlt |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_QWERTY] = LAYOUT(
        XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        NUM_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, QUO_FUN,
          LCAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, KC_RBRC,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   RCAPS,
                                   KC_LCTL,    NUMS,     NAV,  KC_SPC,  KC_ENT,   SYMBS,   FUNCS, KC_RALT
    ),

    /*
     * 2nd layer -> Navigation
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      | PSCR |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |      |      |      |                    |      |      |  Up  |      |      |BACKSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |NUMTAB|      |LCTRL | LALT |LSHIFT|      |-------.    ,-------| Home | Left | Down |Right | End  | DEL  |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LCAPS |      |      | META | MENU |      |-------|    |-------|      |      |      |      |      |RCAPS |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |ADJS  | NUMS |      | /SPACE  /       \ENTER \  |      |DEL   |BACKSP|
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_NAVIGATION] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,                    XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                    KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, KC_LGUI,  KC_APP, XXXXXXX,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                      ADJS, _______, XXXXXXX,  _______, _______, XXXXXXX,  KC_DEL, KC_BSPC
    ),

    /*
     * 3rd layer -> Numpad
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |    - |    + |    = |                    |      |    7 |    8 |    9 |      |BACKSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |NUMTAB|      |      |    * |    / |    % |-------.    ,-------|      |    4 |    5 |    6 |      | DEL  |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |LCAPS |      |      |    ^ |    , |    . |-------|    |-------|      |    1 |    2 |    3 |      |RCAPS |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      | NAV  | /Space  /       \Enter \  |      |    0 |    . |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_NUMPAD] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS,  KC_EQL,                    XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_PSLS, KC_PERC,                    XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, KC_CIRC, KC_COMM,  KC_DOT,  _______, _______, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
                                   _______, XXXXXXX, _______,  _______, _______,    KC_0,  KC_DOT,  _______
    ),

    /*
     * 4rd layer -> Symbols
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |BackSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |    ( |    ) |    # |                    |    ! |    & |    | |    \ |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |    { |    } |    @ |-------.    ,-------|    $ |    = |    - |    _ |   `  |      |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |    [ |    ] |      |-------|    |-------|    + |    - |    < |    > |    ~ |    ? |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /Space  /       \Enter \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_SYMBOLS] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_HASH,                    KC_EXLM, KC_AMPR, KC_PIPE, KC_PSLS, KC_BSLS, _______,
        _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,   KC_AT,                     KC_DLR,  KC_EQL, KC_PMNS, KC_UNDS,  KC_GRV,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,  _______, _______, KC_PLUS,KC_MINUS, KC_LABK, KC_RABK, KC_TILD, KC_QUES,
                                   _______, _______, _______,  _______, _______, _______, XXXXXXX, _______
    ),

    /*
     * 5th layer -> Functions
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | ESC  |      |      |      |      |      |                    |      |   F9 |  F10 |  F11 |  F12 |BACKSP|
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |NUMTAB|      |LCTRL | LALT |LSHIFT|      |-------.    ,-------|      |   F5 |   F6 |   F7 |   F8 |DEL   |
     * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |   F1 |   F2 |   F3 |   F4 |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |      |      |      | /Space  /       \Enter \  |      |      |      |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_FUNCTIONS] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
        _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                    XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
                                   _______, _______, _______,  _______, _______, _______, XXXXXXX, _______
    ),

    /*
     * 6th layer -> Adjust
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *                   |LCTRL | NUMS | NAV  | /Space  /       \Enter \  |      |BackSP| RAlt |
     *                   |      |      |      |/       /         \      \ |      |      |      |
     *                   `----------------------------'           '------''--------------------'
     */
    [_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                    _______, _______, _______, _______, _______, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, UG_TOGG, UG_HUEU, UG_SATU, UG_VALU,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, _______, XXXXXXX, XXXXXXX, UG_NEXT, UG_HUED, UG_SATD, UG_VALD,
                                   _______, _______, _______,  _______, _______, _______, XXXXXXX, _______
    ),
};

#ifdef OLED_ENABLE

// Custom OLED screen configuration
// Rotate the OLED screen 180 degrees
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;
    }

    return rotation;
}

#endif
