#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "test/cmocka/cmocka.h"

// Inclusion du module à tester.
#include "src/package/package.c"

static int setUp(void **state)
{
	return 0;
}

static int tearDown(void **state)
{
	return 0;
}

static void testFunctionTropBien0(void **state)
{
	int result;
	result = toBeTested(0);
	assert_int_equal(0, result);
}

static void testFunctionTropBien1(void **state)
{
    int result;
    result = toBeTested(1);
    assert_int_equal(0, result);
}

static const struct CMUnitTest tests[] =
{
	cmocka_unit_test(testFunctionTropBien0),
    cmocka_unit_test(testFunctionTropBien1)
};

int packageTestRunTests()
{
	return cmocka_run_group_tests_name("Test de la classe Package", tests, setUp, tearDown);
}