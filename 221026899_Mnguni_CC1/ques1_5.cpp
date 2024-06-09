#include "ques1_1.h"
#include "ques1_2.h" 
#include <iostream>
#include <sstream>
#include <string>
using namespace std;


const int MAXSIZE = 50; 

int enterTransactions(Transaction* transactionArray) {
    int accountNumber;
    int transactionType;
    float transactionAmount;
    char answer = 'Y';
    int trans = 0;

    while (answer == 'Y' || answer == 'y') {
        cout << "For transaction " << trans + 1 << " enter:\n";
        cout << "\tAccount number: ";
        cin >> accountNumber;
        cout << "\tTransaction type (1 for payment, 2 for purchase): ";
        cin >> transactionType;
        cout << "\tTransaction amount: R";
        cin >> transactionAmount;

        // Set the transaction here
        transactionArray[trans].setTransaction(accountNumber, transactionType, transactionAmount);

        cout << "Do you want to enter another transaction? (Y for yes, N for no): ";
        cin >> answer;
        trans++;
    }

    return trans; // Return the number of transactions entered
}

void enterAccount(Account* accountObj) {
    int accountNumber;
    char firstName[MAXSIZE];
    char surname[MAXSIZE];
    char accountCategory;
    int repaymentCategory;
    float balance;

    cout << "\tAccount number: ";
    cin >> accountNumber;
    cout << "\tFirst name: ";
    cin >> firstName;
    cout << "\tSurname: ";
    cin >> surname;
    cout << "\tAccount Category (P for Platinum, G for Gold, S for Silver, B for Bronze): ";
    cin >> accountCategory;
    cout << "Repayment Category (1, 2 or 3): ";
    cin >> repaymentCategory;
    cout << "Current Balance: ";
    cin >> balance;

    // Set account details
    accountObj->setAccount(accountNumber, firstName, surname, repaymentCategory, accountCategory, balance);
}

void displayAccount(Account* accountObj) {
    string accountDetails;

    // Get account details
    accountDetails = accountObj->getAccount();

    // Get amount payable
    float amntPayable = accountObj->determineAmountPayable();

    // Display account information
    cout << "Account Details:\n";
    cout << accountDetails;
    cout << "\tAmount Payable: R" << amntPayable << endl;
}
