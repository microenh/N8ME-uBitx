#pragma once
#include "defines.h"

#include <Arduino.h>

/* value is the position on the screen
 *  0 ..  4 first row 
 *    ..
 * 25 .. 29 last row
 * 
 * value can be changed to move buttons around
 */

enum MAIN_BUTTIONS {
  // top row
  BUTTON_MODE  = 5,
  FREQ_DISP_A1,
  FREQ_DISP_A2,
  FREQ_DISP_B1,
  FREQ_DISP_B2,

  // second row
  BUTTON_RIT   = 10,
  BUTTON_SPLIT,
  BUTTON_STEP,
  #if defined USE_RF_SHIFT || defined USE_RF_SHIFT_STEP
    BUTTON_RF_SHIFT,
  #endif
  #ifdef USE_IF_SHIFT
    BUTTON_IF_SHIFT,
  #endif
    BUTTON_SETUP,
    BUTTON_FINP,
  #ifdef USE_SPOT
    BUTTON_SPOT,
  #endif
  #ifdef USE_LOCK
    BUTTON_LOCK,
  #endif
    BUTTON_CWS,
  #ifdef USE_TUNE
    BUTTON_TUNE,
  #endif
  #ifdef USE_ATTN
    BUTTON_ATTN,
  #endif
  #if defined USE_HAM_BAND || defined USE_BC_BAND
    BUTTON_BAND,
  #endif

  #ifdef USE_MAN_SAVE
    BUTTON_SAVE,
  #endif

  // bottom row
  #ifdef USE_MEMORY
    BUTTON_M1 = 25,
    BUTTON_M2,
    BUTTON_M3,
    BUTTON_M4,
    BUTTON_M5,
  #endif
};
