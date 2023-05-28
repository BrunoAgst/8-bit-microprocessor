#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

// NOTE: registrars
unsigned char INSTRUCTION = 0x00;
unsigned char ADD_INSTRUCTION = 0x00;
unsigned char ARGUMENT = 0x00;
unsigned char ACC = 0x00;
unsigned char ADD_ROM = 0x00;
unsigned char BR = 0x00;

// NOTE: flag registers
unsigned char CFLAG = 0;
unsigned char ZFLAG = 0;

// NOTE: counters
unsigned char cycle = 0;
unsigned char counter = 0;
unsigned char level = 1;

// NOTE: rom memory simulator
char rom[5] = {
    0x04, 0xFF, 0x05, 0x01, 0x00};

void fetch_cycle()
{
    while (level)
    {
        switch (cycle)
        {
        case 0:
        case 1:
            get_instruction();
            break;
        case 2:
            search_instruction();
            break;
        case 3:
        case 4:
        case 5:
            search_operation(INSTRUCTION);
            break;
        default:
            break;
        }
    }
}

void get_instruction()
{
    if (cycle == 0)
    {
        ADD_ROM = counter;
        cycle++;
        return;
    }

    if (cycle == 1)
    {
        ADD_INSTRUCTION = rom[counter];
        counter++;
        cycle++;
        return;
    }
}

void search_instruction()
{
    ADD_ROM = counter;
    if (!select_instruction(ADD_INSTRUCTION))
        return;
    cycle++;
}

int select_instruction(char opcode)
{
    int valid = 0;
    switch (opcode)
    {
    case 0x04:
        INSTRUCTION = LDI;
        valid = 1;
        break;
    case 0x05:
        INSTRUCTION = ADD;
        valid = 1;
        break;
    default:
        level = 0;
        valid = 0;
        break;
    }
    return valid;
}

void search_operation(char instruct)
{
    switch (instruct)
    {
    case LDI:
        ldi_exec();
        break;
    case ADD:
        add_exec();
        break;
    default:
        break;
    }
}

void ldi_exec()
{
    if (cycle == 3)
    {
        ARGUMENT = rom[counter];
        counter++;
        cycle++;
        return;
    }

    if (cycle == 4)
    {
        ACC = ARGUMENT;
        print_output();
        cycle = 0;
        return;
    }
}

void add_exec()
{
    if (cycle == 3)
    {
        ARGUMENT = rom[counter];
        counter++;
        cycle++;
        return;
    }

    if (cycle == 4)
    {
        BR = ARGUMENT;
        cycle++;
        return;
    }

    if (cycle == 5)
    {
        CFLAG = (ACC + BR) >> 8;
        ACC += BR;
        ZFLAG = ACC ? 0 : 1;
        print_output();
        cycle = 0;
        return;
    }
}

void print_output()
{
    printf("Cycle - %d\n", cycle);
    printf("Counter - %d\n", counter);
    printf("ADD_ROM - 0x%.2x\n", ADD_ROM);
    printf("INSTRUCTION - 0x%.2x\n", INSTRUCTION);
    printf("ARGUMENT - 0x%.2x\n", ARGUMENT);
    printf("BR - 0x%.2x\n", BR);
    printf("ACC - 0x%.2x\n", ACC);
    printf("CFLAG - 0x%.2x\n", CFLAG);
    printf("ZFLAG - 0x%.2x\n", ZFLAG);
    printf("\n");
}