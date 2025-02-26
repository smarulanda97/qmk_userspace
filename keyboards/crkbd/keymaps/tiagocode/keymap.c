#include QMK_KEYBOARD_H

#if __has_include("keymap.h")
#    include "keymap.h"
#endif

#include <stdio.h>

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
     * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |   A  |   S  |   D  |   F  |   G  |                    |   H  |   J  |   K  |   L  |   ;  |  '   |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          |Space |      | /Space /        \Enter \  |Enter | SYMB |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_QWERTY] = LAYOUT_split_3x6_3(
         KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC,
        NUM_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, QUO_FUN,
          LCAPS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,   RCAPS,
                                            KC_LCTL,     NAV,  KC_SPC,    KC_ENT,   SYMBS, KC_LALT
    ),

    /*
     * 2nd layer -> Navigation
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |      |      |      |                    |      |      |      |      |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |LCTRL | LAlt |LShift|      |                    | Home | Left | Down |Right | End  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |      |      |      |      |RShift|
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          | NUMS | NAV  | /Space /        \Enter \  | ADJS |FUNCS |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_NAVIGATION] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX,   KC_UP, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                     KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT,  KC_END,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                               ADJS, XXXXXXX, _______,   _______,  KC_DEL, KC_BSPC
    ),    
    
    /*
     * 3rd layer -> Numpad
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |    - |    + |    = |                    |      |    7 |    8 |    9 |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |    * |    / |    % |                    |      |    4 |    5 |    6 |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |    ^ |    , |    . |-------|    |-------|      |    1 |    2 |    3 |      |RShift|
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          | NUMS | NAV  | /Space /        \Enter \  |    0 |    . |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_NUMPAD] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, KC_MINS, KC_PLUS,  KC_EQL,                     XXXXXXX,    KC_7,    KC_8,    KC_9, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, KC_ASTR, KC_PSLS, KC_PERC,                     XXXXXXX,    KC_4,    KC_5,    KC_6, XXXXXXX,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, KC_CIRC, KC_COMM,  KC_DOT,                     XXXXXXX,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, _______,   _______,    KC_0,  KC_DOT
    ),


    /*
     * 4rd layer -> Symbols
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |    ( |    ) |    # |                    |    ! |    & |    | |    \ |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |    { |    } |    @ |                    |    $ |    = |    - |    _ |   `  |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |    [ |    ] |      |-------|    |-------|    + |    - |    < |    > |    ~ |    ? |
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          | NUMS | NAV  | /Space /        \Enter \  |SYMBS |FUNCS |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_SYMBOLS] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, KC_HASH,                     KC_EXLM, KC_AMPR, KC_PIPE, KC_PSLS, KC_BSLS, _______,
        _______, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR,   KC_AT,                      KC_DLR,  KC_EQL, KC_PMNS, KC_UNDS,  KC_GRV,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX,                     KC_PLUS,KC_MINUS, KC_LABK, KC_RABK, KC_TILD, KC_QUES,
                                            XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX
    ),

    /*
     * 5th layer -> Functions
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |      |      |      |                    |      |   F9 |  F10 |  F11 |  F12 | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |LCTRL | LAlt |LShift|      |                    |      |   F5 |   F6 |   F7 |   F8 |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |   F1 |   F2 |   F3 |   F4 |      |
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          | NUMS | NAV  | /Space /        \Enter \  |SYMBS |      |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_FUNCTIONS] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,   KC_F9,  KC_F10,  KC_F11,  KC_F12, _______,
        _______, XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, XXXXXXX,                     XXXXXXX,   KC_F5,   KC_F6,   KC_F7,   KC_F8,  KC_DEL,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,   KC_F1,   KC_F2,   KC_F3,   KC_F4, _______,
                                            XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX
    ),

    /*
     * 6th layer -> Adjust
     *
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * | ESC  |      |      |      |      |      |                    |      |      |      |      |      | Del  |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * | Tab  |      |      |      |      |      |                    |      |      |RGB ON| HUE+ | SAT+ | VAL+ |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |LShift|      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
     * `-----------------------------------------/      /      \      \-----------------------------------------'
     *                          |      |      | /Space /        \Enter \  |      |      |
     *                          |      |      |/      /          \      \ |      |      |
     *                          `--------------------'            '------''-------------'
     */
    [_ADJUST] = LAYOUT_split_3x6_3(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, UG_TOGG, RM_TOGG, RM_HUEU, RM_SATU, RM_VALU,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, RM_NEXT, RM_HUED, RM_SATD, RM_VALD,
                                            XXXXXXX, XXXXXXX, _______,   _______, XXXXXXX, XXXXXXX
    )
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