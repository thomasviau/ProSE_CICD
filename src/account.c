#include <pthread.h>
#include "account.h"
#include "bank_database.h"

// Init Mutex
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void Account_init (void) {
    BankDatabase_init(INITIAL_BALANCE);
}

void Account_withdraw (unsigned int amount) {
    int new_balance;

    // Verrouillage
	pthread_mutex_lock(&mutex);

    new_balance = BankDatabase_readAccountFile();
    new_balance = new_balance - amount;
    BankDatabase_writeAccountFile (new_balance);

    // Deverouillage
	pthread_mutex_unlock(&mutex);
}

int Account_get_balance () {
    int result;
	pthread_mutex_lock(&mutex);
    result = BankDatabase_readAccountFile();
	pthread_mutex_unlock(&mutex);
    return result;
}