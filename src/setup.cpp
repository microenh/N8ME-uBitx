#include "setup.h"
#include "defines.h"
#include "display.h"
#include "radio.h"

void setup_loop::setup(void){
  // disp.set_info_border(6, 3);
  #ifdef USE_MEMORY
  erase_memory = false;
  #endif
  disp.draw_info_border(6,3);
}

setup_loop loop_setup;