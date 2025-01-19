/* Copyright 2019 Yiancar
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

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  RUNLINE = SAFE_RANGE,
  SELECTTOP,
  UPPER,
  WORKPASS
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT( /* Base */
    RUNLINE,  SELECTTOP,  UPPER,  WORKPASS \
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RUNLINE:
      if (record->event.pressed) {
        // when keycode RUNLINE is pressed
        tap_code16(KC_END);
        tap_code16(LSFT(KC_HOME));
        tap_code16(KC_F5);
      } else {
        // when keycode RUNLINE is released
      }
      break;
    case SELECTTOP:
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
    case WORKPASS:
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
