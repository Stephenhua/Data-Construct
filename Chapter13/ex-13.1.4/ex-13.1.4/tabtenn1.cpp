#include "tabteen.h"
#include <iostream>
TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) :firstname(fn), lastname(ln), hasTable(ht){}

void TableTennisPlayer::Name()const{
	std::cout << "Name is :" << lastname << " " << firstname << std::endl;
}

RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string &ln, bool ht):TableTennisPlayer(fn,ln,ht){
	rating = r;

}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp):rating(r),TableTennisPlayer(tp){

}