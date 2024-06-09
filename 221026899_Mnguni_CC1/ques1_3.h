#pragma once
#ifndef SIX_MONTH_ACCOUNT_H
#define SIX_MONTH_ACCOUNT_H

#include "ques1_2.h" // Include necessary headers

class SixMonthAccount : public Account {
private:
    static float clubFee;

public:
    
    SixMonthAccount(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal);
    static void setClubFee(float cF);
    float determineAmountPayable() override;
};

#endif // SIX_MONTH_ACCOUNT_H
