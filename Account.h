//Account.h
#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Account
{
  protected:
	  double balance = 0.0;
	  int numDeposits = 0;
	  int numWithdrawals = 0;
	  double annualInterestRate = 0.0;
	  double monthlyServiceCharges = 0.0;
  public:
	  Account(double b, double a) { balance = b; annualInterestRate = a; }
	  virtual void deposit(double amount);
	  virtual void withdraw(double amount);
	  void calcInt();
	  virtual void monthlyProc();
};

void Account::deposit(double amount) {
	balance += amount;
	numDeposits++;
}

void Account::withdraw(double amount) {
	balance -= amount;
	numWithdrawals++;
}

void Account::calcInt() {
	double monthlyInterestRate = annualInterestRate / 12;
	balance += (balance * monthlyInterestRate);
}

void Account::monthlyProc() {
	balance = balance - monthlyServiceCharges;
	calcInt();
	cout << "Number of Withdrawals: " << numWithdrawals << endl;
	cout << "Number of Deposits: " << numDeposits << endl;
	cout << "Ending balance: $" << fixed << setprecision(2) << balance << endl;

	//Reset number of withdrawals and deposits
	numWithdrawals = 0;
	numDeposits = 0;

}
