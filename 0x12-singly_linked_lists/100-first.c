#include <stdio.h>

void __attribute__((constructor)) customPrint(void);

/**
 * customPrint - Displays a message prior to
 *               the main function's execution.
 */
void customPrint(void)
{
    printf("You're beat! and yet, you must allow,\n"
               "I carry my abode on my rear!\n");
}
