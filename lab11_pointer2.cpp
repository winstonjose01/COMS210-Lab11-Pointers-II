#include <iostream>>
using namespace std;


struct BankCustomer{

    string first_name;
    string last_name;
    int phone_no;
    int social_security_no;
    int * no_bank_accounts;
    double * balance;
    
    ~BankCustomer() {
        if (no_bank_accounts)
            delete no_bank_accounts;
        no_bank_accounts = nullptr;
        if (balance)
            delete balance;
        balance = nullptr;

    }
};

main(){

    
}