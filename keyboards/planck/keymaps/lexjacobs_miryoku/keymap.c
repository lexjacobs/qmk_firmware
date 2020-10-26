#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
#endif
#include "eeprom.h"
/* #include "keymap_german.h" */
/* #include "keymap_nordic.h" */
/* #include "keymap_french.h" */
/* #include "keymap_spanish.h" */
/* #include "keymap_hungarian.h" */
/* #include "keymap_swedish.h" */
/* #include "keymap_br_abnt2.h" */
/* #include "keymap_canadian_multilingual.h" */
/* #include "keymap_german_ch.h" */
/* #include "keymap_jp.h" */
/* #include "keymap_bepo.h" */
/* #include "keymap_italian.h" */
/* #include "keymap_slovenian.h" */
/* #include "keymap_danish.h" */
/* #include "keymap_norwegian.h" */
/* #include "keymap_portuguese.h" */

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
};

enum planck_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _LAYER4,
  _LAYER5,
  _LAYER6,
  _LAYER7,
  _LAYER8,
  _LAYER9,
  _LAYER10,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_planck_grid(KC_Q,KC_W,KC_E,KC_R,KC_T,KC_TRANSPARENT,KC_TRANSPARENT,KC_Y,KC_U,KC_I,KC_O,KC_P,LCTL_T(KC_A),LALT_T(KC_S),LGUI_T(KC_D),LSFT_T(KC_F),KC_G,KC_TRANSPARENT,KC_TRANSPARENT,KC_H,RSFT_T(KC_J),LGUI_T(KC_K),RALT_T(KC_L),RCTL_T(KC_QUOTE),LSFT_T(KC_Z),KC_X,KC_C,KC_V,KC_B,KC_TRANSPARENT,KC_TRANSPARENT,KC_N,KC_M,KC_COMMA,KC_DOT,RSFT_T(KC_SLASH),KC_TRANSPARENT,KC_TRANSPARENT,LT(5,KC_ESCAPE),LT(6,KC_BSPACE),LT(7,KC_TAB),KC_TRANSPARENT,KC_NO,LT(8,KC_ENTER),LT(9,KC_SPACE),LT(10,KC_DELETE),KC_TRANSPARENT,KC_TRANSPARENT),

  [_LOWER] = LAYOUT_planck_grid(KC_1,KC_2,KC_3,KC_4,KC_5,KC_TRANSPARENT,KC_TRANSPARENT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_LCTRL,KC_LALT,KC_LGUI,KC_LSHIFT,KC_GRAVE,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_QUOTE,LGUI_T(KC_Z),LGUI_T(KC_X),LGUI_T(KC_C),LGUI_T(KC_V),LGUI_T(KC_B),KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_PGUP,KC_PGDOWN,KC_END,KC_SCOLON,KC_TRANSPARENT,KC_TRANSPARENT,KC_ESCAPE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_RAISE] = LAYOUT_planck_grid(KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_TRANSPARENT,KC_TRANSPARENT,KC_CIRC,KC_AMPR,KC_ASTR,KC_GRAVE,KC_PIPE,KC_TAB,KC_ASTR,KC_LPRN,KC_RPRN,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_PGUP,KC_PGDOWN,KC_END,KC_QUOTE,KC_PERC,KC_DLR,KC_LCBR,KC_RCBR,KC_EXLM,KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_MINUS,KC_PLUS,KC_CIRC,KC_BSLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_ESCAPE,KC_BSPACE,KC_TAB,KC_ENTER,KC_NO,KC_TRANSPARENT,KC_DELETE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_ADJUST] = LAYOUT_planck_grid(KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_F11,KC_F12,EEP_RST,KC_TRANSPARENT,KC_F14,KC_F15,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RGB_SLD,RGB_MOD,RGB_HUD,RGB_HUI,LED_LEVEL,RESET,KC_TRANSPARENT,MU_MOD,AU_TOG,MU_TOG,KC_TRANSPARENT,KC_TRANSPARENT,TOGGLE_LAYER_COLOR,RGB_TOG,RGB_VAD,RGB_VAI,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER4] = LAYOUT_planck_grid(KC_Q,KC_W,KC_F,KC_P,KC_G,KC_TRANSPARENT,KC_TRANSPARENT,KC_J,KC_L,KC_U,KC_Y,KC_QUOTE,LCTL_T(KC_A),LALT_T(KC_R),LGUI_T(KC_S),LSFT_T(KC_T),KC_D,KC_TRANSPARENT,KC_TRANSPARENT,KC_H,RSFT_T(KC_N),RGUI_T(KC_E),RALT_T(KC_I),RCTL_T(KC_O),LSFT_T(KC_Z),KC_X,KC_C,KC_V,KC_B,KC_TRANSPARENT,KC_TRANSPARENT,KC_K,KC_M,KC_COMMA,KC_DOT,RSFT_T(KC_SLASH),KC_TRANSPARENT,KC_TRANSPARENT,LT(5,KC_ESCAPE),LT(6,KC_BSPACE),LT(7,KC_TAB),KC_TRANSPARENT,KC_NO,LT(8,KC_ENTER),LT(9,KC_SPACE),LT(10,KC_DELETE),KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER5] = LAYOUT_planck_grid(KC_AUDIO_VOL_UP,KC_AUDIO_MUTE,KC_UP,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,RESET,KC_AUDIO_VOL_DOWN,KC_LEFT,KC_DOWN,KC_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_SPACE,KC_ENTER,KC_TRANSPARENT,KC_NO,KC_ENTER,KC_SPACE,KC_DELETE,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER6] = LAYOUT_planck_grid(KC_1,KC_2,KC_3,KC_4,KC_5,KC_TRANSPARENT,KC_TRANSPARENT,KC_6,KC_7,KC_8,KC_9,KC_0,KC_LCTRL,KC_LALT,KC_LGUI,KC_LSHIFT,KC_GRAVE,KC_TRANSPARENT,KC_TRANSPARENT,KC_LEFT,KC_DOWN,KC_UP,KC_RIGHT,KC_SCOLON,LGUI(KC_Z),LGUI(KC_X),LGUI(KC_C),LGUI(KC_V),LGUI(LSFT(KC_Z)),KC_TRANSPARENT,KC_TRANSPARENT,KC_UNDS,KC_MINUS,KC_PLUS,KC_EQUAL,KC_BSLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_ESCAPE,KC_TRANSPARENT,KC_TAB,KC_TRANSPARENT,KC_NO,KC_DOT,KC_SPACE,KC_DELETE,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER7] = LAYOUT_planck_grid(KC_0,KC_9,KC_8,KC_7,KC_6,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_LCTRL,KC_LALT,KC_LGUI,KC_RSHIFT,KC_ENTER,KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_LEFT,KC_MS_DOWN,KC_MS_UP,KC_MS_RIGHT,KC_COLN,KC_TRANSPARENT,KC_TRANSPARENT,KC_GRAVE,LGUI(KC_TAB),LGUI(KC_GRAVE),KC_TRANSPARENT,KC_TRANSPARENT,KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_UP,KC_MS_WH_RIGHT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_ESCAPE,KC_BSPACE,KC_TRANSPARENT,KC_TRANSPARENT,KC_NO,KC_MS_BTN2,KC_MS_BTN1,KC_MS_BTN3,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER8] = LAYOUT_planck_grid(KC_TRANSPARENT,KC_TRANSPARENT,KC_EQUAL,KC_TRANSPARENT,KC_TILD,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_UNDS,KC_TRANSPARENT,KC_TRANSPARENT,KC_PIPE,KC_TRANSPARENT,KC_PIPE,KC_CIRC,KC_TILD,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_RSHIFT,KC_RGUI,KC_RALT,KC_RCTRL,KC_TRANSPARENT,KC_TRANSPARENT,KC_GRAVE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_UNDS,KC_EQUAL,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_ESCAPE,KC_BSPACE,KC_TAB,KC_TRANSPARENT,KC_NO,KC_TRANSPARENT,KC_SPACE,KC_DELETE,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER9] = LAYOUT_planck_grid(KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_TRANSPARENT,KC_TRANSPARENT,KC_CIRC,KC_AMPR,KC_ASTR,KC_GRAVE,KC_PIPE,KC_LBRACKET,KC_RBRACKET,KC_LPRN,KC_RPRN,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_HOME,KC_PGUP,KC_PGDOWN,KC_END,KC_QUOTE,KC_PERC,KC_DLR,KC_LCBR,KC_RCBR,KC_EXLM,KC_TRANSPARENT,KC_TRANSPARENT,KC_HASH,KC_MINUS,KC_PLUS,KC_CIRC,KC_BSLASH,KC_TRANSPARENT,KC_TRANSPARENT,KC_ESCAPE,KC_BSPACE,KC_TAB,KC_TRANSPARENT,KC_NO,KC_ENTER,KC_TRANSPARENT,KC_DELETE,KC_TRANSPARENT,KC_TRANSPARENT),

  [_LAYER10] = LAYOUT_planck_grid(KC_F1,KC_F2,KC_F3,KC_F4,KC_F5,KC_TRANSPARENT,KC_TRANSPARENT,TO(0),TO(4),KC_TRANSPARENT,KC_TRANSPARENT,KC_BRIGHTNESS_UP,KC_F6,KC_F7,KC_F8,KC_F9,KC_F10,KC_TRANSPARENT,KC_TRANSPARENT,RGB_SLD,RGB_MOD,RGB_HUD,RGB_HUI,KC_BRIGHTNESS_DOWN,KC_F11,KC_F12,KC_F13,KC_F14,KC_F15,KC_TRANSPARENT,KC_TRANSPARENT,TOGGLE_LAYER_COLOR,RGB_TOG,RGB_VAD,RGB_VAI,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT,KC_ESCAPE,KC_BSPACE,KC_TAB,KC_TRANSPARENT,KC_NO,KC_ENTER,KC_SPACE,KC_TRANSPARENT,KC_TRANSPARENT,KC_TRANSPARENT),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = { {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198}, {82,113,198} },

    [2] = { {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184}, {0,159,184} },

    [3] = { {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165}, {154,26,165} },

    [5] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [10] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,183,238}, {0,183,238}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

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
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 10:
      set_layer_color(10);
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

// BEGIN ADD-ON CODE AFTER ORYX PRODUCED BOILERPLATE
// force layer switch hold on all thumb LayerTap keys only
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
switch (keycode) {
case LT(5,KC_ESCAPE):
return true;
case LT(6,KC_BSPACE):
return true;
case LT(7,KC_TAB):
return true;
case LT(8,KC_ENTER):
return true;
case LT(9,KC_SPACE):
return true;
case LT(10,KC_DELETE):
return true;
default:
return false;
}
}
// END ADD-ON CODE AFTER ORYX PRODUCED BOILERPLATE
