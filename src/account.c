#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "account.h"

struct Account* createAccount(struct Account* head) {
    struct Account* newAcc = (struct Account*)malloc(sizeof(struct Account));

    printf("\nEnter Account Number: ");
    scanf("%d", &newAcc->acc_no);
    printf("Enter Name: ");
    scanf("%s", newAcc->name);
    printf("Enter Initial Balance: ");
    scanf("%f", &newAcc->balance);

    newAcc->next = NULL;

    if (head == NULL) head = newAcc;
    else {
        struct Account* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newAcc;
    }

    printf("\n Account created successfully!\n");
    return head;
}

void displayAccounts(struct Account* head) {
    if (head == NULL) {
        printf("\nNo accounts found!\n");
        return;
    }

    printf("\n       Account List       \n");
    struct Account* temp = head;
    while (temp != NULL) {
        printf("Acc No:%d | Name:%s | Balance:%.2f\n", temp->acc_no, temp->name, temp->balance);
        temp = temp->next;
    }
}

struct Account* searchAccount(struct Account* head, int acc_no) {
    struct Account* temp = head;
    while (temp != NULL) {
        if (temp->acc_no == acc_no)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

struct Account* deleteAccount(struct Account* head, int acc_no) {
    struct Account* temp = head;
    struct Account* prev = NULL;

    while (temp != NULL && temp->acc_no != acc_no) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nAccount not found!\n");
        return head;
    }

    if (prev == NULL) head = head->next;
    else prev->next = temp->next;

    free(temp);
    printf("\n Account deleted successfully!\n");
    return head;
}
