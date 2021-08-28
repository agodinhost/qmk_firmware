
# 1 Envinronment preparation

## 1.1 Install qmk-msys
see #links below

## 1.2 Setup the qmk-msys home
	# open a QMK MSYS terminal
	$ cd /d/temp/qmk_firmware
	$ pwd
	$ qmk setup -H /d/temp/qmk_firmware

## 1.3 Check your environment
    $ qmk doctor
    $ qmk env
    
## 1.4 Create a QMK project fork
    Yes, it's a good practice to fork the original project,
    doing so will prevent you from messing up the main project ...

## 1.5 Clone the QMK project
    $ git clone <em>repository_url</em> -recursive deep 1

## 1.6 Change to a working label
    I had some issues using the QMK master, personally I think it is best
    to change to the latest label (0.13.34)
    
## 1.7 Submmit your code
    Create a Pull Request in order to submit your code to the QMK project.
    They will decide IF they will use your junk. If they decide they will merge your
    code into a label - so, try to not mess around too much, it will make this
    process easier.

---
# 2 Development

## 2.1 Check one specifc keyboard
	$ qmk info -r --keyboard bm68rgb
	$ qmk info --ascii --keyboard bm68rgb

## 2.2 Create a keymap.c from a QMK Keymap json
	qmk json2c <your-file-name>.json > keymap.c

## 2.3 Optionally create a new keyboard
	$ qmk new-keyboard
		keyboard name: xyz
		keymap Type [avr]: avr
		Yor Name: <name>
	# this command will create the folder /keyboards/<name>

## 2.4 Create a new keymap
	$ qmk new-keymap
		keyboard name: bm68rgb
		keymap name: <name>
	# this command will create the folder /keyboards/bm68rgb/keymaps/<name>
	# your keymap.c MUST be moved into this folder. 

## 2.5 Optionally add your shared files into the folder /users\/\<name>
see [Userspace: Sharing Code Between Keymaps](https://docs.qmk.fm/#/feature_userspace)

## 2.5.1 Set the userspace folder
    $ declare -x USER_NAME=<name>

## 2.6 Compile the firmware
	$ qmk compile -kb kprepublic/bm68rgb -km <name>
    $ make -j 1 kprepublic/bm68rgb:<name>
    # your shared folder MUST be listed into the compile output.
	# OR
	$ make -j 1 kprepublic/bm68rgb:agodinhost

## 2.7 Flash the firmware
    Use the QMK Toolbox to flash the firmware (G:\DRIVERS\KEYBOARDS\tools)
	Press ESC when connecting the USB cable to enter into the DFU mode
	OR
	Press Fn + B (reset)

## 2.8 Clear the EEPROM
    You are there coding your marvelous new version of the QMK that is going to save the last
    red pandas in the world when, out of blue, a weirdy behavior appears - that kind that turns
    your few hairs white. nothing makes sense anymore?
    So, stop whining and clear the dammed EEPROM ...

# 3 QMK Configurator
The QMK configurator used these options below to create my firmware:
```
	make -s -j 1 -r -R -f build_keyboard.mk GIT_VERSION=ed84a4-dirty BUILD_DATE=2021-08-10-21:38:01 CHIBIOS_VERSION=2021-08-10-21:38:01 CHIBIOS_CONTRIB_VERSION=2021-08-10-21:38:01 KEYBOARD=bm68rgb KEYMAP=bm68rgb_layout_65_ansi_mine KEYBOARD_FILESAFE=bm68rgb TARGET=bm68rgb_bm68rgb_layout_65_ansi_mine KEYBOARD_OUTPUT=.build/obj_bm68rgb KEYMAP_OUTPUT=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine MAIN_KEYMAP_PATH_1=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine MAIN_KEYMAP_PATH_2=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine MAIN_KEYMAP_PATH_3=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine MAIN_KEYMAP_PATH_4=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine MAIN_KEYMAP_PATH_5=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine KEYMAP_C=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine/src/keymap.c KEYMAP_PATH=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine/src VERBOSE=false COLOR=true SILENT=false QMK_BIN=bin/qmk
```

---
# 4 QMK Configurator output
```
# bm68rgb

![bm68rgb](https://i.imgur.com/uuYP8OIl.jpeg)

A 65% hotswap in switch RGB keyboard from KPRepublic.

* Keyboard Maintainer: [peepeetee](https://github.com/peepeetee)
* Hardware Supported: BM68 RGB
* Hardware Availability: [KP Republic](https://kprepublic.com/products/bm68rgb-bm68-rgb-65-hot-swappable-custom-mechanical-keyboard-pcb-programmed-qmk-via-firmware-full-rgb-switch-underglow-type-c)

Make example for this keyboard (after setting up your build environment):

    make bm68rgb:default

Flashing example for this keyboard:

    make bm68rgb:default:flash

To reset the board into bootloader mode, do one of the following:

* Short the two-pad footprint to the left of the spacebar switch while the board is plugged in
* Hold the Esc key while connecting the USB cable (also erases persistent settings)

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

Loaded 2 layers and 136 keycodes. Defined 0 Any key keycodes
* Sending bm68rgb:bm68rgb_layout_65_ansi_mine with LAYOUT_65_ansi
* Received job_id: 7345afa1-01e0-45b5-8af5-f2dbd3f1b689
* Running . . . . . . . . .
* Finished:
Warning: The bin/qmk script is being deprecated. Please install the QMK CLI: python3 -m pip install qmk
Ψ Compiling keymap with 
make -s -j 1 -r -R -f build_keyboard.mk GIT_VERSION=ed84a4-dirty BUILD_DATE=2021-08-10-21:38:01 
CHIBIOS_VERSION=2021-08-10-21:38:01 CHIBIOS_CONTRIB_VERSION=2021-08-10-21:38:01 
KEYBOARD=bm68rgb KEYMAP=bm68rgb_layout_65_ansi_mine KEYBOARD_FILESAFE=bm68rgb 
TARGET=bm68rgb_bm68rgb_layout_65_ansi_mine KEYBOARD_OUTPUT=.build/obj_bm68rgb 
KEYMAP_OUTPUT=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine 
MAIN_KEYMAP_PATH_1=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine 
MAIN_KEYMAP_PATH_2=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine 
MAIN_KEYMAP_PATH_3=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine 
MAIN_KEYMAP_PATH_4=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine 
MAIN_KEYMAP_PATH_5=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine 
KEYMAP_C=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine/src/keymap.c 
KEYMAP_PATH=.build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine/src 
VERBOSE=false COLOR=true SILENT=false QMK_BIN=bin/qmk


Warning: The bin/qmk script is being deprecated. Please install the QMK CLI: python3 -m pip install qmk
avr-gcc (GCC) 5.4.0
Copyright (C) 2015 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Warning: The bin/qmk script is being deprecated. Please install the QMK CLI: python3 -m pip install qmk
Warning: The bin/qmk script is being deprecated. Please install the QMK CLI: python3 -m pip install qmk
Warning: The bin/qmk script is being deprecated. Please install the QMK CLI: python3 -m pip install qmk
Compiling: keyboards/bm68rgb/bm68rgb.c                                                              
Compiling: .build/obj_bm68rgb_bm68rgb_layout_65_ansi_mine/src/keymap.c                              
Compiling: quantum/quantum.c                                                                        
Compiling: quantum/send_string.c                                                                    
Compiling: quantum/bitwise.c                                                                        
Compiling: quantum/led.c                                                                            
Compiling: quantum/keymap_common.c                                                                  
Compiling: quantum/keycode_config.c                                                                 
Compiling: quantum/bootmagic/bootmagic_full.c                                                       
Compiling: quantum/bootmagic/magic.c                                                                
Compiling: quantum/matrix_common.c                                                                  
Compiling: quantum/matrix.c                                                                         
Compiling: quantum/debounce/sym_defer_g.c                                                           
Compiling: quantum/mousekey.c                                                                       
Compiling: quantum/color.c                                                                          
Compiling: quantum/rgb_matrix.c                                                                     
Compiling: quantum/rgb_matrix_drivers.c                                                             
Compiling: quantum/process_keycode/process_rgb.c                                                    
Compiling: drivers/avr/ws2812.c                                                                     
Compiling: quantum/led_tables.c                                                                     
Compiling: quantum/process_keycode/process_space_cadet.c                                            
Compiling: quantum/process_keycode/process_magic.c                                                  
Compiling: quantum/process_keycode/process_grave_esc.c                                              
Compiling: tmk_core/common/host.c                                                                   
Compiling: tmk_core/common/keyboard.c                                                               
Compiling: tmk_core/common/action.c                                                                 
Compiling: tmk_core/common/action_tapping.c                                                         
Compiling: tmk_core/common/action_macro.c                                                           
Compiling: tmk_core/common/action_layer.c                                                           
Compiling: tmk_core/common/action_util.c                                                            
Compiling: tmk_core/common/debug.c                                                                  
Compiling: tmk_core/common/sendchar_null.c                                                          
Compiling: tmk_core/common/eeconfig.c                                                               
Compiling: tmk_core/common/report.c                                                                 
Compiling: tmk_core/common/usb_util.c                                                               
Compiling: tmk_core/common/avr/suspend.c                                                            
Compiling: tmk_core/common/avr/timer.c                                                              
Compiling: tmk_core/common/sync_timer.c                                                             
Compiling: tmk_core/common/avr/bootloader.c                                                         
Assembling: tmk_core/common/avr/xprintf.S                                                           
Compiling: tmk_core/common/avr/printf.c                                                             
Compiling: tmk_core/protocol/lufa/lufa.c                                                            
Compiling: tmk_core/protocol/usb_descriptor.c                                                       
Compiling: lib/lufa/LUFA/Drivers/USB/Class/Common/HIDParser.c                                       
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/Device_AVR8.c                                        
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/EndpointStream_AVR8.c                                
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/Endpoint_AVR8.c                                      
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/Host_AVR8.c                                          
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/PipeStream_AVR8.c                                    
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/Pipe_AVR8.c                                          
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/USBController_AVR8.c                                 
Compiling: lib/lufa/LUFA/Drivers/USB/Core/AVR8/USBInterrupt_AVR8.c                                  
Compiling: lib/lufa/LUFA/Drivers/USB/Core/ConfigDescriptors.c                                       
Compiling: lib/lufa/LUFA/Drivers/USB/Core/DeviceStandardReq.c                                       
Compiling: lib/lufa/LUFA/Drivers/USB/Core/Events.c                                                  
Compiling: lib/lufa/LUFA/Drivers/USB/Core/HostStandardReq.c                                         
Compiling: lib/lufa/LUFA/Drivers/USB/Core/USBTask.c                                                 
Compiling: tmk_core/protocol/lufa/usb_util.c                                                        
Linking: .build/bm68rgb_bm68rgb_layout_65_ansi_mine.elf                                             
Creating load file for flashing: .build/bm68rgb_bm68rgb_layout_65_ansi_mine.hex                     
Copying bm68rgb_bm68rgb_layout_65_ansi_mine.hex to qmk_firmware folder                              
Checking file size of bm68rgb_bm68rgb_layout_65_ansi_mine.hex                                       
 * The firmware size is fine - 22950/28672 (80%, 5722 bytes free)
```
