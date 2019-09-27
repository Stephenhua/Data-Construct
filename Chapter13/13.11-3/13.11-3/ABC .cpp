#include <iostream>
#include <string>
#include "ABC.h"
using std::endl;
using std::cout;

ABC::ABC(const char * l , int r ){
	label = new char[strlen(l) + 1];
	strcpy(label, l);
	rating = r;
}
ABC::ABC(const ABC & rs){
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
}
ABC & ABC::operator=(const ABC & rs){
	if (this == &rs)
		return *this;
	delete[] label;
	label = new char[strlen(rs.label) + 1];
	strcpy(label, rs.label);
	rating = rs.rating;
	return *this;
}

ABC::~ABC(){
	delete[] label;
}

void ABC::View(){
	cout << "Label: " << label << endl;
	cout << "Rating: " << rating << endl;
}
std::ostream& operator<<(std::ostream& os, const ABC& rs){
	os << "Label: " << rs.label << endl;
	os << "Rating: " << rs.rating << endl;
	return os;
}

baseDMA::baseDMA(const char * l , int r ) :ABC(l, r){

}

baseDMA::baseDMA(const baseDMA & rs) : ABC(rs){

}

void baseDMA::View(){
	ABC::View();
}

lacksDMA::lacksDMA(const char * c , const char * l , int r ) :ABC(l, r){
	strcpy(color,c);
	color[COL_LEN - 1] = 0;
}

lacksDMA::lacksDMA(const char * c, const ABC & rs):ABC(rs){
	strcpy(color, c);
	color[COL_LEN - 1] = 0;
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls){
	os << (const ABC&)ls;
	os << "Color: " << ls.color << endl;
	return os;
}

void lacksDMA::View(){
	ABC::View();
	cout << "Color: " << color << endl;
}


hasDMA::hasDMA(const char * s , const char * l , int r) : ABC(l, r){
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}
hasDMA::hasDMA(const char * s, const ABC & rs): ABC(rs){
	style = new char[strlen(s) + 1];
	strcpy(style, s);
}
hasDMA::hasDMA(const hasDMA & hs){
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
}
hasDMA::~hasDMA(){
	delete[] style;
}

hasDMA & hasDMA::operator=(const hasDMA & hs){
	if (this == &hs){
		return *this;
	}
	ABC::View();
	delete[] style;
	style = new char[strlen(hs.style) + 1];
	strcpy(style, hs.style);
	return *this;
}
std::ostream& operator<<(std::ostream& os, const hasDMA& hs){
	os << (const ABC&)hs;
	os << "Style: " << hs.style << endl;
	return os;
}
void hasDMA::View(){
	ABC::View();
	cout << "style :" << endl;
}