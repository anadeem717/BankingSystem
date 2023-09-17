#include "Account.h"
#include <iostream>
#include <cstdlib>
using namespace std; 

// start assigning account numbers from 10000. Example, would be AN10001, AN10002, etc.
int Account::assignAccountNum = 10000;

// defining constructor for class Account
Account::Account(const string& firstName, const string& lastName, const string& userName, const string& userPass, double balance)

    :firstName(firstName), lastName(lastName), accountNum("AN" + to_string(assignAccountNum)), userName(userName), userPass(userPass), balance(balance) {

    assignAccountNum++; // iterates to next account number
}

// function that initializes the user's username to their account 
void Account::createUsername(const string& newUsername) {
    userName = newUsername;
}

// function that initializes the user's password to their account.
void Account::createPass(const string& newPass) {
    userPass = newPass;
}

// checks to see if the attempted username and password matches the registered username / password
bool Account::validateLogin(const string& attemptUsername, const string& attemptPass) {
    return (attemptUsername == userName && attemptPass == userPass);
}

// method for depositing money into user's account
void Account::deposit(double amount) {
    balance += amount;
    cout << "$" << amount << " Has been successfully deposited. New balance is $" << balance << endl;
}

// method for witdrawing money from user's account
void Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "$" << amount << " Has been successfully withdrawn. New balance is $" << balance << endl;
    } 
    else {
        cout << "Insufficient funds." << endl; // if the amount the user wants to withdraw exceeds their balance
    }
}

// method for displaying the user's account information
void Account::display() const {
    cout << "Account information for " << firstName << " " << lastName << ":" << endl;
    cout << "Your Account number: " << accountNum << endl;
    cout << "Total Balance: $" << balance << endl;
}
