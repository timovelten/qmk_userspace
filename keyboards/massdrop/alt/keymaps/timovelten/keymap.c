#include QMK_KEYBOARD_H

void render_color_picker(void);

enum alt_keycodes {
    U_T_AUTO = SAFE_RANGE, //USB Extra Port Toggle Auto Detect / Always Active
    U_T_AGCR,              //USB Toggle Automatic GCR control
    DBG_TOG,               //DEBUG Toggle On / Off
    DBG_MTRX,              //DEBUG Toggle Matrix Prints
    DBG_KBD,               //DEBUG Toggle Keyboard Prints
    DBG_MOU,               //DEBUG Toggle Mouse Prints
    MD_BOOT,               //Restart into bootloader after hold timeout

    // RGB Presets
    MY_RGB0,
    MY_RGB1,
    MY_RGB2,

    // Color keys for color picker
    CLPICKR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi_blocker(
        QK_GESC ,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_MPLY,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_MPRV,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_MNXT,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_LEFT, KC_DOWN, KC_RGHT
    ),
    [1] = LAYOUT_65_ansi_blocker(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_MUTE,
        _______, RGB_SPD, RGB_VAI, RGB_SPI, RGB_HUI, RGB_SAI, _______, U_T_AUTO,U_T_AGCR,_______, KC_PSCR, KC_SCRL, KC_PAUS, _______, KC_HOME,
        _______, RGB_RMOD,RGB_VAD, RGB_MOD, RGB_HUD, RGB_SAD, _______, _______, _______, _______, _______, _______,          _______, KC_PGUP,
        _______, RGB_TOG, _______, _______, _______, MD_BOOT, NK_TOGG, DBG_TOG, _______, _______, _______, _______,          KC_PGUP, KC_PGDN,
        _______, _______, _______,                            _______,                              MO(2), _______, KC_HOME, KC_PGDN, KC_END
    ),
    [2] = LAYOUT_65_ansi_blocker(
        _______, MY_RGB1, MY_RGB2, _______, _______, _______, _______, _______, _______, _______, MY_RGB0, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, \
        _______, _______, _______,                            OSL(3),                             _______, _______, _______, _______, _______  \
    ),
    [3] = LAYOUT_65_ansi_blocker(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, _______, _______, _______, _______, \
        _______, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, _______,          _______, _______, \
        _______, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, CLPICKR, _______,          _______, _______, \
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______  \
    ),
    /*
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______
    ),
    */
};

// 
// Arrays for the color picker (static)
//

// Arrays, used to store where to display what colors in color picker

const uint8_t MY_COLORS[][3] = {
    {246, 232, 255}, // Red 300
    {0, 195, 229}, // Red 600
    {246, 232, 255}, // Red A400

    {240, 150, 240}, // Pink 300
    {239, 223, 216}, // Pink 600
    {239, 255, 245}, // Pink A400

    {206, 122, 200}, // Purple 300
    {203, 200, 170}, // Purple 600
    {206, 255, 249}, // Purple A400

    {185, 109, 205}, // Deep Purple 300
    {184, 178, 177}, // Deep Purple 600
    {183, 224, 255}, // Deep Purple A400

    {146, 151, 246}, // Blue 300
    {147, 221, 229}, // Blue 600
    {154, 214, 255}, // Blue A400

    {132, 167, 225}, // Cyan 300
    {132, 255, 193}, // Cyan 600
    {131, 255, 255}, // Cyan A400

    {123, 147, 182}, // Teal 300
    {123, 255, 137}, // Teal 600
    {106, 255, 230}, // Teal A400

    {86, 89, 199}, // Green 300
    {86, 148, 160}, // Green 600
    {106, 255, 230}, // Green A400

    {38, 137, 255}, // Yellow 300
    {34, 201, 253}, // Yellow 600
    {38, 255, 255}, // Yellow A400

    {25, 178, 255}, // Orange 300
    {23, 255, 251}, // Orange 600
    {24, 255, 255}, // Orange A400

    {0, 0, 255}, // White
    {0, 0, 224}, // Less White
    {0, 0, 158} // Gray
};

const uint8_t MY_COLOR_MAP[MATRIX_ROWS][MATRIX_COLS] = {
        {  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 },
        {  255,   0,   3,   6,   9,  12,  15,  18,  22,  25,  28,  31, 255, 255, 255 },
        {  255,   1,   4,   7,  10,  13,  16,  20,  23,  26,  29,  32, 255, 255, 255 },
 {  255,   255,   2 ,  5,   8,  11,  14,  17,  21,  24,  27,  30,  33, 255, 255 },
        {  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 }
};

// 
// End
//

#define MODS_SHIFT  (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTL))
#define MODS_ALT  (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

// Need to  make the color picker work
bool rgb_matrix_indicators_user(void) {
    static bool reset_color = false;

    render_color_picker();

    // Caps lock indicator
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(30, 0, 0, 0);
        reset_color = true;
    } else if (reset_color) {
        // This is a dirty fix so that this actually works with the raindrop animation
        // that I actually kind of like
        RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);
        rgb_matrix_set_color(30, rgb.r, rgb.g, rgb.b);

        reset_color = false;
    }

    return false;
}

void render_color_picker(void) {
    if(get_highest_layer(layer_state|default_layer_state) != 3) {
        return;
    }
    
    for (uint8_t y = 0; y < MATRIX_ROWS; y++) {
        for (uint8_t x = 0; x < MATRIX_COLS; x++) {
            uint8_t idx = MY_COLOR_MAP[y][x];
            uint8_t led_index = g_led_config.matrix_co[y][x];

            if (idx != 255) {
                HSV hsv = { 
                    MY_COLORS[idx][0], 
                    MY_COLORS[idx][1], 
                    MY_COLORS[idx][2]
                };
                RGB rgb = hsv_to_rgb(hsv);

                rgb_matrix_set_color(led_index, rgb.r, rgb.g, rgb.b);
            } else {
                rgb_matrix_set_color(led_index, 0, 0, 0);
            }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint32_t key_timer;

    switch (keycode) {
            case MY_RGB0:
            rgb_matrix_mode(RGB_MATRIX_STARTUP_MODE);
            rgb_matrix_sethsv(RGB_MATRIX_STARTUP_HUE, RGB_MATRIX_STARTUP_SAT, RGB_MATRIX_STARTUP_VAL);
            return false;
        case MY_RGB1:
            rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
            return false;
        case MY_RGB2:
            rgb_matrix_mode(RGB_MATRIX_RAINDROPS);
            rgb_matrix_set_speed(1);
            return false;
        case CLPICKR: {
            uint8_t row = (record->event).key.row;
            uint8_t col = (record->event).key.col;

            uint8_t idx = MY_COLOR_MAP[row][col];

            if (idx == 255) {
                return true;
            }

            rgb_matrix_sethsv(MY_COLORS[idx][0], MY_COLORS[idx][1], MY_COLORS[idx][2]);

            return false;
        }
        case U_T_AUTO:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_extra_manual, "USB extra port manual mode");
            }
            return false;
        case U_T_AGCR:
            if (record->event.pressed && MODS_SHIFT && MODS_CTRL) {
                TOGGLE_FLAG_AND_PRINT(usb_gcr_auto, "USB GCR auto mode");
            }
            return false;
        case DBG_TOG:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_enable, "Debug mode");
            }
            return false;
        case DBG_MTRX:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_matrix, "Debug matrix");
            }
            return false;
        case DBG_KBD:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_keyboard, "Debug keyboard");
            }
            return false;
        case DBG_MOU:
            if (record->event.pressed) {
                TOGGLE_FLAG_AND_PRINT(debug_mouse, "Debug mouse");
            }
            return false;
        case MD_BOOT:
            if (record->event.pressed) {
                key_timer = timer_read32();
            } else {
                if (timer_elapsed32(key_timer) >= 500) {
                    reset_keyboard();
                }
            }
            return false;
        case RGB_TOG:
            if (record->event.pressed) {
              switch (rgb_matrix_get_flags()) {
                case LED_FLAG_ALL: {
                    rgb_matrix_set_flags(LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case (LED_FLAG_KEYLIGHT | LED_FLAG_MODIFIER | LED_FLAG_INDICATOR): {
                    rgb_matrix_set_flags(LED_FLAG_UNDERGLOW);
                    rgb_matrix_set_color_all(0, 0, 0);
                  }
                  break;
                case LED_FLAG_UNDERGLOW: {
                    rgb_matrix_set_flags(LED_FLAG_NONE);
                    rgb_matrix_disable_noeeprom();
                  }
                  break;
                default: {
                    rgb_matrix_set_flags(LED_FLAG_ALL);
                    rgb_matrix_enable_noeeprom();
                  }
                  break;
              }
            }
            return false;
        default:
            return true; //Process all other keycodes normally
    }
}
