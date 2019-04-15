#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cmocka.h"

#define NB_SUITE_TESTS 1

extern int packageTestRunTests(void);

int (* suite_tests[])(void) = {packageTestRunTests};

static void testRunner();

int main(int argc, char * argv[])
{
	testRunner();
	return 0;
}

static void testRunner()
{
	int i;

	for (i = 0; i < NB_SUITE_TESTS; i++) {
		suite_tests[i]();
	}
}
