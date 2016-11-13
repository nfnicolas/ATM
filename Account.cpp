
#include "Account.h"



Account::Account(int thePin,int theAccountNumber,double theAvalaible,double theTotal):
	pin(thePin),
	accountNumber(theAccountNumber),
	avalaibleBalance(theAvalaible),
	totalBalance(theTotal)
{
}

bool Account::validatePIN(int userPin) const
{
	if (userPin == pin)
		return true;
	else
		return false;
}

double Account::getAvalaibleBalance() const
{
	return avalaibleBalance;
}

double Account::getTotalBalance() const
{
	return totalBalance;
}

int Account::getAccountNumber() const
{
	return accountNumber;
}


Account::~Account()
{
}
