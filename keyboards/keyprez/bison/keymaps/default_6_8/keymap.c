/* Copyright 2021 csandven
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _COLEMAK,
    _LOWER,
    _RAISE,
    _HRM,
    _FN,
};

enum custom_keycodes {
    KC_PRVWD = SAFE_RANGE,
    KC_NXTWD
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FN MO(_FN)
#define ESC_CTL MT(MOD_LCTL, KC_ESC)
#define HRM_LG MT(MOD_LGUI, KC_A)
#define HRM_LA MT(MOD_LALT, KC_S)
#define HRM_LC MT(MOD_LCTL, KC_D)
#define HRM_LS MT(MOD_LSFT, KC_F)
#define HRM_RG MT(MOD_RGUI, KC_SCLN)
#define HRM_RA MT(MOD_RALT, KC_L)
#define HRM_RC MT(MOD_RCTL, KC_K)
#define HRM_RS MT(MOD_RSFT, KC_J)

#define KC_QWRTY PDF(_QWERTY)
#define KC_COLMK PDF(_COLEMAK)
#define KC_HRM PDF(_HRM)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * QWERTY
    * ,-----------------------------------------.                    ,-------------------------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |   =  |  DEL |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | [    |   ]  |  \   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * | ESC  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |  BS  |  Fn  |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |       |    |       |   N  |   M  |   ,  |   .  |   /  | Enter| Home | End  |
    * `----------------------------------------/-------/     \------\-------------------------------------------------------'
    *           | LGUI | LAlt | LCTR |LOWER |  BS     /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *           |      |      |      |      |        /         \      \ |      |      |      |      |
    *            `----------------------------------'           '------''---------------------------'
    */
    [_QWERTY] = LAYOUT_6_8(
        KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, KC_EQL,  KC_DEL,
        KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_LBRC, KC_RBRC, KC_BSLS,
        ESC_CTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, KC_BSPC, FN,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     KC_MPLY,KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,  KC_HOME, KC_END,
                          KC_LGUI,KC_LALT, LOWER,       KC_BSPC,              KC_SPC,      RAISE, KC_RALT, KC_RGUI
    ),

    /*
    * COLEMAK
    * ,-----------------------------------------.                    ,-------------------------------------------------------.
    * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |   =  |  DEL |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | [    |   ]  |  \   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * | ESC  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |  BS  |  Fn  |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------+------+------|
    * |LShift|   Z  |   X  |   C  |   V  |   B  |       |    |       |   K  |   M  |   ,  |   .  |   /  | Enter| Home | End  |
    * `-----------------------------------------/-------/     \------\-------------------------------------------------------'
    *            | LGUI | LAlt | LCTR |LOWER |  BS     /       \Space \  |RAISE | RCTR | RAlt | RGUI |
    *            |      |      |      |      |        /         \      \ |      |      |      |      |
    *             `----------------------------------'           '------''---------------------------'
    */
    [_COLEMAK] = LAYOUT_6_8(
        KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_MINS, KC_EQL,  KC_DEL,
        KC_TAB,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN,  KC_LBRC, KC_RBRC, KC_BSLS,
        ESC_CTL,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT, KC_BSPC, FN,
        KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,     XXXXXXX,KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT,  KC_HOME, KC_END,
                         KC_LGUI,KC_LALT, LOWER,       KC_BSPC,              KC_SPC,      RAISE, KC_RALT, KC_RGUI
    ),

    /*
    * LOWER
    * ,-----------------------------------------.                    ,-------------------------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  |      |                    |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * |      |  F5  |  F6  |  F7  |  F8  |      |-------.    ,-------| LEFT | DOWN |  UP  | RIGHT|      |      |      |      |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------+------+------|
    * |      |  F9  |  F10 |  F11 |  F12 |      |       |    |       |      |      |      |      |      |      |      |      |
    * `-----------------------------------------/-------/     \------\-------------------------------------------------------'
    *            |      |      |      |      |         /       \      \  |      |      |      |      |
    *            |      |      |      |      |        /         \      \ |      |      |      |      |
    *             `----------------------------------'           '------''---------------------------'
    */
    [_LOWER] = LAYOUT_6_8(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  _______,                      _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   KC_F5,   KC_F6,   KC_F7,  KC_F8,  _______,                      KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______, _______, _______, _______,
        _______,   KC_F9,  KC_F10,  KC_F11, KC_F12,  _______, _______,     _______,_______, _______, _______, _______, _______, _______, _______, _______,
                          _______,_______, _______,       _______,              _______,      _______, _______, _______
    ),

    /*
    * RAISE
    * ,-----------------------------------------.                    ,-------------------------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * |      |  F1  |  F2  |  F3  |  F4  |      |                    |      |      | PrevW|  UP  | NextW|      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * |      |  F5  |  F6  |  F7  |  F8  |      |-------.    ,-------|      |      | LEFT | DOWN | RIGHT|      |      |      |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------+------+------|
    * |      |  F9  |  F10 |  F11 |  F12 |      |       |    |       |      |      |      |      |      |      |      |      |
    * `-----------------------------------------/-------/     \------\-------------------------------------------------------'
    *            |      |      |      |      |         /       \      \  |      |      |      |      |
    *            |      |      |      |      |        /         \      \ |      |      |      |      |
    *             `----------------------------------'           '------''---------------------------'
    */
    [_RAISE] = LAYOUT_6_8(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, _______,
        _______,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  _______,                      _______, _______,KC_PRVWD,   KC_UP,KC_NXTWD, _______, _______, _______,
        _______,   KC_F5,   KC_F6,   KC_F7,  KC_F8,  _______,                      _______, _______, KC_LEFT, KC_DOWN,KC_RIGHT, _______, _______, _______,
        _______,   KC_F9,  KC_F10,  KC_F11, KC_F12,  _______, _______,     _______,_______, _______, _______, _______, _______, _______, _______, _______,
                           _______,_______, _______,       _______,              _______,      _______, _______, _______
    ),

    /*
    * HRM
    * ,-----------------------------------------.                    ,-------------------------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * |      |HRM_LG|HRM_LA|HRM_LC|HRM_LS|      |-------.    ,-------|      |HRM_RS|HRM_RC|HRM_RA|HRM_RG|      |      |      |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |       |    |       |      |      |      |      |      |      |      |      |
    * `-----------------------------------------/-------/     \------\-------------------------------------------------------'
    *            |      |      |      |      |         /       \      \  |      |      |      |      |
    *            |      |      |      |      |        /         \      \ |      |      |      |      |
    *             `----------------------------------'           '------''---------------------------'
    */
    [_HRM] = LAYOUT_6_8(
        _______, _______, _______, _______,_______, _______,                      _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______,_______, _______,                      _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  HRM_LG,  HRM_LA,  HRM_LC, HRM_LS, _______,                      _______,  HRM_RS,  HRM_RC,  HRM_RA,  HRM_RG, _______, _______, _______,
        _______, _______, _______, _______,_______, _______, _______,     _______,_______, _______, _______, _______, _______, _______, _______, _______,
                        _______,_______, _______,       _______,              _______,      _______, _______, _______
    ),

    /*
    * FN
    * ,-----------------------------------------.                    ,-------------------------------------------------------.
    * |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * |      |QWERTY|      |      |      |      |                    |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |      |-------.    ,-------|KC_HRM|      |      |      |      |      |      |      |
    * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------+------+------|
    * |      |      |      |COLEMAK|     |      |       |    |       |      |      |      |      |      |      |      |      |
    * `-----------------------------------------/-------/     \------\-------------------------------------------------------'
    *            |      |      |      |      |         /       \      \  |      |      |      |      |
    *            |      |      |      |      |        /         \      \ |      |      |      |      |
    *             `----------------------------------'           '------''---------------------------'
    */
    [_FN] = LAYOUT_6_8(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, _______,
        _______,KC_QWRTY, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                       KC_HRM, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,KC_COLMK, _______, _______, _______,     _______,_______, _______, _______, _______, _______, _______, _______, _______,
                                          _______,_______, _______,       _______,              _______,      _______, _______, _______
    ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_LEFT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_LEFT);
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_RIGHT);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_RIGHT);
            }
            break;
    }
    return true;
}
