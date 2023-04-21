/* Copyright 2021 flamwenco
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
#include "analog.h"
#include "print.h"
#include "midi.h"

extern MidiDevice midi_device;

int16_t max_pot_val = 1023;
int16_t max_ticks = 16;
int16_t pot_oldVal = 0;
int16_t pot_val    = 0;
int16_t pot_ccVal  = 0;
bool moving     = false;
bool is_shift_lock_active = false;
#define POT_TOLERANCE 12
#define POT_PIN B6
uint8_t midi2vol = 0x3E;

enum my_keycodes {
  LOCK_SHIFT = SAFE_RANGE
};

enum midi_cc_keycodes_LTRM { MIDI_CC1 = SAFE_RANGE, MIDI_CC2, MIDI_CC3, MIDI_CC4, MIDI_CC5, MIDI_CC6, MIDI_CC7, MIDI_CC8, MIDI_CC9, MIDI_CC10, MIDI_CC11, MIDI_CC12, MIDI_CC13, MIDI_CC14, MIDI_CC15, MIDI_CC16, MIDI_CC17, MIDI_CC18, MIDI_CC19, MIDI_CC20, MIDI_CC21, MIDI_CC22, MIDI_CC23, MIDI_CC24, MIDI_CC25, MIDI_CC26 };

void matrix_init_user(void) {
    analogReference(ADC_REF_POWER);
}

void matrix_scan_user(void){
    pot_val   = (analogReadPin(POT_PIN));

    /* // If there is a big enough change, then we need to do something
    if (abs(pot_val - pot_oldVal) > POT_TOLERANCE) {
        moving = true;
        pot_oldVal = pot_val;
    }
    else{
        if (moving){
            // Do some fancy conversion to get 'absolute' position to num tap_codes to send
            // Reset moving to 0 so that we don't get multiple attempts to do this
            int num_ticks = ((float)(max_pot_val - pot_val)/max_pot_val)*max_ticks;
            for (int i = 0; i<max_ticks;++i){
                tap_code(KC__VOLDOWN);
            }
            for (int i = 0; i<num_ticks;++i){
                tap_code(KC__VOLUP);
            }
            moving = false;
        }
    } */

    pot_ccVal = pot_val / 8;
    if (abs(pot_val - pot_oldVal) > POT_TOLERANCE) {
      pot_oldVal = pot_val;
      // uprintf("%d\n", pot_ccVal);
      midi_send_cc(&midi_device, 0, 27, pot_ccVal);
    }
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    }
    return false;
}

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _NUM,
    _FN,
    _EXTRA
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_NUM] =  { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_FN] =  { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
    [_EXTRA] =  { ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT_625(
    KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,             KC_BSPC, KC_MPLY,
    LCTL_T(KC_ESC), KC_A,    KC_S,    KC_D,   KC_F,    KC_G, KC_H, KC_J, KC_K,    KC_L,   LT(_NUM, KC_ENT),
    KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH,          KC_UP, 
    MO(_FN), KC_LALT, KC_LGUI, KC_SPC, KC_LGUI,                                    KC_LEFT,          KC_DOWN, KC_RIGHT
    ),
    [_NUM] = LAYOUT_625(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,  KC_5,  KC_6,  KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, KC_MPLY,
    KC_TRNS, KC_LBRC, KC_RBRC, KC_NO,   KC_NO, KC_NO, KC_NO, KC_MINS, KC_EQL,  KC_SCLN, KC_TRNS,
    KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4, KC_F5, KC_F6, KC_QUOT, KC_BSLS, KC_NO,   KC_NO,   KC_UP, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                        KC_LEFT, KC_DOWN, KC_RIGHT    ),
    [_FN] = LAYOUT_625(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_MPLY,
    KC_TRNS, KC_LCBR, KC_RCBR, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UNDS, KC_PLUS, KC_COLN, KC_TRNS,
    KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DQT,  KC_PIPE, KC_NO,   KC_NO,   KC_UP, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_LEFT, KC_DOWN, KC_RIGHT    ),
    [_EXTRA] = LAYOUT_625(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS    )
};

