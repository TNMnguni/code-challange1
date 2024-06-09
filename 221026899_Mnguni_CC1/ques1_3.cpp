#include "ques1_2.h"

using namespace std;
class SixMonthAccount : public Account {
private:
    static float clubFee;

public:
    
    SixMonthAccount(int accNo, const char* fName, const char* sName, char accCat, int repCat, float bal)
        : Account(accNo, fName, sName, accCat, repCat, bal) {
        
    };

   
    static void setClubFee(float cF);
    
    float determineAmountPayable()override {
        float amountPayable = getBalance() / 6; // Divide balance by 6 months
        if (amountPayable < 100.0) {
            amountPayable = 100.0; // Ensure minimum payment of 100.0
        }
        amountPayable += clubFee; // Add club fee
        return amountPayable;
    }
};

void SixMonthAccount::setClubFee(float cF) {
    clubFee = cF;
}

float SixMonthAccount::clubFee = 0.0;