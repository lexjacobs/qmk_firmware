SRC += muse.c
# Set any rules.mk overrides for your specific keymap here.
# See rules at https://docs.qmk.fm/#/config_options?id=the-rulesmk-file
LINK_TIME_OPTIMIZATION_ENABLE = yes
COMMAND_ENABLE = no
AUDIO_ENABLE = no
# COMBO_ENABLE = yes
TAP_DANCE_ENABLE = yes
STENO_ENABLE = yes          # Additional protocols for Stenography(+1700), requires VIRTSER
