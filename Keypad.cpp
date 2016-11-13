#include "Keypad.h"

int Keypad::getInput() const
{
	int input;
	cin >> input; //we assumed that user enteres integer
	return input;
}
