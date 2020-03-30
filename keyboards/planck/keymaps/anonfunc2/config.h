#pragma once

// #ifdef AUDIO_ENABLE
// #define STARTUP_SONG SONG(PLANCK_SOUND)
// #endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

#define TAPPING_TERM    200
#define COMBO_TERM    25

// Both?
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT

// Per key?
#define TAPPING_FORCE_HOLD

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR

#define OFF 0, 0, 0

#define COMBO_COUNT 9