#include"BankCount.h"
#include<string>
#include<iostream>
using namespace std;

Account::Account(const string &client, const string &name, double  depo)
{
	fullname = client;
	accountname = name;
	deposit = depo;
}

void Account::save(double money){
	if (money < 0)
	{
		cout << "The money can'tn be negative,please repeat save your money\n";
	}
	else
	{
		deposit += money;
	}
}
void Account::take(double money){
	if (money < 0)
	{
		cout << "Money can't be negative ,please repeat input" << endl;
	}
	else if (money>deposit)
	{
		cout << "Sorry ,your account monby is not enough" << endl;
	}
	else
	{
		deposit -= money;
	}
}

void Account::show()const{
	cout << "Your count number is:" << accountname << ";your name is :" << fullname << endl;
	cout << "money:$" << deposit << endl;
}