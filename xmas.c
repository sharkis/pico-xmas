#include "hardware/clocks.h"
#include "hardware/pio.h"
#include "pico/stdlib.h"
#include "ws2812.pio.h"
#include <stdio.h>

int main() {
  PIO pio = pio0;
  int sm_id = 0;
  uint offset = pio_add_program(pio, &ws2812_program);

  ws2812_program_init(pio, sm_id, offset, 1, 800000, false);
  int ledoffset = 0;
  while (true) {
	  for(int i=0;i<10;i++){
		  if(i%2==ledoffset){
        pio_sm_put_blocking(pio0, sm_id, 0xff000000);
		  }
		  else{
        pio_sm_put_blocking(pio0, sm_id, 0x00ff0000);
		  }
	  }

	  ledoffset++;
	  if(ledoffset==2)ledoffset=0;
    sleep_ms(500);
  }
}
