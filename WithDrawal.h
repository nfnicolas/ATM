#pragma once
#include"Transaction.h"
#include"BankDatabase.h"
#include"CashDispenser.h"
#include"Screen.h"
#include"Keypad.h"
class CashDispenser;
class Keypad;

class WithDrawal:public Transaction
{
	int amount;
	CashDispenser&cashDispenser;
	Keypad&keypad;
	int displayMenuOfAmounts()const;
public:
	WithDrawal(int,Screen&,BankDatabase&,CashDispenser&,Keypad&);
	virtual void execute();
	~WithDrawal();
};

