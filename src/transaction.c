#include <stdio.h>
#include "transaction.h"

void depositMoney(struct Account *head) {
    int acc;
    float amt;
    printf("\nEnter account number to deposit: ");
    scanf("%d", &acc);
    struct Account *accPtr = searchAccount(head, acc);

    if (accPtr == NULL) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amt);
    accPtr->balance += amt;
    printf("✅ Deposited successfully! New balance: %.2f\n", accPtr->balance);
}

void withdrawMoney(struct Account *head) {
    int acc;
    float amt;
    printf("\nEnter account number to withdraw: ");
    scanf("%d", &acc);
    struct Account *accPtr = searchAccount(head, acc);

    if (accPtr == NULL) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amt);

    if (amt > accPtr->balance) {
        printf("❌ Insufficient balance!\n");
    } else {
        accPtr->balance -= amt;
        printf("✅ Withdrawn successfully! Remaining balance: %.2f\n", accPtr->balance);
    }
}
