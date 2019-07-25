//SavingsAccount.h
#pragma once
#include <iostream>
#include <string>
#include "Account.h"
using namespace std;

class SavingsAccount : public Account
{
  protected:
	  bool status;
	  const double minBalance = 25.00;
	  const double serviceCharge = 1.00;
  public:
	  SavingsAccount(double balance, double aIR) : Account(balance, annualInterestRate) { status = true; this->balance = balance; annualInterestRate = aIR/100; }
	  bool checkStatus();
	  void withdraw(double amount);
	  void deposit(double amount);
	  void monthlyProc();
	  void viewBalance();
};

bool SavingsAccount::checkStatus() {
	//User cannot have lower than mininum balance, otherwise account will be inactive.
	if (balance < minBalance) {
		return false;   //false = inactive
	}
	return true;
}

void SavingsAccount::withdraw(double amount) {
	if (checkStatus()) {
		Account::withdraw(amount);
		if (!checkStatus()) {
			cout << "This withdrawal makes your account lower than the minimum balance needed ($25.00). Account is now inactive." << endl;
		}
	}
	else {
		cout << "Sorry, can't withdraw because account is inactive." << endl;
	}
}

void SavingsAccount::deposit(double amount) {
	double newBalance = balance + amount;
	if (newBalance > 25.00) {
		status = true;  //true = active
	}
	Account::deposit(amount);
	
}

void SavingsAccount::monthlyProc() {
	
	if (numWithdrawals > 3) {
		int numWOverMax = numWithdrawals - 3;
		//For every withdrawal more than 3, a service charge is taken.
		for (int i = 0; i < numWOverMax; i++) {
			balance -= serviceCharge;
		}
	}
}

void SavingsAccount::viewBalance() {
	cout << "Current Savings balance: $" << fixed << setprecision(2) << balance << endl;
}
