
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <stdbool.h>

typedef struct account *Account;

/**
 * Opens a new account with zero balance
 */
Account AccountOpen(void);

/**
 * Closes an account 
 */
void AccountClose(Account acc);

/**
 * Returns account balance
 */
int AccountBalance(Account acc);

/**
 * Withdraws money from account
 * Returns true if enough balance, false otherwise
 * Assumes amount is positive 
 */
bool AccountWithdraw(Account acc, int amount);

/**
 * Deposits money into account
 * Assumes amount is positive 
 */
void AccountDeposit(Account acc, int amount);

#endif
