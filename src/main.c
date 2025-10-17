#include <stdio.h>
#include <stdlib.h>
#include "account.h"
#include "transaction.h"
#include "fileio.h"
// #include "ui.h" // temporarily disabled

int main() {
    struct Account *head = NULL;

    // initGraphics(); // splash screen (UI disabled)

    head = loadAccountsFromFile();

    int choice;
    while (1) {
        // Replacing mainMenu() with a simple text-based menu
        printf("\n===== BANK MENU =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display All Accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
                printf("\nExiting... Data saved successfully.\n");
                // closeGraphics(); // disabled
                return 0;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }

    return 0;
}
