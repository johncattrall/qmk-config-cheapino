#pragma once

/* Home row mods, ported feel from the ZMK "timeless" setup:
 * balanced flavor ~ PERMISSIVE_HOLD; require-prior-idle + opposite-hands
 * rule come from Achordion (achordion_chord + streak timeout below). */
#undef TAPPING_TERM
#define TAPPING_TERM 280
#define PERMISSIVE_HOLD
#define QUICK_TAP_TERM 175

/* Autoshift: ZMK as_ht used a 350 ms tapping term. */
#define AUTO_SHIFT_TIMEOUT 350
#define NO_AUTO_SHIFT_SPECIAL

/* Combos resolve against the base layer, so the same physical chords work
 * on Graphite (positional combos, like ZMK). */
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_TERM 50

/* Achordion: require-prior-idle equivalent. */
#define ACHORDION_STREAK
