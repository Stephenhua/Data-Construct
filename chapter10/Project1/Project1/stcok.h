#ifndef STOCK_H_
#define STOCK_H_

# include <iostream>
# include <string>
using namespace std;

class Stock{
private:
	string company;
	long shares;//the number of stock;
	double shares_val_;
	double total_val_;
	void set_tot(){ total_val_ = shares*shares_val_; }
public:
	Stock();
	Stock(const string &co, long n = 0, double pr = 0.0);
	~Stock();
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const ;
	const Stock &topval(const Stock &s) const;
};
#endif

