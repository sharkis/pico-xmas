#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "ws2812.pio.h"

int main(){
	PIO pio = pio0;
    int sm_id = 0;
    uint offset = pio_add_program(pio, &ws2812_program);

    ws2812_program_init(pio, sm_id, offset, 1, 800000, true);

	gpio_init(25);
	gpio_set_dir(25,GPIO_OUT);
	while(true){
		gpio_put(25,1);
		for(int i=0;i<10;i++){


	pio_sm_put_blocking(pio0,sm_id,0xffffffff);
		}
		sleep_ms(250);
		gpio_put(25,0);
		sleep_ms(250);
	}

}
