// COMSC 210 | 

#include <iostream>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

const int NO_CUSTOMERS = 2;
int total_accounts;

struct BankCustomer{
    string first_name;
    string last_name;
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
bool validateInputInt (int &);
bool validateInputDouble (double &)
;
int main(){
    BankCustomer *customers = new BankCustomer[NO_CUSTOMERS];

    for (int i = 0; i < NO_CUSTOMERS; i++){
        inputCustomerInfo (&customers[i]);
    }
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < NO_CUSTOMERS; i++){
        printCustomerInfo (&customers[i]);
    }

    return 0;
}

void inputCustomerInfo (BankCustomer *cptr){
    static int numCust = 1;
    cout << "Enter the account details for Customer #" << numCust << ": \n";

    cout << "First Name: ";
    getline(cin, cptr -> first_name);
    cout << "Last Name: ";
    getline(cin, cptr -> last_name);
    cout << "Last 4 digits of Social Security No: ";
    while (true){
        cin >> cptr -> social_security_no;
        if (cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "Invalid input\n";
            cout << "Enter the right value :";
        }
        else {
                break;
            }
    }
    cout << "How many account does this customer have: ";
    cin >> total_accounts;
    cptr -> bank_accounts = new int[total_accounts];
    cptr -> balance = new double[total_accounts];
    for (int i = 0; i < total_accounts; i++){
        cout << "\nEnter the account number for #" << i+1 <<": ";
        while(!validateInputInt(cptr -> bank_accounts[i]));
        cout << "Enter the balance for account number #" << i+1 <<": ";
       //cin >> cptr -> balance[i];
       // Input validation
        while(!validateInputDouble (cptr -> balance[i]));

    cin.ignore();
    numCust++;
}
}

void printCustomerInfo (BankCustomer *cptr){

    cout << "Customer Name : " << cptr ->first_name << " " << cptr -> last_name << "\n";
    cout << "Last 4 Digits of SSN: " << cptr ->social_security_no << "\n";
    cout << "Accounts and Balance: \n";
    for (int i = 0; i < total_accounts ; i++){
        cout << i + 1 <<". Account No :"<< cptr -> bank_accounts[i] << "\t|\t";
        cout << "Balance: $" << cptr -> balance[i] << "\n";
    }
    cout <<"\n";
}

bool validateInputInt(int &input){
    cin >> input;
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input. Please enter a valid number :";
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

bool validateInputDouble (double &input){
    cin >> input;
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input. Please enter a valid number :";
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}