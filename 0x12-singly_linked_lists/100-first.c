#include <stdio.h>

void __attribute__((constructor)) tortoise(void);

/**
 * tortoise - Displays a message before the main function.
 */
void tortoise(void)
{
	printf("You're outpaced! But still, you must admit,\n"
	       "I carry my home on my back!\n");
}

