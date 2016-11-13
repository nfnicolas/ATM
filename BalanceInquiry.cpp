#include "BalanceInquiry.h"



BalanceInquiry::BalanceInquiry(int userAccountNumber,Screen&atmScreen,BankDatabase&atmBantDatebase):
	Transaction(userAccountNumber,atmScreen,atmBantDatebase)
{
}


BalanceInquiry::~BalanceInquiry()
{
}

void BalanceInquiry::execute()
{
	BankDatabase&bankDatebase = getBankDatabase();
	Screen&screen = getScreen();
	double avalaibleBalance = bankDatebase.getAvalaibleBalance(getAccountNumber());
	double totalBalance = bankDatebase.getTotalBalance(getAccountNumber());
	screen.displayMessageLine("\nBalance Information: ");
	screen.displayMessage("-Avalaible balance: ");
	screen.displayDollarAmount(avalaibleBalance);
	screen.displayMessage("-Total balance: ");
	screen.displayDollarAmount(totalBalance);
	screen.displayMessage("");

}
