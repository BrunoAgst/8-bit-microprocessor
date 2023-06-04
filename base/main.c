#include "micro_processor.c"
#include "headers.h"

int main()
{
    print_init();
    fetch_cycle();
    return 0;
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