#include "quantum.h"
#include "hid.h"

// Called when the host sends a HID report to this device
void raw_hid_receive(uint8_t *data, uint8_t length) {
    // Example: interpret first byte as a command
    switch (data[0]) {
        case 0x01:  // Toggle Caps Lock LED
            // You can use QMK's LED control functions here
            writePinHigh(B0);  // example pin
            break;

        case 0x02:  // Turn off Caps Lock LED
            writePinLow(B0);
            break;

        case 0x10:  // Trigger a macro
            SEND_STRING("Hello from QMK!");
            break;

        default:
            // Unknown command
            break;
    }
}
