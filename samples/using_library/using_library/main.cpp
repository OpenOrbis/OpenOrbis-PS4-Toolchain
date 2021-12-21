#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <orbis/libkernel.h>

// Handle for library, set by sceKernelLoadStartModule()
int exampleLib = -1;

// testLibraryFunction function pointer, set by sceKernelDlsym()
int (*testLibraryFunction)(char*, size_t, int) = NULL;

int main()
{
    int rv;
    
    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    // Open the library and resolve symbols
    exampleLib = sceKernelLoadStartModule("/app0/sce_module/libExample.prx", 0, NULL, 0, 0, 0);
    rv = sceKernelDlsym(exampleLib, "_Z19testLibraryFunctionPcmi", (void**)&testLibraryFunction);

    printf("Opened exampleLib: %d | Jumping to %p\n", exampleLib, testLibraryFunction);

    // Only try to call the function pointer if it was resolved, or we'll crash
    if (rv == 0)
    {
	char *buf = (char *)malloc(0x100);
	memset(buf, 0, 0x100);
        rv = testLibraryFunction(buf, 0x100, 13371338);
        printf("test string: %s | rv = 0x%08x\n", buf, rv);
    }
    else
        printf("Failed to resolve (function doesn't exist)!\n");

    for (;;);

    return 0;
}
