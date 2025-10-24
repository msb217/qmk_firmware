#include QMK_KEYBOARD_H
#if __has_include("keymap.h")
#    include "keymap.h"
#endif

// layer enums
#define _BASE 0
#define _NAV 1
#define _SYM 2
#define _FUNC 3
#define _NO_MODS 4

#include "process_combo.h"
enum combo_events {
    UIO_BACKSPACE,
    SYM_BACKSPACE,
    NUM_BACKSPACE,
    JKL_ENTER,
    SYM_ENTER,
    NUM_ENTER,
    SDF_ESCAPE,
    COMBO_LENGTH
};

const uint16_t PROGMEM uio_backspace[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM sym_backspace[] = {KC_AMPR, KC_ASTR, KC_LPRN, COMBO_END};
const uint16_t PROGMEM num_backspace[] = {KC_P7, KC_P8, KC_P9, COMBO_END};
const uint16_t PROGMEM jkl_enter[] = {LT(_SYM,KC_J), RGUI_T(KC_K), RALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM sym_enter[] = {KC_MINS, KC_SCLN, KC_COLN, COMBO_END};
const uint16_t PROGMEM num_enter[] = {KC_P4, KC_P5, KC_P6, COMBO_END};
const uint16_t PROGMEM sdf_escape[] = {LALT_T(KC_S), LGUI_T(KC_D), LT(_SYM,KC_F), COMBO_END};
combo_t key_combos[COMBO_LENGTH] = {
    [UIO_BACKSPACE] = COMBO(uio_backspace, KC_BSPC),
    [SYM_BACKSPACE] = COMBO(sym_backspace, KC_BSPC),
    [NUM_BACKSPACE] = COMBO(num_backspace, KC_BSPC),
    [JKL_ENTER] = COMBO(jkl_enter, KC_ENT),
    [SYM_ENTER] = COMBO(sym_enter, KC_ENT),
    [NUM_ENTER] = COMBO(num_enter, KC_ENT),
    [SDF_ESCAPE] = COMBO(sdf_escape, KC_ESC)
};

// tap tap
enum {
    TD_F1_F11,
    TD_F2_F12,
    TD_F3_F13,
    TD_F4_F14,
    TD_F5_F15,
    TD_F6_F16,
    TD_F7_F17,
    TD_F8_F18,
    TD_F9_F19,
    TD_F10_F20
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_F1_F11] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_F11),
    [TD_F2_F12] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_F12),
    [TD_F3_F13] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_F13),
    [TD_F4_F14] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_F14),
    [TD_F5_F15] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_F15),
    [TD_F6_F16] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_F16),
    [TD_F7_F17] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_F17),
    [TD_F8_F18] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_F18),
    [TD_F9_F19] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_F19),
    [TD_F10_F20] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_F20)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
            KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
            KC_NO, LCTL_T(KC_A), LALT_T(KC_S), LGUI_T(KC_D), LT(_SYM,KC_F), KC_G, KC_H, LT(_SYM,KC_J), RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_QUOT), KC_NO,
            KC_NO, HYPR_T(KC_Z), KC_X, KC_C, KC_V, KC_B, TT(_NO_MODS), TT(_BASE), KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
            MO(_FUNC), LT(_FUNC,KC_TAB), LSFT_T(KC_SPC), RSFT_T(KC_SPC), MO(_NAV), MO(_FUNC)
	),
    [_NAV] = LAYOUT(
            KC_NO, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_NO,
            KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO,
            KC_NO, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
    [_SYM] = LAYOUT(
            KC_NO, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_ASTR, KC_NO,
            KC_NO, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR, KC_BSLS, KC_PIPE, KC_MINS, KC_COLN, KC_SCLN, KC_DQUO, KC_NO,
            KC_NO, KC_NO, KC_NO, KC_TILD, KC_GRV, KC_EQL, KC_TRNS, KC_TRNS, KC_PPLS, KC_UNDS, KC_LT, KC_GT, KC_QUES, KC_NO,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FUNC] = LAYOUT(
            KC_NO, KC_P1, KC_P2, KC_P3, KC_P4, KC_P5, KC_P6, KC_P7, KC_P8, KC_P9, KC_P0, KC_NO,
            KC_NO, TD(TD_F1_F11), TD(TD_F2_F12), TD(TD_F3_F13), TD(TD_F4_F14), TD(TD_F5_F15), TD(TD_F6_F16), TD(TD_F7_F17), TD(TD_F8_F18), TD(TD_F9_F19), TD(TD_F10_F20), KC_NO,
            KC_NO, KC_F21, KC_F22, KC_F23, KC_F24, KC_NO, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
    [_NO_MODS] = LAYOUT(
            KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_NO,
            KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_QUOT, KC_NO,
            KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_TRNS, KC_TRNS, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO,
            KC_NO, KC_LSFT, KC_SPC, KC_ENT, KC_LALT, KC_LCTL
    )
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPC):
            return 125;
        case RSFT_T(KC_SPC):
            return 125;
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}

#include "os_detection.h"
bool process_detected_host_os_user(os_variant_t os) {
    switch (os) {
        case OS_WINDOWS:
            tap_code16(QK_MAGIC_GUI_OFF);
            break;
        case OS_LINUX:
        case OS_UNSURE:
        case OS_MACOS:
        case OS_IOS:
        default:
            break;
    }
    return true;
}

#ifdef OTHER_KEYMAP_C
#    include OTHER_KEYMAP_C
#endif // OTHER_KEYMAP_C

