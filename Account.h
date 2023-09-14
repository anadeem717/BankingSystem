#include <string>
using namespace std; 

class Account {
private:

// defining private variables to be used only within the class...
    string firstName, lastName, accountNum, userName, userPass;
    double balance;
    static int assignAccountNum; // fixed variable for the account number of the user. 

public:
// public variables and methods to be used from anywhere, methods are further explained in the account.cpp file. 
    Account(const string& firstName, const string& lastName, const string& userName, const string& userPass, double balance);
    void createUsername(const string& newUsername);
    void createPass(const string& newPass);
    bool validateLogin(const string& attemptUsername, const string& attemptPass);
    void deposit(double amount);
    void withdraw(double amount);
    void display() const;
};


