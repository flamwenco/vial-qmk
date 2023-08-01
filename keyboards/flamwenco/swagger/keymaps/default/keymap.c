// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers{
    BASE,
    _FN1,
    _FN2,
    _FN3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT(
        KC_TAB,        KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,           KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        CTL_T(KC_ESC), KC_A,    KC_S,     KC_D,     KC_F,     KC_G,           KC_H,     KC_J,     KC_K,     KC_L,     KC_ENT,
        KC_LSFT,       KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,           KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,
        RGB_MOD,       KC_LALT, KC_LGUI,         KC_SPC,                      KC_SPC,         KC_LALT,  KC_LGUI,  RGB_RMOD
    ),

    [_FN1] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,              KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        _______, _______, _______, _______, _______, _______,           KC_LBRC, KC_MINS, KC_EQL,  _______, KC_SCLN,
        _______, _______, _______, _______, _______, _______,           KC_RBRC, KC_QUOT, KC_BSLS, _______, _______,
        _______, _______, _______,          _______,                             _______,          _______, _______, _______
    ),

    [_FN2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,                             _______,          _______, _______, _______
    ),

    [_FN3] = LAYOUT(
        _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,           _______, _______, _______, _______, _______,
        _______, _______, _______,          _______,                             _______,          _______, _______, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN1] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN2] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_FN3] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};
#endif