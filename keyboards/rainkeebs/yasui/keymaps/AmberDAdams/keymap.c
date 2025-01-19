
/* Copyright 2021 Regan Palmer
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

// Defines keycodes for macros
enum custom_keycodes {
    LANGCH,
    WINUP,
    WINDN,
    //DCKLT,
    //DCKRT,
    TABUP,
    TABDN
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// add arrow keys to an upper layer along with a numpad and mouse arrow keys, alt-tab and language toggle
	[0] = LAYOUT(
		KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P,
		KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT,
		KC_LCTL, KC_LALT, KC_BSPC, MO(1), KC_SPC, KC_LGUI, KC_SPC, MO(2), KC_RALT, LANGCH
    ),

	[1] = LAYOUT(
		KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
		KC_ESC, KC_TAB, MO(3), KC_TRNS, KC_NUHS, KC_MINS, KC_EQL, KC_QUOT, KC_SCLN, KC_HOME,
		KC_TRNS, KC_DEL, KC_CAPS, KC_LBRC, KC_RBRC, KC_NUBS, KC_SLSH, KC_APP, KC_UP, KC_END,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT
    ),

	[2] = LAYOUT(
		KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10,
		KC_ESC, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, KC_TRNS, KC_TRNS, DM_PLY1, DM_PLY2, KC_TRNS,
		KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_TRNS, KC_TRNS, DM_REC1, DM_REC2, DM_RSTP,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // the d key is the mo for this layer, a and s to be set up to alt-tab through windows, q and w to be set up to cycle through tabs
	[3] = LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_NLCK, KC_7, KC_8, KC_9, KC_PPLS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_END , KC_PGDN, KC_PSLS, KC_4, KC_5, KC_6, KC_PMNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PAST, KC_1, KC_2, KC_3, KC_EQL,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_COMM, KC_0, KC_KP_DOT, MT(MOD_LSFT, KC_PENT)
    )
};


// this is work on my macros - the only one that is in place at the moment is LANGCH to change my input language.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LANGCH:
            if (record->event.pressed) {
                tap_code16(LALT(KC_LSFT));
            } else {}
            break;
        case WINUP:
            if (record->event.pressed) {
                tap_code16(LALT(KC_TAB));
            } else {}
            break;
        case WINDN:
            if (record->event.pressed) {
                tap_code16(LALT(LSFT(KC_TAB)));
            } else {}
            break;
/*         case DCKLT:
            if (record->event.pressed) {
                tap_code16(LWIN(KC_LEFT));
            } else {}
            break;
        case DCKRT:
            if (record->event.pressed) {
                tap_code16(LWIN(KC_RIGHT));
            } else {}
            break;
        case TABUP:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_PGUP));
            } else {}
            break;
        case TABDN:
            if (record->event.pressed) {
                tap_code16(LCTL(KC_PGDN));
            } else {}
            break; ,*/
    }
    return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}
