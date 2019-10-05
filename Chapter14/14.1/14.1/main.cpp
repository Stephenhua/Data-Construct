#include <iostream>
#include "student.h"

using std::cin;
using std::cout;
using std::endl;

void set(Student &sa, int n);
const int pupil = 3;
const int quzizzes = 5;

int main(){
	Student ada[pupil] = { Student(quzizzes), Student(quzizzes), Student(quzizzes) };
	int i;
	for (int i = 0; i < pupil; i++){
		set(ada[i], quzizzes);
	}
	cout << "\nStudent List\n" << endl;
	for (int i = 0; i < pupil; i++){
		cout << ada[i].Name() << endl;
	}
	cout << "\nResult:" << endl;
	for (int i = 0; i < pupil; i++)
	{
		cout << ada[i]<<endl;
		cout << "Average :" << ada[i].Average() << endl;
	}
	cout << "Done.\n";
	system("pause");
	return 0;
}

void set(Student &sa, int n)
{
	cout << "Please enter the student's name:";
	getline(cin,sa);
	cout << "Please enter " << n << "quiz scores:\n";
	for (int i = 0; i < n; i++){
		cin >> sa[i];
	}
	while (cin.get() != '\n')
	{
		continue; 
	}
}