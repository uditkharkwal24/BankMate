#ifndef FILEIO_H
#define FILEIO_H

#include "account.h"

struct Account* loadAccountsFromFile();
void saveAccountsToFile(struct Account *head);

#endif
