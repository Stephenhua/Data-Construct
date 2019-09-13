# include<iostream>
# include "stcok.h"
using namespace std;


Stock::Stock()
{
	std::cout << "Defalut constructor cllaed \n";
	company = "no name";
	shares = 0;
	shares_val_ = 0.0;
	total_val_ = 0.0;
}


Stock::Stock(const string &co,long n,double pr)
{
	std::cout << "Constructing using " << co << "called\n";
	company = co;
	if (n < 0)
	{
		cout << "The number of stock can't be negative;" << company << "shares set to 0\n";
		shares = 0;
	}
	else
		shares = n;

	shares_val_ = pr;
	set_tot();
}
Stock::~Stock()
{
	cout << "Bye ," << company << endl;
}

void Stock::buy(long num, double price)
{
	if (num < 0)
	{
		cout << "number of shares purchased can't be negative." << endl;
	}
	else
	{
		shares += num;
		shares_val_ = price;
		set_tot();
	}
}
void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		cout << "number if shares purchased can't be negative" << endl;
	}
	else
	{
		shares -= num;
		shares_val_ = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	shares_val_ = price;
	set_tot();
}

void Stock::show() const 
{
	ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
	std::streamsize prec = cout.precision(3);
	cout << "Company" << company << ";Shares" << shares << endl;
	cout << "Shares prices is:$ " << shares_val_ << "\n";
	cout.precision(2);
	cout << "Total Worth :$" << total_val_ << "\n";
	cout.setf(orig, ios::ios_base::floatfield);
	cout.precision(prec);
}
const Stock &Stock::topval(const Stock &s) const
{
	if (s.total_val_> this->total_val_)
	{
		return s;
	}
	else
	{
		return *this;
	}
}