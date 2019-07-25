//Source.cpp
#include "Account.h"
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
	double initialCBalance;
	double initialSBalance;
	double interestRate = 0;

	cout << "Enter initial balance for your Savings Account: $";
	cin >> initialSBalance;
	cin.ignore();

	cout << "Enter initial balance for your Checking Account: $";
	cin >> initialCBalance;
	cin.ignore();

	cout << "What is the annual interest rate? (out of 100%): ";
	cin >> interestRate;
	cin.ignore();

	CheckingAccount checking(initialCBalance, interestRate);
	SavingsAccount savings(initialSBalance, interestRate);

	int choice;
	double amount;

	cout << endl;
	cout << "WELCOME TO YOUR BANK ACCOUNT" << endl;
	cout << "Here are your options: " << endl;
	cout << "1: Deposit into Savings Account" << endl;
	cout << "2: Deposit into Checking Account" << endl;
	cout << "3: Withdraw from Savings Account" << endl;
	cout << "4: Withdraw from Checking Account" << endl;
	cout << "5: View Account Balance" << endl;
	cout << "6: Update and Display Account Statistics" << endl;

	do {
		cout << endl;
		cout << "Enter an option (1-6, 0 to Exit): ";
		cin >> choice;
		
		switch (choice) {
		case 0:
			cout << "Goodbye!" << endl;
			break;

		case 1:
			cout << "Enter an amount to deposit into your Savings Account: $";
			cin >> amount;
			savings.deposit(amount);
			break;

		case 2:
			cout << "Enter an amount to deposit into your Checking Account: $";
			cin >> amount;
			checking.deposit(amount);
			break;

		case 3:
			cout << "Enter amount to withdraw from your Savings Account: $";
			cin >> amount;
			savings.withdraw(amount);
			break;

		case 4:
			cout << "Enter an amount to withdraw from your Checking Account: $";
			cin >> amount;
			checking.withdraw(amount);
			break;

		case 5:
			cout << "Which account would you like to view? (1: Savings, 2: Checking) ";
			int viewChoice;
			cin >> viewChoice;
			cin.ignore();

			switch (viewChoice) {
			case 1:
				savings.viewBalance();
				break;
			case 2:
				checking.viewBalance();
				break;
			default:
				break;
			}
			break;
		case 6:
			cout << endl;
			cout << "SAVINGS ACCOUNT MONTHLY STATISTICS:\n";
			savings.Account::monthlyProc();
			cout << endl;
			cout << "CHECKING ACCOUNT MONTHLY STATISTICS:\n";
			checking.Account::monthlyProc();

			break;
		
		default:
			cout << "Invalid option selected!\n";
			cin.ignore();
			break;
		}
	} while (choice != 0);

	return 0;
}
