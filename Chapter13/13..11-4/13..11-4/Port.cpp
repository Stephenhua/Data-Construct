#include <iostream>
#include <string>
#include "Port.h"
using std::cout;
using std::endl;

Port::Port(const char *br , const char *st, int b ){
	brand = new char[strlen(br) + 1];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}
Port::Port(const Port & p){
	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles =p.bottles;
}
Port & Port::operator=(const Port &p){
	if (this == &p)
		return *this;
	delete[] brand;

	brand = new char[strlen(p.brand) + 1];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;

}
Port & Port::operator+=(int b){
	bottles += b;
	return *this;
}
Port & Port::operator-=(int b){
	if (bottles >= b){
		bottles -= b;
	}
	else{
		cout << "you don't have enough bottles;\n";
	}
	return *this;
}
ostream& operator<<(ostream &os, const Port &p){
	os << p.brand << ", " << p.style << ", " << p.bottles;
	return os;
}

void Port::show()const{
	std::cout << "Brand: " << brand << std::endl;
	std::cout << "Kind: " << style << std::endl;
	std::cout << "Bottles: " << bottles << std::endl;
}

VintagePort::VintagePort():Port(){
	nikename = new char[1];
	nikename[0] = '\0';
	year = 0;
}
VintagePort::VintagePort(const char *br, const char *st ,int b, const char *nn, int y) : Port(br, st, b){
	nikename = new char[strlen(nn) + 1];
	strcpy(nikename, nn);
	year=y;
}
VintagePort::VintagePort(const VintagePort& vp):Port(vp){
	nikename = new char[strlen(vp.nikename) + 1];
	strcpy(nikename, vp.nikename);
	year = vp.year;
}

VintagePort& VintagePort::operator = (const VintagePort &vp){
	if (this == &vp)
		return *this;
	Port::operator=(vp);
	delete[] nikename;
	nikename = new char[strlen(vp.nikename) + 1];
	strcpy(nikename, vp.nikename);
	year = vp.year;
}
void VintagePort::Show()const{
	Port::show();
	cout << "Nickname is:" << nikename << endl;
	cout << "Year:" << year << endl;
}
ostream& operator<<(ostream &os, const VintagePort & vp){
	os << (const Port&)vp;
	os << "," << vp.nikename << "," << vp.year;
	return os;
}

