/* Copyright 2019 Ryota Goto
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

// Defines keycode macros
enum custom_keycodes {
    SSMS_HLTROW = SAFE_RANGE,
    SSMS_COMNTON,
    SSMS_COMNTOFF,
    SSMS_WORDQTE,
    SSMS_LINEQTE,
    SSMS_TOP100,
    SSMS_SELDIST,
    SSMS_ROWNUM,
    SSMS_TEMPEXISTS,
    SSMS_CREATETBL,
    SSMS_INSVALS,
    SSMS_UPDVALS,
    SSMS_DELVALS,
    SSMS_LEFTJOIN,
    SSMS_RIGHTJOIN,
    SSMS_INNJOIN,
    SSMS_FULLJOIN,
    OTLK_DLDATTCHS,
    OTLK_APPTTEAMS,
    OTLK_SRCHFOLDR,
    EXCL_SHORTDT,
    EXCL_CURRNCY,
    EXCL_SELCONTIG,
    EXCL_AUTSZCOLS,
    EXCL_COLSIZE50,
    EXCL_MKPIVTBL,
    EXCL_REPLNULL,
    EXCL_REFRPTQ,
    EXCL_PST,
    EXCL_PSTVALS,
    EXCL_PSTFRMLA,
    EXCL_PSTTRANSP,
    GITC_STATUS,
    GITC_DIFF,
    GITC_SHOW,
    GITC_LOGSTAT,
    GITC_ADDALL,
    GITC_CMTWMSG,
    GITC_MERGE,
    GITC_PULL,
    GITC_PUSHTRNK,
    GITC_CMTAMEND,
    GITC_BRANCH,
    GITC_CHCKOUT,
    GITC_RMTEV,
    GITC_ADDRMT,
    GITC_CLONE,
    GITC_INIT,
    CMDLINE_DIR,
    LAYRNAME_0,
    LAYRNAME_1,
    LAYRNAME_2,
    LAYRNAME_3,
    LAYRNAME_4
};

// Tap Dance declarations
enum {
    TD_ENT_Q,
    TD_NL_EQ,
    TD_CM_BK,
    TD_LYR_0,
    TD_LYR_1,
    TD_LYR_2,
    TD_LYR_3,
    TD_LYR_4
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_ENT_Q] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_Q),
    [TD_NL_EQ] = ACTION_TAP_DANCE_DOUBLE(KC_EQUAL, KC_NLCK),
    [TD_CM_BK] = ACTION_TAP_DANCE_DOUBLE(KC_BSPC, KC_COMM)
};

// Keymap
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ortho_5x4( /* Base numpad */
    // THIS LT SOLUTION IS TEMPORARY TO GET IDENTIFIERS FOR LAYERS.
    LT(4, KC_0)          , TO(1)        , KC_PSLS , KC_PAST  ,
	KC_PPLS              , KC_9         , KC_8    , KC_7     ,
	KC_PMNS              , KC_6         , KC_5    , KC_4     ,
	TD(TD_NL_EQ)         , KC_3         , KC_2    , KC_1     ,
	MT(MOD_LSFT, KC_PENT), TD(TD_CM_BK) , KC_0    , KC_DOT
  ),

  [1] = LAYOUT_ortho_5x4( /* SSMS */ 
    LT(0, KC_1)    , TO(2)    , LSA(KC_UP)   , LCTL(LSFT(KC_U)) ,
    SSMS_HLTROW    , SSMS_COMNTON   , SSMS_WORDQTE , SSMS_LINEQTE    ,
    SSMS_TOP100    , SSMS_SELDIST   , SSMS_ROWNUM  , SSMS_TEMPEXISTS ,
    SSMS_CREATETBL , SSMS_INSVALS   , SSMS_UPDVALS , SSMS_DELVALS    ,
    SSMS_LEFTJOIN  , SSMS_RIGHTJOIN , SSMS_INNJOIN , SSMS_FULLJOIN
  ),
  
  [2] = LAYOUT_ortho_5x4( /* Outlook Navigation*/
    LT(1, KC_2) , TO(3)            , KC_BSPC        , KC_DEL         ,
    KC_LEFT     , KC_UP            , KC_DOWN        , KC_RGHT        ,
    KC_LSFT     , LCTL(LSFT(KC_M)) , OTLK_DLDATTCHS , KC_ENT         ,
    KC_TAB      , LCTL(LSFT(KC_A)) , OTLK_APPTTEAMS , OTLK_SRCHFOLDR ,
    KC_APP      , C(KC_1)          , C(KC_2)        , KC_F9
  ),

  //[3] = LAYOUT_ortho_5x4( /* Outlook message composition */),
  
  [3] = LAYOUT_ortho_5x4( /* Excel */
    LT(2, KC_3)    , TO(4)          , EXCL_SHORTDT   , EXCL_CURRNCY   ,
    KC_LEFT        , KC_UP          , KC_DOWN        , KC_RGHT        ,
    EXCL_SELCONTIG , EXCL_AUTSZCOLS , EXCL_COLSIZE50 , EXCL_MKPIVTBL  ,
    C(KC_X)        , C(KC_C)        , EXCL_REPLNULL  , EXCL_REFRPTQ   ,
    EXCL_PST       , EXCL_PSTVALS   , EXCL_PSTFRMLA  , EXCL_PSTTRANSP
  ),
  
  [4] = LAYOUT_ortho_5x4( /* Git CMD */
    LT(3, KC_4)  , TO(0)        , GITC_STATUS   , GITC_DIFF     ,
    GITC_SHOW    , GITC_LOGSTAT , GITC_ADDALL   , GITC_CMTWMSG  ,
    GITC_MERGE   , GITC_PULL    , GITC_PUSHTRNK , GITC_CMTAMEND ,
    GITC_BRANCH  , GITC_CHCKOUT , GITC_RMTEV    , GITC_ADDRMT   ,
    TD(TD_ENT_Q) , GITC_CLONE   , GITC_INIT     , CMDLINE_DIR
  )

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode) {
      case SSMS_CREATETBL:
        if (record->event.pressed) {
            SEND_STRING("CREATE TABLE ();");
        } else {}
        break;
      case SSMS_DELVALS:
        if (record->event.pressed) {
            SEND_STRING("DELETE FROM WHERE 1=0;"); //we write this with a false condition so we don't accidentally delete any data
        } else {}
        break;
      case SSMS_FULLJOIN:
        if (record->event.pressed) {
            SEND_STRING("FULL JOIN  ON  = "); //move cursor back
        } else {}
        break;
      case SSMS_HLTROW:
        if (record->event.pressed) {
            tap_code16(KC_END);
            tap_code16(LSFT(KC_HOME));
            tap_code16(KC_F5);
        } else {}
        break;
      case SSMS_INNJOIN:
        if (record->event.pressed) {
            SEND_STRING("INNER JOIN  ON  = ");
        } else {}
        break;
      case SSMS_INSVALS:
        if (record->event.pressed) {
            SEND_STRING("INSERT INTO  VALUES (),();");
        } else {}
        break;
      case SSMS_LEFTJOIN:
        if (record->event.pressed) {
            SEND_STRING("LEFT JOIN  ON  = ");
        } else {}
        break;
      case SSMS_RIGHTJOIN:
        if (record->event.pressed) {
            SEND_STRING("RIGHT JOIN  ON  = ");
        } else {}
        break;
      case SSMS_ROWNUM:
        if (record->event.pressed) {
            SEND_STRING("ROW_NUMBER() OVER (PARTITION BY  ORDER BY  ) AS ");
        } else {}
        break;
      case SSMS_SELDIST:
        if (record->event.pressed) {
            SEND_STRING("SELECT DISTINCT  FROM ");
        } else {}
        break;
      case SSMS_TEMPEXISTS:
        if (record->event.pressed) {
            SEND_STRING("IF OBJECT_ID('tempdb..#') IS NOT NULL DROP TABLE #");
        } else {}
        break;
      case SSMS_COMNTON:
        if (record->event.pressed) {
            SEND_STRING("Turn comment on");
        } else {}
        break;
      case SSMS_COMNTOFF:
        if (record->event.pressed) {
            SEND_STRING("Turn comment off");
        } else {}
        break;
      case SSMS_TOP100:
        if (record->event.pressed) {
            SEND_STRING("SELECT TOP 100 * FROM ");
        } else {}
        break;
      case SSMS_UPDVALS:
        if (record->event.pressed) {
            SEND_STRING("UPDATE  SET =  WHERE 1=0;");
        } else {}
        break;
      case SSMS_WORDQTE:
        if (record->event.pressed) {
            tap_code16(LCTL(KC_RIGHT));
            tap_code16(KC_QUOT);
            tap_code16(LCTL(KC_LEFT));
            tap_code16(LCTL(KC_LEFT));
            tap_code16(KC_QUOT);
        } else {}
        break;
      case SSMS_LINEQTE:
        if (record->event.pressed) {
            tap_code16(KC_END);
            tap_code16(KC_QUOT);
            tap_code16(KC_HOME);
            tap_code16(KC_QUOT);
        } else {}
        break;
      case OTLK_APPTTEAMS:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "htm");
        } else {}
        break;
      case OTLK_DLDATTCHS:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_ENTER) SS_TAP(X_LALT) "hy" SS_TAP(X_ENTER));
        } else {}
        break;
      case OTLK_SRCHFOLDR:
        if (record->event.pressed){
            tap_code16(LCTL(LALT(KC_K)));
        } else {}
        break;
      case GITC_ADDALL:
        if (record->event.pressed) {
            SEND_STRING("git add ." SS_TAP(X_ENTER));
        } else {}
        break;
      case GITC_ADDRMT:
        if (record->event.pressed) {
            SEND_STRING("git remote add ");
        } else {}
        break;
      case GITC_BRANCH:
        if (record->event.pressed) {
            SEND_STRING("git branch ");
        } else {}
        break;
      case GITC_CHCKOUT:
        if (record->event.pressed) {
            SEND_STRING("git checkout ");
        } else {}
        break;
      case GITC_CLONE:
        if (record->event.pressed) {
            SEND_STRING("git clone ");
        } else {}
        break;
      case GITC_CMTAMEND:
        if (record->event.pressed) {
            SEND_STRING("git commit --amend" SS_TAP(X_ENTER));
        } else {}
        break;
      case GITC_CMTWMSG:
        if (record->event.pressed) {
            SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
        } else {}
        break;
      case GITC_DIFF:
        if (record->event.pressed) {
            SEND_STRING("git diff" SS_TAP(X_ENTER));
        } else {}
        break;
      case GITC_INIT:
        if (record->event.pressed) {
            SEND_STRING("git init" SS_TAP(X_ENTER));
        } else {}
        break;
      case GITC_LOGSTAT:
        if (record->event.pressed) {
            SEND_STRING("git log --stat" SS_TAP(X_ENTER));
        } else {}
        break;
      case GITC_MERGE:
        if (record->event.pressed) {
            SEND_STRING("git merge ");
        } else {}
        break;
      case GITC_PULL:
        if (record->event.pressed) {
            SEND_STRING("git pull" SS_TAP(X_ENTER));
        } else {}
        break;
      case GITC_PUSHTRNK:
        if (record->event.pressed) {
            SEND_STRING("git push origin trunk");
        } else {}
        break;
      case GITC_RMTEV:
        if (record->event.pressed) {
            SEND_STRING("git remote -v" SS_TAP(X_ENTER));
        } else {}
        break;
      case GITC_SHOW:
        if (record->event.pressed) {
            SEND_STRING("git show [commit-id]");
            int number;
            for(number=1;number<=12;number++)	//for loop to execute 11 times (highlight whole of [commit-id]
            {
                tap_code16(LSFT(KC_LEFT));
            }
        } else {}
        break;
      case GITC_STATUS:
        if (record->event.pressed) {
            SEND_STRING("git status" SS_TAP(X_ENTER));
        } else {}
        break;
      case EXCL_AUTSZCOLS:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "hoi");
        } else {}
        break;
      case EXCL_COLSIZE50:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "how50" SS_TAP(X_ENTER));
        } else {}
        break;
      case EXCL_CURRNCY:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "hnCurrency" SS_TAP(X_ENTER));
        } else {}
        break;
      case EXCL_MKPIVTBL:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "nv" SS_TAP(X_ENTER));
        } else {}
        break;
      case EXCL_REPLNULL:
        if (record->event.pressed){
            SEND_STRING(SS_LCTL("f") "NULL" SS_TAP(X_TAB) SS_TAP(X_ESC) SS_TAP(X_LALT) "hfdr" SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_ENTER));
        } else {}
        break;
      case EXCL_PST:
        if (record->event.pressed){
            tap_code16(LCTL(KC_V));
            tap_code16(KC_DOWN);
        } else {}
        break;
      case EXCL_PSTFRMLA:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "hvf" SS_TAP(X_DOWN));
        } else {}
        break;
      case EXCL_PSTTRANSP:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "hvt" SS_TAP(X_DOWN));
        } else {}
        break;
      case EXCL_PSTVALS:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "hvv" SS_TAP(X_DOWN));
        } else {}
        break;
      case EXCL_REFRPTQ:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "ara");
        } else {}
        break;
      case EXCL_SELCONTIG:
        if (record->event.pressed){
            tap_code16(LCTL(KC_UP));
            tap_code16(LCTL(KC_LEFT));
            tap_code16(LSFT(LCTL(KC_RIGHT)));
            tap_code16(LSFT(LCTL(KC_DOWN)));
        } else {}
        break;
      case EXCL_SHORTDT:
        if (record->event.pressed){
            SEND_STRING(SS_TAP(X_LALT) "hnShort Date" SS_TAP(X_ENTER));
        } else {}
        break;
      case CMDLINE_DIR:
        if (record->event.pressed) {
            SEND_STRING("dir" SS_TAP(X_ENTER));
        } else {}
        break;
      case LAYRNAME_0:
        if (record->event.pressed) {
            SEND_STRING("Numpad Layer");
        } else {}
        break;
      case LAYRNAME_1:
        if (record->event.pressed) {
            SEND_STRING("SSMS Layer");
        } else {}
        break;
      case LAYRNAME_2:
        if (record->event.pressed) {
            SEND_STRING("Outlook Layer");
        } else {}
        break;
      case LAYRNAME_3:
        if (record->event.pressed) {
            SEND_STRING("Excel Layer");
        } else {}
        break;
      case LAYRNAME_4:
        if (record->event.pressed) {
            SEND_STRING("Git Layer");
        } else {}
        break;
  }
  return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
