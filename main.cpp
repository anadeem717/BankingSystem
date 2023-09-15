#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Account.h" // Include your Account class header here

using namespace std;

/*
    Function that checks to see if the password user created is strong to help ensure a secured account. 
    Password must contain at least:
    - 10 characters
    - 1 special character
    - 2 numbers
    - 1 uppercase leter
*/
bool isStrongPassword(const string& password) {
    // Password must be at least 10 characters long
    if (password.length() < 10) {
        return false; 
    }
    bool specialChar = false; 
    int numDigit = 0; 
    bool upperCase = false;

    // loop that iterates through each character in password and checks password rules. 
    for (int i = 0; i < password.length(); i++) {
        char charCurrent = password[i];

        if (isdigit(charCurrent)) {
            numDigit++;
        } 
        else if (isupper(charCurrent)) {
            upperCase = true;
        } 
        else if (ispunct(charCurrent) || charCurrent == ' ' || charCurrent == '\t') {
            specialChar = true;
        }
    }

    // if the password meets the criteria returns true, otherwise false
    return (specialChar && numDigit >= 2 && upperCase);
}


int main() {

    // ***WORK ON MODULARIZING main() BY CREATING FUNCTIONS FOR MENU AND LOGIN***

    vector<Account> allAccounts; // array to store accounts registered 
    int choice = 0; // options for menu

    // runs the main program until the user quits out of program
    while (true) {
        cout << "********** Welcome to ARNAD Bank **********" << endl;
        cout << "1. Register an account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Process for registering an account...
        if (choice == 1) {
            string firstName, lastName, userName, userPass;
            double balance;

            cout << "Enter your first name: ";
            cin >> firstName;
            cout << "Enter your last name: ";
            cin >> lastName;
            cout << "Create a username: ";
            cin >> userName;
            cout << endl;

            // following loop will keep iterating until a strong password is created. 
            do {
                cout << "Create a password:" << endl;
                cout << "Password must contain:" << endl << "- At least 10 characters" << endl << "- At least 1 special character" << endl << "- At least 1 uppercase letter" << endl << "- At least 2 numbers" << endl;
                cin >> userPass;
                cout << endl;

                // if password is weak, will restart the loop and program will ask user to try again. 
                if (!isStrongPassword(userPass)) {
                    cout << "INVALID PASSWORD... Please try again to make a strong password." << endl << endl;
                    continue;
                }
                cout << "PASSWORD VALID... " << endl;
            } while (!isStrongPassword(userPass));

            // deposit money for inital balance. 
            cout << "How much would you like to initially deposit into your account?: ";
            cin >> balance;
            cout << endl;

            // Account for user is added to array of all accounts 
            // ***Have to work on saving registered accounts even when program is terminated...***
            allAccounts.push_back(Account(firstName, lastName, userName, userPass, balance));
            cout << "**************************************************" << endl;
            cout << "Account for " << firstName << " " << lastName << " successfully registered." << endl;
            cout << "**************************************************" << endl << endl;
        }
        // if user chooses to login, which will then allow them to access main banking system. 
        else if (choice == 2) {
            string attemptUsername, attemptPass;
            cout << "Enter your username: ";
            cin >> attemptUsername;
            cout << "Enter your password: ";
            cin >> attemptPass;
            cout << endl;
            
            // iterates through vector and checks to see if username / pasword matches an account in array
            for (Account& account : allAccounts) {
                if (!account.validateLogin(attemptUsername, attemptPass)) {
                    cout << "Incorrect login, please try again." << endl << endl;
                }
                
                // if user successfully logged in they can now access main banking system...
                else if (account.validateLogin(attemptUsername, attemptPass)) {
                    cout << "*******************" << endl;
                    cout << "Login successful..." << endl;
                    cout << "*******************" << endl << endl;

                    while (choice != 4) {
                        /*
                        Main banking system for user:
                        1. User can add funds to account
                        2. User can withdraw funds from account
                        3. Account info is displayed (account number, balance, and first/last name)
                        4. Returns to registration / login menu
                        */ 
                        cout << "********** Main Menu **********" << endl;
                        cout << "1. Deposit" << endl;
                        cout << "2. Withdraw" << endl;
                        cout << "3. View account information" << endl;
                        cout << "4. Logout" << endl;
                        cout << "Enter your choice: ";
                        
                        cin >> choice;
                        cout << endl;

                        if (choice == 1) {
                            double depositAmount;
                            cout << "Enter the amount you would like to deposit: ";
                            cin >> depositAmount;
                            cout << endl;
                            account.deposit(depositAmount);
                        } 
                        
                        else if (choice == 2) {
                            double withdrawAmount;
                            cout << "Enter the amount you would like to withdraw: ";
                            cin >> withdrawAmount;
                            cout << endl;
                            account.withdraw(withdrawAmount);
                        } 
                        
                        else if (choice == 3) {
                            account.display();
                        } 
                        
                        else if (choice == 4) {
                            cout << "*********************************************************************" << endl;
                            cout << "Logged out successfully." << endl;
                            cout << "*********************************************************************" << endl;
                            break;
                        } 
                        
                        else {
                            cout << "Invalid choice, please enter a valid option." << endl;
                        }
                    }

                    break; 
                }
            }
        } 

        else if (choice == 3) {
            cout << "Thank you for using ARNAD Bank. Have a nice day!" << endl;
            break;
        } 

        else {
            cout << "Invalid input, please enter 1 to register an account, 2 to login, or 3 to quit." << endl;
        }
    }

    return 0;
}

