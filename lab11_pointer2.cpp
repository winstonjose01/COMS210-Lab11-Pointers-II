// COMSC 210 | Lab 11 | Winston Jose
// Github link: https://github.com/winstonjose01/COMS210-Lab11-Pointers-II


#include <iostream>
#include <limits>
#include <string>
#include <cctype>
using namespace std;

// Global variables
const int NO_CUSTOMERS = 3; // No of bank customers
int total_accounts; // Variable to hold number of bank accts

// Bank customer struct
struct BankCustomer{
    string first_name;          // Customer's first name
    string last_name;           // Customers's last name
    int social_security_no;     // Customers last 4 digit SSN
    int * bank_accounts;        // Customer's bank accout no.
    double * balance;           // Customer's bank account balance
    
    ~BankCustomer() {
        if (bank_accounts)
            delete bank_accounts; // Deallocate memory for bank accounts
        bank_accounts = nullptr;  // Set pointer to nullptr
        if (balance)
            delete balance;       // Deallocate memory for balance
        balance = nullptr;        // Set pointer to nullptr

    }
};
// Function declaration
void inputCustomerInfo (BankCustomer *); // Function to input customer info
void printCustomerInfo (BankCustomer *); // Function to print customer info
bool validateInputInt (int &);           // Validation of integer input
bool validateInputDouble (double &)      // Validation of string input
;
int main(){
    // Dynamically allocate memory for a array of BankCustomer objects
    BankCustomer *customers = new BankCustomer[NO_CUSTOMERS];

    // Loop to gather information for each customer
    for (int i = 0; i < NO_CUSTOMERS; i++){
        inputCustomerInfo (&customers[i]);
    }
    // Loop to print customer information
    cout << "-------------------------------------------------\n";
    for (int i = 0; i < NO_CUSTOMERS; i++){
        printCustomerInfo (&customers[i]);
    }
    // Deallocate memory for the customers array
    delete [] customers;

    return 0;
}

// This functon will populate the BankCustomer struct with user input
// Arguments: Struct pointer to a BankCustomer object
// Returns: No return
void inputCustomerInfo (BankCustomer *cptr){
    static int numCust = 1;
    cout << "\nEnter the account details for Customer #" << numCust << ": \n";

    cout << "First Name: ";
    getline(cin, cptr -> first_name); // Input first name

    cout << "Last Name: ";
    getline(cin, cptr -> last_name); // Input last name

    // Input and validate the last 4 digits of SSN 
    cout << "Last 4 digits of Social Security No: ";
    while (!validateInputInt (cptr -> social_security_no));
    // Input qty of account no
    cout << "How many account does this customer have: ";
    cin >> total_accounts;
    
    //Dynamically allocate memory for banks account and balance
    cptr -> bank_accounts = new int[total_accounts];
    cptr -> balance = new double[total_accounts];

    // Iterate the customer count
    numCust++;

    // Loop to input the account number and balance
    for (int i = 0; i < total_accounts; i++){
        // Input and validate account no
        cout << "\nEnter the account number for #" << i+1 <<": ";
        while(!validateInputInt (cptr -> bank_accounts[i]));
        // Input and validate balance
        cout << "Enter the balance for account number #" << i+1 <<": ";
        while(!validateInputDouble (cptr -> balance[i]));

    cin.ignore(); //Ignore the newline in the buffer
    }
}

// This functon will print the BankCustomer struct elements
// Arguments: Struct pointer to a BankCustomer object
// Returns: No return
void printCustomerInfo (BankCustomer *cptr){
    // Display the customer name
    cout << "Customer Name : " << cptr ->first_name << " " << cptr -> last_name << "\n";
    
    // Display the last 4 digits of SSN
    cout << "Last 4 Digits of SSN: " << cptr ->social_security_no << "\n";

    // Display account numbers and balances
    cout << "Accounts and Balance: \n";
    for (int i = 0; i < total_accounts ; i++){
        cout << "\t" << i + 1 <<". Account No :"<< cptr -> bank_accounts[i] << "\t|\t";
        cout << "Balance: $" << cptr -> balance[i] << "\n";
    }
    cout <<"\n";
}
// This function validates integer input
// Arguments: Reference to an integer variable
// Returns: True if input is valid, false otherwise
bool validateInputInt(int &input){
    cin >> input;
    if (cin.fail()){
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input. Please enter a valid number :";
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return true;
}

// This function validates double input
// Arguments: Reference to an double variable
// Returns: True if input is valid, false otherwise
bool validateInputDouble (double &input){
    cin >> input;
    if (cin.fail()){
        cin.clear(); // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid input. Please enter a valid number :";
        return false;
    }
    return true;
}