#pragma once
#include <string>
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>  // Include necessary header for string

class Transaction {

private:
	int accountNumber;
	int transactionType;
	float transactionAmount;
public:
	Transaction(int aN = 0, int tT = 1, float tA = 0.0);
	void setTransaction(int aN, int tT, float tA);
	int getAccountNumber();
	float getTransactionAmnt();
};
#endif //TRANSACTION_H
