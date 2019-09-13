#ifndef GOLF_H_
#define GOLF_H_
#include<cstring>
class Golf{

private:

	std::string fullname;
	int handicap;

public:
	Golf(const std::string name, int hc = 0);
	int setgolf();
	void sethandicap(const int hc);
	void showgolf()const;
};


#endif