#CheckingAccount.h
#pragma once
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

class CheckingAccount : public Account
{
  protected:
	  const double serviceCharge = 15.00;
	  const double monthlyFee = 5.00;
  public:
	  CheckingAccount(double balance, double aIR) : Account(balance, annualInterestRate) { this->balance = balance; annualInterestRate = aIR/100; }
	  void withdraw(double amount);
	  void monthlyProc();
	  void viewBalance();
};

void CheckingAccount::withdraw(double amount) {
	double newBalance = balance - amount;

	//User cannot withdraw more than what they have in the account. $15 service charge will be taken instead.
	if (newBalance < 0) {
		cout << "Sorry, can't withdraw because account will go below $0." << endl;
		cout << "A service charge of $15.00 will be taken out of your account instead." << endl;
		balance -= serviceCharge;
		viewBalance();
	}
	else {
		Account::withdraw(amount);
	}
}

void CheckingAccount::monthlyProc() {
	monthlyServiceCharges += monthlyFee + (numWithdrawals * 0.10);
	balance -= monthlyServiceCharges;
}

void CheckingAccount::viewBalance() {
	cout << "Current Checking balance: $" << fixed << setprecision(2) << balance << endl;
}
