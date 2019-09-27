#ifndef POTR_H_
#define POTR_H_
#include <iostream>
#include <string>
using namespace std;
class Port{
private:
	char *brand;
	char style[20];
	int bottles;
public:
	Port(const char *br ="none",const char *st = "none", int b=0);
	Port(const Port & p);
	virtual ~Port(){ delete[] brand; }
	virtual void show()const;
	Port & operator=(const Port &p);
	Port & operator+=(int b);
	Port & operator-=(int b);
	int BottleCount() const { return bottles; }
	friend ostream& operator<<(ostream &os, const Port &p);
};

class VintagePort : public Port{
private:
	char *nikename;
	int year;
public:
	VintagePort();
	VintagePort(const char *br, const char *st ,int b, const char *nn, int y);
	VintagePort(const VintagePort& vp);
	~VintagePort(){ delete[] nikename; }
	VintagePort& operator =(const VintagePort &vp);
	void Show()const;
	friend ostream& operator<<(ostream &os, const VintagePort & vp);
};
#endif