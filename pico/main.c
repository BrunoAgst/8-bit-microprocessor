#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "processor.c"

void gpio_callback();

const int LED = 25;

int main()
{
    gpio_init(LED);
    gpio_set_dir(LED, GPIO_OUT);
    gpio_put(LED, true);
    printf("\ninitialization...\n");
    init();

    gpio_set_irq_enabled_with_callback(SW, 0x04, true, &gpio_callback);

    while (1)
        ;
}

void gpio_callback()
{
    fetch_cycle();
}