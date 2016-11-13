#include "BankDatabase.h"



Account * BankDatabase::getAccount(int accountNumber)
{
	for (size_t i = 0; i < accounts.size(); ++i)   //loop for matches account numbers
	{
		if (accounts[i].getAccountNumber() == accountNumber)
			return &accounts[i];
	}
	return nullptr; //if not match account number
}

BankDatabase::BankDatabase() //creat two accounts for exemple
{
	Account account1(1234,2345,3456,4567);
	Account account2(4749, 5657, 2345, 9876);
	accounts.push_back(account1);
	accounts.push_back(account2);
}

bool BankDatabase::authenticateUser(int accountUser, int pinUser)
{
	Account*const account_ptr = getAccount(accountUser); //atempt to retrieve account number
	if (account_ptr != nullptr)
		return account_ptr->validatePIN(pinUser);
	else
		return false; //account not found
}

double BankDatabase::getAvalaibleBalance(int accountUser)
{
	Account*const account_ptr = getAccount(accountUser); //get avalaible balance
	return account_ptr->getAvalaibleBalance();
}

double BankDatabase::getTotalBalance(int accountUser)
{
	Account*const account_ptr = getAccount(accountUser); //get total balance
	return account_ptr->getTotalBalance();
}


BankDatabase::~BankDatabase()
{
}
