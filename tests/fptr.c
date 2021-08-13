// This test verifies that function pointers to dynamically resolved functions work.
//
// Test criteria:
//     The test should run without crashing.
//
// Related issues:
//     https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/issues/82
// 
// Fix under test:
//     https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/issues/83
//
// Issue reported by: sleirsgoevy
// Fix written by: sleirsgoevy
// Tested by: sleirsgoevy
// Date: 2020/08/11
#define TEST_TITLE "Function pointers"

#include <orbis/libkernel.h>

#include "_test.h"

// PoC by sleirsgoevy. Should run without crashing.
void test()
{
	sceKernelPread(-1, 0, 0, 0);
    size_t(*sceKernelPread2)(int, void*, size_t, off_t) = &sceKernelPread;

    TEST_MSG("Following function pointer")
    sceKernelPread2(-1, 0, 0, 0);
    TEST_PASS
}

int main()
{
	printf("Running toolchain unit test: %s\n--\n", TEST_TITLE);
	test();
	printf("\n--\n%d/%d tests pass. Test complete.\n", passCount, testCount);
	for(;;);
}