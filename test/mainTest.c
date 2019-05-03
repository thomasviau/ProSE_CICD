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
 * @brief Example main_test file for coding style in C
 * @version 1.0
 * @date 28/04/2019
 * @author Thomas VIAU
 * @copyright BSD 2-clauses
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include "../cmocka/cmocka.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** Nombre de suites de tests à exécuter. */
#define NB_SUITE_TESTS 1

extern int exampleRunTests(void);

/** Liste des suites de tests à exécuter. */
int (* suiteTests[])(void) =
		{
				exampleRunTests
		};


/**
 * @brief Fonction de lancement de chacune des suites de test avec CMocka.
 *
 * @param[in] void
 */
static void testRunner() {
	for (int i = 0; i < NB_SUITE_TESTS; i++) {
		suiteTests[i]();
	}
}


/**
 * @brief Fonction d'affichage d'une aide sur la sortie standard pour utiliser le programme de test.
 *
 * @param[in] nom
 */
static void afficheAide(char * nom) {
	printf("Suite de tests pour le programme à tester\n");
	printf("Usage : %s [-texte] [-subunit] [-tap] [-xml]\n", nom);

	exit(0);
}

/**
 * @brief Fonction principale du programme de test.
 *
 * @param[in] argc et argv
 */
int main(int argc, char * argv[]) {
	if (argc > 1) {
		if (!strcmp(argv[1], "-texte")) {
			cmocka_set_message_output(CM_OUTPUT_STDOUT);
		} else
		if (!strcmp(argv[1], "-subunit")) {
			cmocka_set_message_output(CM_OUTPUT_SUBUNIT);
		} else
		if (!strcmp(argv[1], "-tap")) {
			cmocka_set_message_output(CM_OUTPUT_TAP);
		} else
		if (!strcmp(argv[1], "-xml")) {
			cmocka_set_message_output(CM_OUTPUT_XML);
		} else {
			afficheAide(argv[0]);
		}
	}

	testRunner();

	return 0;
}