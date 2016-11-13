#pragma once
class CashDispenser
{
	static const int INITIAL_COUNT = 500;
	int count;   //number $20 bills of remaning
public:
	CashDispenser();
	void dispenserCash(int);
	bool isSufficientCashAvalaibel(int)const;  //indicates cash dispenser
	~CashDispenser();
};

