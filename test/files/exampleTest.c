/** Copyright (c) 2019, TURBOTEX
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 * Neither the name of the University of California, Berkeley nor the
 * names of its contributors may be used to endorse or promote products
 * derived from this software without specific prior written permission.

 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

/**
 * @file main_test.c
 * @brief Example test file for coding style in C
 * @version 1.0
 * @date 28/04/2019
 * @author Thomas VIAU
 * @copyright BSD 2-clauses
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>

#include "test/cmocka/cmocka.h"
#include "src/files/example.c"

/**
 * @brief Function setUp of CMocka
 *
 * @param[in] void
 */
static int setUp(void **state) {
	return 0;
}

/**
 * @brief Function tearDown of CMocka
 *
 * @param[in] void
 */
static int tearDown(void **state) {
	return 0;
}

/**
 * @brief Test function of addFunction
 *
 * @param[in] void
 */
static void testFilesAddFunction(void **state) {
	int a = 5;
	int b = 7;

	int result = addFunction(a, b);

	assert_int_equal(a+b, result);
}

/**
 * @brief First test function of plusOne
 *
 * @param[in] void
 */
static void testFilesPlusOne1(void **state) {
	int a = 1;

	int result = plusOne(a);

	assert_int_equal(a+1, result);
}

/**
 * @brief Second test function of plusOne
 *
 * @param[in] void
 */
static void testFilesPlusOne2(void **state) {
	int a = 5;

	int result = plusOne(a);

	assert_int_equal(a+1, result);
}

/**
 * @brief Tests table to execute
 */
static const struct CMUnitTest tests[] =
		{
				cmocka_unit_test(testFilesAddFunction),
				cmocka_unit_test(testFilesPlusOne1),
				cmocka_unit_test(testFilesPlusOne2)
		};


/**
 * @brief Function that runs tests
 *
 * @retval
 */
int exampleRunTests()
{
	return cmocka_run_group_tests_name("Test du module mod1", tests, setUp, tearDown);
}