// NOTE: pico
int get_bit32(unsigned long int hex, int number_bit);
int get_bit8(char hex, int number_bit);
unsigned char getBitsGPIO(unsigned long int hex, int *bitwise);
unsigned long int setBitsGPIO(char hex, int *bitwise);
void configureGPIO();
unsigned char getDipValue();
void setOutput(unsigned char hex);
