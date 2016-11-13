#pragma once
#include<iostream>
#include<string>
using namespace std;
class Screen
{
public:
	void displayMessage(string)const;  //output a message
	void displayMessageLine(string)const; //output a new line line message
	void displayDollarAmount(double)const; // output dollar amount
};

