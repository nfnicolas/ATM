#include "Transaction.h"

Transaction::Transaction(int userAcountNumber, Screen &atmScreen, BankDatabase &atmBankDatabase):
	accountNumber(userAcountNumber),
	screen(atmScreen),
	bankDatabase(atmBankDatabase)
{
}

Transaction::~Transaction()
{
}

Screen & Transaction::getScreen() const
{
	return screen;
}

int Transaction::getAccountNumber() const
{
	return accountNumber;
}

BankDatabase & Transaction::getBankDatabase() const
{
	return bankDatabase;
}
