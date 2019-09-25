#include"brass.h"
#include <iostream>
#include<string>
using namespace std;
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);
format setFormat()
{
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}

Brass::Brass(const string &s, long an, double bal)
{
	fullName = s;
	acctNum = an;
	balance = bal;
}

void Brass::Deposit(double amt)
{
	if (amt < 0)
	{
		cout << "Negitive deposit not allowed;" << "deposit is camncalled .\n";
	}
	else
	{
		balance += amt;
	}
}

void Brass::Withdrow(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);

	if (amt < 0)
	{
		cout << "Withdrow amout must be postive; so cancelled " << endl;
	}
	else if (amt <= balance)
	{
		balance -= amt;
	}
	else
	{
		cout << "Withdrow amout of $ " << amt << "  exceeds your balance .\n";
	}
	restore(initialState, prec);
}

double Brass::Balance()const
{
	return balance;
}

void Brass::ViewAcct() const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "Client" << fullName << endl;
	cout << "Account Number" << acctNum << endl;
	cout << "Balance : $" << balance << endl;
	restore(initialState, prec);//用于将数值存储为合适的值
}
BrassPlus::BrassPlus(const string &s, long an, double bal, double ml, double r) :Brass(s, an, bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) :Brass(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

void BrassPlus::ViewAcct()const
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::ViewAcct();

	cout << "Maximum loan : $" << maxLoan << endl;
	cout << "Owed to bank :$" << owesBank << endl;
	cout.precision(2);
	cout << "Loan rate :" << 100 * rate << "%\n";
	restore(initialState, prec);
}

void BrassPlus::Withdrow(double amt)
{
	format initialState = setFormat();
	precis prec = cout.precision(2);
	double bal = Balance();
	if (amt < bal)
	{
	Brass:Withdrow(amt);
	}
	else if (amt <= bal + maxLoan - owesBank)
	{
		double advance = amt - bal;
		owesBank += advance*(1.0 + rate);
		cout << "Bank advance :$" << advance << endl;
		cout << "Finance charge:$" << advance*rate << endl;
		Deposit(advance);
		Brass::Withdrow(amt);

	}
	else
	{
		cout << "Credit limit exceed .Transaction canceled.\n";
	}
	restore(initialState, prec);
}
