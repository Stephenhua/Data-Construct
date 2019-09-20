#include"answer.h"
#include<iostream>
using namespace std;

Cow::Cow(){

}
Cow::~Cow()
{
	delete[] hobby;
	hobby = nullptr;
}

Cow::Cow(const char *nm, const char *ho, double wt)
{
	strncpy (name, nm, 20);
	int ho_lenght = strlen(ho);
	hobby = new char[ho_lenght + 1];
	strncpy(hobby, ho, ho_lenght);
	/*
	strncpy函数的原型如下所示：

	char * strncpy(char * str2, char * str1, int size);

	功能就是复制str1中的内容，赋进str2中，复制的长度由size的数值决定，size的类型不一定是Int，但我们一般来说遇到的长度都是整数，
		*/
	hobby[ho_lenght] = '\0';
	weight = wt;
}

Cow::Cow(const Cow &c)//复制构造函数
{
	strncpy(name, c.name, 20);
	int ho_lengh = strlen(c.hobby);
	hobby = new char[ho_lengh + 1];
	strncpy(hobby, c.hobby, ho_lengh);
	hobby[ho_lengh + 1] = '\0';
	weight = c.weight;
}
Cow& Cow::operator=(const Cow &c)
{
	strncpy(name, c.name, 20);
	int ho_lengh = strlen(c.hobby);
	hobby = new char[ho_lengh + 1];
	strncpy(hobby, c.hobby, ho_lengh);
	hobby[ho_lengh + 1] = '\0';
	weight = c.weight;
	return *this;

}

void Cow::ShowCow()const
{
	cout << "Cow name  is" << name << endl;
	cout << "Cow hobby is " << hobby << endl;
	cout << "Cow weight is" << weight << endl;

}





