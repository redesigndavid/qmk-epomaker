/* Copyright 2015-2023 Jack Humbert
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
#include "rdmctmzt_common.h"

enum luma40_layers { _QWERTY, _FUNCTIONS, _SYMBOLS, _NUMBERS, _SPEC };

#define SPACE__ LT(_SYMBOLS, KC_SPC)
#define SUPER_F LT(_FUNCTIONS, KC_F)
#define SUPER_J LT(_NUMBERS, KC_J)
#define SUPER_G LT(_NUMBERS, KC_G)
#define CTL_ESC CTL_T(KC_ESC)
#define LSHIFT KC_LSFT
#define KC_SPEC MO(_SPEC)
#define SPR_COL LT(_SPEC, KC_SCLN)


enum custom_keycodes {
    MY_KEY = SAFE_RANGE
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,---------------------------------------------------------------------------------------.
 * | Tab      |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |----------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ctrl/Esc |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |----------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift    |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |----------+------+------+------+------+------+------+------+------+------+------+------|
 * |          | ADJT |      |  GUI |  Alt |Space | Space| Enter|      |      |      |      |
 * `---------------------------------------------------------------------------------------'
 */
    [_QWERTY] = LAYOUT_tkl_ansi(
        KC_TAB,   KC_Q,     KC_W,     KC_E,    KC_R,      KC_T,     KC_Y,      KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,     \
        CTL_ESC,  KC_A,     KC_S,     KC_D,    SUPER_F,   SUPER_G,  KC_H,      SUPER_J,  KC_K   ,  KC_L,     SPR_COL,     KC_QUOT,     \
        LSHIFT,   KC_Z,     KC_X,     KC_C,    KC_V,      KC_B,     KC_N,      KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_ENT ,     \
        KC_SPEC,  XXXXXXX,  XXXXXXX,  KC_LGUI, KC_LALT,             SPACE__,   KC_ENT,   QK_LEAD,  XXXXXXX,  XXXXXXX,  XXXXXXX
    ),

    [_FUNCTIONS] = LAYOUT_tkl_ansi(
        _______,  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,   KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  LCA(KC_DEL), \
        _______,  KC_F11 ,  KC_F12 ,  _______,  _______,  _______,  KC_LEFT,   KC_DOWN,  KC_UP  ,  KC_RGHT,  KC_PSCR,  CG_TOGG,     \
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  KC_PAUS,  _______,     \
        _______,  _______,  _______,  _______,  _______,            _______,   _______,  _______,  RM_NEXT,  RM_TOGG,  QK_BAT
    ),

    [_SYMBOLS] = LAYOUT_tkl_ansi(
        _______,  KC_EXLM,  KC_HASH,  KC_DLR ,  KC_PERC,  KC_AMPR,  KC_TILD,   KC_SLSH,  KC_BSLS,  KC_LCBR,  KC_RCBR,  KC_0,        \
        _______,  KC_LABK,  KC_RABK,  KC_LCBR,  KC_RCBR,  KC_CIRC,  KC_GRV,    KC_LBRC,  KC_RBRC,  KC_LPRN,  KC_RPRN,  _______,     \
        _______,  KC_COLN,  KC_UNDS,  KC_EXLM,  KC_AT  ,  KC_ASTR,  KC_MINS,   KC_PLUS,  KC_EQL,   KC_PIPE,  XXXXXXX,  _______,     \
        _______,  _______,  _______,  _______,  _______,            KC_BSPC,   _______,  _______,  _______,  _______,  _______
    ),

    [_NUMBERS] = LAYOUT_tkl_ansi(
        _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,      KC_7,     KC_8,     KC_9,     KC_0,     _______,     \
        _______,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     _______,   _______,  _______,  _______,  _______,  _______,     \
        _______,  KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     _______,   _______,  _______,  _______,  _______,  _______,     \
        _______,  _______,  _______,  _______,  _______,            _______,   _______,  _______,  _______,  _______,  _______
    ),

    [_SPEC] = LAYOUT_tkl_ansi(
        MD_USB ,  MD_BLE1, MD_BLE2,   MD_BLE3,  MD_24G ,  RM_NEXT,  _______,   _______,  _______,  _______,  _______,  _______,     \
        _______,  DM_REC1,  DM_REC2,  DM_PLY1,  DM_PLY2,  DM_RSTP,  _______,   _______,  _______,  _______,  _______,  _______,     \
        _______,  _______,  _______,  _______,  _______,  _______,  RM_TOGG,   RM_SATD,  RM_HUED,  RM_VALU,  RM_SPDU, QK_BAT ,      \
        _______,  _______,  _______,  _______,  _______,            EE_CLR,    RM_SATU,  RM_HUED,  RM_VALD,  RM_SPDD, QK_BOOT
    ),

};


void leader_end_user(void) {
    if (leader_sequence_one_key(KC_1)) {
        // tmux: prefix + %
        tap_code16(LCTL(KC_A));
        tap_code16(S(KC_5));   // %
    } else if (leader_sequence_one_key(KC_V)) {
        // tmux: prefix + "
        tap_code16(LCTL(KC_A));
        tap_code16(S(KC_QUOT)); // "
    } else if (leader_sequence_one_key(KC_C)) {
        // tmux: prefix + c
        tap_code16(LCTL(KC_A));
        tap_code(KC_C);
    } else if (leader_sequence_one_key(KC_Z)) {
        // tmux: prefix + z
        tap_code16(LCTL(KC_A));
        tap_code(KC_Z);
    } else if (leader_sequence_one_key(KC_H)) {
        // tmux: prefix + h
        tap_code16(LCTL(KC_A));
        tap_code(KC_H);
    } else if (leader_sequence_one_key(KC_J)) {
        // tmux: prefix + j
        tap_code16(LCTL(KC_A));
        tap_code(KC_J);
    } else if (leader_sequence_one_key(KC_K)) {
        // tmux: prefix + k
        tap_code16(LCTL(KC_A));
        tap_code(KC_K);
    } else if (leader_sequence_one_key(KC_L)) {
        // tmux: prefix + l
        tap_code16(LCTL(KC_A));
        tap_code(KC_L);
    } else if (leader_sequence_two_keys(KC_W, KC_C)) {
        // example: Leader, w, c => prefix + &
        tap_code16(LCTL(KC_A));
        tap_code16(S(KC_7));   // &
    } else if (leader_sequence_one_key(KC_Q)) {
        tap_code16(LCTL(KC_A));
        tap_code16(KC_Q);   // &
    } else if (leader_sequence_one_key(KC_A)) {
        tap_code16(LCTL(KC_A));
        tap_code16(KC_1);   // &
    } else if (leader_sequence_one_key(KC_S)) {
        tap_code16(LCTL(KC_A));
        tap_code16(KC_2);   // &
    } else if (leader_sequence_one_key(KC_D)) {
        tap_code16(LCTL(KC_A));
        tap_code16(KC_3);   // &
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == MY_KEY && record->event.pressed) {
        tap_code16(LCTL(KC_A));
        return false;
    }
    return true;
}
const uint16_t PROGMEM test_combo1[] = {SUPER_J,  KC_K, COMBO_END};
combo_t key_combos[] = {
    COMBO(test_combo1, LCTL(KC_A)),
};
