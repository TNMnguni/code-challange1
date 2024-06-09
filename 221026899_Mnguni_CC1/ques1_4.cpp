#include "ques1_2.h"

using namespace std;

class TwelveMonthAccount : public Account {
private:
    static float interestRate;

public:
    TwelveMonthAccount() : Account(0, "", "", 'P', 1, 0.0) {};
    

    TwelveMonthAccount(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal)
        : Account(accNo, fName, sName, accCat, repCat, bal) {

    };
    static void setInterestRate(float iR);
    
    float calculateInterest() {
        float interest = getBalance() * (interestRate / 100);
        return interest;
    }
    float determineAmountPayable()override {
        float amountPayable = getBalance() + calculateInterest() / 12; // Divide balance plus interest rate by 12 months
        if (amountPayable < 200.0) {
            amountPayable = 200.0; // Ensure minimum payment of 200.0
        }
        return amountPayable;
    }
};

void TwelveMonthAccount::setInterestRate(float iR) {
    interestRate = iR;
}

float TwelveMonthAccount::interestRate = 0.0;