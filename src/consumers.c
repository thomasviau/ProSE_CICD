#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "account.h"

#define WITHDRAW_AMOUNT (10)
#define WITHDRAW_PER_CONSUMER (50000)
#define CONSUMERS_COUNT (200)

void * consumer (void * param) {
    int i;

    // Verrouillage thread dans account.c directement

    for (i = 0 ; i < WITHDRAW_PER_CONSUMER ; i++)
        Account_withdraw(WITHDRAW_AMOUNT);

	pthread_exit(NULL);
}

int main (void) {

	pthread_t thread[CONSUMERS_COUNT];
	int rc;

	// Initialisation du compte

	Account_init();
	printf("Account balance before : %d \n", Account_get_balance());

	// Création des threads

	for (int i = 0 ; i < CONSUMERS_COUNT ; i++) {
		if ((rc = pthread_create(&(thread[i]), NULL, consumer, &(thread[i]))))
			return EXIT_FAILURE; // Gestion erreur
	}

	// Attente fin des threads

	for (int i = 0 ; i < CONSUMERS_COUNT ; i++)
		pthread_join(thread[i], NULL);

	printf("Account balance after : %d \n", Account_get_balance());

}