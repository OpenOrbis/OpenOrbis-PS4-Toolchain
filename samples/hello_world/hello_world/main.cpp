#include <stdio.h>
#include <orbis/libkernel.h>

int main(void)
{
    printf("Hello world! Waiting 2 seconds...\n");

    sceKernelUsleep(2 * 1000000);

    printf("Done. Infinitely looping...\n");

    for (;;) {}
}
