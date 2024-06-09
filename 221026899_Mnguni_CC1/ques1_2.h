#pragma once
#include <string>
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>  // Include necessary header for string
#include "ques1_1.h"
using namespace std;

class Account {
    // Declare member variables
    int accountNumber;
    char firstName[50];
    char surname[50];
    char accountCategory;
    int repaymentCategory;
    static float creditLimits[4][3];
    float balance;

public:
  
    Account(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal);
    void setAccount(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal);
    static void readAndSetCreditLimits(string fileName);
    float determineCreditLimit();
    void operator+(Transaction& trans);
    virtual float determineAmountPayable();
    float getBalance();
    string getAccount();
    
};

#endif // ACCOUNT_H
