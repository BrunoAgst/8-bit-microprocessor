#include "pico.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

void configureGPIO()
{
    stdio_init_all();

    gpio_init(SW);
    gpio_pull_up(SW);

    for (int i = 0; i < 8; i++)
    {
        gpio_init(OUTPUT_GPIO[i]);
        gpio_init(INPUT_GPIO[i]);
        gpio_set_dir(OUTPUT_GPIO[i], GPIO_OUT);
        gpio_set_dir(INPUT_GPIO[i], GPIO_IN);
    }
}

unsigned long int setBitsGPIO(char hex, int *bitwise)
{
    unsigned long int mask = 0x1000003;

    for (int i = 0; i < 8; i++)
    {
        mask ^= (get_bit8(hex, i) << bitwise[i]);
    }
    return mask;
}

unsigned char getBitsGPIO(unsigned long int hex, int *bitwise)
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

int get_bit8(char hex, int number_bit)
{
    if (!(hex & (1 << number_bit)))
    {
        return 0;
    }
    return 1;
}

unsigned char getDipValue()
{
    unsigned long int input = gpio_get_all();
    unsigned char hex = getBitsGPIO(input, bitwiseGet);
    return hex;
}

void setOutput(unsigned char hex)
{
    unsigned long int output = setBitsGPIO(hex, bitwiseSet);
    gpio_put_all(output);
}