/*
 * main.c
 *
 * Simple example program to blink an LED on the Raspberry PI Pico
 * and communicate over the USB serial port
*/
#include <stdio.h>
#include <pico/stdio.h>
#include <pico/time.h>
#include <hardware/gpio.h>


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
