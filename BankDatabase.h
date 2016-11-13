#pragma once
#include<vector>
#include"Account.h"
using namespace std;
class BankDatabase
{
	vector<Account>accounts; //accounts of the bank
	Account*getAccount(int); //pointer to Account object
public:
	BankDatabase();
	bool authenticateUser(int, int); //determinit account user and your pin
	double getAvalaibleBalance(int); //get an avalaible balance
	double getTotalBalance(int); //get a total balance
	~BankDatabase();
};

