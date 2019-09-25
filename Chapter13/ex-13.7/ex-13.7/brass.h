#ifndef BRASH_H_
#define BRASH_H_

#include <string>
class Brass{
private:
	std::string fullname;
	long acctNum;
	double balance;
public:
	Brass(const std::string &fu="noboday", long an=-1, double ba=0);
	void Deposit(double amt);
	virtual void WithDrow(double amt);
	double Balance() const;
	virtual void viewAcct()const;
	virtual ~Brass(){}
};

class BrassPlus:public Brass{
private:
	double maxlon;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string &fu = "noboday", double ac = -1, double ba = 0.0, double ml = 500.0, double r = 0.11125);
	BrassPlus(const Brass &ba, double ml = 500, double r = 0.11125);
	virtual void viewAcct() const;
	virtual void WithDraw(double amt);
	void restRate(double m){ rate = m; }
	void restOwes(double m){ owesBank = 0; }
};
#endif