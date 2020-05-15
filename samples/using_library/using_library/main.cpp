#include <stdio.h>
#include <errno.h>
#include <orbis/libkernel.h>

// Handle for library, set by sceKernelLoadStartModule()
int exampleLib = -1;

// testLibraryFunction function pointer, set by sceKernelDlsym()
void (*testLibraryFunction)() = NULL;

int main()
{
    int rv;

    // Open the library and resolve symbols
    exampleLib = sceKernelLoadStartModule("/app0/libExample.prx", 0, NULL, 0, 0, 0);
    rv = sceKernelDlsym(exampleLib, "_Z19testLibraryFunctionv", (void **)&testLibraryFunction);

    // Only try to call the function pointer if it was resolved, or we'll crash
    if (rv == 0)
        testLibraryFunction();
    else
        printf("Failed to resolve (function doesn't exist)!\n");

    for (;;);
    return 0;
}