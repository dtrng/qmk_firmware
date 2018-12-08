#include "ergodox_ez.h"
#include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_swedish.h"

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  RGB_SLD,
  AA,
  AE,
  OSLH,
  TO_WIN,
  TO_MAC,
  TO_LINUX
};

#undef NO_AA
#define NO_AA 0xE5

#undef NO_AE
#define NO_AE 0xE4

#undef NO_OSLH
#define NO_OSLH 0xF6


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox(
      // left hand
      KC_EQUAL,              KC_1,            KC_2,     KC_3,           KC_4,           KC_5,   KC_LEFT,
      KC_ESCAPE,             KC_Q,            KC_W,     KC_E,           KC_R,           KC_T,   TG(1),
      CTL_T(KC_ESCAPE),      KC_A,            KC_S,     KC_D,           KC_F,           KC_G,
      SFT_T(KC_TILD),        CTL_T(KC_Z),     KC_X,     KC_C,           KC_V,           KC_B,   MT(MOD_HYPR, KC_NO), 
      LT(1,KC_GRAVE),        ALT_T(KC_QUOTE), KC_LGUI,  MO(2),          MO(1), 

                                                                 ALT_T(KC_APPLICATION), KC_LGUI,
                                                                                        KC_HOME,
                                                 KC_SPACE,       KC_BSPACE,             KC_END,    

      // right hand
      KC_RIGHT,           KC_6,            KC_7,          KC_8,          KC_9,     KC_0,             KC_MINUS,
      TG(1),              KC_Y,            KC_U,          KC_I,          KC_O,     KC_P,             KC_BSLASH,
                          KC_H,            KC_J,          KC_K,          KC_L,     LT(2,KC_SCOLON),  GUI_T(KC_QUOTE),
      MT(MOD_MEH, KC_NO), KC_N,            KC_M,          KC_COMMA,      KC_DOT,   RCTL_T(KC_SLASH), KC_RSHIFT,
                                           MO(1),         MO(2),         KC_RGUI,  KC_LALT,          MO(1),

      KC_LALT,            CTL_T(KC_ESCAPE),
      KC_PGUP,
      KC_PGDOWN,          KC_TAB,             KC_ENTER
  ),

  [1] = LAYOUT_ergodox(
      // left hand
      KC_ESCAPE,  KC_F1,    KC_F2,    KC_F3,        KC_F4,        KC_F5,    KC_TRNS,
      KC_TRNS,    KC_EXLM,  KC_AT,    KC_LCBR,      KC_RCBR,      KC_PIPE,  KC_TRNS,
      KC_TRNS,    KC_TRNS,  KC_DLR,   KC_LPRN,      KC_RPRN,      KC_GRAVE,
      KC_TRNS,    KC_PERC,  KC_CIRC,  KC_LBRACKET,  KC_RBRACKET,  KC_TILD,  KC_TRNS,
      KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,      KC_TRNS,

                                                                RGB_MOD,  KC_TRNS,
                                                                          KC_TRNS,
                                                      RGB_VAD,  RGB_VAI,  KC_TRNS,

      // right hand
      KC_TRNS,  KC_F6,    KC_F7,       KC_F8,       KC_F9,        KC_F10,       KC_F11,
      KC_TRNS,  KC_TRNS,  KC_LPRN,     KC_RPRN,     KC_LBRACKET,  KC_RBRACKET,  KC_F12,
                KC_TRNS,  UC(0x00E5),  UC(0x00E4),  UC(0x00F6),      KC_TRNS,      KC_TRNS,
      KC_TRNS,  KC_TRNS,  UC(0x00C5),  UC(0x00C4),  UC(0x00D6),      KC_BSLASH,    KC_TRNS,
                          KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_EQUAL,     KC_TRNS,

      RGB_TOG,  RGB_SLD,
      KC_TRNS,
      KC_TRNS,  RGB_HUD,  RGB_HUI
  ),

  [2] = LAYOUT_ergodox(
      // left hand
      KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_MS_UP,    KC_TRNS,      KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_MS_LEFT,  KC_MS_DOWN,  KC_MS_RIGHT,  KC_TRNS,  
      KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS,  KC_TRNS,
      KC_TRNS,  KC_TRNS,  KC_TRNS,     KC_TRNS,     KC_TRNS,

                                                            KC_TRNS,  KC_TRNS,
                                                                      KC_TRNS,  
                                                  KC_TRNS,  KC_TRNS,  KC_TRNS,
      
      // right hand
      KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,            KC_TRNS,        KC_TRNS,  TO_WIN,
      KC_TRNS,  KC_TRNS,   KC_TRNS,     KC_TRNS,            KC_TRNS,        KC_TRNS,  TO_MAC,
                KC_LEFT,   KC_DOWN,     KC_UP,              KC_RIGHT,       KC_TRNS,  TO_LINUX,
      KC_TRNS,  KC_TRNS,   KC_MS_BTN1,  KC_MS_BTN2,         KC_TRNS,        KC_TRNS,  KC_TRNS,
                           KC_TRNS,     KC_AUDIO_VOL_DOWN,  KC_AUDIO_MUTE,  KC_TRNS,  KC_TRNS,
      
      KC_TRNS,  KC_TRNS,
      KC_TRNS,  
      KC_TRNS,  KC_TRNS,KC_TRNS
  ),

};

const uint16_t PROGMEM fn_actions[] = {
  [1] = ACTION_LAYER_TAP_TOGGLE(1)
};

// leaving this in place for compatibilty with old keymaps cloned and re-compiled.
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
        if (record->event.pressed) {
          SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        }
        break;
      }
    return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      // dynamically generate these.
      case EPRM:
        eeconfig_init();
        return false;
        break;
      case RGB_SLD:
        rgblight_mode(1);
        return false;
        break;
      case AA:
        send_unicode_hex_string("00E5 30CE 0CA0");
        return false;
        break;
      case AE:
        send_unicode_hex_string("00E5 30CE 0CA0");
        return false;
        break;
      case OSLH:
        SEND_STRING("This is a string");
        return false;
        break;
      case TO_LINUX:
        set_unicode_input_mode(UC_LNX);
        return false;
        break;
      case TO_MAC:
        set_unicode_input_mode(UC_OSX);
        return false;
        break;
      case TO_WIN:
        set_unicode_input_mode(UC_WIN);
        return false;
        break;
    }
  }
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {

    uint8_t layer = biton32(state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_3_on();
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }
    return state;

};
