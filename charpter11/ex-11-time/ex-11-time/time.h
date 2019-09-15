#ifndef TIME_H_
#define TIME_H_

class Time{
private:
	int hours;
	int minutes;
public:
	Time();
	~Time();
	Time(int h, int m = 0);
	void AddMin(int m);
	void AddHou(int h);

	void Rest(int h = 0, int m = 0);

	Time operator-(const Time &t)const;
	Time operator+(const Time &t)const;
	Time operator*(double t)const;
	Time Sum(const Time& t)const;
	void show()const;
};
#endif