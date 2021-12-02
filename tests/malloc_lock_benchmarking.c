// This test benchmarks the performance of malloc(), and was primarily written to
// measure the difference between locked and unlocked malloc calls for MUSL thread
// safety.
//
// Test criteria:
//     Benchmark.
//
// Related issues:
//     https://github.com/OpenOrbis/OpenOrbis-PS4-Toolchain/issues/94
// 
// Purpose:
//     Determine if we can always set apps to multi-threaded / if the overhead is
//     negligible.
//
// Benchmark written by: specter
// Date: 2020/10/08
#define TEST_TITLE "MUSL malloc() benchmark"

#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include <pthread.h> 

#include "_test.h"

// A normal C function that is executed as a thread  
// when its name is specified in pthread_create() 
void *myThreadFun(void *vargp) 
{ 
    sleep(1); 
    printf("Printing GeeksQuiz from Thread \n"); 
    return NULL; 
} 

void test()
{
	float startTime;
	float endTime;
	float totalTime;

	int testCount = 1000;

	pthread_t thread_id;
	pthread_create(&thread_id, NULL, myThreadFun, NULL); 

	TEST_MSG("Measuring performance of malloc() in locked state")

	for(int count = 0; count < testCount; count++)
	{
		startTime = (float)clock() / CLOCKS_PER_SEC;
		void *test = malloc(32);
		endTime = (float)clock() / CLOCKS_PER_SEC;

		free(test);

		totalTime += (endTime - startTime);
	}

	TEST_INFO("Average execution time: %f\n", (float)(totalTime / (float)testCount));
}

int main()
{
	printf("Running toolchain benchmark test: %s\n--\n", TEST_TITLE);
	test();
	printf("\n--\nBenchmark complete.\n");
	for(;;);
}