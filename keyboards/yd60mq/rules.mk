# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = yes       # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6

LAYOUTS = 60_ansi 60_ansi_split_bs_rshift 60_ansi_tsangan 60_hhkb 60_iso 60_iso_split_bs_rshift 60_iso_tsangan

DEFAULT_FOLDER = yd60mq/12led

# Woody/agodinhost

# HID_ENABLED = yes → compiles HID support into QMK.
# HID_ENABLED = no → no HID endpoints are exposed.
HID_ENABLE = yes

# RAW_ENABLE = yes → enables raw HID receive/send.
RAW_ENABLE = yes

# NO_KEYBOARD = yes → QMK does not compile in the keyboard HID endpoint. Your board will only expose other HID interfaces (like System Control or Consumer Control), but not the typing interface (UsagePage=0x01, Usage=0x06).
# NO_KEYBOARD = no → QMK does compile in the keyboard HID endpoint, so the firmware exposes the normal typing interface alongside any extras.
NO_KEYBOARD = no

# KEYBOARD_SHARED_EP = yes → QMK merges keyboard reports into another endpoint.
# KEYBOARD_SHARED_EP = no → QMK keep keyboard reports on their own endpoint (not merged), it get a dedicated keyboard HID interface.
KEYBOARD_SHARED_EP = no

# Optional: enable extra HID features if you need them
#EXTRAKEY_ENABLE = yes  # Audio control and System control
EXTRAKEY_ENABLE = yes   # for media keys (Consumer Control)
SYSTEM_ENABLE = yes     # for system control (power/sleep)
