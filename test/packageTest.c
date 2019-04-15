#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "cmocka/cmocka.h"

// Inclusion du module à tester.
#include "package.c"

static int setUp(void **state)
{
	return 0;
}

static int tearDown(void **state)
{
	return 0;
}

static void testFunctionTropBien(void **state)
{
	int result;

	result = toBeTested();

	assert_int_equal(0, result);
}

static const struct CMUnitTest tests[] =
{
	cmocka_unit_test(testFunctionTropBien)
};


int packageTestRunTests()
{
	return cmocka_run_group_tests_name("Test de la classe Package", tests, setUp, tearDown);
}