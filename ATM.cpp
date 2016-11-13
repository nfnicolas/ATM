#include "ATM.h"


void ATM::authenticatedUser()
{
	screen.displayMessage("\nPlease enter your account number");
	int accountNumber = keypad.getInput();//input account number
	screen.displayMessage("\nEnter your pin");
	int pin = keypad.getInput();//input the pin

	userAuthenticated = bankDatabase.authenticateUser(accountNumber, pin); //check authenticated user from bankDatabase
	if (userAuthenticated)
	{
		currentAccountNumber = accountNumber; //save account#
	}
	else
		screen.displayMessageLine("\nInvalid account number or pin. Try again");
}

void ATM::performTransaction()
{
	Transaction*currentTransaction_ptr; //pointer to store transaction currently being processed
	bool userExit = false; //user not chosen to exit

	while (!userExit)  //user has not chosen option to exit system
	{
		int mainSelection = displayMainMenu();
		switch (mainSelection)
		{
		case BALANCE_INQUIRY:
		case WITHDRAWAL:

			currentTransaction_ptr = createTransaction(mainSelection);//initial as new object of chosen type
			currentTransaction_ptr->execute(); //execute transaction
			delete currentTransaction_ptr;
			break;
		case EXIT:
			screen.displayMessageLine("\nExiting the system");
			userExit = true;  //this session end
			break;
		default:screen.displayMessageLine("\nYou did not valid selection. Try again.");
			break;
		}
	}
}

int ATM::displayMainMenu() const
{
	screen.displayMessageLine("\nMain Menu");
	screen.displayMessageLine("1-View my balance");
	screen.displayMessageLine("2-Withdrawal cash");
	screen.displayMessageLine("3-Exit\n");
	screen.displayMessageLine("Enter your choice: ");
	return keypad.getInput();  //return user's selection
}

Transaction * ATM::createTransaction(int type)
{
	Transaction*tempPtr=nullptr; //create a temporary pointer

	switch (type)  //determenit which type to create of transaction
	{
	case BALANCE_INQUIRY:  //create a new balance inquiry
		tempPtr = new BalanceInquiry(currentAccountNumber, screen, bankDatabase);
		break;
	case WITHDRAWAL:
		tempPtr = new WithDrawal(currentAccountNumber, screen, bankDatabase,cashDispenser, keypad);
		break;
	}
	return tempPtr;
}


//user is not authenticated to start and no current account number to start
ATM::ATM():userAuthenticated(false),currentAccountNumber(0)
{
}

void ATM::run()
{
	while (true)
	{
		while (!userAuthenticated) //user is yet not authenticated
		{
			screen.displayMessageLine("\nWelcom");
			authenticatedUser();
		}
		performTransaction(); // user is now authenticated
		userAuthenticated = false;  //reset before next ATM session
		currentAccountNumber = 0;   //reset before next ATM session
		screen.displayMessageLine("\nThank you. Good bye! ");
	}
}


ATM::~ATM()
{
}
