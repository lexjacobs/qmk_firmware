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
  DYNAMIC_MACRO_RANGE,
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
};

#include "dynamic_macro.h"

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// enum combos {
//   WF_ESC,
//   RS_BS,
//   ST_TAB,
//   CD_ENTER,
//   EN_COLON,
//   HCMA_UNDER,
//   HM_QUOTE,
//   KN_LT,
//   EI_GT,
//   UL_ESC,
//   YCLN_BSLASH,
// };

// const uint16_t PROGMEM wf_combo[] = {KC_W, KC_F, COMBO_END};
// const uint16_t PROGMEM rs_combo[] = {KC_R, KC_S, COMBO_END};
// const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};
// const uint16_t PROGMEM cd_combo[] = {KC_C, KC_D, COMBO_END};
// const uint16_t PROGMEM en_combo[] = {KC_E, KC_N, COMBO_END};
// const uint16_t PROGMEM hcma_combo[] = {KC_H, KC_COMMA, COMBO_END};
// const uint16_t PROGMEM hm_combo[] = {KC_H, KC_M, COMBO_END};
// const uint16_t PROGMEM kn_combo[] = {KC_N, KC_K, COMBO_END};
// const uint16_t PROGMEM ei_combo[] = {KC_E, KC_I, COMBO_END};
// const uint16_t PROGMEM ul_combo[] = {KC_U, KC_L, COMBO_END};
// const uint16_t PROGMEM ycln_combo[] = {KC_Y, KC_SCOLON, COMBO_END};

// combo_t key_combos[COMBO_COUNT] = {
//   [WF_ESC] = COMBO(wf_combo, KC_ESC),
//   [RS_BS] = COMBO(rs_combo, KC_BSPACE),
//   [ST_TAB] = COMBO(st_combo, KC_TAB),
//   [CD_ENTER] = COMBO(cd_combo, KC_ENTER),
//   [EN_COLON] = COMBO(en_combo, KC_COLON),
//   [HCMA_UNDER] = COMBO(hcma_combo, KC_UNDERSCORE),
//   [HM_QUOTE] = COMBO(hm_combo, KC_DOUBLE_QUOTE),
//   [KN_LT] = COMBO(kn_combo, KC_LT),
//   [EI_GT] = COMBO(ei_combo, KC_GT),
//   [UL_ESC] = COMBO(ul_combo, KC_ESC),
//   [YCLN_BSLASH] = COMBO(ycln_combo, KC_BSLASH),
// };

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

/* Colemak-ModDH
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |   K  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   M  |   H  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
  [_BASE] = LAYOUT_planck_grid(
      MT(MOD_MEH, KC_TAB), KC_Q,       KC_W,    KC_F,    KC_P,    KC_B,     KC_J,     KC_L,  KC_U,             KC_Y,           KC_SCOLON,        KC_BSPACE,
      LT(4,KC_ESCAPE),     KC_A,       KC_R,    KC_S,    KC_T,    KC_G,     KC_K,     KC_N,  KC_E,             KC_I,           KC_O,             KC_QUOTE,
      KC_LSHIFT,           KC_Z,       KC_X,    KC_C,    KC_D,    KC_V,     KC_M,     KC_H,  LGUI_T(KC_COMMA), LALT_T(KC_DOT), LCTL_T(KC_SLASH), RSFT_T(KC_ENTER),
      KC_HYPR,             KC_LCTRL,   KC_LALT, KC_LGUI, LOWER,   KC_SPACE, KC_NO,    RAISE, KC_LEFT,          KC_DOWN,        KC_UP,            KC_RIGHT
    ),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |RecM1 |RecM2 |PlayM1|PlayM2|      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |   Stop Rec  |      | Prev | Play | Stop | Next |
 * `-----------------------------------------------------------------------------------'
 */
  [_LOWER] = LAYOUT_planck_grid(
      KC_TILD, KC_EXLM,        KC_AT,          KC_HASH,         KC_DLR,          KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR,             KC_LPRN,             KC_RPRN,       KC_TRNS,
      KC_TRNS, DYN_REC_START1, DYN_REC_START2, DYN_MACRO_PLAY1, DYN_MACRO_PLAY2, KC_TRNS,      KC_TRNS, KC_UNDS, KC_PLUS,             KC_LCBR,             KC_RCBR,       KC_PIPE,
      KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,         KC_TRNS,      KC_TRNS, KC_TRNS, KC_TRNS,             KC_HOME,             KC_END,        KC_TRNS,
      KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,         KC_TRNS,         DYN_REC_STOP, KC_NO,   KC_TRNS, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_STOP, KC_MEDIA_NEXT_TRACK
      ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Mute | Vol- | Vol+ | Vol+ |
 * `-----------------------------------------------------------------------------------'
 */
  [_RAISE] = LAYOUT_planck_grid(
      KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,          KC_8,            KC_9,              KC_0,            KC_DELETE,
      KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  KC_MINUS,      KC_EQUAL,        KC_LBRACKET,       KC_RBRACKET,     KC_BSLASH,
      KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, KC_NONUS_HASH, KC_NONUS_BSLASH, KC_PGUP,           KC_PGDOWN,       KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,  KC_NO,  KC_TRNS,       KC_AUDIO_MUTE,   KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_UP
      ),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |Qwerty| Base |Numpad|Steno | ASUp |ASTogl|MSpd0 |MSpd1 |MSpd2 |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  | Nav  |Aud on|Audoff|AuTogl|ASDwn |ASOn  |RGBTgl|RGB+  |RGB-  |LEDs  |Reset |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |MusMod|Mus on|Musoff|MuTogl|ASEcho|ASOff |RGBMod|RGB<  |RGB>  |NKRO  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_ADJUST] = LAYOUT_planck_grid(
      KC_TRNS,   TO(6),   TO(0),   TO(5),   TO(9),   KC_ASUP,  KC_ASTG,  KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2, KC_TRNS,           KC_TRNS,
      KC_DELETE, TO(4),   AU_ON,   AU_OFF,  AU_TOG,  KC_ASDN,  KC_ASON,  RGB_TOG,      RGB_VAI,      RGB_VAD,      LED_LEVEL,         RESET,
      KC_TRNS,   MU_MOD,  MU_ON,   MU_OFF,  MU_TOG,  KC_ASRP,  KC_ASOFF, RGB_MOD,      RGB_HUI,      RGB_HUD,      MAGIC_TOGGLE_NKRO, KC_TRNS,
      KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,    KC_TRNS,  KC_TRNS,      KC_TRNS,      KC_TRNS,      KC_TRNS,           KC_TRNS
      ),

/* Nav Layer
 * ,-----------------------------------------------------------------------------------.
 * |      |Cmd-6 |Cmd-7 |Cmd-8 |Cmd-9 |Cmd-0 |      |W-Left|W-Down| W-up |W-Rght|      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |Cmd-1 |Cmd-2 |Cmd-3 |Cmd-4 |Cmd-5 | Home | Left | Down | Up   |Right |  End |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |M-Back|LClick|MClick|RClick|M-Fwd |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |      |      |             |      |M-Left|M-Down| M-Up |M-Righ|
 * `-----------------------------------------------------------------------------------'
 */
  [_LAYER4] = LAYOUT_planck_grid(
      KC_TRNS, LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0), KC_TRNS, KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_UP, KC_MS_WH_RIGHT, KC_TRNS,
      KC_TRNS, LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5), KC_HOME, KC_LEFT,       KC_DOWN,       KC_UP,       KC_RIGHT,       KC_END,
      KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, KC_MS_BTN4,    KC_MS_BTN1,    KC_MS_BTN3,  KC_MS_BTN2,     KC_MS_BTN5,
      TO(0),   KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_NO,   KC_TRNS,       KC_MS_LEFT,    KC_MS_DOWN,  KC_MS_UP,       KC_MS_RIGHT
      ),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   7  |   8  |   9  |   /  |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   4  |   5  |   6  |   *  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |   0  |   1  |   2  |   3  |   -  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |   0  |   0  |   .  |   +  |      |
 * `-----------------------------------------------------------------------------------'
 */
  [_LAYER5] = LAYOUT_planck_grid(
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_KP_7, KC_KP_8, KC_9,      KC_SLASH,    KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_4,    KC_5,    KC_6,      KC_ASTR,     KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3,      KC_KP_MINUS, KC_TRNS,
      TO(0),   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_0,    KC_0,    KC_KP_DOT, KC_PLUS,     KC_TRNS
      ),

    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc/8|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | EXIT | Ctrl | Alt  | GUI  |QLwer7|    Space    |QRse8 | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
  [_LAYER6] = LAYOUT_planck_grid(
      KC_TAB,          KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,  KC_U,   KC_I,     KC_O,    KC_P,      KC_BSPACE,
      LT(8,KC_ESCAPE), KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,  KC_J,   KC_K,     KC_L,    KC_SCOLON, KC_QUOTE,
      KC_TRNS,         KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,  KC_M,   KC_COMMA, KC_DOT,  KC_SLASH,  KC_ENTER,
      TO(0),           KC_TRNS, KC_TRNS, KC_TRNS, OSL(7), KC_TRNS, KC_NO, OSL(8), KC_LEFT,  KC_DOWN, KC_UP,     KC_RIGHT
      ),

    // Lower for the qwerty layer
  [_LAYER7] = LAYOUT_planck_grid(
      KC_TILD,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PIPE,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_HOME,KC_END,KC_TRNS,KC_TRNS,
      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_NO,KC_NO,KC_TRNS,KC_MEDIA_NEXT_TRACK,KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,KC_MEDIA_PLAY_PAUSE
      ),

    // Raise for the qwerty layer
  [_LAYER8] = LAYOUT_planck_grid(
      KC_GRAVE,KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,          KC_8,            KC_9,              KC_0,            KC_DELETE,
      KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6,  KC_MINUS,      KC_EQUAL,        KC_LBRACKET,       KC_RBRACKET,     KC_BSLASH,
      KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, KC_NONUS_HASH, KC_NONUS_BSLASH, KC_PGUP,           KC_PGDOWN,       KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,  KC_NO,  KC_TRNS,       KC_AUDIO_MUTE,   KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_VOL_UP
      ),

/* Plover layer (http://opensteno.org)
 * ,-----------------------------------------------------------------------------------.
 * |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |   #  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  FN  |   S  |   T  |   P  |   H  |   *  |   *  |   F  |   P  |   L  |   T  |   D  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   S  |   K  |   W  |   R  |   *  |   *  |   R  |   B  |   G  |   S  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Exit |      |      |   A  |   O  |             |   E  |   U  |  PWR | RES1 | RES2 |
 * `-----------------------------------------------------------------------------------'
 */

[_LAYER9] = LAYOUT_planck_grid(
  STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,  STN_NC,
  STN_FN,  STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1, STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
  XXXXXXX, STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
  TO(0),   XXXXXXX, XXXXXXX, STN_A,   STN_O,   XXXXXXX, XXXXXXX, STN_E,   STN_U,   STN_PWR, STN_RE1, STN_RE2
),
};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

#define HSV_WHITE 0, 0, 255

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [1] = {
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},      {HSV_RED},       {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}
    },

    [2] = {
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},       {HSV_BLUE},       {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}
    },

    [4] = {
        {OFF},      {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {OFF},       {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {OFF},
        {OFF},      {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_CORAL}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_CORAL},
        {OFF},      {OFF},      {OFF},      {OFF},      {OFF},      {OFF},      {OFF},       {HSV_CORAL},       {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_CORAL},
        {HSV_PINK}, {OFF},      {OFF},      {OFF},            {OFF},            {OFF},       {OFF},             {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}, {HSV_SPRINGGREEN}
    },

    [5] = {
        {OFF},      {OFF}, {OFF}, {OFF}, {OFF}, {OFF}, {OFF},      {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_PINK},        {OFF},
        {OFF},      {OFF}, {OFF}, {OFF}, {OFF}, {OFF}, {OFF},      {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_SPRINGGREEN}, {OFF},
        {OFF},      {OFF}, {OFF}, {OFF}, {OFF}, {OFF}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_PINK},        {OFF},
        {HSV_PINK}, {OFF}, {OFF}, {OFF},    {OFF},     {OFF},      {HSV_BLUE}, {HSV_BLUE}, {HSV_GOLD}, {HSV_SPRINGGREEN}, {OFF}
    },

    [6] = {
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},
        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},
        {HSV_PINK},  {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE},       {HSV_WHITE},        {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE}, {HSV_WHITE} },

    [7] = {
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},
        {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED},      {HSV_RED},       {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}, {HSV_RED}
    },

    [8] = {
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},
        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE},      {HSV_BLUE},        {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}, {HSV_BLUE}
    },

    [9] = {
        {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_TURQUOISE},
        {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},      {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},
        {OFF},           {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},      {HSV_TURQUOISE}, {HSV_TURQUOISE}, {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},      {HSV_BLUE},
        {HSV_PINK},      {OFF},           {OFF},           {HSV_BLUE},      {HSV_BLUE},                       {OFF},           {HSV_BLUE},      {HSV_BLUE},      {OFF},           {OFF},           {OFF},},

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
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 4:
      set_layer_color(4);
      break;
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
    case 7:
      set_layer_color(7);
      break;
    case 8:
      set_layer_color(8);
      break;
    case 9:
      set_layer_color(9);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_record_dynamic_macro(keycode, record)) {
    return false;
  }
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
