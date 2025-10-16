#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

struct Account* loadAccountsFromFile() {
    FILE *fp = fopen("bankdata.txt", "r");
    if (fp == NULL) {
        printf("\nNo existing data found. Starting fresh.\n");
        return NULL;
    }

    struct Account *head = NULL, *temp, *newAcc;
    while (1) {
        newAcc = (struct Account*)malloc(sizeof(struct Account));
        if (fscanf(fp, "%d %s %f", &newAcc->acc_no, newAcc->name, &newAcc->balance) != 3) {
            free(newAcc);
            break;
        }
        newAcc->next = NULL;

        if (head == NULL)
            head = newAcc;
        else {
            temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newAcc;
        }
    }

    fclose(fp);
    printf("\n✅ Accounts loaded from file.\n");
    return head;
}

void saveAccountsToFile(struct Account *head) {
    FILE *fp = fopen("bankdata.txt", "w");
    if (fp == NULL) {
        printf("\nError opening file for writing!\n");
        return;
    }

    struct Account *temp = head;
    while (temp != NULL) {
        fprintf(fp, "%d %s %.2f\n", temp->acc_no, temp->name, temp->balance);
        temp = temp->next;
    }

    fclose(fp);
}
