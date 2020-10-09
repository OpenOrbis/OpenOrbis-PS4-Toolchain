#pragma once
#ifndef COMMON_TESTING_H
#define COMMON_TESTING_H

#include <stdio.h>

#define TEST_MSG(m) printf("[*] %s\n", m); \
	testCount++;

#define TEST_INFO(i, ...) printf("\t[+] "); \
	printf((i), __VA_ARGS__);

#define TEST_PASS printf("\t[*] Passed.\n"); \
	passCount++;

#define TEST_FAIL printf("\t[*] FAILED!\n");

int testCount = 0;
int passCount = 0;

#endif
