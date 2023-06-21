/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#ifdef AUDIO_ENABLE
#    include "muse.h"
#endif

enum planck_layers {
  _MACOS,
  _WINDOWS,
  _LOWER,
  _RAISE,
  _MACCMD,
  _WINCMD,
  _GAMING,
  _ADJUST
};

enum planck_keycodes {
  MACOS = SAFE_RANGE, MAC_TAB, MAC_C, MAC_V, MAC_X, MAC_Q, MAC_W, MAC_F, MAC_T, MAC_Z, MAC_SCREEN, MAC_BLOCK,
  MAC_L, MAC_R, MAC_RGHT, MAC_LEFT, MAC_SPC, MAC_MINUS, MAC_PLUS, MAC_FSIZE, MAC_J, MAC_S, MAC_E, MAC_D, MAC_G,
  WINDOWS
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MACCMD MO(_MACCMD)
#define WINCMD MO(_WINCMD)
#define GAMING MO(_GAMING)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* MacOS
   * ,-------------------------------------------------------------------------------------------------.
   * |  Esc  |   Q   |   W   |    E    |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | Bksp  |
   * |-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |  Tab  |   A   |   S   |    D    |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |
   * |-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Shift |   Z   |   X   |    C    |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | Shift |
   * |-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Ctrl  | Brite |  Alt  | MacCMD  | Lower |     Space     | Raise |  Alt  | XXXXX | XXXXX | Enter |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_MACOS] = LAYOUT_planck_grid(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
      KC_LCTL, XXXXXXX, KC_LOPT, MACCMD,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_ROPT, XXXXXXX, XXXXXXX, KC_ENT
  ),

  /* MacOS Command
   * ,-----------------------------------------------------------------------------------------------.
   * | XXXXX |   Q   |   W   | XXXXX |   R   |   T   | XXXXX | XXXXX | XXXXX | Minus | Plus  | FSize |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |  Tab  | XXXXX |   S   | XXXXX |   F   | XXXXX | XXXXX | Left  | XXXXX |   L   | Right | XXXXX |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | XXXXX | XXXXX |   X   |   C   |   V   | XXXXX | XXXXX | XXXXX | XXXXX | XXXXX | XXXXX | XXXXX |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | XXXXX | XXXXX | XXXXX |       |       |     Space     |       | XXXXX | XXXXX | XXXXX | XXXXX |
   * `-----------------------------------------------------------------------------------------------'
   */
  [_MACCMD] = LAYOUT_planck_grid(
      MAC_SCREEN, MAC_Q,    MAC_W,    MAC_E,    MAC_R,    MAC_T,    XXXXXXX,  XXXXXXX,  XXXXXXX,  MAC_MINUS,  MAC_PLUS, MAC_FSIZE,
      MAC_TAB,    XXXXXXX,  MAC_S,    MAC_D,    MAC_F,    MAC_G,    XXXXXXX,  MAC_J,    XXXXXXX,  MAC_L,      XXXXXXX,  XXXXXXX,
      XXXXXXX,    MAC_Z,    MAC_X,    MAC_C,    MAC_V,    XXXXXXX,  XXXXXXX,  MAC_LEFT, XXXXXXX,  XXXXXXX,    MAC_RGHT, XXXXXXX,
      MAC_BLOCK,  XXXXXXX,  XXXXXXX,  _______,  _______,  MAC_SPC,  MAC_SPC,  _______,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX
  ),

  /* Windows
   * ,-------------------------------------------------------------------------------------------------.
   * |  Esc  |   Q   |   W   |    E    |   R   |   T   |   Y   |   U   |   I   |   O   |   P   | Bksp  |
   * |-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |  Tab  |   A   |   S   |    D    |   F   |   G   |   H   |   J   |   K   |   L   |   ;   |   '   |
   * |-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Shift |   Z   |   X   |    C    |   V   |   B   |   N   |   M   |   ,   |   .   |   /   | Shift |
   * |-------+-------+-------+---------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Ctrl  | Brite |  Alt  | WinCMD  | Lower |     Space     | Raise |  Alt  | XXXXX | XXXXX | Enter |
   * `-------------------------------------------------------------------------------------------------'
   */
  [_WINDOWS] = LAYOUT_planck_grid(
      KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
      KC_LCTL, XXXXXXX, KC_LALT, WINCMD,  LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LALT, XXXXXXX, XXXXXXX, KC_ENT
  ),

  /* Gaming
   * ,-----------------------------------------------------------------------------------------------.
   * |  Esc  |       |   Q   |   W   |   E   |   R   |   T   |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |  Tab  |       |   A   |   S   |   D   |   F   |   G   |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Shift |       |   Z   |   X   |   C   |   V   |   B   |       |       |       |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Ctrl  |       |       |  Alt  | Lower |     Space     |       |       |       |       |       |
   * `-----------------------------------------------------------------------------------------------'
   */
  [_GAMING] = LAYOUT_planck_grid(
      KC_ESC,   XXXXXXX,  KC_Q,     KC_W,     KC_E,   KC_R,   KC_T,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      KC_TAB,   XXXXXXX,  KC_A,     KC_S,     KC_D,   KC_F,   KC_G,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      KC_LSFT,  XXXXXXX,  KC_Z,     KC_X,     KC_C,   KC_V,   KC_B,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,
      KC_LCTL,  XXXXXXX,  XXXXXXX,  KC_LALT,  LOWER,  KC_SPC, KC_SPC, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
  ),

  /* Lower
   * ,-----------------------------------------------------------------------------------------------.
   * |       |   7   |   8   |   9   |   0   |   #   |   ^   |   &   |   *   |   (   |   )   | Bksp  |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |   4   |   5   |   6   |   !   |   $   |   \   |   -   |   +   |   {   |   }   |   `   |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |   1   |   2   |   3   |   @   |   %   |   |   |   _   |   =   |   [   |   ]   |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |       |       |       |       |       |               |       | Next  | Vol-  | Vol+  | Play  |
   * `-----------------------------------------------------------------------------------------------'
   */
  [_LOWER] = LAYOUT_planck_grid(
      _______,  KC_7,     KC_8,     KC_9,     KC_0,     KC_HASH,  KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN, KC_RPRN, KC_DEL,
      _______,  KC_4,     KC_5,     KC_6,     KC_EXLM,  KC_DLR,   KC_BSLS,  KC_MINS,  KC_PLUS,  KC_LCBR, KC_RCBR, KC_GRV,
      _______,  KC_1,     KC_2,     KC_3,     KC_AT,    KC_PERC,  KC_PIPE,  KC_UNDS,  KC_EQL,   KC_LBRC, KC_RBRC, XXXXXXX, 
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_MNXT,  KC_VOLD, KC_VOLU, KC_MPLY
  ),

  /* Raise
   * ,-----------------------------------------------------------------------------------------------.
   * |  F1   |  F2   |  F3   |  F4   |  F5   |  F6   |  F7   |  F8   |  F9   |  F10  |  F11  |  F12  |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * |  Tab  |       |       |       |       |       |       | Left  | Down  |  Up   | Right |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Shift |       |       |       |       |       |       |       | Pg Up | Pg Dn |       |       |
   * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
   * | Ctrl  |       |       |       |       |               |       |       |       |       |       |
   * `-----------------------------------------------------------------------------------------------'
   */
  [_RAISE] = LAYOUT_planck_grid(
      KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,    KC_F12,
      _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXXXXXX,
      _______,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_PGUP,  KC_PGDN,  XXXXXXX,  XXXXXXX,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
  ),

  /* Adjust (Lower + Raise)
   *                      v------------------------RGB CONTROL--------------------v
   * ,-----------------------------------------------------------------------------------.
   * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|MacOS | Win  | Game |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |             |      |      |      |      |      |
   * `-----------------------------------------------------------------------------------'
   */
  [_ADJUST] = LAYOUT_planck_grid(
      _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
      _______, _______, MU_NEXT, AU_ON,   AU_OFF,  MU_ON,   MU_OFF,  MACOS,   WINDOWS, GAMING,  _______, _______,
      _______, AU_PREV, AU_NEXT, XXXXXXX, CK_ON,   MI_ON,   MI_OFF,  AG_NORM, CK_DOWN, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
  )

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MACOS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_MACOS);
      }
      return false;
      break;
    case WINDOWS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WINDOWS);
      }
      return false;
      break;
    case MAC_TAB:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_TAB);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_C:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_C);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_V:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_V);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_X:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_X);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_Z:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_Z);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_F:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_F);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_Q:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_Q);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_W:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_W);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_T:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_T);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_L:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_L);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_R:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_R);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_RGHT:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        tap_code(KC_RGHT);
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LALT);
      }
      return false;
      break;
    case MAC_LEFT:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LALT);
        tap_code(KC_LEFT);
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LALT);
      }
      return false;
      break; 
    case MAC_MINUS:
      if (record->event.pressed) {
        register_code(KC_LGUI); 
        tap_code(KC_LSFT);
        tap_code(KC_MINS);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_FSIZE:
      if (record->event.pressed) {
        register_code(KC_LGUI); 
        tap_code(KC_LSFT);
        tap_code(KC_0);
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_SPC:
      if (record->event.pressed) {
        register_code(KC_LGUI); 
        tap_code(KC_SPC); 
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_J:
      if (record->event.pressed) {
        register_code(KC_LGUI); 
        tap_code(KC_J); 
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_S:
      if (record->event.pressed) {
        register_code(KC_LGUI); 
        tap_code(KC_S); 
      } else {
        unregister_code(KC_LGUI);
      }
      return false;
      break;
    case MAC_SCREEN:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap_code(KC_5); 
      } else {
        unregister_code(KC_LGUI);
        unregister_code(KC_LSFT);
      }
      return false;
      break;
    case MAC_D:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_D); 
      } else {
        unregister_code(KC_LGUI); 
      }
      return false;
      break;
    case MAC_E:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        tap_code(KC_E); 
      } else {
        unregister_code(KC_LGUI); 
      }
      return false;
      break;
    case MAC_BLOCK:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LCTL);
        tap_code(KC_Q); 
      } else {
        unregister_code(KC_LGUI); 
        unregister_code(KC_LCTL); 
      }
      return false;
      break;
    case MAC_G:
      if (record->event.pressed) {
        register_code(KC_LGUI);
        register_code(KC_LSFT);
        tap_code(KC_T); 
      } else {
        unregister_code(KC_LGUI); 
        unregister_code(KC_LSFT); 
      }
      return false;
      break;
  }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
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
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
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
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
    case MACCMD:
    case WINCMD:
      return false;
    default:
      return true;
  }
}
