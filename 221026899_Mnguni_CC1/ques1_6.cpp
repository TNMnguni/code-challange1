#include <string>
#include "ques1_2.h"
#include "ques1_1.h"
#include "ques1_3.h"
#include "ques1_5.h"
#include "ques1_4.h"
#include <iostream>

using namespace std;

const int MAXSIZE = 50;

int main()
{
    string fileName = "creditlimits.csv";
    Account::readAndSetCreditLimits(fileName);

    int accountNumber =0;
    char firstName[MAXSIZE];
    char surname[MAXSIZE];
    char accountCategory ='P';
    int repaymentCategory = 0;
    float balance = 0.0f;
    Account account(accountNumber, firstName, surname, accountCategory, repaymentCategory, balance);

  
    enterAccount(&account);

  
    SixMonthAccount six(accountNumber, firstName, surname, accountCategory, repaymentCategory, balance);


    Transaction* transactions = new Transaction[10];

    six.setClubFee(12.50);
    int numTransactions = enterTransactions(transactions);

    for (int i = 0; i < numTransactions; ++i) {
        six + transactions[i];
    }

    displayAccount(&six);

    Account* ptrAccount = &six;
    cout << "Amount payable for six: R" << ptrAccount->determineAmountPayable() << endl;

    TwelveMonthAccount* twelve = new TwelveMonthAccount(accountNumber, firstName, surname, accountCategory, repaymentCategory, balance);
    TwelveMonthAccount::setInterestRate(15.5);

    ptrAccount = twelve;
    cout << "Amount payable for TwelveMonthAccount: R" << ptrAccount->determineAmountPayable() << endl;

     delete[] transactions;
    delete twelve;

    return 0;
}