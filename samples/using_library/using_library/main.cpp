#include <stdio.h>
#include <errno.h>
#include <orbis/libkernel.h>

// Handle for library, set by sceKernelLoadStartModule()
int exampleLib = -1;

// testLibraryFunction function pointer, set by sceKernelDlsym()
int (*testLibraryFunction)() = NULL;

int main()
{
    int rv;
    
    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    // Open the library and resolve symbols
    exampleLib = sceKernelLoadStartModule("/app0/sce_module/libExample.prx", 0, NULL, 0, 0, 0);
    rv = sceKernelDlsym(exampleLib, "_Z19testLibraryFunctionv", (void**)&testLibraryFunction);

    printf("Opened exampleLib: %d | Jumping to %p\n", exampleLib, testLibraryFunction);

    // Only try to call the function pointer if it was resolved, or we'll crash
    if (rv == 0)
    {
        rv = testLibraryFunction();
        printf("rv = 0x%08x\n", rv);
    }
    else
        printf("Failed to resolve (function doesn't exist)!\n");

    for (;;);

    return 0;
}
