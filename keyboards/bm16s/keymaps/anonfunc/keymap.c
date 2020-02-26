#include QMK_KEYBOARD_H

#define _BASE 0
#define _EMOJI 1
#define _NUMPAD 4

enum custom_keycodes {
    NOT_IT,
    SHRUG,
    DISFACE,
    FU,
    TFLIP,
    TFLIP2,
    SAD_EYES,
    TPUT,
    HAPPYFACE,
    HEARTFACE,
    CLOUD,
    CHANFACE,
    CMDCLEAR,
    KC_SNEK,
    KC_LOVE,

};
//Tap Dance Declarations
enum {
  TD_EXAMPLE1 = 0,
  TD_SHRUG,
  TD_EXAMPLE3,
  TD_EXAMPLE4
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* ## Base Pad
     *  ## ,-------+-------+-------+-------,
     *  ## | Bri+  | Talon |ScrSav | Vol+  |
     *  ## |       |       |       |       |
     *  ## +-------+-------+-------+-------+
     *  ## | Bri-  | Tap1  |Alfred | Vol-  |
     *  ## |       |       |       |       |
     *  ## +-------+-------+-------+-------+
     *  ## | Prev  | Play  | Next  | Mute  |
     *  ## |       |       |       |       |
     *  ## +-------+-------+-------+-------+
     *  ## |       |       | Emoji |NumPad |
     *  ## |       |       |       |       |
     *  ## `-------+-------+-------+-------'
    */
    [_BASE] = LAYOUT_ortho_4x4(
		KC_BRIU, HYPR(KC_TAB),    HYPR(KC_BSPACE), KC_VOLU,
		KC_BRID, TD(TD_EXAMPLE1), LCMD(KC_SPACE), KC_VOLD,
		KC_MPRV, KC_MPLY,         KC_MNXT,        KC_MUTE,
        KC_NO,  KC_NO, TT(_EMOJI),        TT(_NUMPAD)
	),

    /* ## EMOJI Pad
     *  ## ,-------+-------+-------+-------,
     *  ## | TFlip |TFlip2 |       | FU    |
     *  ## |       |       |       |       |
     *  ## +-------+-------+-------+-------+
     *  ## | Kirby | Snake |(｡♥‿♥｡)| Clear |
     *  ## |       |       |       | Line  |
     *  ## +-------+-------+-------+-------+
     *  ## | Shrug | ಠ_ಠ   |Hearts | Happy |
     *  ## | 2x    |       |       |       |
     *  ## +-------+-------+-------+-------+
     *  ## | RESET |       |       |       |
     *  ## |       |       |       |       |
     *  ## `-------+-------+-------+-------'
    */
      //purple
    [_EMOJI] = LAYOUT_ortho_4x4(
       TFLIP,   TFLIP2,   KC_NO,      FU ,
       CLOUD,   KC_SNEK,  KC_LOVE,      CMDCLEAR,
       TD(TD_SHRUG),   DISFACE,  HEARTFACE,    HAPPYFACE,
       RESET, TO(_BASE),  TO(_BASE),  TO(_BASE)
    ),

    /*  ## Number Pad
     *  ## ,-------+-------+-------+-------,
     *  ## |   7   |   8   |   9   | Bksp  |
     *  ## |       |       |       |       |
     *  ## +-------+-------+-------+-------+
     *  ## |   4   |   5   |   6   |   +   |
     *  ## |       |       |       |       |
     *  ## +-------+-------+-------+-------+
     *  ## |   1   |   2   |   3   | Tab   |
     *  ## |       |       |       |       |
     *  ## +-------+-------+-------+-------+
     *  ## |   0   |    .  |       |       |
     *  ## |       |       |       |       |
     *  ## `-------+-------+-------+-------'
     */
 	[_NUMPAD] = LAYOUT_ortho_4x4(
 		KC_7, KC_8, KC_9, KC_BSPACE,
 		KC_4, KC_5, KC_6, KC_PLUS,
 		KC_1, KC_2, KC_3, KC_TAB,
 		KC_0, KC_DOT, KC_NO, TO(_BASE)
 	),

};

void change_input_mode(void) {
    register_code(KC_LGUI);
    register_code(KC_LSHIFT);
    register_code(KC_LALT);
    register_code(KC_LCTRL);
    tap_code(KC_SPACE);
    unregister_code(KC_LGUI);
    unregister_code(KC_LSHIFT);
    unregister_code(KC_LALT);
    unregister_code(KC_LCTRL);
    _delay_ms(100);
}

// https://r12a.github.io/app-conversion/
void my_unicode(const char *str) {
    change_input_mode();
    send_unicode_hex_string(str);
    change_input_mode();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case CLOUD:       // (っ◕‿◕)っ
                if(record->event.pressed){
                    my_unicode("0028 3063 25D5 203F 25D5 0029 3063");
                }
                return false;
                break;
            case FU:       // t(-_-t)
                if(record->event.pressed){
                    SEND_STRING("t(-_-t)");
                }
                return false;
                break;
            case HAPPYFACE:       // ʘ‿ʘ
                if(record->event.pressed){
                     my_unicode("0298 203F 0298");
                }
                return false;
                break;
            case CMDCLEAR:
                if (record->event.pressed) {
                    register_code(KC_LGUI);
                    tap_code(KC_A);
                    unregister_code(KC_LGUI);
                    tap_code(KC_DEL);
                }
                return false;
                break;
            case KC_SNEK:
                if (record->event.pressed) {
                    my_unicode("d83d dca9");
                }
                return false;
                break;
            case KC_LOVE:
                if (record->event.pressed) {
                    my_unicode("0028 FF61 2665 203F 2665 FF61 0029");
                }
                return false;
                break;
            case SHRUG: // ¯\_(ツ)_/¯
                if (record->event.pressed) {
                    my_unicode("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
                }
                return false;
                break;
            case HEARTFACE:       // ♥‿♥
                if(record->event.pressed){
                    my_unicode("2665 203F 2665");
                }
                return false;
                break;
            case DISFACE:       // ಠ_ಠ
                if(record->event.pressed){
                    my_unicode("0CA0 005F 0CA0");
                }
                return false;
                break;
            case TFLIP:         // (╯°□°)╯ ︵ ┻━┻
                if(record->event.pressed){
                    my_unicode("0028 256F 00B0 25A1 00B0 0029 256F 0020 FE35 0020 253B 2501 253B");
                }
                return false;
                break;
            case TFLIP2:         // ┻━┻︵ \(°□°)/ ︵ ┻━┻
                if(record->event.pressed){
                    my_unicode("253B 2501 253B FE35 0020 005C 0028 00B0 25A1 00B0 0029 002F 0020 FE35 0020 253B 2501 253B");
                }
                return false;
                break;
                }
    }
    return true;
}


/* tap dance time */
void tdexample1(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    SEND_STRING("one");
    reset_tap_dance(state);
  }
}
void tdshrug(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      my_unicode("00AF 005C 005F 0028 30C4 0029 005F 002F 00AF");
      break;
    default:
      SEND_STRING("/shrug");
      break;
  }
  reset_tap_dance(state);
}

void tdexample3(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    SEND_STRING("three");
    reset_tap_dance(state);
  }
}
void tdexample4(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 2) {
    SEND_STRING("four");
    reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_EXAMPLE1] = ACTION_TAP_DANCE_FN(tdexample1),
    [TD_SHRUG] = ACTION_TAP_DANCE_FN(tdshrug),
    [TD_EXAMPLE3] = ACTION_TAP_DANCE_FN(tdexample3),
    [TD_EXAMPLE4] = ACTION_TAP_DANCE_FN(tdexample4)
};

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
    rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
    rgblight_setrgb(0, 16, 0); //green
    set_unicode_input_mode(UC_OSX);
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
        rgblight_setrgb(0, 16, 0); //green
        break;
    case _EMOJI:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_MOOD+5);
        break;
    case _NUMPAD:
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb(0, 0, 16); //blue
        break;
    default: //  for any other layers, or the default layer
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb(0, 0, 0); //off?
        break;
    }
  return state;
}
