#pragma once
class Screen;
class BankDatabase;

class Transaction
{
	int accountNumber;  //indicates account involved
	Screen&screen;
	BankDatabase&bankDatabase;
public:
	Transaction(int,Screen&,BankDatabase&);
	virtual ~Transaction();
	Screen&getScreen()const;
	int getAccountNumber()const;  //return account number
	BankDatabase&getBankDatabase()const;  //return reference to database
	virtual void execute() = 0;    //to perform transaction
};

