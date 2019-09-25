#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize prices;
format setFormat();
void restore(format f, prices p);

Brass::Brass(const string &s, long an, double bal){
	fullname = s;
	acctNum = an;
	balance = bal;
}
void Brass::Deposit(double amt){
	if (amt < 0){
		cout << "Negative deposit is not allowed ;" << endl;
	}
	else{
		balance += amt;
	}
}

void Brass::WithDrow(double amt){
	format intitalState = setFormat();
	prices prec = cout.precision(2);

	if (amt < 0){
		cout << "wuthdraw negative is not allowed;\n";
	}
	else if (amt >balance){
		cout << "withdrow amtout of $ " << amt << "excedds your balance .\n";
	}
	else{
		balance -= amt;
	}
	restore(intitalState, prec);
}
double Brass::Balance() const{
	return balance;
}
void Brass::viewAcct()const{
	format intitalState = setFormat();
	prices prec = cout.precision(2);
	cout << "Client :" << fullname << endl;
	cout << "Account number:" << acctNum << endl;
	cout << "Balance:" << balance << endl;
	restore(intitalState, prec);
}

BrassPlus::BrassPlus(const std::string &fu, double  ac, double ba, double ml, double r):Brass(fu,ac,ba){
	maxlon = ml;
	owesBank = 0.0;
	rate = r;
}
BrassPlus::BrassPlus(const Brass &ba, double ml, double r ):Brass(ba){
	maxlon = ml;
	owesBank = 0.0;
	rate = r;
}
void BrassPlus::viewAcct() const{
	format intitalState = setFormat();
	prices prec = cout.precision(2);
	Brass::viewAcct();
	cout << "Maximum loan :$" << maxlon << endl;
	cout << "owed to bank :$" << owesBank << endl;
	cout << "Loan Rate:" << 100 * rate << endl;
	restore(intitalState, prec);
}

void BrassPlus::WithDraw(double amt){
	format intitalState = setFormat();
	prices prec = cout.precision(2);

	double bal = Balance();
	if (amt <= bal){
		Brass::WithDrow(amt);
	}
	else if (amt <= bal + maxlon - owesBank){
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance :$" << advance << endl;
		cout << "Finance charge :$" << advance *rate << endl;
		Deposit(advance);
		Brass::WithDrow(amt);
	}
	else{
		cout << "Credit limit exceed .Trancesstion calcelled .\n";
	}
	restore(intitalState, prec);
}

format setFormat(){
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, prices p){
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}