#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "transaction.h"
#include "fileio.h"
#include "ui.h"

int main() {
    struct Account *head = NULL;

    initGraphics(); // splash screen

    head = loadAccountsFromFile();

    int choice;
    while (1) {
        choice = mainMenu();

        switch (choice) {
            case 1:
                head = createAccount(head);
                break;
            case 2:
                depositMoney(head);
                break;
            case 3:
                withdrawMoney(head);
                break;
            case 4:
                displayAccounts(head);
                break;
            case 5:
                saveAccountsToFile(head);
                printf("\nExiting... Data saved.\n");
                closeGraphics();
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
