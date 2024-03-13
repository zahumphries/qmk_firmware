#include QMK_KEYBOARD_H

enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
};

enum custom_keycodes {
    KC_LDSK,
    KC_RDSK,
    KC_PRVWD,
    KC_NXTWD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | MUTE |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * | Ctrl | RGB  | GUI  | Alt  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
    * `-----------------------------------------------------------------------------------'
    */
    [_QWERTY] = LAYOUT_preonic_grid(
    KC_MUTE,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_ESC,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL,  RGB_TOG, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 | Del  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |   ~  |      | PWrd |  Up  | NWrd | TERM |      |      |      |   {  |   }  | F11  |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | CAPS | Home | Left | Down | Right|  End |      |   _  |   +  |   [  |   ]  | F12  |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      | Cut  | Copy | Paste|      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |    Play     |      | Home | Pg Dn| Pg Up| End  |
    * `-----------------------------------------------------------------------------------'
    */
    [_LOWER] = LAYOUT_preonic_grid(
    _______, KC_F1,    KC_F2,      KC_F3,     KC_F4,       KC_F5,      KC_F6,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL,
    KC_TILD, _______,  C(KC_LEFT), KC_UP,     C(KC_RIGHT), C(KC_TILD), KC_CIRC,  KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_F11,
    KC_CAPS, KC_HOME,  KC_LEFT,    KC_DOWN,   KC_RIGHT,    KC_END,     _______,  KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_F12,
    _______, _______,  S(KC_DEL),  C(KC_INS), S(KC_INS),   _______,    _______,  _______, _______, _______, _______, _______,
    _______, _______,  _______,    _______,   _______,     KC_MPLY,    KC_MPLY,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),

    /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      | DWord|
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |   `  |      | LDsk | MVUP | RDsk |      |      |      |      |      |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |CAPWRD|      |      | MVDN |      |      |      |   -  |   =  |      |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      | Prev | Vol- | Vol+ | Next |
    * `-----------------------------------------------------------------------------------'
    */
    [_RAISE] = LAYOUT_preonic_grid(
    _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, C(KC_DEL),
    KC_GRV,  _______, KC_LDSK, A(KC_UP),   KC_RDSK, _______, _______, _______, _______, _______, _______, _______,
    CW_TOGG, _______, _______, A(KC_DOWN), _______, _______, _______, KC_MINS, KC_EQL,  _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______,    _______, _______, _______, _______, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
    ),

    /* Adjust (Lower + Raise)
    * ,-----------------------------------------------------------------------------------.
    * |      |      |      |      |      |      |      |      |      |      |      |  CAD |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      | Reset| Debug|      |      |      |      |      |      |      |      |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * |      |      |      |      |      |AGnorm|AGswap|Qwerty|      |      |      |      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |      |      |      |      |      |      |MACWIN|      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |      |      |      |      |      |             |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
    [_ADJUST] = LAYOUT_preonic_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, C(A(KC_DEL)),
    _______, QK_BOOT, DB_TOGG, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,
    _______, _______, _______, _______, _______,  AG_NORM, AG_SWAP, QWERTY, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, CG_TOGG, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
          case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            return false;
            break;
        case KC_NXTWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            return false;
            break;
        case KC_LDSK:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_MASK_CG));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_MASK_CG));
                    unregister_code(KC_LEFT);
                }
            }
            return false;
            break;
        case KC_RDSK:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LGUI));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_MASK_CG));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LGUI));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_MASK_CG));
                    unregister_code(KC_RIGHT);
                }
            }
            return false;
            break;
      }
    return true;
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        register_code(KC_VOLU);
        unregister_code(KC_VOLU);
    } else {
        register_code(KC_VOLD);
        unregister_code(KC_VOLD);
    }
    return false;
}

// Light all 9 LEDs starting with LED 0
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 9, HSV_CYAN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
