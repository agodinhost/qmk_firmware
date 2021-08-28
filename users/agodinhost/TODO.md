
# 1. Caffeine On/Off

## 1.1 use mouse/keyboards keystrokes.
Prevent your computer from going to sleep
[Caffeine](https://www.zhornsoftware.co.uk/caffeine/)
[Caffeine for linux, open source](https://launchpad.net/caffeine)
	
# 2. Caffeine timer increment / decrement
	1 to 0 (10)

# 3. Simple RGB numeric display, green for the 1sr digit, yellow 2nd digit and red
	for the 3rd digit.

# 4. Record on/off
	this must be done in silently, without any indication that it's turned on.
	when turned off it should display whatever was pressed before.
	
---
# 4 Some Ideas
1. ALREADY SUPPORTED, Ctrl + Backspace -> Backspace Word
1. ALREADY SUPPORTED, Ctrl + Delete    -> Delete Word

1. DONE, Double Tap Right -> End
1. DONE, Double Tap Left  -> Home
1. DONE, Double Tap Up    -> Pg Up
1. DONE, Double Tap Down  -> Pg Down
    /* MT( held, tap ) */
    /* ACTION_TAP_DANCE_DOUBLE(once, twice) */
    /* The TAP_DANCE is not working into the master, using 0.13.34 - see https://github.com/qmk/qmk_firmware/issues/2162 */
    /* https://thomasbaart.nl/2018/12/13/qmk-basics-tap-dance/ */

1. DONE, Double Tap Backspace -> CTRL + Backspace
1. DONE, Double Tap Delete    -> CTRL + Delete
1. DONE, Double Tap PgUp      -> CTRL + Home
1. DONE, Double Tap PgDn      -> CTRL + End

1. DONE, Version

1. DONE, AUTO_SHIFT enabled
1. DONE, AUTO_SHIFT toggle in keymap
    using MO(2) + ENTER
    I tried to use MO(2) + KC_SLSH and MO(2) + KC_LSFT however it did not worked, don't know why ...

1. DONE, AUTO_SHIFT disabled at startup by default.
    AUTO_SHIFT_DISABLED_AT_STARTUP
    contrib at quantum\process_auto_shift.c

1. DONE, AUTO_SHIFT with auto repeat

1. DONE *, Shift + Backspace = Delete       *CONFLICTS WITH DOUBLE TAB
1. DONE *, Shift + Delete = Backspace       *CONFLICTS WITH DOUBLE TAB

1. TODO, disable unwanted RGB_LIGH modes that you dont like to reduce the final file size.

1. TODO, Split Wakeup.c / wakeup.h. This wll make easier to merge your code.

1. TODO, RCTRL Tap = MO(3)
1. TODO, RALT Tap = MO(4)

1. TODO, MACROS Layer MO(3)
    MACRO00 ... MACRO15
    USER00 ... USER15
    
    dynamic_keymap_macro_send
    [Dynamic macros: record and replay macros in runtime](https://git.roxanne.dev/roxxers/qmk-custom-firmware/src/commit/e229dcadb5c9f8c09f14a439fe5a4c7c48ba2249/Macros.md?lang=tr-TR#dynamic-macros-record-and-replay-macros-in-runtime)

1. REASEARCH, Auto shift using TAP instead of hold.

1. TODO: SECRET
    spy ON if SECRET not provided
1. Turn the keyboard on
    IF the secret is not provied up to 2 mins after then start to record all keystrokes.
    
    at anytime, if the secret is provided AND there is anything into the memmory
        send it's keypresses.

---
1. Tap Fn as RGui, Hold as MO(1)
1. Hold ENTER as MO(2)

Select Line
Fn+C Select and Copy Word


source strings to search
DYN_REC_START1 
	see xd75/keymaps/dyn_macro_tap_dance/keymap.c

	quantum/dynamic_macro.c
	
	quantum/process_grave_esc.c
	
	quantum/quantum.c -> process_record_quantum

LEAD?
    parece bacaninha
    exemplo em arkag

Bluetooth
    HC-05 / HC-06 / RN-42

    Adafruit Bluefruit LE UART Friend PCB
        https://www.adafruit.com/product/2479
    
    Adafruit Bluefruit LE UART Friend PCB
        https://github.com/adafruit/Adafruit-Bluefruit-LE-UART-Friend-PCB
        (eagle schematics and PCB)

        USES -> MDBT40-256RV3
            https://www.adafruit.com/product/4076
            https://cdn-shop.adafruit.com/product-files/2267/MDBT40-P256R.pdf

        Adafruit Bluefruit LE Firmware (hex)
            https://github.com/adafruit/Adafruit_BluefruitLE_Firmware


    Some keyboard projects at gihub
        https://github.com/help-14/mechanical-keyboard

    GH60
        Reference, github

    Hub Keyboard
        https://github.com/konstantinwerner/hub_keyboard
        PCB, case and one USB hub

    https://68keys.io/guide/board/
        https://github.com/sbstjn/68Keys.io
        gerber file
 


    Blog
    https://www.masterzen.fr/2020/12/16/desiging-a-keyboard-part4/
    
    Layout the keyboard here: http://www.keyboard-layout-editor.com/
    Convert to PCB here: http://kalerator.clueboard.co/
        https://news.ycombinator.com/item?id=13406772
