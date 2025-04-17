/* Copyright 2023 damga123 <thomas@splitkb.com>
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

enum layers {
    _QWERTY = 0,
    _GAME,
    _NAV,
    _SYM,
    _FUNCTION,
};


// Aliases for readability
#define QWERTY   DF(_QWERTY)
#define GAME     TG(_GAME)
#define SYM      MO(_SYM)
#define NAV      MO(_NAV)
#define FKEYS    MO(_FUNCTION)

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_L):
            return TAPPING_TERM - 30;
        case SFT_T(KC_S):
            return TAPPING_TERM - 30;
        case LT(_SYM, KC_D):
            return TAPPING_TERM - 30;
        case LT(_SYM, KC_K):
            return TAPPING_TERM - 30;
        default:
            return TAPPING_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//    ┌──────┬──────────┬──────────┬─────────────┬──────┬──────┐                               ┌─────┬─────────┬─────────────┬──────────┬──────────┬──────┐
//    │ esc  │    q     │    w     │      e      │  r   │  t   │                               │  y  │    u    │      i      │    o     │    p     │ bspc │
//    ├──────┼──────────┼──────────┼─────────────┼──────┼──────┤                               ├─────┼─────────┼─────────────┼──────────┼──────────┼──────┤
//    │ tab  │ CTL_T(a) │ SFT_T(s) │ LT(_SYM, d) │  f   │  g   │                               │  h  │    j    │ LT(_SYM, k) │ SFT_T(l) │ CTL_T(;) │  '   │
//    ├──────┼──────────┼──────────┼─────────────┼──────┼──────┼─────┬──────┐   ┌───────┬──────┼─────┼─────────┼─────────────┼──────────┼──────────┼──────┤
//    │ lsft │    z     │    x     │      c      │  v   │  b   │  [  │ caps │   │ FKEYS │  ]   │  n  │    m    │      ,      │    .     │    /     │ rsft │
//    └──────┴──────────┴──────────┼─────────────┼──────┼──────┼─────┼──────┤   ├───────┼──────┼─────┼─────────┼─────────────┼──────────┴──────────┴──────┘
//                                 │    mply     │ lgui │ lalt │ spc │ NAV  │   │  del  │ bspc │ ent │ QK_LEAD │     app     │
//                                 └─────────────┴──────┴──────┴─────┴──────┘   └───────┴──────┴─────┴─────────┴─────────────┘
[_QWERTY] = LAYOUT(
  KC_ESC  , KC_Q        , KC_W        , KC_E           , KC_R    , KC_T    ,                                            KC_Y   , KC_U    , KC_I           , KC_O        , KC_P           , KC_BSPC,
  KC_TAB  , CTL_T(KC_A) , SFT_T(KC_S) , LT(_SYM, KC_D) , KC_F    , KC_G    ,                                            KC_H   , KC_J    , LT(_SYM, KC_K) , SFT_T(KC_L) , CTL_T(KC_SCLN) , KC_QUOT,
  KC_LSFT , KC_Z        , KC_X        , KC_C           , KC_V    , KC_B    , KC_LBRC , KC_CAPS ,     FKEYS  , KC_RBRC , KC_N   , KC_M    , KC_COMM        , KC_DOT      , KC_SLSH        , KC_RSFT,
                                        KC_MPLY        , KC_LGUI , KC_LALT , KC_SPC  , NAV     ,     KC_DEL , KC_BSPC , KC_ENT , QK_LEAD , KC_APP
),

//    ┌──────┬───┬───┬──────┬──────┬──────┐                               ┌─────┬──────┬─────┬───┬───┬──────┐
//    │ esc  │ q │ w │  e   │  r   │  t   │                               │  y  │  u   │  i  │ o │ p │ bspc │
//    ├──────┼───┼───┼──────┼──────┼──────┤                               ├─────┼──────┼─────┼───┼───┼──────┤
//    │ tab  │ a │ s │  d   │  f   │  g   │                               │  h  │  j   │  k  │ l │ ; │  '   │
//    ├──────┼───┼───┼──────┼──────┼──────┼─────┬──────┐   ┌───────┬──────┼─────┼──────┼─────┼───┼───┼──────┤
//    │ lsft │ z │ x │  c   │  v   │  b   │  [  │ caps │   │ FKEYS │  ]   │  n  │  m   │  ,  │ . │ / │ rsft │
//    └──────┴───┴───┼──────┼──────┼──────┼─────┼──────┤   ├───────┼──────┼─────┼──────┼─────┼───┴───┴──────┘
//                   │ mply │ lctl │ lalt │ spc │ SYM  │   │  del  │ bspc │ ent │ lgui │ NAV │
//                   └──────┴──────┴──────┴─────┴──────┘   └───────┴──────┴─────┴──────┴─────┘
[_GAME] = LAYOUT(
  KC_ESC  , KC_Q , KC_W , KC_E    , KC_R    , KC_T    ,                                            KC_Y   , KC_U    , KC_I    , KC_O   , KC_P    , KC_BSPC,
  KC_TAB  , KC_A , KC_S , KC_D    , KC_F    , KC_G    ,                                            KC_H   , KC_J    , KC_K    , KC_L   , KC_SCLN , KC_QUOT,
  KC_LSFT , KC_Z , KC_X , KC_C    , KC_V    , KC_B    , KC_LBRC , KC_CAPS ,     FKEYS  , KC_RBRC , KC_N   , KC_M    , KC_COMM , KC_DOT , KC_SLSH , KC_RSFT,
                          KC_MPLY , KC_LCTL , KC_LALT , KC_SPC  , SYM     ,     KC_DEL , KC_BSPC , KC_ENT , KC_LGUI , NAV
),

//    ┌─────┬──────┬──────┬─────┬─────┬─────┐                           ┌──────┬──────┬──────┬──────┬─────┬─────┐
//    │     │      │      │     │     │     │                           │ home │ pgdn │ pgup │ end  │     │     │
//    ├─────┼──────┼──────┼─────┼─────┼─────┤                           ├──────┼──────┼──────┼──────┼─────┼─────┤
//    │     │ lctl │ lsft │     │     │     │                           │ left │ down │  up  │ rght │     │     │
//    ├─────┼──────┼──────┼─────┼─────┼─────┼─────┬─────┐   ┌─────┬─────┼──────┼──────┼──────┼──────┼─────┼─────┤
//    │     │      │      │     │     │     │     │     │   │     │     │      │      │      │      │     │     │
//    └─────┴──────┴──────┼─────┼─────┼─────┼─────┼─────┤   ├─────┼─────┼──────┼──────┼──────┼──────┴─────┴─────┘
//                        │     │     │     │     │     │   │     │     │      │      │      │
//                        └─────┴─────┴─────┴─────┴─────┘   └─────┴─────┴──────┴──────┴──────┘
[_NAV] = LAYOUT(
  _______ , _______ , _______ , _______ , _______ , _______ ,                                             KC_HOME , KC_PGDN , KC_PGUP , KC_END   , _______ , _______,
  _______ , KC_LCTL , KC_LSFT , _______ , _______ , _______ ,                                             KC_LEFT , KC_DOWN , KC_UP   , KC_RIGHT , _______ , _______,
  _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______ , _______  , _______ , _______,
                                _______ , _______ , _______ , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
),

//    ┌───┬───┬───┬──────┬──────┬──────┐                                ┌─────┬──────┬─────┬────┬───┬───┐
//    │ ` │ @ │ 7 │  8   │  9   │  #   │                                │  -  │  &   │  ?  │ "" │ $ │ = │
//    ├───┼───┼───┼──────┼──────┼──────┤                                ├─────┼──────┼─────┼────┼───┼───┤
//    │ ~ │ ! │ 4 │  5   │  6   │  %   │                                │  ^  │  :   │  /  │ (  │ ) │ + │
//    ├───┼───┼───┼──────┼──────┼──────┼───┬───────────┐   ┌─────┬──────┼─────┼──────┼─────┼────┼───┼───┤
//    │ | │ \ │ 1 │  2   │  3   │  {   │ [ │           │   │     │  ]   │  }  │  _   │  ,  │ .  │ ; │ * │
//    └───┴───┴───┼──────┼──────┼──────┼───┼───────────┤   ├─────┼──────┼─────┼──────┼─────┼────┴───┴───┘
//                │ lalt │ lgui │ lctl │ 0 │ C_S_T(no) │   │ del │ bspc │ ent │ lsft │     │
//                └──────┴──────┴──────┴───┴───────────┘   └─────┴──────┴─────┴──────┴─────┘
[_SYM] = LAYOUT(
  KC_GRV  , KC_AT   , KC_7 , KC_8    , KC_9    , KC_HASH ,                                                  KC_MINS , KC_AMPR , KC_QUES , KC_DQUO , KC_DLR  , KC_EQL ,
  KC_TILD , KC_EXLM , KC_4 , KC_5    , KC_6    , KC_PERC ,                                                  KC_CIRC , KC_COLN , KC_SLSH , KC_LPRN , KC_RPRN , KC_PLUS,
  KC_PIPE , KC_BSLS , KC_1 , KC_2    , KC_3    , KC_LCBR , KC_LBRC , _______      ,     _______ , KC_RBRC , KC_RCBR , KC_UNDS , KC_COMM , KC_DOT  , KC_SCLN , KC_ASTR,
                             KC_LALT , KC_LGUI , KC_LCTL , KC_0    , C_S_T(KC_NO) ,     KC_DEL  , KC_BSPC , KC_ENT  , KC_LSFT , _______
),

//    ┌─────┬────────┬────┬─────┬─────┬──────┐                           ┌─────┬──────┬──────┬──────┬──────┬─────┐
//    │     │ QWERTY │ f9 │ f10 │ f11 │ f12  │                           │     │      │      │      │      │     │
//    ├─────┼────────┼────┼─────┼─────┼──────┤                           ├─────┼──────┼──────┼──────┼──────┼─────┤
//    │     │  GAME  │ f5 │ f6  │ f7  │  f8  │                           │     │ rsft │ rctl │ lalt │ rgui │     │
//    ├─────┼────────┼────┼─────┼─────┼──────┼─────┬─────┐   ┌─────┬─────┼─────┼──────┼──────┼──────┼──────┼─────┤
//    │     │        │ f1 │ f2  │ f3  │  f4  │     │     │   │     │     │     │      │      │      │      │     │
//    └─────┴────────┴────┼─────┼─────┼──────┼─────┼─────┤   ├─────┼─────┼─────┼──────┼──────┼──────┴──────┴─────┘
//                        │     │     │ lalt │     │     │   │     │     │     │      │      │
//                        └─────┴─────┴──────┴─────┴─────┘   └─────┴─────┴─────┴──────┴──────┘
[_FUNCTION] = LAYOUT(
  _______ , QWERTY  , KC_F9 , KC_F10  , KC_F11  , KC_F12  ,                                             _______ , _______ , _______ , _______ , _______ , _______,
  _______ , GAME    , KC_F5 , KC_F6   , KC_F7   , KC_F8   ,                                             _______ , KC_RSFT , KC_RCTL , KC_LALT , KC_RGUI , _______,
  _______ , _______ , KC_F1 , KC_F2   , KC_F3   , KC_F4   , _______ , _______ ,     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______,
                              _______ , _______ , KC_LALT , _______ , _______ ,     _______ , _______ , _______ , _______ , _______
)
};

void leader_start_user(void) {
}

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_S, KC_A)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("ss"));
}
}
