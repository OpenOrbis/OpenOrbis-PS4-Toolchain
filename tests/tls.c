// This test verifies that Thread-Local Storage (TLS) has been implemented properly
// by attempting to use the multi-byte string to/from wide-character string
// functions (mbstowcs, wcstombs), which implicitly use TLS.
//
// Test criteria:
//     Both testMbstowcs() and testWbstombs() should return a positive number of
//     bytes written without crashing. Printed strings should also be verified.
//
// Related issues:
//     https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/issues/86
//     https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/issues/84
// 
// Fix under test:
//     https://github.com/OpenOrbis/musl/pull/8
//
// Issue reported by: 0x199 (root caused by sleirsgoevy)
// Fix written by: sleirsgoevy
// Tested by: specter
// Date: 2020/10/08
#define TEST_TITLE "Thread-Local Storage (TLS)"

#include <stdlib.h>
#include <string.h>

#include "_test.h"

int testMbstowcs();
int testWbstombs();

// The test is based on expected value (EV). The test string is "Hello world!" which
// is 12 characters long. Therefore, both tests should return 12 as the EV.
void test()
{
	int expectedValue = 12;

	TEST_MSG("Testing mbstowcs()")

	if(testMbstowcs() == expectedValue)
	{
		TEST_PASS
	}
	else
		TEST_FAIL

	TEST_MSG("Testing wbstombs()")

	if(testWbstombs() == expectedValue)
	{
		TEST_PASS
	}
	else
		TEST_FAIL
}

int testMbstowcs()
{
	int written;

	const char str[] = "Hello world!";
	wchar_t buf[128];

	written = mbstowcs(buf, str, sizeof(buf));

	// Null terminate if needed
	if(written == sizeof(buf))
		buf[128 - 1] = 0;

	TEST_INFO("multibyte string = %s\n", str);
	TEST_INFO("wide string      = %ls\n", buf);

	return written;
}

int testWbstombs()
{
	int written;

	const wchar_t str[] = L"Hello world!";
	char buf[128];

	written = wcstombs(buf, str, sizeof(buf));

	// Null terminate if needed
	if(written == sizeof(buf))
		buf[sizeof(buf) - 1] = 0;

	TEST_INFO("multibyte string = %s\n", buf);
	TEST_INFO("wide string      = %ls\n", str);

	return written;
}

int main()
{
	printf("Running toolchain unit test: %s\n--\n", TEST_TITLE);
	test();
	printf("\n--\n%d/%d tests pass. Test complete.\n", passCount, testCount);
	for(;;);
}