/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "g/keymap_combo.h"

#define _BASE 0 // default layer
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

// Blank template at the bottom
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
 * ## `------+------+------+------+------'          `------+------+------+------+------'
 * ##
 * ##               ,------+------+------.          ,------+------+------.
 * ##               |  ⇥   | ⎋    |  ⌫   |          |Space |   ↩︎  |   '  |
 * ##               |      |      |Lower |          |Raise |      |      |
 * ##               `------+------+------'          `------+------+------'
 * 
 * Since the board has no lighting, all layers *must* be hold to activate.
 */
[_BASE] = LAYOUT_gergoplex(
    KC_Q, KC_W, KC_F, KC_P, KC_B, /**/    KC_J, KC_L, KC_U, KC_Y, KC_SCOLON, 
    LSFT_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LGUI_T(KC_T), KC_G, /**/    KC_K, LGUI_T(KC_N), LALT_T(KC_E), LCTL_T(KC_I), LSFT_T(KC_O), 
    KC_Z, KC_X, KC_C, KC_D, KC_V, /**/ KC_M, KC_H, KC_COMMA, KC_DOT, KC_SLASH,
    KC_TAB, KC_ESC, LT(_LOWER, KC_BSPACE), /**/ LT(_RAISE, KC_SPACE), KC_ENTER, KC_QUOTE
    ),

/* ## Lower
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |   !  |   @  |   #  |   $  |   %  |          |   ^  |   &  |   *  |   (  |   )  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------+
 * ## |   F1 |  F2  |  F3  |  F4  |  F5  |          |   \  |   -  |   +  |   [  |   ]  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------+
 * ## |   F6 |  F7  |  F8  |  F9  |  F10 |          |   |  |   _  |   =  |   {  |   }  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------'          `------+------+------+------+------'
 * ##
 * ##               ,------+------+------.          ,------+------+------.
 * ##               | F11  | F12  |  xxx |          | ADJ  |   `  |   ~  |
 * ##               |      |      |      |          |      |      |      |
 * ##               `------+------+------'          `------+------+------'
 */
  [_LOWER] = LAYOUT_gergoplex(
    KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,  /**/ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,KC_RPRN,
      KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5, /**/ KC_BSLASH, LGUI_T(KC_MINUS), LALT_T(KC_EQUAL), LCTL_T(KC_LBRACKET), LSFT_T(KC_RBRACKET),
      KC_F6, KC_F7,   KC_F8,   KC_F9,   KC_F10, /**/ KC_PIPE,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,
      KC_F11, KC_F12, KC_TRNS, /**/ KC_TRNS,KC_GRAVE,KC_TILDE
      ),


/* ## Raise
 * ## ,------+------+------+------+------.          ,------+------+------+------+------.
 * ## |   1  |   2  |   3  |   4  |   5  |          |   6  |   7  |   8  |   9  |   0  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------+------+------+------+------|
 * ## |SHIFT |CTRL  |ALT   |CMD   | PGUP |          | ⎈↑   |   ←  |   ↓  |   ↑  |   →  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## |------+------+------+------+------|          |------|------+------+------+------+
 * ## | ▶︎ ❙❙ | Vol- | Vol+ | Mute | PGDN |          | ⎈↓   |  M←  |  M↓  |  M↑  |  M→  |
 * ## |      |      |      |      |      |          |      |      |      |      |      |
 * ## `------+------+------+------+------'          `------+------+------+------+------'
 * ##
 * ##               ,------+------+------.          ,------+------+------.
 * ##               |  ↖︎   |  ↘︎   |  ⌦   |          |  xxx |Click |RClick|
 * ##               |      |      | ADJ  |          |      |      |      |
 * ##               `------+------+------'          `------+------+------'
 */
  [_RAISE] =  LAYOUT_gergoplex(
    KC_1,  KC_2,    KC_3,    KC_4,    KC_5, /**/   KC_6,   KC_7,          KC_8,            KC_9,              KC_0,
      KC_LSHIFT, KC_LCTL,KC_LALT,KC_LGUI,KC_PGUP,  /**/ KC_MS_WH_UP, KC_LEFT,  KC_DOWN,KC_UP,KC_RIGHT, 
      KC_MPLY, KC_VOLD, KC_VOLU, KC_MUTE, KC_PGDN,  /**/ KC_MS_WH_DOWN, KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, 
      KC_HOME, KC_END, LT(_LOWER, KC_DELETE),  /**/    KC_TRNS, KC_MS_BTN1, KC_MS_BTN2
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
 * ## `------+------+------+------+------'          `------+------+------+------+------'
 * ##
 * ##               ,------+------+------.          ,------+------+------.
 * ##               |      |      |      |          |      |      |Reset |
 * ##               |      |      |      |          |      |      |      | 
 * ##               `------+------+------'          `------+------+------'
 */
  [_ADJUST] = LAYOUT_gergoplex(
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /**/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, HYPR(KC_BSPACE), HYPR(KC_TAB), KC_NO, /**/ KC_NO, HYPR(KC_T), KC_NO, KC_NO,  
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, /**/ KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
      KC_NO, KC_NO, KC_NO, /**/ KC_NO, KC_NO, RESET,
      ),
};


uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
