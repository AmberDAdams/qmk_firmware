/* Copyright 2019 Fate
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

enum custom_keycodes {
  SELTOP,
  UPPER,
  WRKPASS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_APP,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUBS, KC_DEL,  KC_HOME,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_SLSH, KC_BSPC,          KC_END,
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_QUOT, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,                    KC_GESC,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,          KC_UP,
    KC_LCTL,          KC_LALT,          KC_SPC,  MO(2) ,           KC_SPC,           KC_LWIN,                   KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [1] = LAYOUT(
    // colemak, but done differentially versus qwerty (layer 0) in an attempt to save controller space
    // likely to flip these around in future so that colemak is base
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, KC_F,    KC_P,    KC_G,    _______, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, _______, _______,          _______,
    _______, _______, KC_R,    KC_S,    KC_T,    KC_D,    _______, _______, KC_N,    KC_E,    KC_I,    KC_O,    _______,                   _______,
    _______, _______, _______, _______, _______, _______, _______, KC_K,    _______, _______, _______, _______,          _______,
    _______,          _______,          _______, _______,          _______,          _______,                   _______, _______, _______
  ),

  [2] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,   KC_F11,  KC_F12,  _______, RESET, KC_PGUP,
    TO(0),   _______, _______, _______, _______, _______, KC_RBRC, _______, _______, _______, _______, _______, _______, _______,        KC_PGDN,
    TO(1),   WRKPASS, UPPER,   SELTOP,  _______, _______, _______, _______, _______, _______, _______, _______, _______,                 _______,
    _______, _______, _______, _______, _______, KC_NUHS, _______, _______, _______, _______, _______, _______,          _______,
    _______,          _______,          _______, _______,          _______,          _______,                   _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case SELTOP:
      if (record->event.pressed) {
        // when keycode SELECTTOP is pressed
        SEND_STRING("SELECT TOP 100 * FROM ");
      } else {
        // when keycode SELECTTOP is released
      }
      break;
    case UPPER:
      if (record->event.pressed) {
        // when keycode UPPER is pressed
        tap_code16(LCTL(LSFT(KC_U)));
      } else {
        // when keycode UPPER is released
      }
      break;
    case WRKPASS:
      if (record->event.pressed) {
        // when keycode WORKPASS is pressed
        SEND_STRING("y#Tv30D66?" SS_TAP(X_ENTER));
      } else {
        // when keycode WORKPASS is released
      }
      break;
  }
  return true;
}
