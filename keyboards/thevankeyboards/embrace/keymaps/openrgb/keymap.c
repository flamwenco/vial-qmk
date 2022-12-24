#include "embrace.h"
#include "g/keymap_combo.h"

enum custom_keycodes {
  M_IME = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(KC_1,           KC_2,    KC_3,    KC_4,  KC_5,   KC_6,                                             KC_MUTE,
	       KC_TAB,         KC_Q,    KC_W,    KC_E,  KC_R,   KC_T,   KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
	       LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,  KC_F,   KC_G,   KC_H, KC_J,    KC_K,    KC_L,    KC_SCLN, LT(1, KC_ENT),
	       KC_LSFT, KC_Z,  KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M, KC_COMM, KC_DOT,  KC_UP,   KC_SLSH,
	       MO(2),   KC_LALT, KC_LGUI,               KC_NO,  KC_SPC, KC_NO,         KC_LEFT, KC_DOWN, KC_RIGHT),
  [1] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                            KC_MPLY,
	       KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
	       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_F,    KC_G,    KC_NO, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS,
	       KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_QUOT, KC_BSLS, KC_NO,   KC_TRNS, KC_NO,
	       KC_TRNS, KC_TRNS, KC_TRNS,          KC_NO,   KC_TRNS, KC_NO,                   KC_TRNS, KC_TRNS, KC_TRNS),
  [2] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_MPLY,
	       KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN, KC_DEL,
	       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UNDS, KC_PLUS, KC_LCBR,  KC_RCBR, KC_TRNS,
	       KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_DQUO, KC_PIPE, KC_NO,    KC_TRNS, KC_NO,
	       KC_TRNS, KC_TRNS, KC_TRNS,          KC_NO,   KC_TRNS, KC_NO,                     RGB_RMOD, RGB_TOG, RGB_MOD),
  [3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS,
	       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_TRNS,
	       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_TRNS,
	       KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_TRNS, KC_NO,
	       KC_TRNS, KC_TRNS, KC_TRNS,          KC_NO,   KC_TRNS, KC_NO,               KC_TRNS, KC_TRNS, KC_TRNS),

  /* empty layer
     [3] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_TRNS,
   	       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_TRNS,
   	       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_TRNS,
   	       KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,   KC_TRNS, KC_NO,
   	       KC_TRNS, KC_TRNS, KC_TRNS,          KC_NO,   KC_TRNS, KC_NO,               KC_TRNS, KC_TRNS, KC_TRNS),
  */
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
  [0] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
  [1] =  { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
  [2] =  { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
  [3] =  { ENCODER_CCW_CW(KC_TRNS, KC_TRNS) },
};
#endif

#if defined(RGB_MATRIX_ENABLE)
/* RGB Matrix */
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {                4,        9,       14,       18,       23,       28,             NO_LED                               },
    {      0,        5,       10,       15,       19,       24,       29,       33,       37,       40,       44,       48 },
    {      1,        6,       11,       16,       20,       25,       30,       34,       38,       41,       45,       49 },
    {      2,        7,       12,       17,       21,       26,       31,       35,       39,       42,       46,       50 },
    {      3,        8,       13,                 22,       27,       32,       36,                 43,       47,       51 }
  }, {
    // LED Index to Physical Position
    {   0,  15 }, {   3,  30 }, {   8,  45 }, {   3,  60 },
    {  10,   0 }, {  19,  15 }, {  24,  30 }, {  33,  45 }, {  24,  60 },
    {  29,   0 }, {  38,  15 }, {  43,  30 }, {  52,  45 }, {  45,  60 },
    {  47,   0 }, {  57,  15 }, {  61,  30 }, {  71,  45 },
    {  66,   0 }, {  75,  15 }, {  80,  30 }, {  89,  45 }, {  82,  60 },
    {  85,   0 }, {  94,  15 }, {  99,  30 }, { 108,  45 }, { 115,  60 },
    { 103,   0 }, { 113,  15 }, { 118,  30 }, { 127,  45 }, { 129,  60 },
    { 132,  15 }, { 136,  30 }, { 146,  45 }, { 162,  60 },
    { 150,  15 }, { 155,  30 }, { 164,  45 },
    { 169,  15 }, { 174,  30 }, { 183,  45 }, { 183,  60 },
    { 188,  15 }, { 192,  30 }, { 202,  45 }, { 202,  60 },
    { 213,  15 }, { 216,  30 }, { 220,  45 }, { 220,  60 }
  }, {
    // LED Index to Flag
    4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4,
    4, 4, 4, 4
  } };
#endif
