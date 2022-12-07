#pragma once

#include "defines.h"

#include <Arduino.h>

enum SETUP_BUTTONS {
    BUTTON_CANCEL = 10,
    BUTTON_SAVE,
    BUTTON_CWP,
    BUTTON_KEYER,
    #ifdef USE_PDL_POL
        BUTTON_PADDLE,
    #endif
    #ifdef USE_CFG_TOUCH
        BUTTON_TOUCH,
    #endif
    #ifdef USE_TUNE
        BUTTON_TUNE_PWR,
    #endif
    BUTTON_DELAY,
    #ifdef USE_CFG_FREQ
        BUTTON_FREQ,
    #endif
    #ifdef USE_CFG_BFO
        BUTTON_BFO,
    #endif
    #ifdef USE_TX_DIS
        BUTTON_TX_DISABLE,
    #endif
    #ifdef USE_MEMORY
        BUTTON_CLR_MEMORY,
    #endif
};
