
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Account.h"

int main(void) {
    Account acc = AccountOpen();

    acc->bal = 1000000;

    // I'm a millionaire now, woohoo!
    printf("Balance: %d\n", AccountBalance(acc));

    AccountClose(acc);
}
