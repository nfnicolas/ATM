#include "WithDrawal.h"

static const int CANCELED = 6;  //the const that corresponed menu option to cancel

int WithDrawal::displayMenuOfAmounts() const
{
	int userChoice = 0;
	Screen&screen = getScreen();
	int amounts[] = { 0,20,40,60,100,200 };
	while (userChoice == 0)
	{
		screen.displayMessageLine("\nWithdrawal options");
		screen.displayMessageLine("1-$20");
		screen.displayMessageLine("2-$40");
		screen.displayMessageLine("3-$60");
		screen.displayMessageLine("4-$100");
		screen.displayMessageLine("5-$200");
		screen.displayMessageLine("6-Cancel transation");
		screen.displayMessage("\nChoise option from 1 to 6: ");

		int input = keypad.getInput(); //get input user's through keypad
		switch (input)
		{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			userChoice = amounts[input]; //save user's choice
			break;
		case CANCELED:
			userChoice = CANCELED; //save user's choice if canceled
			break;
		default:screen.displayMessageLine("\nInvalid selection. Try again");
		}
	}
	return userChoice; //return withdrawal amount or canceled
}

WithDrawal::WithDrawal(int userAcountNumber,Screen&atmScreen,BankDatabase&atmBankDatabase,
	CashDispenser&atmCashDispenser,Keypad&atmKeypad):Transaction(userAcountNumber,atmScreen,
		atmBankDatabase),cashDispenser(atmCashDispenser),keypad(atmKeypad)
{
}

void WithDrawal::execute()
{
	bool cashDispenced = false;
	bool transactionCanceled = false;
	BankDatabase&bankDataBase = getBankDatabase();
	Screen&screen = getScreen();
	do
	{
		int selection = displayMenuOfAmounts();
		if (selection != CANCELED)
		{
			amount = selection;
			double avalaibleBalance = bankDataBase.getAvalaibleBalance(getAccountNumber());
			if (amount <= avalaibleBalance)
			{
				if (cashDispenser.isSufficientCashAvalaibel(amount))
				{
					//bankDataBase.debit(getAccountNumber(), amount);
					cashDispenser.dispenserCash(amount);
					cashDispenced = true;
					screen.displayMessageLine("\nPlease take your cash from the cash dispenser");
				}
				else  //if havn't enough cash in the ATM
					screen.displayMessageLine(
						"\nInsufficient cash avalaible in the ATM"
						"\n\nPlease enter a smaller sum");
			}
			else //if havn't enough cash in user's account
				screen.displayMessageLine(
					"\nInsufficient funds in your account"
					"\n\nPlease enter a smaller sum");
		}
		else //user eneter wrong option
			screen.displayMessageLine("\nCanceled transaction\n");
		transactionCanceled = true; //user cancel transaction
	} while (!cashDispenced && !transactionCanceled);
}


WithDrawal::~WithDrawal()
{
}
