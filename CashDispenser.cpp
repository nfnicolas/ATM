#include "CashDispenser.h"



CashDispenser::CashDispenser()
{
}

void CashDispenser::dispenserCash(int amount)
{
	int billsRequired = amount;
	count -= billsRequired; //upgrate the count of bills
}

bool CashDispenser::isSufficientCashAvalaibel(int amount) const
{
	int billsRequired = amount / 20; //number of $20 bills required
	if (count >= billsRequired)
		return true;  //enough bills are avalaible
	else
	return false;  //not enough bills avalaible
}


CashDispenser::~CashDispenser()
{
}
