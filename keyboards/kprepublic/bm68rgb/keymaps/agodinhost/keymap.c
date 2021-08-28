/*
Copyright 2021 Anaximandro Godinho @agodinhost

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "agodinhost.h"

#define BASE   0 /* default layer */
#define COMMON 1 /* common layer */
#define MACROL 2 /* macro layer */

enum {
    TP_BSPC, TP_DEL,
    TP_HOME,
    TP_UP,   TP_DOWN,
    TP_LEFT, TP_RGHT,
    TP_PGUP, TP_PGDN
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TP_BSPC] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, RCTL(KC_BSPC)),
    [TP_DEL ] = ACTION_TAP_DANCE_DOUBLE(KC_DEL,  RCTL(KC_DEL)),
    [TP_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END ),
    [TP_UP  ] = ACTION_TAP_DANCE_DOUBLE(KC_UP,   KC_PGUP),
    [TP_DOWN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
    [TP_LEFT] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
    [TP_RGHT] = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_END ),
    [TP_PGUP] = ACTION_TAP_DANCE_DOUBLE(KC_PGUP, RCTL(KC_HOME)),
    [TP_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_PGDN, RCTL(KC_END))
};

#define DT_BSPC TD(TP_BSPC)
#define DT_DEL  TD(TP_DEL)
#define DT_HOME TD(TP_HOME)
#define DT_UP   TD(TP_UP)
#define DT_DOWN TD(TP_DOWN)
#define DT_LEFT TD(TP_LEFT)
#define DT_RGHT TD(TP_RGHT)
#define DT_PGUP TD(TP_PGUP)
#define DT_PGDN TD(TP_PGDN)

#define HD_RALT RALT_T(MO(3)) /* macro layer */
#define HD_RCTL RCTL_T(MO(4)) /* user layer */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_65_ansi(
KC_GESC,  KC_1,     KC_2,     KC_3,     KC_4,    KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,  DT_BSPC,  DT_DEL,
KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,    KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLS,  DT_HOME,
KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,    KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_ENT,  DT_PGUP,
KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,    KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  DT_UP,   DT_PGDN,
KC_LCTL,  KC_LGUI,  KC_LALT,  KC_SPC,   HD_RALT, MO(1),    HD_RCTL,  DT_LEFT,  DT_DOWN,  DT_RGHT),
	[COMMON] = LAYOUT_65_ansi(
KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_TRNS,  KC_TRNS,
KC_TRNS,  RGB_TOG,  RGB_MOD,  RGB_HUI,  RGB_HUD, RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD,  KC_TRNS,  KC_TRNS,  BL_TOGG,  BL_STEP, KC_TRNS,  KC_END,
KC_TRNS,  RGB_SPI,  RGB_SPD,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_ASTG, KC_TRNS,
KC_TRNS,  KC_WKTOG, KC_WKINC, KC_WKDEC, KC_INFO, RESET,    NK_TOGG,  KC_RCTOG, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP, KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_HOME,  KC_PGDN,  KC_END),
	[MACROL] = LAYOUT_65_ansi(
KC_TRNS,  MACRO01,  MACRO02,  MACRO03,  MACRO04, MACRO05,  MACRO06,  MACRO07,  MACRO08,  MACRO09,  MACRO00,  MACRO11,  MACRO12, KC_TRNS,  KC_TRNS,
KC_TRNS,  MACRO11,  MACRO12,  MACRO13,  MACRO14, MACRO15,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_ASTG, KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_PGUP, KC_TRNS,
KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)
    /* the final hex size is smaller when we do NOT initialize the unused layers. */
};
