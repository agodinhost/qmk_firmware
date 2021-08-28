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

#ifdef CONSOLE_ENABLE
//#define DEBUG_MATRIX_SCAN_RATE
#endif

#define FORCE_NKRO                  // NKRO by default requires to be turned on, this forces it on during keyboard startup regardless of EEPROM setting. NKRO can still be turned off but will be turned on again if the keyboard reboots.

// LTO_ENABLE = yes already disable the function and macro features
// #define NO_ACTION_FUNCTION
// #define NO_ACTION_MACRO
// TODO: LTO_ENABLE will break MACRO00 ... MACRO15?

#define NO_ACTION_ONESHOT           // Disable one-shot modifiers
#define RETRO_TAPPING               // Tap anyway, even after TAPPING_TERM, if there was no other key interruption between press and release
#define PERMISSIVE_HOLD             // Makes tap and hold keys trigger the hold if another key is pressed before releasing, even if it hasn't hit the TAPPING_TERM. See Permissive Hold for details
#define TAPPING_TERM 135            // How long before a tap becomes a hold, if set above 500, a key tapped during the tapping term will turn it into a hold too
#define TAPPING_TOGGLE 2            // How many taps before triggering the toggle

#define AUTO_SHIFT_TIMEOUT 160      // was 150
#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_NO_SETUP
#define AUTO_SHIFT_DISABLED_AT_STARTUP

#include "quantum/led_matrix/disable_all_led_matrix.h"

#include "quantum/rgb_matrix/disable_all_rgb_matrix.h"
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_RAINDROPS
#undef DISABLE_RGB_MATRIX_RAINDROPS
#undef DISABLE_RGB_MATRIX_DIGITAL_RAIN
#undef DISABLE_RGB_MATRIX_SPLASH
