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

#pragma once
#include QMK_KEYBOARD_H

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

#define WAKEUP_KEYBOARD_ENABLE
//#define WAKEUP_MOUSE_ENABLE

#if defined(WAKEUP_MOUSE_ENABLE) || defined(WAKEUP_KEYBOARD_ENABLE)
#    define WAKEUP_ENABLE
#endif

#define ONE_SECOND          1000
#define ONE_MINUTE          60000
#define TWO_MINUTES         120000
#define THREE_MINUTES       180000
#define FOUR_MINUTES        240000
#define FIVE_MINUTES        300000
#define ONE_HOUR            3600000

#define WAKEUP_UPDATE_MILIS ONE_MINUTE
#define WAKEUP_HOURS_MIN    1
#define WAKEUP_HOURS_MAX    12

#define WAKEUP_INDEX        45  /* col + row * MATRIX_COLS */

#define NUMBER_INDEX        1   /* col + row * MATRIX_COLS */

enum custom_keycodes {
    KC_WKTOG = SAFE_RANGE,      /* wake up toggle */
    KC_WKINC,                   /* wake up increment */
    KC_WKDEC,                   /* wake up Decrement */
    KC_INFO,                    /* version info */
    KC_RCTOG                    /* record toggle */
};
