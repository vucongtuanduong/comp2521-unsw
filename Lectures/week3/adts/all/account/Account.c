
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Account.h"

struct account {
    int bal;
};

/**
 * Opens a new account with zero balance
 */
Account AccountOpen(void) {
    Account acc = malloc(sizeof(struct account));
    if (acc == NULL) {
        fprintf(stderr, "error: out of memory\n");
        exit(EXIT_FAILURE);
    }

    acc->bal = 0;
    return acc;
}

/**
 * Closes an account 
 */
void AccountClose(Account acc) {
    free(acc);
}

/**
 * Returns account balance
 */
int AccountBalance(Account acc) {
    return acc->bal;
}

/**
 * Withdraws money from account
 * Returns true if enough balance, false otherwise
 * Assumes amount is positive 
 */
bool AccountWithdraw(Account acc, int amount) {
    if (amount < 0) {
        fprintf(stderr, "error: invalid amount\n");
        return false;
    }

    if (amount > acc->bal) {
        return false;
    } else {
        acc->bal -= amount;
        return true;
    }
}

/**
 * Deposits money into account
 * Assumes amount is positive 
 */
void AccountDeposit(Account acc, int amount) {
    if (amount < 0) {
        fprintf(stderr, "error: invalid amount\n");
        return;
    }

    acc->bal += amount;
}
