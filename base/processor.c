#include <stdio.h>
#include <stdlib.h>
#include "processor.h"

// NOTE: registrars
unsigned char INSTRUCTION = 0x00;
unsigned char OTR = 0x00;
unsigned char ADD_INSTRUCTION = 0x00;
unsigned char ARGUMENT = 0x00;
unsigned char ACC = 0x00;
unsigned char ADD_ROM = 0x00;
unsigned char BR = 0x00;
unsigned int ITR = 0x00;
unsigned char UR[10] = {0x00};

// NOTE: flag registers
unsigned char CFLAG = 0;
unsigned char ZFLAG = 0;
unsigned char EFLAG = 0;

// NOTE: counters
unsigned char cycle = 0;
unsigned char counter = 0;
unsigned char level = 1;

// NOTE: rom memory simulator
char rom[20] = {0x00};

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
    case 0x00:
        INSTRUCTION = HLT;
        level = 0;
        valid = 0;
        break;
    case 0x01:
        INSTRUCTION = NOP;
        valid = 1;
        break;
    case 0x02:
        INSTRUCTION = OTI;
        valid = 1;
        break;
    case 0x03:
        INSTRUCTION = LDA;
        valid = 1;
        break;
    case 0x04:
        INSTRUCTION = LDI;
        valid = 1;
        break;
    case 0x05:
        INSTRUCTION = ADD;
        valid = 1;
        break;
    case 0x06:
        INSTRUCTION = SUB;
        valid = 1;
        break;
    case 0x07:
        INSTRUCTION = STA;
        valid = 1;
        break;
    case 0x08:
        INSTRUCTION = AND;
        valid = 1;
        break;
    case 0x09:
        INSTRUCTION = ORL;
        valid = 1;
        break;
    case 0x0A:
        INSTRUCTION = XOR;
        valid = 1;
        break;
    case 0x0B:
        INSTRUCTION = NOT;
        valid = 1;
        break;
    case 0x0C:
        INSTRUCTION = GTA;
        valid = 1;
        break;
    case 0x0D:
        INSTRUCTION = IFC;
        valid = 1;
        break;
    case 0x0E:
        INSTRUCTION = IFZ;
        valid = 1;
        break;
    case 0x0F:
        INSTRUCTION = ITI;
        valid = 1;
        break;
    case 0x1F:
        INSTRUCTION = SHL;
        valid = 1;
        break;
    case 0x2F:
        INSTRUCTION = SHR;
        valid = 1;
        break;
    case 0x3F:
        INSTRUCTION = CPA;
        valid = 1;
        break;
    default:
        printf("\n[Error] - Instruction not found\n");
        level = 0;
        valid = 0;
    }
    return valid;
}

void search_operation(char instruction)
{
    switch (instruction)
    {
    case NOP:
        nop_exec();
        break;
    case OTI:
        oti_exec();
        break;
    case LDA:
        lda_exec();
        break;
    case LDI:
        ldi_exec();
        break;
    case ADD:
        add_exec();
        break;
    case SUB:
        sub_exec();
        break;
    case STA:
        sta_exec();
        break;
    case AND:
        and_exec();
        break;
    case ORL:
        orl_exec();
        break;
    case XOR:
        xor_exec();
        break;
    case NOT:
        not_exec();
        break;
    case GTA:
        gta_exec();
        break;
    case IFC:
        ifc_exec();
        break;
    case IFZ:
        ifz_exec();
        break;
    case ITI:
        iti_exec();
        break;
    case SHL:
        shl_exec();
        break;
    case SHR:
        shr_exec();
        break;
    case CPA:
        cpa_exec();
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
        cycle = 0;
        return;
    }
}

void sub_exec()
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
        CFLAG = (ACC - BR) >> 8;
        ACC -= BR;
        ZFLAG = ACC ? 0 : 1;
        cycle = 0;
        return;
    }
}

void sta_exec()
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
        if (ARGUMENT >= 0x00 && ARGUMENT < 0x10)
        {
            UR[ARGUMENT] = ACC;
            cycle = 0;
            return;
        }
        else
        {
            printf("Error UR 0x%.2x invalid", ARGUMENT);
            cycle = 0;
            return;
        }
    }
}

void lda_exec()
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
        if (ARGUMENT >= 0x00 && ARGUMENT < 0x10)
        {
            ACC = UR[ARGUMENT];
            ZFLAG = ACC ? 0 : 1;
            cycle = 0;
            return;
        }
        else
        {
            printf("Error UR 0x%.2x invalid", ARGUMENT);
            cycle = 0;
            return;
        }
    }
}

void and_exec()
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
        ACC &= ARGUMENT;
        ZFLAG = ACC ? 0 : 1;
        cycle = 0;
        return;
    }
}

void orl_exec()
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
        ACC |= ARGUMENT;
        ZFLAG = ACC ? 0 : 1;
        cycle = 0;
        return;
    }
}

void xor_exec()
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
        ACC ^= ARGUMENT;
        ZFLAG = ACC ? 0 : 1;
        cycle = 0;
        return;
    }
}

void not_exec()
{
    if (cycle == 3)
    {
        ACC = ~ACC;
        ZFLAG = ACC ? 0 : 1;
        cycle = 0;
        return;
    }
}

void oti_exec()
{
    if (cycle == 3)
    {
        OTR = ACC;
        print_output();
        cycle = 0;
        return;
    }
}

void gta_exec()
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
        counter = ARGUMENT;
        cycle = 0;
        return;
    }
}

void ifc_exec()
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
        if (CFLAG == 1)
        {
            counter = ARGUMENT;
            cycle = 0;
            return;
        }
        else
        {
            cycle = 0;
            return;
        }
    }
}

void ifz_exec()
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
        if (ZFLAG == 1)
        {
            counter = ARGUMENT;
            cycle = 0;
            return;
        }
        else
        {
            cycle = 0;
            return;
        }
    }
}

void nop_exec()
{
    cycle = 0;
    return;
}

void iti_exec()
{
    if (cycle == 3)
    {
        printf("Enter hex value to add in ITI without 0x: ");
        scanf("%x", &ITR);
        cycle++;
        return;
    }

    if (cycle == 4)
    {
        ACC = ITR;
        cycle = 0;
        return;
    }
}

void shl_exec()
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
        ACC <<= ARGUMENT;
        ZFLAG = ACC ? 0 : 1;
        cycle = 0;
        return;
    }
}

void shr_exec()
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
        ACC >>= ARGUMENT;
        ZFLAG = ACC ? 0 : 1;
        cycle = 0;
        return;
    }
}

void cpa_exec()
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
    }
    if (cycle == 5)
    {
        EFLAG = (ACC == BR) ? 1 : 0;
        cycle = 0;
        return;
    }
}

void print_output()
{
    printf("\n******************************\n");
    printf("Counters:\n");
    printf("Cycle - %d\n", cycle);
    printf("Counter - %d\n", counter);
    printf("\nRegisters:\n");
    printf("ADD_ROM - 0x%.2x\n", ADD_ROM);
    printf("INSTRUCTION - 0x%.2x\n", INSTRUCTION);
    printf("ARGUMENT - 0x%.2x\n", ARGUMENT);
    printf("BR - 0x%.2x\n", BR);
    printf("ACC - 0x%.2x\n", ACC);
    printf("OTR - 0x%.2x\n", OTR);
    printf("ITR - 0x%.2x\n", ITR);
    printf("UR0 - 0x%.2x\n", UR[0]);
    printf("UR1 - 0x%.2x\n", UR[1]);
    printf("UR2 - 0x%.2x\n", UR[2]);
    printf("UR3 - 0x%.2x\n", UR[3]);
    printf("UR4 - 0x%.2x\n", UR[4]);
    printf("UR5 - 0x%.2x\n", UR[5]);
    printf("UR6 - 0x%.2x\n", UR[6]);
    printf("UR7 - 0x%.2x\n", UR[7]);
    printf("UR8 - 0x%.2x\n", UR[8]);
    printf("UR9 - 0x%.2x\n", UR[9]);
    printf("\nFlags:\n");
    printf("CFLAG - 0x%.2x\n", CFLAG);
    printf("ZFLAG - 0x%.2x\n", ZFLAG);
    printf("EFLAG - 0x%.2x\n", EFLAG);
    printf("\n******************************\n");
}

void print_init()
{
    printf("\n\n");
    printf(" ####   ####  #    # #####  #    # ##### ###### #####   \n");
    printf("#    # #    # ##  ## #    # #    #   #   #      #    #  \n");
    printf("#      #    # # ## # #    # #    #   #   #####  #    #  \n");
    printf("#      #    # #    # #####  #    #   #   #      #####   \n");
    printf("#    # #    # #    # #      #    #   #   #      #   #   \n");
    printf(" ####   ####  #    # #       ####    #   ###### #    #  \n");
    printf("\n\n");
    printf("          #####                                  \n");
    printf("         #     #       #####   #  #####          \n");
    printf("         #     #       #    #  #    #            \n");
    printf("          #####  ##### #####   #    #            \n");
    printf("         #     #       #    #  #    #            \n");
    printf("         #     #       #    #  #    #            \n");
    printf("          #####        #####   #    #            \n");
    printf("\n\n");
}