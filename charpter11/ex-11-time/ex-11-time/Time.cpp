#include<iostream>
#include "time.h"

Time::Time(){
	hours = 0;
	minutes = 0;
}

Time::Time(int h, int m){
	hours = h;
	minutes = m;
}

void Time::AddHou(int h)
{
	hours += h;
}
void Time::AddMin(int m)
{
	minutes += m;
	minutes += minutes / 60;
	minutes %= 60;
}

void Time::Rest(int h, int m){
	hours = h;
	minutes = m;
}

Time Time::operator+(const Time & t)const
{
	Time sum;
	sum.minutes += t.minutes;
	sum.hours = sum.minutes / 60 + hours + t.hours;
	sum.minutes %= 60;
	return sum;
}


Time Time::operator-(const Time& t)const{
	Time diff;
	int to1, to2;
	to1 = t.minutes + 60 * t.hours;
	to2 = this->minutes + 60 * this->hours;
	diff.minutes= to2 - to1;
	diff.hours = diff.minutes / 60;
	diff.minutes = diff.minutes % 60;
	return diff;
}


Time Time::operator*(double t)const{
	Time reslut;
	long totalminute = hours *t* 60 + t*minutes;
	reslut.hours = totalminute / 60;
	reslut.minutes = totalminute % 60;
	return reslut;
}


Time Time::Sum(const Time& t)const{
	Time sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + sum.minutes / 60;
	sum.minutes %= 60;
	return sum;
}
void Time::show()const
{
	std::cout << hours << "hours," << minutes << "minutes;\n";
}

Time::~Time(){

}