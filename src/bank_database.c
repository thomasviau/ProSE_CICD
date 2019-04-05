#include "bank_database.h"

/* NE PAS MODIFIER CE FICHIER, IL DOIT ÊTRE UTILISÉ TEL QUEL ! */

static int Account;

void BankDatabase_init (int value)
{
  Account = value;
}

int BankDatabase_readAccountFile (void)
{
  return Account;
}

void BankDatabase_writeAccountFile (int value)
{
  Account = value;
}
