#include "pico.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

void configure_gpio()
{
    stdio_init_all();

    gpio_init(SW);
    gpio_pull_up(SW);

    gpio_init(DS_DATA);
    gpio_set_dir(DS_DATA, GPIO_OUT);

    gpio_init(LATCH);
    gpio_set_dir(LATCH, GPIO_OUT);

    gpio_init(CLK);
    gpio_set_dir(CLK, GPIO_OUT);

    for (int i = 0; i < 8; i++)
    {
        gpio_init(INPUT_GPIO[i]);
        gpio_set_dir(INPUT_GPIO[i], GPIO_IN);
    }
}

unsigned char get_bits_gpio(unsigned long int hex, int *bitwise)
{
    unsigned char mask = 0x00;
    for (int i = 0; i < 8; i++)
    {
        mask ^= (get_bit32(hex, bitwise[i]) << i);
    }
    return mask;
}

int get_bit32(unsigned long int hex, int number_bit)
{
    if (!(hex & (1 << number_bit)))
    {
        return 0;
    }
    return 1;
}

unsigned char get_dip_value()
{
    unsigned long int input = gpio_get_all();
    unsigned char hex = get_bits_gpio(input, INPUT_GPIO);
    return hex;
}

void shift_out(unsigned int hex)
{
    for (int i = 0; i < 8; i++)
    {
        gpio_put(CLK, 0);
        gpio_put(DS_DATA, (hex & (1 << (7 - i))) ? 1 : 0);
        gpio_put(CLK, 1);
    }
    gpio_put(LATCH, 1);
    gpio_put(LATCH, 0);
}