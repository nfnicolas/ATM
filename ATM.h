#pragma once
#include"BalanceInquiry.h"
#include"Transaction.h"
#include"WithDrawal.h"
#include"CashDispenser.h"
#include"BankDatabase.h"
#include"Keypad.h"
#include"Screen.h"
enum MenuOption{BALANCE_INQUIRY=1,WITHDRAWAL,EXIT};
class ATM
{
	bool userAuthenticated;
	int currentAccountNumber;
	Screen screen;
	BankDatabase bankDatabase;
	Keypad keypad;
	CashDispenser cashDispenser;
	void authenticatedUser(); //atempt to authenticate user
	void performTransaction();// perform transaction
	int displayMainMenu()const; //display menu ATM
	Transaction*createTransaction(int);
public:
	ATM();
	void run();
	~ATM();
};

