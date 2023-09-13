#include <string>
using namespace std; // Use namespace std

class Account {
private:
    string firstName, lastName, accountNum, userName, userPass;
    double balance;

public:
    Account(const string& firstName, const string& lastName, const string& userName, const string& userPass, double balance);
    void createUsername(const string& newUsername);
    void createPass(const string& newPass);
    bool validateLogin(const string& attemptUsername, const string& attemptPass);
    void deposit(double amount);
    void withdraw(double amount);
    void display() const;
};


