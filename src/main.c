/*
* This file contains main functions needed
* for the LocalBus communication protokol.
* The Localbus is a communication protokol 
* based on a UART connection between one master
* and multiple slaves.  
* The UART can run up to 48 Mbaud if the processor
* can handle it. 
* For slow communications 115200 baud is recommended.
*/
#include <stdio.h>
#include "pico/stdlib.h"

const uint LED_PIN = 25;

int main()
{
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 0);

    while(1)
    {
        printf("Hello from the Raspberry PI\n");
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);

    }

  return 0;
}
