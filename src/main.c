/**
 * @file main.c
 *
 * @brief Ceci est le main, vive le main
 * @date 04/03/2019
 * @author Nathan Le Granvallet
 *
 * @copyright Nexelis
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "package/package.h"

int main (void)
{

	int value;
	value = toBeTested(0);

	printf("Hello !");
	printf("%d", value);
	return 0;

}