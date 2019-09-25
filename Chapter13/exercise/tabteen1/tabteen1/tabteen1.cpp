#include"tabtenn1.h"
#include<iostream>
#include <string>
using namespace std;
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) :firstname(fn), lastname(ln), hasTable(ht){}
//构造函数初始化
void  TableTennisPlayer::Name()const
{
	std::cout << lastname << " , " << firstname;
}

RatedPlayer::RatedPlayer(const int r , const string &fn , const string &ln, bool ht ) : TableTennisPlayer(fn, ln, ht)
{
	rating = r;
}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp) : TableTennisPlayer(tp), rating(r)
{

}