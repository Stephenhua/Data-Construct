#ifndef BANKCOUNT_H_
#define BANKCOUNT_H_
#include <iostream>
#include <string>
using namespace std;
class Account{
private:
	string fullname;
	string accountname;
	double deposit;
public:
	Account(const string &client,const string &name,double depo=0.0);
	void save(double money);
	void take(double money);
	void show()const;
};

#endif