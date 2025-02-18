#pragma once

#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_STARTUP_SAT 0
#define RGB_MATRIX_STARTUP_VAL 255
#define RGB_MATRIX_STARTUP_HUE 145
#define TAPPING_TOGGLE 3

#undef USB_LED_INDICATOR_ENABLE

// Note: Using sym_eager_pk, DEBOUNCE of 40ms means that when spamming key down, there will be no
// input for 40 ms after the initial keydown, then no input for another 40 ms after the key up
// event. So the minimum delay between two successive key down events is 80 ms.
#undef DEBOUNCE
#define DEBOUNCE 3