#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    BASE, // default layer
    NMPD, // numpad
    SYMB, // symbols
};

enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  VRSN = EZ_SAFE_RANGE,
#else
  VRSN = SAFE_RANGE,
#endif
  DBL_SHFT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   F  |   P  |   G  | Alt  |           | Dbl  |   J  |   L  |   U  |   Y  |   ;  |   \    |
 * |--------+------+------+------+------+------| Home |           |Shift |------+------+------+------+------+--------|
 * | LAlt/` |   A  |   R  |   S  |   T  |   D  |------|           |------|   H  |   N  |   N  |   E  |   O  |' / Cmd |
 * |--------+------+------+------+------+------| App  |           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   K  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | App  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | NMPD |       | SYMB |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_EQL,           KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LEFT,
  KC_DEL,           KC_Q,        KC_W,          KC_F,    KC_P,    KC_G,    LALT(KC_HOME),
  LALT_T(KC_GRAVE), KC_A,        KC_R,          KC_S,    KC_T,    KC_D,
  KC_LSPO,          CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    KC_APP,
  LT(SYMB,KC_GRV),  KC_QUOT,     LALT(KC_LSFT), KC_LEFT, KC_RGHT,
                                                           ALT_T(KC_APP), KC_LGUI,
                                                                          KC_HOME,
                                                         KC_SPC, KC_BSPC, MO(NMPD),
  // right hand
  KC_RGHT,      KC_6,    KC_7,    KC_8,    KC_9,        KC_0,           KC_MINS,
  DBL_SHFT,     KC_J,    KC_L,    KC_U,    KC_Y,        KC_SCLN,        KC_BSLS,
                KC_H,    KC_N,    KC_E,    KC_I,        KC_O, GUI_T(KC_QUOT),
  MEH_T(KC_NO), KC_K,    KC_M,    KC_COMM, KC_DOT,      CTL_T(KC_SLSH), KC_RSPC,
                         KC_UP,   KC_DOWN, KC_LBRC,     KC_RBRC,        TT(SYMB),
  KC_LALT,  CTL_T(KC_ESC),
  KC_PGUP,
  MO(SYMB), KC_TAB, KC_ENT
),
/* Keymap 1: Numpad and Navigation
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |      | Home |  Up  | End  |      |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      | Left | Down | Right| PgUp |------|           |------| Down |   4  |   5  |   6  |   .  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |      |      |      | PgDn |      |      |           |      |   &  |   1  |   2  |   3  |   0  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |   +  |   -  |   *  |   /  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NMPD] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,  KC_F1,    KC_F2,    KC_F3,   KC_F4,    KC_F5,    KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_HOME,  KC_UP,   KC_END,   KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_LEFT,  KC_DOWN, KC_RIGHT, KC_PGUP,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_PGDN,  KC_TRNS,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS,  KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,
  KC_TRNS,  KC_UP,    KC_7,     KC_8,     KC_9,     KC_ASTR,  KC_F12,
            KC_DOWN,  KC_4,     KC_5,     KC_6,     KC_DOT,   KC_TRNS,
  KC_TRNS,  KC_AMPR,  KC_1,     KC_2,     KC_3,     KC_0,     KC_TRNS,
                      KC_PLUS,  KC_MINUS, KC_ASTR,  KC_SLASH, KC_TRNS,
  KC_TRNS,  KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Symbols and media keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F11   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  @   |  !   |  {   |  }   |  |   |      |           |      |      |      |      |      |      |  F12   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  *   |  _   |  [   |  ]   |  &   |------|           |------|      | Prev | Next |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  $   |  #   |  -   |  =   |  %   |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_TRNS,
  KC_TRNS,  KC_AT,    KC_EXLM,  KC_LCBR,  KC_RCBR,  KC_PIPE,  KC_TRNS,
  KC_TRNS,  KC_ASTR,  KC_UNDS,  KC_LBRC,  KC_RBRC,  KC_AMPR,
  KC_TRNS,  KC_DLR,   KC_HASH,  KC_MINUS, KC_EQUAL, KC_PERC,  KC_TRNS,
  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_BTN1,  KC_BTN2,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12,
           KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case DBL_SHFT:
        tap_code(KC_LSHIFT);
        tap_code(KC_LSHIFT);
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
