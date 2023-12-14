#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void __attribute__((constructor)) cheat(void) {
    srand(time(NULL));
    for (int i = 0; i < 5; ++i) {
        printf("%d ", rand() % 75 + 1);
    }
    printf("%d\n", rand() % 15 + 1);
}
