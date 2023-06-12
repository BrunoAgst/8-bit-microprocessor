#include <stdio.h>
#include <stdlib.h>

unsigned char stack[10] = {0x00};
unsigned char *ptr = stack;
int counter_stack = sizeof(stack) / sizeof(stack[0]);
void add_stack(unsigned char *array, char value);
void sub_stack(unsigned char *array);
void print_stack();

int main()
{
    printf("counter stack: %.2d\n", counter_stack);

    add_stack(ptr, 0x2);
    add_stack(ptr, 0x08);
    add_stack(ptr, 0x0B);
    add_stack(ptr, 0x0A);
    sub_stack(ptr);
    print_stack();
}

void add_stack(unsigned char *array, char value)
{
    array[counter_stack] = value;
    counter_stack -= 1;
}

void sub_stack(unsigned char *array)
{
    counter_stack += 1;
    printf("ultimo valor 0x%.2X\n", array[counter_stack]);
    array[counter_stack] = 0x00;
}

void print_stack()
{
    for (int i = 0; i <= 10; i++)
    {
        printf("%.2x\n", stack[i]);
    }
}