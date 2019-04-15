#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "package.h"

int main (void)
{

	int value;
	value = toBeTested();

	printf("Hello !");
	printf("%d", value);
	return 0;
}