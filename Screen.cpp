#include "Screen.h"

void Screen::displayMessage(string message) const
{
	cout << message<<endl;
}

void Screen::displayMessageLine(string message) const
{
	cout << message<<endl;
}

void Screen::displayDollarAmount(double amount) const
{
	cout << "$" << amount<<endl;
}
