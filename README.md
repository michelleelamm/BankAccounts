# BankAccounts
C++ School project where user keeps track of Savings and Checking Accounts, including monthly service charges/fees and annual interest rate.

For both accounts: 
When user chooses to show monthly statistics, it automatically assumes the month has ended.

Rules for Savings Account: 
Minimum balance required is $25.00. User can withdraw as much money as they want. However, if the withdrawal makes the account fall under the minimum balance, account will become inactive. After account becomes inactive, there cannot be anymore withdrawals until user deposits enough to meet the minimum balance requirement (which makes the account active again). If number of withdrawals in a month exceeds three (3), for every withdrawal after the third, a service charge of $1 is taken. 

Rules for Checking Account:
No minimum balance. Monthly Fee of $5. User cannot withdraw more than what they have in the account. $15 service charge will be taken instead. 10% of the number of withdrawals is added to total monthly service charges.
