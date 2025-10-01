/* Copyright 2019 Santiago Marulanda <contact@tiagocode.com>
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
    * ,----------------------------------------------------------------------------------------------------------------------.
    * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * | ESC  |   Q  |   W  |   E  |   R  |   T  |      |                    |      |   Y  |   U  |   I  |   O  |   P  |BACKSP|
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * |NUMTAB|   A  |   S  |   D  |   F  |   G  |      |                    |      |   H  |   J  |   K  |   L  |   ;  |QUOFUN|
    * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
    * |LCAPS |   Z  |   X  |   C  |   V  |   B  |      |                    |      |   N  |   M  |   ,  |   .  |   /  | RCAPS|
    * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
    * |      |      |LCTRL | LCMD |||||||| NAV  |SPACE |SPACE ||||||||ENTER |ENTER |SYMBS ||||||||FUNCS | RALT |      |      |
    * ,----------------------------------------------------------------------------------------------------------------------.
    */
    [_QWERTY] = LAYOUT(
        XXXXXXX,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,                       XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, XXXXXXX,                       XXXXXXX,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        NUM_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G, XXXXXXX,                       XXXXXXX,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, QUO_FUN,
          LCAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,                       XXXXXXX,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   RCAPS,
        XXXXXXX, XXXXXXX, KC_LCTL, KC_LCMD,              NAV,  KC_SPC,  KC_SPC,      KC_ENT,  KC_ENT,   SYMBS,            FUNCS, KC_RALT, XXXXXXX, XXXXXXX
    ),

    /*
    * 2nd layer -> Navigation
    *
    * ,----------------------------------------------------------------------------------------------------------------------.
    * |      |   1  |   2  |   3  |   4  |   5  |      |                    |      |   6  |   7  |   8  |   9  |   0  |      |
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * | ESC  |      |      |      |      |      |      |                    |      |      |      |  Up  |      |      |BACKSP|
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * |NUMTAB|      | LCTRL| LALT |LSHIFT|      |      |                    |      | Home | Left | Down | Right|  End | DEL  |
    * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
    * |LCAPS |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
    * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
    * |      |      |      |ADJS  ||||||||      |       |SPACE ||||||||ENTER |      |DEL   ||||||||BACKSP|      |      |      |
    * ,----------------------------------------------------------------------------------------------------------------------.
    */
    [_NAVIGATION] = LAYOUT(
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5, XXXXXXX,                       XXXXXXX,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, _______,
        _______, KC_LCMD, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX,    ADJS,          XXXXXXX, _______, _______,     _______, _______,  KC_DEL,          KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX
   ),

    /*
    * 3rd layer -> Numpad
    *
    * ,----------------------------------------------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * | ESC  |      |      |    - |    + |    = |      |                    |      |      |    7 |    8 |    9 |      |BACKSP|
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * | Tab  |      |      |    * |    / |    % |      |                    |      |      |    4 |    5 |    6 |      | DEL  |
    * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
    * |LCAPS |      |      |    ^ |    . |    . |      |                    |      |      |    1 |    2 |    3 |      |      |
    * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
    * |      |      |      |ADJS  ||||||||      |       |SPACE |||||||ENTER |      |    0 ||||||||    . |      |      |      |
    * ,----------------------------------------------------------------------------------------------------------------------.
    */
    [_NUMPAD] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS,  KC_EQL, XXXXXXX,                       XXXXXXX, XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_PSLS, KC_PERC, XXXXXXX,                       XXXXXXX, XXXXXXX,    KC_4,    KC_5,    KC_6,  KC_END,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, KC_CIRC, KC_COMM,  KC_DOT, XXXXXXX,                       XXXXXXX, XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, _______, _______,     _______, XXXXXXX,    KC_0,  KC_DOT,          XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /*
    * 4rd layer -> Symbols
    *
    * ,----------------------------------------------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * | ESC  |      |      |      |      |      |      |                    |      |      |      |  Up  |      |      |BACKSP|
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * | Tab  |      |      |      |      |      |      |                    |      | Home | Left | Down | Right|  End | DEL  |
    * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
    * |LCAPS |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
    * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
    * |      |      |      |ADJS  ||||||||      |       |SPACE ||||||||ENTER |      |DEL   ||||||||BACKSP|      |      |      |
    * ,----------------------------------------------------------------------------------------------------------------------.
    */
    [_SYMBOLS] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_HASH, XXXXXXX,                       XXXXXXX, KC_EXLM, KC_AMPR, KC_PIPE, KC_PSLS, KC_BSLS, _______,
        _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,   KC_AT, XXXXXXX,                       XXXXXXX,  KC_DLR,  KC_EQL, KC_PMNS, KC_UNDS,  KC_GRV,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,                       XXXXXXX, KC_PLUS,KC_MINUS, KC_LABK, KC_RABK, KC_TILD, KC_QUES,
        _______, XXXXXXX, XXXXXXX, _______,          _______, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),

    /*
    * 5th layer -> Functions
    *
    * ,----------------------------------------------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * | ESC  |      |      |      |      |      |      |                    |      |      |   F9 |  F10 |  F11 |  F12 |BACKSP|
    * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
    * |      |      |LCTRL | LALT |LSHIFT|      |      |                    |      |      |   F5 |   F6 |   F7 |   F8 | DEL  |
    * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |                    |      |      |   F1 |   F2 |   F3 |   F4 |      |
    * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
    * |      |      |      |ADJS  ||||||||      |       |SPACE ||||||||ENTER |      |DEL   ||||||||BACKSP|      |      |      |
    * ,----------------------------------------------------------------------------------------------------------------------.
    */
    [_FUNCTIONS] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
        _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                       XXXXXXX, XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
        _______, XXXXXXX, XXXXXXX, _______,          _______, XXXXXXX, _______,     _______, XXXXXXX, XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX
    ),
};

