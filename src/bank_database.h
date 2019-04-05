#if !defined BANK_DATABASE_H
#define BANK_DATABASE_H

/**
 * Initialize the account file
 *
 * @param initialBalance initial balance of the account
 */
void BankDatabase_init (int initialBalance);

/**
 * read the account file
 *
 * @return current account balance value
 */
int BankDatabase_readAccountFile (void);

/**
 * write to the account file
 *
 * @param value value to input into the account file as the new balance
 */
void BankDatabase_writeAccountFile (int value);

#endif // BANK_DATABASE_H
