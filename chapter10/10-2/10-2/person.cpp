#include<iostream>
#include<string>
#include<cstring>
#include "person.h"

Person::Person(const std::string &ln, const char * fn)
{
	lname = ln;
	strcpy(fname, fn);

}

void Person::Show()const
{
	std::cout << "Formal name " << std::endl;
	std::cout << lname << "" << fname << std::endl;
}

void Person::Formshow()const
{
	std::cout << "Formal Name:" << std::endl;
	std::cout << lname << " " << fname << std::endl;
}