#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "processor.c"

void gpio_callback();

int main()
{
    gpio_init(25);
    gpio_set_dir(25, GPIO_OUT);
    gpio_put(25, true);
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