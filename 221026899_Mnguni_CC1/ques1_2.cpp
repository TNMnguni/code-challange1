#include <string>
#include "ques1_1.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


class Account {

private:
    int accountNumber;
    char firstName[50];
    char surname[50];
    char accountCategory;
    static float creditLimits[4][3];
    int repaymentCategory;
    float balance;



public:
    //Account();
    Account(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal);
    void setAccount(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal);
    static void readAndSetCreditLimits(string fileName);
    float determineCreditLimit();
    void operator+(Transaction& trans);
    virtual float determineAmountPayable();
    float getBalance();
    string getAccount();
};



Account::Account(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal) {
    this->accountNumber = accNo;
    strcpy_s(this->firstName, 50, fName);
    strcpy_s(this->surname, 50, sName);
    this->accountCategory = accCat;
    this->repaymentCategory = repCat;
    this->balance = bal;
}


void  Account::setAccount(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal) {
    this->accountNumber = accNo;
    strcpy_s(this->firstName, 50, fName);
    strcpy_s(this->surname, 50, sName);
    this->accountCategory = accCat;
    this->repaymentCategory = repCat;
    this->balance = bal;
}


void Account::readAndSetCreditLimits(string fileName) {
    ifstream file(fileName);

    if (!file)
    {
        throw "File " + fileName + " could not be opened";
    }

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            file >> creditLimits[i][j];
        }
    }

    file.close();
}


float Account::determineCreditLimit() {
    return creditLimits[accountCategory - 'P'][repaymentCategory - 1];
}

void  Account::operator+(Transaction& trans) {

    if (trans.getAccountNumber() != accountNumber)
    {
        cout << "Cannot apply transaction – account numbers do not match" << endl;
        return;
    }

    float transactionAmount = trans.getTransactionAmnt();

    if (transactionAmount > 0 && balance + transactionAmount > determineCreditLimit())
    {
        cout << "Credit limit exceeded – transaction not applied" << endl;
        return;
    }

    balance += transactionAmount;

    if (balance < 0)
    {
        balance = 0;
    }

    cout << "Transaction applied" << endl;
}

float  Account::determineAmountPayable() {
    float amntPayable = balance;

    return amntPayable;
}

float Account::getBalance()
{
    return balance;
}
string Account::getAccount()
{
    string accountCategoryDescription;

    switch (accountCategory)
    {
    case 'P':
        accountCategoryDescription = "Platinum";
        break;
    case 'G':
        accountCategoryDescription = "Gold";
        break;
    case 'S':
        accountCategoryDescription = "Silver";
        break;
    case 'B':
        accountCategoryDescription = "Bronze";
        break;
    }

    stringstream ss;
    ss << "Account Number: " << accountNumber << endl;
    ss << "First Name: " << firstName << endl;
    ss << "Surname: " << surname << endl;
    ss << "Account Category: " << accountCategoryDescription << endl;

    return  ss.str();
}

float Account::creditLimits[4][3] =
{
    { 300, 600, 900 },
    { 500, 1000, 1500 },
    { 1000, 2000, 3000 },
    { 5000, 7000, 10000 }
};