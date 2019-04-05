#if !defined __ACCOUNT_H_
#define __ACCOUNT_H_
#define INITIAL_BALANCE (100000000)
/**
* Initialize the account with INITIAL_BALANCE
*/
void Account_init (void);
/**
* Make a withdraw on the account. Unlimited
* overdraft is allowed.
*
* @param amount how much to withdraw
*/
void Account_withdraw (unsigned int amount);
/**
* Gives the balance of the account at the
* time it is requested.
*
* @return balance of the account
*/
int Account_get_balance (void);
#endif /* !defined __ACCOUNT_H_ */