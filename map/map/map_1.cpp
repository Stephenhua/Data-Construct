
# include <map>
# include <string>
# include <iostream>
using namespace std;
int main()
{
	map<int, string > mapStudent;
	/*
	//����pair����
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	map<int, string>::iterator iter;
	*/
	//����insert��������value_type����
	mapStudent.insert(map<int, string>::value_type(1, "student_one"));
	mapStudent.insert(map<int, string>::value_type(2, "student_two"));
	mapStudent.insert(map<int, string>::value_type(3, "student_three"));
	map<int, string>::iterator iter;
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;

	//����ĳһ��Ԫ��

	iter = mapStudent.find(1);
	if (iter != mapStudent.end())
		cout << "Find ,the value is " << iter->second << endl;
	else
		cout << "Do not find " << endl;
	
	//��map��ɾ��Ԫ��

	map<int, string>::iterator iter1;
	iter1 = mapStudent.find(1);
	mapStudent.erase(iter1);
	
	map<int, string>::iterator iter2;
	for (iter2 = mapStudent.begin(); iter2 != mapStudent.end(); iter++)
		cout << iter2->first << ' ' << iter2->second <<

	system("pause");
	return 0;
}
