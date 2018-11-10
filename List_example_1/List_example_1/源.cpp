#include <iostream>
#include "list1.cpp"

using namespace std;

int main()
{
	CList <int > C1;
	CList<int > C2;

	cout << "表的初始信息输出测试：" << endl;
	cout << "C1和C2的初始容量为L" << C1.GetLength() << '\t' << C2.GetLength() << endl;
	cout << "C1和C2的初始长度为: " << C1.GetSize() << '\t' << C2.GetSize() << endl;
	cout << endl;

	cout << "表元素添加： " << endl;

	for (int i = 1; i <= 10; i++)
	{
		C1.AddTrail(2 * i);
		C2.AddTrail(i*i + 0.1);
	}

	cout << "C1中所有元素为： " ;
	C1.ShowValues();
	cout << "C2中所有元素为：" ;
	C2.ShowValues();
	cout<< endl;


	cout << "表元素插入测试： " << endl;

	C1.InsertAt(5, 11);
	C2.InsertAt(7, 22.2);
	cout << "C1中所有元素为： ";
	C1.ShowValues();
	cout << "C2中所有元素为：";
	C2.ShowValues();
	cout << endl;


	cout << "表中删除元素测试：" << endl;
	C1.RemoveAt(3, 2);
	C2.RemoveAt(4);
	cout << "C1中所有元素为： ";
	C1.ShowValues();
	cout << "C2中所有元素为：";
	C2.ShowValues();
	cout << endl;

	system("pause");
	return EXIT_SUCCESS;
}