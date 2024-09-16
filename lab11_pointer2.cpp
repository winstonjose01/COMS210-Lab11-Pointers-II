#include <iostream>>
using namespace std;

const int NO_CUSTOMERS = 4;

struct BankCustomer{
    string first_name;
    string last_name;
    int phone;
    int social_security_no;
    int * bank_accounts;
    double * balance;
    
    ~BankCustomer() {
        if (bank_accounts)
            delete bank_accounts;
        bank_accounts = nullptr;
        if (balance)
            delete balance;
        balance = nullptr;

    }
};
// Function declaration
void inputCustomerInfo (BankCustomer *);
void printCustomerInfo (BankCustomer *);

main(){

    BankCustomer *customers = new BankCustomer[NO_CUSTOMERS];

    for (int i = 0; i < NO_CUSTOMERS; i++){
        inputCustomerInfo (&customers[i]);
    }

    for (int i = 0; i < NO_CUSTOMERS; i++){
        printCustomerInfo (&customers[i]);
    }

}

void inputCustomerInfo (BankCustomer * custptr){
    static int numCust = 1;
    cout << "Enter the account details for Customer #" << numCust << ": \n";

    cout << "First Name: ";
    getline(cin, custptr->first_name);
    cout << "Last Name: ";
    getline(cin, custptr->last_name);
    cout << "Phone No: ";
    cin >> custptr -> phoe
    cout 


}

void printCustomerInfor (BankCustomer *custptr){



}