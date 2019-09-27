//#include <isotream>
#include <string>
#include "cd.h"
using std::endl;
using std::cout;

Cd::Cd(char *s1, char *s2, int n, double x){
	performence=new char [strlen(s1)+1];
	strcpy(performence, s1);
	label = new char[strlen(s2) + 1];
	strcpy(label, s2);
	selections=n;
	palytime=x;
}
Cd::Cd(const Cd & d){
	performence = new char[strlen(d.performence) + 1];
	strcpy(performence, d.performence);
	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	palytime = d.palytime;
}
Cd::Cd(){
	performence = new char[1];
	performence[0] = '\0';
	label = new char[1];
	label[0] = '\0';
	selections = 0;
	palytime = 0;
}
Cd::~Cd(){
	delete[] label;
	delete[] performence;
}
void Cd::report()const{
	cout << "performers:" << performence << endl;
	cout << "label:" << label << endl;
	cout << "number of selections:" << selections << endl;
	cout << "playing time in minutes:" << palytime<< endl;
	cout << endl;

}
Cd & Cd::operator=(const Cd &d){
	if (this == &d)
		return *this;
	delete[]label;
	delete[] performence;
	performence = new char[strlen(d.performence) + 1];
	strcpy(performence, d.performence);
	label = new char[strlen(d.label) + 1];
	strcpy(label, d.label);
	selections = d.selections;
	palytime = d.palytime;
	return *this;
}

Cd2::Cd2(char *s1, char *s2, char *s3, int n, double x) :Cd(s1, s2, n, x){
	name = new char[strlen(s3) + 1];
	strcpy(name, s3);
}
Cd2::Cd2(const Cd2 &d, char *c) : Cd(d){
	name = new char[strlen(c) + 1];
	strcpy(name, c);
}
Cd2::Cd2(const Cd2& d):Cd(d){
	name = new char[strlen(d.name) + 1];
	strcpy(name, d.name);
}
Cd2::Cd2(){
	name = new char[1];
	name[0] = '\0';
}
Cd2::~Cd2(){
	delete[] name;
}
void Cd2::report()const{
	cout << "name:" << name << endl;
	Cd::report();
}
Cd2 &Cd2::operator =(const Cd2 &d){
	if (this == &d)
		return *this;
	Cd::operator=(d);
	delete[]name;
	name = new char[strlen(d.name) + 1];
	strcpy(name, d.name);
	return *this;
}