
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Account.h"

int main(void) {
    Account acc = AccountOpen();
    printf("Balance: %d\n", AccountBalance(acc));

    AccountDeposit(acc, 50);
    printf("Balance: %d\n", AccountBalance(acc));

    bool res = AccountWithdraw(acc, 20);
    if (!res) {
        printf("Withdrawal failed\n");
    }
    printf("Balance: %d\n", AccountBalance(acc));

    res = AccountWithdraw(acc, 40);
    if (!res) {
        printf("Withdrawal failed\n");
    }
    printf("Balance: %d\n", AccountBalance(acc));

    AccountClose(acc);
}
