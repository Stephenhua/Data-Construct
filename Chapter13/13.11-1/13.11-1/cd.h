#ifndef CD_H_
#define CD_H_
#include <iostream>
class Cd{
private:
	char *performence;
	char *label;
	int selections;
	double palytime;
public:

	Cd(char *s1, char *s2, int n, double x);
	Cd(const Cd & d);
	Cd();
	virtual ~Cd();
	virtual void report()const;
	Cd & operator=(const Cd &d);

};

class Cd2 :public Cd{
private:
	char *name;
public:
	Cd2(char *s1, char *s2, char *s3, int n, double x);
	Cd2(const Cd2 &d, char *c);
	Cd2(const Cd2& d);
	Cd2();
	~Cd2();
	virtual void report()const;
	Cd2 &operator =(const Cd2 &d);

};
#endif