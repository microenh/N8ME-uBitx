#include "setup.h"
#include "setup_buttons.h"
#include "radio.h"
#include "main_loop.h"
#include "touchscreen_calibration.h"


void setup_loop::touch_release(const byte button) {
  switch(button) {
    #ifdef USE_PDL_POL
    case BUTTON_PADDLE:
      radio_obj.toggle_paddle_polarity();
      break;
    #endif

    case BUTTON_SAVE:
      radio_obj.clear_setup_highlights();
      radio_obj.write_eeprom();  
      next = &loop_main;
      break;

    case BUTTON_CANCEL:
      radio_obj.clear_setup_highlights();
      radio_obj.restore_settings();
      next = &loop_main;
      break;

    case BUTTON_KEYER:
      radio_obj.inc_keyer();
      break;

    #ifdef USE_TX_DIS
    case BUTTON_TX_DISABLE:
      radio_obj.toggle_tx_disable();
      break;
    #endif

    #ifdef USE_CFG_TOUCH
    case BUTTON_TOUCH:
      next = &loop_ts_calibration;
      break;
    #endif

    case BUTTON_CWP:
      radio_obj.toggle_cw_pitch();
      break;

    case BUTTON_DELAY:
      radio_obj.toggle_cw_delay();
      break;

    #ifdef USE_CFG_BFO
    case BUTTON_BFO:
      radio_obj.toggle_bfo_cal();
      break;
    #endif

    #ifdef USE_CFG_FREQ
    case BUTTON_FREQ:
      radio_obj.toggle_freq_cal();
      break;
    #endif

    #ifdef USE_TUNE
    case BUTTON_TUNE_PWR:
      radio_obj.toggle_tune_pwr();
      break;
    #endif

    case SWITCH:
      if (radio_obj.in_cw_delay) radio_obj.toggle_cw_delay();
      if (radio_obj.in_cw_pitch) radio_obj.toggle_cw_pitch();
      #ifdef USE_CFG_BFO
        if (radio_obj.in_bfo_cal)  radio_obj.toggle_bfo_cal();
      #endif
      #ifdef USE_CFG_FREQ
        if (radio_obj.in_freq_cal) radio_obj.toggle_freq_cal();
      #endif
      #ifdef USE_TUNE
        if (radio_obj.in_tune_pwr) radio_obj.toggle_tune_pwr();
      #endif
      break;
  }
}  