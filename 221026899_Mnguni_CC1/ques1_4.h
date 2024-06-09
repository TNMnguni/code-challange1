#pragma once
#ifndef TWELVE_MONTH_ACCOUNT_H
#define TWELVE_MONTH_ACCOUNT_H

#include "ques1_2.h" // Include necessary headers

class TwelveMonthAccount : public Account {
private:
    static float interestRate;

public:
   
    TwelveMonthAccount(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal);
    static void setInterestRate(float iR);
    float calculateInterest();
    float determineAmountPayable() override;
};

#endif // TWELVE_MONTH_ACCOUNT_H
