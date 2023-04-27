/* SPDX-License-Identifier: GPL-2.0-or-later */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
	       KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,          KC_BSPC,
	       KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    LT(1, KC_ENT),
	       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
	                                  KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_LALT, KC_LGUI
	       ),

  [1] = LAYOUT(
         KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
	       KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_F,    KC_G,    KC_RBRC, KC_MINS, KC_EQL,  KC_TRNS, KC_TRNS,
	       KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LBRC, KC_QUOT, KC_BSLS, KC_TRNS, KC_TRNS,
	                                  KC_LALT, KC_LGUI, KC_SPC,  KC_SPC,  KC_LALT, KC_LGUI
	       ),

    
  [2] = LAYOUT(
	       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	       KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	       ),

    
  [3] = LAYOUT(
	       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	       KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
	                                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	       ),
};

enum combos {
  F1_F1,
  F2_F2,
  F3_F3,
  F4_F4,
  F5_F5,
  F6_F6,
  F7_F7,
  F8_F8,
  F9_F9,
  G0_F10,
  G1_F11,
  G2_F12,
  JX_CUT,
  JC_COPY,
  JV_PASTE,
  COMBO_LENGTH
};

uint16_t COMBO_LEN = COMBO_LENGTH; // remove the COMBO_COUNT define and use this instead!


const uint16_t PROGMEM f1_combo[] = {KC_F, KC_1, COMBO_END};
const uint16_t PROGMEM f2_combo[] = {KC_F, KC_2, COMBO_END};
const uint16_t PROGMEM f3_combo[] = {KC_F, KC_3, COMBO_END};
const uint16_t PROGMEM f4_combo[] = {KC_F, KC_4, COMBO_END};
const uint16_t PROGMEM f5_combo[] = {KC_F, KC_5, COMBO_END};
const uint16_t PROGMEM f6_combo[] = {KC_F, KC_6, COMBO_END};
const uint16_t PROGMEM f7_combo[] = {KC_F, KC_7, COMBO_END};
const uint16_t PROGMEM f8_combo[] = {KC_F, KC_8, COMBO_END};
const uint16_t PROGMEM f9_combo[] = {KC_F, KC_9, COMBO_END};
const uint16_t PROGMEM g0_combo[] = {KC_G, KC_0, COMBO_END};
const uint16_t PROGMEM g1_combo[] = {KC_G, KC_1, COMBO_END};
const uint16_t PROGMEM g2_combo[] = {KC_G, KC_2, COMBO_END};

const uint16_t PROGMEM jx_combo[] = {KC_J, KC_X, COMBO_END};
const uint16_t PROGMEM jc_combo[] = {KC_J, KC_C, COMBO_END};
const uint16_t PROGMEM jv_combo[] = {KC_J, KC_V, COMBO_END};

combo_t key_combos[] = {
  [F1_F1] = COMBO(f1_combo, KC_F1),
  [F2_F2] = COMBO(f2_combo, KC_F2),
  [F3_F3] = COMBO(f3_combo, KC_F3),
  [F4_F4] = COMBO(f4_combo, KC_F4),
  [F5_F5] = COMBO(f5_combo, KC_F5),
  [F6_F6] = COMBO(f6_combo, KC_F6),
  [F7_F7] = COMBO(f7_combo, KC_F7),
  [F8_F8] = COMBO(f8_combo, KC_F8),
  [F9_F9] = COMBO(f9_combo, KC_F9),
  [G0_F10] = COMBO(g0_combo, KC_F10),
  [G1_F11] = COMBO(g1_combo, KC_F11),
  [G2_F12] = COMBO(g2_combo, KC_F12),
  [JX_CUT] = COMBO(jx_combo, LGUI(KC_X)),
  [JC_COPY] = COMBO(jc_combo, LGUI(KC_C)),
  [JV_PASTE] = COMBO(jv_combo, LGUI(KC_V))
};
