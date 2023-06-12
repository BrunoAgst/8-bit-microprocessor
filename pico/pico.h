// NOTE: pico
const unsigned int SW = 16;
const int DS_DATA = 17;
const int LATCH = 18;
const int CLK = 19;
const unsigned int INPUT_GPIO[8] = {15, 14, 13, 12, 11, 10, 9, 8};

int get_bit32(unsigned long int hex, int number_bit);
unsigned char get_bits_gpio(unsigned long int hex, int *bitwise);
void configure_gpio();
unsigned char get_dip_value();
void shift_out(unsigned int hex);
