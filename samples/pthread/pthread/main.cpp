#include <stdio.h>
#include <orbis/libkernel.h>

OrbisPthread myThread;

void threadedFunction()
{
    for (int count = 0; count < 10; count++)
    {
        printf("Thread B is running: %d\n", count);
        sceKernelUsleep(2 * 100000);
    }
}

int main()
{
    printf("Pthread example\n-\n");

    scePthreadCreate(&myThread, NULL, (void *)threadedFunction, NULL, "example_pthread");

    for (int count = 0; count < 10; count++)
    {
        printf("Thread A is running: %d\n", count);
        sceKernelUsleep(2 * 100000);
    }

    sceKernelUsleep(3 * 1000000);
    scePthreadCancel(myThread);

    return 0;
}
