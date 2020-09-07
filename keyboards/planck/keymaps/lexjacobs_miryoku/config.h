#pragma once

#ifdef AUDIO_ENABLE
#define STARTUP_SONG SONG(PLANCK_SOUND)
#endif

#define MIDI_BASIC

#define ENCODER_RESOLUTION 4

/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#define ORYX_CONFIGURATOR
#undef DEBOUNCE
#define DEBOUNCE 15

#undef RGBLIGHT_HUE_STEP
#define RGBLIGHT_HUE_STEP 6

#define RGB_MATRIX_STARTUP_SPD 60

/* USER ADDED AFTER ORYX BOILERPLATE BEGIN */
#define TAPPING_FORCE_HOLD_PER_KEY
/* USER ADDED AFTER ORYX BOILERPLATE END */
