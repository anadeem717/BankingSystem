#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Account.h" // Include your Account class header here

using namespace std;

// Function declaration for isStrongPassword
bool isStrongPassword(const string& password);

int main() {
    srand(static_cast<unsigned>(time(0)));
    vector<Account> accounts;
    int choice = 0;

    while (true) {
        cout << "********** Welcome to ARNAD Bank **********" << endl;
        cout << "1. Register an account" << endl;
        cout << "2. Login" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

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

            do {
                cout << "Create a password:" << endl;
                cout << "Password criteria: at least 10 characters, 1 special character, 1 uppercase letter, and 2 numbers: ";
                cin >> userPass;
                cout << endl;
                if (!isStrongPassword(userPass)) {
                    cout << "INVALID PASSWORD... Please try again to make a strong password." << endl << endl;
                    continue;
                }
                cout << "PASSWORD VALID. " << endl;
            } while (!isStrongPassword(userPass));

            cout << "How much would you like to initially deposit into your account?: ";
            cin >> balance;
            cout << endl;

            accounts.push_back(Account(firstName, lastName, userName, userPass, balance));
            cout << "**************************************************" << endl;
            cout << "Account for " << firstName << " " << lastName << " successfully registered." << endl;
            cout << "**************************************************" << endl << endl;
        }
        // Inside the main function's choice == 2 block
        else if (choice == 2) {
            string attemptUsername, attemptPass;
            cout << "Enter your username: ";
            cin >> attemptUsername;
            cout << "Enter your password: ";
            cin >> attemptPass;
            cout << endl;

            for (Account& account : accounts) {
                if (!account.validateLogin(attemptUsername, attemptPass)) {
                    cout << "Incorrect login, please try again." << endl << endl;
                }
                
                else if (account.validateLogin(attemptUsername, attemptPass)) {
                    cout << "*******************" << endl;
                    cout << "Login successful..." << endl;
                    cout << "*******************" << endl << endl;

                    while (choice != 4) {
                        // Display the menu for the logged-in user
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

                    break; // Exit the loop after a successful login
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

// Function definition for isStrongPassword
bool isStrongPassword(const string& password) {
    if (password.length() < 10) {
        return false; // Password is not at least 10 characters long
    }

    bool specialChar = false;
    int numDigit = 0;
    bool upperCase = false;

    for (char c : password) {
        if (isdigit(c)) {
            numDigit++;
        } 

        else if (isupper(c)) {
            upperCase = true;
        } 

        else if (ispunct(c) || c == ' ' || c == '\t') {
            specialChar = true;
        }
    }

    // Check if the password meets the criteria
    return (specialChar && numDigit >= 2 && upperCase);
}
