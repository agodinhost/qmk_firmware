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

#include "agodinhost.h"
#include "version.h"

#ifndef inc
#    define inc(val, min, max)                         \
        __extension__({                                \
            __typeof(val) tmp = val + 1;               \
            val               = tmp > max ? min : tmp; \
        })
#endif
#ifndef dec
#    define dec(val, min, max)                         \
        __extension__({                                \
            __typeof(val) tmp = val - 1;               \
            val               = tmp < min ? max : tmp; \
        })
#endif

static inline
bool shiftReplace(uint16_t keycode, keyrecord_t *record) {
    static uint8_t mod_state = 0;     /* last mod_state */
    static bool    reg_state = false; /* last register state */
    if (IS_PRESSED(record->event)) {
        mod_state = get_mods();
        if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            register_code(keycode);
            set_mods(mod_state);
            reg_state = true;
            return false;
        }
    } else {
        if (reg_state) {
            reg_state = false;
            unregister_code(keycode);
            return false;
        }
    }
    return true;
}

static inline
bool getInfo(keyrecord_t *record) {
    if (IS_PRESSED(record->event)) {
        SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION ", Built on: " QMK_BUILDDATE);
        SEND_STRING(CHIBIOS_VERSION "/" CHIBIOS_CONTRIB_VERSION);
        return false;
    }
    return true;
}

#ifdef WAKEUP_ENABLE
static bool     wk_on    = false;
static uint16_t wk_timer = 0;
static uint8_t  wk_after = WAKEUP_HOURS_MIN; /* wake up after 1 hour, default. RANGE 1, 10 */
static uint8_t  mn_count = 0;
static uint8_t  hr_count = 0;

static const uint8_t COLORS[3][3] = {{RGB_RED}, {RGB_YELLOW}, {RGB_GREEN}};

static inline
void set_color(int index, const uint8_t color[3]) {
    rgb_matrix_set_color(index, color[0], color[1], color[2]);
}

static inline
void rgb_display(uint8_t n) {
    uint8_t i = 0;
    while (n > 0) {
        uint8_t m = n % 10;
#ifdef CONSOLE_ENABLE
        uprintf("m: %u\n", m);
#endif
        set_color(NUMBER_INDEX + m, COLORS[i]);
        i++;
        n /= 10;
    }
}

/* ------------------------------------------------------------------------- */

static inline
bool wkTog(keyrecord_t *record) {
    if (IS_PRESSED(record->event)) {
        wk_on = !wk_on;
        wk_timer = timer_read();
        return false;
    }
#ifdef CONSOLE_ENABLE
    uprintf("wk_on: %b\n", wk_on);
#endif
    return true;
}

static inline
bool wkInc(keyrecord_t *record) {
    if (IS_PRESSED(record->event)) {
        inc(wk_after, WAKEUP_HOURS_MIN, WAKEUP_HOURS_MAX);
        rgb_display(wk_after);
        return false;
    }
#ifdef CONSOLE_ENABLE
    uprintf("wk_after: %u\n", wk_after);
#endif
    return true;
}

static inline
bool wkDec(keyrecord_t *record) {
    if (IS_PRESSED(record->event)) {
        dec(wk_after, WAKEUP_HOURS_MIN, WAKEUP_HOURS_MAX);
        rgb_display(wk_after);
        return false;
    }
#ifdef CONSOLE_ENABLE
    uprintf("wk_after: %u\n", wk_after);
#endif
    return true;
}

#endif

/* ------------------------------------------------------------------------- */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_BSPACE:
            return shiftReplace(KC_DEL, record);
        case KC_DELETE:
            return shiftReplace(KC_BSPC, record);
        case KC_INFO:
            return getInfo(record);
#ifdef WAKEUP_ENABLE
        case KC_WKTOG:
            return wkTog(record);
        case KC_WKINC:
            return wkInc(record);
        case KC_WKDEC:
            return wkDec(record);
#endif
    //TODO: do I relly need this code below? it seems it is already done at via.c //
    /*
        case MACRO00 ... MACRO15:
            dynamic_keymap_macro_send(keycode);
            return false;
    */

        case KC_RCTOG:
            return false;  // TODO
    }

#ifdef CONSOLE_ENABLE
    uprintf("keycode: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupted: %b, count: %u\n",
        keycode,
        record->event.key.col,
        record->event.key.row,
        record->event.pressed,
        record->event.time,
        record->tap.interrupted,
        record->tap.count);
#endif

    return true; /* Process all other keycodes normally */
}

void matrix_init_user(void) {
    wk_timer = timer_read();
    mn_count = hr_count = 0;
#ifdef CONSOLE_ENABLE
    println("matrix_init_user");
#endif
}

void matrix_scan_user(void) {
    if (wk_on) {
        if (timer_elapsed(wk_timer) >= ONE_MINUTE) {
            mn_count ++;

#ifdef WAKEUP_MOUSE_ENABLE
            tap_code(KC_MS_RIGHT);
            tap_code(KC_MS_DOWN);
            tap_code(KC_MS_LEFT);
            tap_code(KC_MS_UP);
#endif
#ifdef WAKEUP_KEYBOARD_ENABLE
            tap_code(KC_RIGHT);
            tap_code(KC_DOWN);
            tap_code(KC_LEFT);
            tap_code(KC_UP);
#endif
            rgb_matrix_set_color(WAKEUP_INDEX, RGB_RED);
            rgb_display(wk_after);

#ifdef CONSOLE_ENABLE
            print("m");
#endif
            if (mn_count >= 60) {
                mn_count = 0;
                hr_count ++;
                wk_on = hr_count < wk_after;

                rgb_display(hr_count);

#ifdef CONSOLE_ENABLE
                print("h");
#endif
                if (!wk_on) {
                    hr_count = 0;
#ifdef CONSOLE_ENABLE
                    println("D");
#endif
                }
            }

            wk_timer = timer_read();
        }
    }
}
