/* Cheapino v2 port of the Crosses/Bridges ZMK layout.
 * Layer order deliberately mirrors the ZMK config AND the board's
 * hardcoded encoder dispatch in encoder.c:
 *   0 BASE (wheel scroll), 1 GRAPHITE (default-layer swap; wheel),
 *   2 NAV (ctrl-tab), 3 MEDIA (volume), 4 SYS, 5 NUM (wheel).
 * Trackball roles have no equivalent here; the encoder stands in.
 */
#include QMK_KEYBOARD_H
#include "achordion.h"

enum layers { BASE, GRAPHITE, NAV, MEDIA, SYS, NUM };

enum custom_keycodes {
    NUMWORD = SAFE_RANGE,
    TOG_GRAPHITE,
};

/* Home row mods, same assignments as ZMK: S/D/F/G = Ctrl/Alt/Gui/Shift,
 * H/J/K/L(home) mirrored. */
#define HM_S LCTL_T(KC_S)
#define HM_D LALT_T(KC_D)
#define HM_F LGUI_T(KC_F)
#define HM_G LSFT_T(KC_G)
#define HM_H RSFT_T(KC_H)
#define HM_J RGUI_T(KC_J)
#define HM_K RALT_T(KC_K)
#define HM_L RCTL_T(KC_L)
/* Graphite home row: N R T S G | Y H A E I with the same mod positions. */
#define GM_R LCTL_T(KC_R)
#define GM_T LALT_T(KC_T)
#define GM_S LGUI_T(KC_S)
#define GM_G LSFT_T(KC_G)
#define GM_Y RSFT_T(KC_Y)
#define GM_H RGUI_T(KC_H)
#define GM_A RALT_T(KC_A)
#define GM_E RCTL_T(KC_E)

#define LT_SYSQ LT(SYS, KC_Q)
#define LT_SYSB LT(SYS, KC_B)
#define MT_ENT LALT_T(KC_ENT)
#define MT_TAB LSFT_T(KC_TAB)

/* Tap dances: numpad thumb (tap NumWord, double toggle NUM, triple toggle
 * NAV) and the Space thumb (hold = F5 for dictation, tap = Space). */
enum { TD_NUM, TD_SPCF5 };
#define TDNUM TD(TD_NUM)
#define TDSPC TD(TD_SPCF5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[BASE] = LAYOUT_split_3x5_3(
  LT_SYSQ, KC_W,   KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,    HM_S,   HM_D,    HM_F,    HM_G,        HM_H,    HM_J,    HM_K,    HM_L,    KC_BSPC,
  KC_Z,    KC_X,   KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                   KC_ESC,  KC_QUOT, TDSPC,       MT_ENT,  TDNUM,   MT_TAB
),

[GRAPHITE] = LAYOUT_split_3x5_3(
  LT_SYSB, KC_L,   KC_D,    KC_W,    KC_Z,        KC_QUOT, KC_F,    KC_O,    KC_U,    KC_J,
  KC_N,    GM_R,   GM_T,    GM_S,    GM_G,        GM_Y,    GM_H,    GM_A,    GM_E,    KC_I,
  KC_Q,    KC_X,   KC_M,    KC_C,    KC_V,        KC_K,    KC_P,    KC_DOT,  KC_MINS, KC_SLSH,
                   KC_COMM, KC_BSPC, TDSPC,       MT_ENT,  TDNUM,   MT_TAB
),

[NAV] = LAYOUT_split_3x5_3(
  KC_1,    KC_2,   KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_ESC,  _______,_______, _______, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_SCLN,
  KC_GRV,  KC_LCTL,KC_LALT, KC_CAPS, KC_TAB,      KC_MINS, KC_LBRC, KC_RBRC, KC_QUOT, KC_BSLS,
                   KC_BSPC, TG(NAV), KC_SPC,      KC_ENT,  TG(MEDIA), KC_SPC
),

[MEDIA] = LAYOUT_split_3x5_3(
  KC_MUTE, XXXXXXX, XXXXXXX, MS_BTN2, MS_BTN1,    LCTL(KC_LEFT), LCTL(KC_RGHT), MEH(KC_LEFT), MEH(KC_RGHT), XXXXXXX,
  KC_VOLU, XXXXXXX, KC_UP,   XXXXXXX, KC_PGUP,    LSA(KC_H), LSA(KC_L), LSA(KC_K), LSA(KC_J), XXXXXXX,
  KC_VOLD, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,    KC_EQL,  KC_RBRC, MEH(KC_H), MEH(KC_L), KC_SLSH,
                   XXXXXXX, TG(MEDIA), XXXXXXX,   LSA(KC_SPC), LSA(KC_ENT), KC_SPC
),

[SYS] = LAYOUT_split_3x5_3(
  XXXXXXX, XXXXXXX, TOG_GRAPHITE, XXXXXXX, QK_BOOT, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,     EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,
                   XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_SPC
),

[NUM] = LAYOUT_split_3x5_3(
  _______, _______, _______, _______, _______,    KC_COMM, KC_7,    KC_8,    KC_9,    KC_BSPC,
  _______, KC_PLUS, KC_MINS, KC_ASTR, KC_SLSH,    KC_0,    KC_4,    KC_5,    KC_6,    KC_ENT,
  _______, _______, _______, _______, _______,    KC_DOT,  KC_1,    KC_2,    KC_3,    KC_EQL,
                   MEH(KC_T), TG(NUM), _______,   LSA(KC_ENT), LSA(KC_M), MEH(KC_SPC)
)
};

/* Combos on the same physical positions as ZMK; COMBO_ONLY_FROM_LAYER 0
 * makes them positional, so they work on Graphite too. */
const uint16_t PROGMEM combo_nav_l[]   = {KC_B, TDSPC, COMBO_END};
const uint16_t PROGMEM combo_nav_r[]   = {KC_N, MT_ENT, COMBO_END};
const uint16_t PROGMEM combo_media_l[] = {KC_V, TDSPC, COMBO_END};
const uint16_t PROGMEM combo_media_r[] = {KC_M, MT_ENT, COMBO_END};
const uint16_t PROGMEM combo_shENT[]   = {TDSPC, MT_ENT, COMBO_END};
const uint16_t PROGMEM combo_alttab[]  = {KC_QUOT, KC_A, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_nav_l, MO(NAV)),
    COMBO(combo_nav_r, MO(NAV)),
    COMBO(combo_media_l, MO(MEDIA)),
    COMBO(combo_media_r, MO(MEDIA)),
    COMBO(combo_shENT, S(KC_ENT)),
    COMBO(combo_alttab, A(KC_TAB)),
};

/* Graphite custom shift pairs (spec): '->_  ,->?  .->>  -->"  /-><
 * Restricted to the Graphite layer via layer masks. */
const key_override_t ko_quot = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUOT, KC_UNDS, 1 << GRAPHITE);
const key_override_t ko_comm = ko_make_with_layers(MOD_MASK_SHIFT, KC_COMM, KC_QUES, 1 << GRAPHITE);
const key_override_t ko_dot  = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT,  KC_GT,   1 << GRAPHITE);
const key_override_t ko_mins = ko_make_with_layers(MOD_MASK_SHIFT, KC_MINS, KC_DQT,  1 << GRAPHITE);
const key_override_t ko_slsh = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_LT,   1 << GRAPHITE);

const key_override_t *key_overrides[] = {
    &ko_quot, &ko_comm, &ko_dot, &ko_mins, &ko_slsh
};

/* ---- NumWord: momentary NUM layer that ends on any key outside the
 * continue set (digits, operators, backspace, the Amethyst chords). ---- */
static bool numword_active = false;

static bool numword_continues(uint16_t kc) {
    switch (kc) {
        case KC_1 ... KC_0:
        case KC_COMM: case KC_DOT: case KC_PLUS: case KC_MINS:
        case KC_ASTR: case KC_SLSH: case KC_EQL:
        case KC_BSPC: case KC_DEL:
        case LSA(KC_ENT): case LSA(KC_M):
        case MEH(KC_SPC): case MEH(KC_T):
            return true;
        default:
            return false;
    }
}

static void numword_on(void) { numword_active = true; layer_on(NUM); }
static void numword_off(void) { numword_active = false; layer_off(NUM); }

/* ---- Tap dances ---- */
static void td_num_fn(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        numword_on();
    } else if (state->count == 2) {
        numword_active = false;
        layer_invert(NUM);
    } else if (state->count >= 3) {
        layer_invert(NAV);
    }
}

static void td_spc_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && state->pressed) {
        register_code(KC_F5);           /* hold: dictation */
    } else {
        register_code(KC_SPC);
    }
}
static void td_spc_reset(tap_dance_state_t *state, void *user_data) {
    unregister_code(KC_F5);
    unregister_code(KC_SPC);
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_NUM]   = ACTION_TAP_DANCE_FN(td_num_fn),
    [TD_SPCF5] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_spc_finished, td_spc_reset),
};

/* ---- Achordion: opposite-hands rule for the home row mods, thumbs
 * always allowed (same shape as ZMK hold-trigger-key-positions). ---- */
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t *tap_hold_record,
                     uint16_t other_keycode, keyrecord_t *other_record) {
    /* Thumb row (row 3 in each half's matrix) always counts as other-hand. */
    if (other_record->event.key.row % (MATRIX_ROWS / 2) == 3) return true;
    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    switch (tap_hold_keycode) {
        case LT_SYSQ: case LT_SYSB: case MT_ENT: case MT_TAB:
            return 0;  /* layer taps and thumb mod-taps: no achordion */
        default:
            return 800;
    }
}

uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode,
                                        uint16_t next_keycode) {
    return 150;  /* ZMK require-prior-idle-ms */
}

/* ---- process_record ---- */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) return false;

    if (record->event.pressed) {
        switch (keycode) {
            case TOG_GRAPHITE: {
                default_layer_set(default_layer_state == (1UL << GRAPHITE)
                                      ? (1UL << BASE)
                                      : (1UL << GRAPHITE));
                return false;
            }
            case NUMWORD:
                numword_on();
                return false;
        }
        if (numword_active && !numword_continues(keycode) &&
            !IS_QK_MOMENTARY(keycode) && !IS_QK_TAP_DANCE(keycode) &&
            !IS_QK_MOD_TAP(keycode) && !IS_QK_LAYER_TAP(keycode)) {
            /* This key already resolved on the NUM layer; drop the layer
             * so the NEXT key is back on base, like ZMK num_word. */
            numword_off();
        }
    }
    return true;
}

void matrix_scan_user(void) { achordion_task(); }

/* ---- Per-layer LED color. Base = off; NumWord shows green because it
 * raises NUM. noeeprom variants avoid flash wear. ---- */
static void led_for_layers(layer_state_t layers, layer_state_t defaults) {
    uint8_t top = get_highest_layer(layers | defaults);
    switch (top) {
        case NAV:      rgblight_sethsv_noeeprom(HSV_BLUE); break;
        case MEDIA:    rgblight_sethsv_noeeprom(HSV_ORANGE); break;
        case SYS:      rgblight_sethsv_noeeprom(HSV_RED); break;
        case NUM:      rgblight_sethsv_noeeprom(HSV_GREEN); break;
        case GRAPHITE: rgblight_sethsv_noeeprom(HSV_PURPLE); break;
        default:       rgblight_sethsv_noeeprom(HSV_OFF); break;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    led_for_layers(state, default_layer_state);
    return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    led_for_layers(layer_state, state);
    return state;
}
