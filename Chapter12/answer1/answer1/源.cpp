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
	strncpy������ԭ��������ʾ��

	char * strncpy(char * str2, char * str1, int size);

	���ܾ��Ǹ���str1�е����ݣ�����str2�У����Ƶĳ�����size����ֵ������size�����Ͳ�һ����Int��������һ����˵�����ĳ��ȶ���������
		*/
	hobby[ho_lenght] = '\0';
	weight = wt;
}

Cow::Cow(const Cow &c)//���ƹ��캯��
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





