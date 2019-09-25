#ifndef TABTEEN_H_
#define TABTEEN_H_

#include<string>
#include <iostream>
using namespace std;

class TableTennisPlayer{
private:
	string firstname;
	string lastname;
	bool hasTable;
public:
	TableTennisPlayer(const string &fn = "none", const string &ln = "none", bool ht = false);
	void Name() const;
	bool HasTable()const { return hasTable; }
	void RestTable(bool v){ hasTable = v; }
};


class RatedPlayer :public TableTennisPlayer{//ผฬณะ
private:
	unsigned int rating;
public:
	RatedPlayer(const int r = 0, const string &fn = "none", const string &ln = "none", bool ht = false);
	RatedPlayer(unsigned int r, const TableTennisPlayer&tp);
	unsigned int Rating()const { return rating; }
	void ResetRating(unsigned int r){ rating = r; }
};
#endif