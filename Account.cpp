#include "Account.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; // Use namespace std

Account::Account(const string& firstName, const string& lastName, const string& userName, const string& userPass, double balance)
    : firstName(firstName), lastName(lastName), accountNum('A' + to_string(rand() % 10000 + 1000)), userName(userName), userPass(userPass), balance(balance) {}

void Account::createUsername(const string& newUsername) {
    userName = newUsername;
}

void Account::createPass(const string& newPass) {
    userPass = newPass;
}

bool Account::validateLogin(const string& attemptUsername, const string& attemptPass) {
   
    return (attemptUsername == userName && attemptPass == userPass);
}

void Account::deposit(double amount) {
    balance += amount;
    cout << "$" << amount << " Successfully deposited. New balance is $" << balance << endl;
}

void Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "$" << amount << " Successfully withdrawn. New balance is $" << balance << endl;
    } else {
        cout << "Insufficient funds." << endl;
    }
}

void Account::display() const {
    cout << "Account information for " << firstName << " " << lastName << ":" << endl;
    cout << "Account number: " << accountNum << endl;
    cout << "Balance: $" << balance << endl;
}
