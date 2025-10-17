#ifndef ACCOUNT_H
#define ACCOUNT_H

struct Account {
    int acc_no;
    char name[50];
    float balance;
    struct Account *next;
};


struct Account* createAccount(struct Account *head);
void displayAccounts(struct Account *head);
struct Account* searchAccount(struct Account *head, int acc_no);
struct Account* deleteAccount(struct Account *head, int acc_no);

#endif
