#include <iostream>
using namespace std;
#ifndef TRANSACTION

class Transaction
{
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

Transaction::Transaction(int aN, int tT, float tA)
{
	accountNumber = aN;
	transactionType = tT;
	transactionAmount = tA;
}
void Transaction::setTransaction(int aN, int tT, float tA)
{
	this->accountNumber = aN;
	this->transactionType = tT;
	this->transactionAmount = tA;
}

int Transaction::getAccountNumber()
{
	return accountNumber;
}

float Transaction::getTransactionAmnt()
{
	switch (transactionType)
	{
	case 1: return -transactionAmount;
		break;
	case 2: return transactionAmount;
	default:
		throw invalid_argument("Invalid transaction type");
	}
}
#endif