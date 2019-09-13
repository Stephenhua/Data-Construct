
#include<iostream>
#include<cstring>
#include"person.h"

int main(){
	using namespace std;
	Person one;
	one.Show();
	cout << endl;
	one.Formshow();
	cout << endl;

	Person two("Smythecraft");
	two.Formshow();
	cout << endl;
	two.Show();
	cout << endl;

	Person three("Dimwdiddy", "sam");
	three.Show();
	cout << endl;
	three.Formshow();
	cout << endl;

	system("pause");
	return 0;
}