#pragma once
class Account
{
	int pin;
	int accountNumber;
	double avalaibleBalance;  //funds avalaible for withdrawal
	double totalBalance;  // funds avalaible + fuunds waiting to clear
public:
	Account(int,int,double,double);
	bool validatePIN(int)const; // user specified pin code-correct
	double getAvalaibleBalance()const; //return avalaible balance
	double getTotalBalance()const;  //return total balance
	int getAccountNumber()const;  //return account number
	~Account();
};

