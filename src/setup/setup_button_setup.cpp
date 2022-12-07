#include "setup.h"
#include "setup_buttons.h"
#include "loop_master.h"
#include "defines.h"

void setup_loop::button_setup(void) {
  all_buttons    =
  draw_buttons   = BUTTON_BIT(BUTTON_DELAY)
                 #ifdef USE_CFG_BFO
                 | BUTTON_BIT(BUTTON_BFO)
                 #endif
                 #ifdef USE_CFG_FREQ
                 | BUTTON_BIT(BUTTON_FREQ)
                 #endif
                 | BUTTON_BIT(BUTTON_KEYER)
                 #ifdef USE_CFG_TOUCH
                 | BUTTON_BIT(BUTTON_TOUCH)
                 #endif
                 #ifdef USE_PDL_POL
                 | BUTTON_BIT(BUTTON_PADDLE)
                 #endif
                 | BUTTON_BIT(BUTTON_SAVE)
                 #ifdef USE_TUNE
                 | BUTTON_BIT(BUTTON_TUNE_PWR)
                 #endif
                 #ifdef USE_TX_DIS
                 | BUTTON_BIT(BUTTON_TX_DISABLE)
                 #endif
                 | BUTTON_BIT(BUTTON_CWP)
                 | BUTTON_BIT(BUTTON_CANCEL)
                 ;
                
  twoline_buttons = BUTTON_BIT(BUTTON_DELAY)
                  #ifdef USE_CFG_FREQ
                  | BUTTON_BIT(BUTTON_FREQ)
                  #endif
                  #ifdef USE_PDL_POL
                  | BUTTON_BIT(BUTTON_PADDLE)
                  #endif
                  #ifdef USE_CFG_BFO
                  | BUTTON_BIT(BUTTON_BFO)
                  #endif
                  #ifdef USE_CFG_TOUCH
                  | BUTTON_BIT(BUTTON_TOUCH)
                  #endif
                  #ifdef USE_TUNE
                  | BUTTON_BIT(BUTTON_TUNE_PWR)
                  #endif
                  #ifdef USE_TX_DIS
                  | BUTTON_BIT(BUTTON_TX_DISABLE)
                  #endif
                  | BUTTON_BIT(BUTTON_CWP)
                  | BUTTON_BIT(BUTTON_KEYER)
                  ;

  textsize1_buttons = BUTTON_BIT(BUTTON_CANCEL)
                    | BUTTON_BIT(BUTTON_SAVE)
                    ;
}