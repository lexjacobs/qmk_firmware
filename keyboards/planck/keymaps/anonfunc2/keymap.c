#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
// #include "keymap_nordic.h"
// #include "keymap_german.h"
#include "keymap_steno.h"
// #include "keymap_french.h"
// #include "keymap_spanish.h"
// #include "keymap_hungarian.h"
// #include "keymap_swedish.h"
// #include "keymap_br_abnt2.h"
// #include "keymap_canadian_multilingual.h"
// #include "keymap_german_ch.h"
// #include "keymap_jp.h"

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// Combo map diagram at end.
// Note that the combo section can be commented out and all keys should still be reachable on a layer.
enum combos {
  // Left hand
  QW_TICK,
  WF_ESC,
  XC_TAB,
  ZX_SHIFT,
  // Right hand
  HCMA_MINUS,
  DOT_CMA_QUOTE,
  UY_ENTER,
  YCLN_BSLASH,
};

const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM xc_combo[] = {KC_C, KC_X, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM hcma_combo[] = {KC_H, KC_COMMA, COMBO_END};
const uint16_t PROGMEM dot_cma_combo[] = {KC_DOT, KC_COMMA, COMBO_END};
const uint16_t PROGMEM uy_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM ycln_combo[] = {KC_Y, KC_SCOLON, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  // Left hand
  [QW_TICK] = COMBO(qw_combo, KC_GRAVE),
  [WF_ESC] = COMBO(wf_combo, KC_ESC),
  [XC_TAB] = COMBO(xc_combo, KC_TAB),
  [ZX_SHIFT] = COMBO(zx_combo, KC_LSHIFT),

  // Right hand
  [HCMA_MINUS] = COMBO(hcma_combo, KC_MINUS),
  [DOT_CMA_QUOTE] = COMBO(dot_cma_combo, KC_QUOTE),
  [UY_ENTER] = COMBO(uy_combo, KC_ENTER),
  [YCLN_BSLASH] = COMBO(ycln_combo, KC_BSLASH),
};
/* ## COMBOS
 * ## ,----------+---------+------+------.          ,------+------+----------+---------.
 * ## |    TICK  |   ESC   |      |      |          |      |      |   Enter  | BSLASH  |
 * ## |          |         |      |      |          |      |      |          |         |
 * ## |------+---+--+------+------+------|          +------+------+------+---+--+------|
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+---+--+------+------|
 * ## |      |     Tab     |      |      |          |      |   MINUS  | QUOTE   |      |
 * ## |   Shift     |      |      |      |          |      |          |         |      |
 * ## `------+------+------+------+------|          +------+------+---+--+------+------'
 * ##               |      |      |      |          |      |      |      | 
 * ##               |      |      |      |          |      |      |      | 
 * ##               '------+------+------'          `------+------+------'
 */ 
//Tap Dance Declarations
enum {
  TD_A_ESC = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  // [TD_A_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_A, KC_ESC)
// Other declarations would go here, separated by commas, if you have them
};

// In Layer declaration, add tap dance item in place of a key code
// TD(TD_A_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ## Colemak-ModDH
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |   Q  |   W  |   F  |   P  |   B  |          |   J  |   L  |   U  |   Y  |   ;  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------|
 * ## |   A  |   R  |   S  |   T  |   G  |          |   K  |   N  |   E  |   I  |   O  |
 * ## |Shift | Ctrl | Alt  | Cmd  |      |          |      | Cmd  | Alt  | Ctrl |Shift |
 * ## |------+------+------+------+------|          |------+------+------+------+------|
 * ## |   Z  |   X  |   C  |   D  |   V  |          |   M  |   H  |   ,  |   .  |   /  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------|          |------+------+------+------+------'
 * ##               |  TAB | BKSP |L(ESC)|          |Space |Enter |   '  |
 * ##               |      |      |Lower |          |Raise |      |      |
 * ##               `------+------+------'          `------+------+------'
 * 
 * Since the board I'm moving to has no lighting, all layers *must* be hold to activate.
 */
  [_BASE] = LAYOUT_planck_grid(
    KC_Q, KC_W, KC_F, KC_P, KC_B, KC_NO, KC_NO, KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, 
    LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), KC_G, KC_NO, KC_NO, KC_K, LGUI_T(KC_N), LALT_T(KC_E), LCTL_T(KC_I), LSFT_T(KC_O), 
    KC_Z, KC_X, KC_C, KC_D, KC_V,  KC_NO, KC_NO, KC_M, KC_H, KC_COMMA, KC_DOT, KC_SLASH,
    KC_NO, KC_NO, KC_TAB, KC_ESC, LT(_LOWER, KC_BSPACE), KC_NO, KC_NO, LT(_RAISE, KC_SPACE), KC_ENTER, KC_QUOTE, KC_NO, KC_NO
    ),

/* ## Lower
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |   !  |   @  |   #  |   $  |   %  |          |   ^  |   &  |   *  |   (  |   )  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------+
 * ## |   F1 | F2   |  F3  |  F4  |  F5  |          |   \  |   -  |   +  |   [  |   ]  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------+
 * ## |   F6 |  F7  |  F8  |  F9  |  F10 |          |   |  |   _  |   =  |   {  |   }  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------|          |------+------+------+------+------'
 * ##               | F11  | F12  |xxxxxx|          |ADJUST|   `  |   ~  |
 * ##               |      |      |      |          |      |      |      |
 * ##               `------+------+------'          `------+------+------'
 */
  [_LOWER] = LAYOUT_planck_grid(
      KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC, KC_NO, KC_NO, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,KC_RPRN,
      KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5, KC_NO,KC_NO, KC_BSLASH, LGUI_T(KC_MINUS), LALT_T(KC_EQUAL), LCTL_T(KC_LBRACKET), LSFT_T(KC_RBRACKET),
      KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_NO,KC_NO, KC_PIPE,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,
      KC_NO, KC_NO, KC_F11, KC_F12, KC_TRNS, KC_NO,KC_NO, KC_TRNS,KC_GRAVE,KC_TILDE,KC_NO,KC_NO
      ),

/* ## Raise
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |   1  |   2  |   3  |   4  |   5  |          |   6  |   7  |   8  |   9  |   0  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------|
 * ## |SHIFT |CTRL  |ALT   |CMD   | PGUP |          | whlu | left | down | up   | right|
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------|------+------+------+------+
 * ## | |> ||| Vol- | Vol+ | Mute | PGDN |          | whld | mleft|mdwn  | mup  | mrght|
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------|          |------+------+------+------+------'
 * ##               |      |      |Del   |          |xxxxxx|Click |RClick|
 * ##               |      |      |ADJUST|          |      |      |      |
 * ##               `------+------+------'          `------+------+------'
 */
  [_RAISE] = LAYOUT_planck_grid(
      KC_1,  KC_2,    KC_3,    KC_4,    KC_5,    KC_NO, KC_NO, KC_6,   KC_7,          KC_8,            KC_9,              KC_0,
      KC_LSHIFT, KC_LCTL,KC_LALT,KC_LGUI,KC_PGUP,  KC_NO, KC_NO, KC_MS_WH_UP, KC_LEFT,  KC_DOWN,KC_UP,KC_RIGHT, 
      KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_PGDN,  KC_NO, KC_NO, KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, 
      KC_NO, KC_NO, KC_NO, KC_NO, LT(_LOWER, KC_DELETE),       KC_NO, KC_NO, KC_TRNS, KC_MS_BTN1, KC_MS_BTN2, KC_NO, KC_NO
      ),

/* ## Adjust (Lower and Raise)
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |      |      |Scrn  |Talon |      |          |      | IDEs |      |      |      |
 * ## |      |      |Saver |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          +------+------+------+------+------|
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------|          +------+------+------+------+------'
 * ##               |      |      |      |          |      |      |Reset |
 * ##               |      |      |      |          |      |      |      | 
 * ##               `------+------+------'          `------+------+------'
 */
  [_ADJUST] = LAYOUT_planck_grid(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, HYPR(KC_BSPACE), HYPR(KC_TAB), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO
      ),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  rgblight_mode(1);
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

#define HSV_WHITE 0, 0, 255

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
  [0] = {
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {OFF}, {OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {OFF}, {OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {OFF}, {OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},
        {OFF}, {OFF}, {HSV_WHITE}, {HSV_WHITE},      {HSV_WHITE},       {OFF}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {OFF}, {OFF}
    },
    [1] = {
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {OFF}, {OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {OFF}, {OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {OFF}, {OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {OFF}, {OFF}, {HSV_RED}, {HSV_RED},      {HSV_RED},       {OFF}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {OFF}, {OFF}
    },
    [2] = {
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {OFF}, {OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {OFF}, {OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {OFF}, {OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {OFF}, {OFF}, {HSV_BLUE}, {HSV_BLUE},      {HSV_BLUE},       {OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {OFF}, {OFF}
    },
    [3] = {
        {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {OFF}, {OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},
        {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {OFF}, {OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},
        {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {OFF}, {OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN},
        {OFF}, {OFF}, {HSV_GREEN}, {HSV_GREEN},      {HSV_GREEN},       {OFF}, {HSV_GREEN}, {HSV_GREEN}, {HSV_GREEN}, {OFF}, {OFF}
    },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  // This was auto-generated.  Why a switch statement here?
  switch (biton32(layer_state)) {
    case 0:
      set_layer_color(0);
      break;
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
