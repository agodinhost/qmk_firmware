
# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite     # was full, Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       	# was yes, Mouse keys
EXTRAKEY_ENABLE = no       	# was yes, Audio control and System control
CONSOLE_ENABLE = yes         # was no, Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
UNICODE_ENABLE = no			# Unicode

# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no      # teste, era yes Breathing sleep LED during USB suspend

BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output

LTO_ENABLE = yes			# era yes, disable macro and function features
LAYOUTS = 65_ansi

#* see common_features.mk for a complete list of options *#

VIA_ENABLE = yes 			# custom, required in order to use via.
GRAVE_ESC_ENABLE   = yes	# custom
AUTO_SHIFT_ENABLE  = yes	# custom
TAP_DANCE_ENABLE   = yes	# custom
SPACE_CADET_ENABLE = no
LEADER_ENABLE      = no
COMBO_ENABLE       = no
