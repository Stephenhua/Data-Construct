
# include <map>
# include <string>
# include <iostream>
using namespace std;
int main()
{
	map<int, string > mapStudent;
	/*
	//利用pair插入
	mapStudent.insert(pair<int, string>(1, "student_one"));
	mapStudent.insert(pair<int, string>(2, "student_two"));
	mapStudent.insert(pair<int, string>(3, "student_three"));
	map<int, string>::iterator iter;
	*/
	//利用insert函数插入value_type数据
	mapStudent.insert(map<int, string>::value_type(1, "student_one"));
	mapStudent.insert(map<int, string>::value_type(2, "student_two"));
	mapStudent.insert(map<int, string>::value_type(3, "student_three"));
	map<int, string>::iterator iter;
	for (iter = mapStudent.begin(); iter != mapStudent.end(); iter++)
		cout << iter->first << ' ' << iter->second << endl;

	//查找某一个元素

	iter = mapStudent.find(1);
	if (iter != mapStudent.end())
		cout << "Find ,the value is " << iter->second << endl;
	else
		cout << "Do not find " << endl;
	
	//从map中删除元素

	map<int, string>::iterator iter1;
	iter1 = mapStudent.find(1);
	mapStudent.erase(iter1);
	
	map<int, string>::iterator iter2;
	for (iter2 = mapStudent.begin(); iter2 != mapStudent.end(); iter++)
		cout << iter2->first << ' ' << iter2->second <<

	system("pause");
	return 0;
}
