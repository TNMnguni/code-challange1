#pragma once
#ifndef ACCOUNT_FUNCTIONS_H
#define ACCOUNT_FUNCTIONS_H

#include "ques1_1.h"
#include "ques1_2.h"// Include necessary headers for Transaction and Account classes

int enterTransactions(Transaction* transactionArray);
void enterAccount(Account* accountObj);
void displayAccount(Account* accountObj);

#endif // ACCOUNT_FUNCTIONS_H
