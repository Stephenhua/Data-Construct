#include <iostream>
#include "list1.cpp"

using namespace std;

int main()
{
	CList <int > C1;
	CList<int > C2;

	cout << "��ĳ�ʼ��Ϣ������ԣ�" << endl;
	cout << "C1��C2�ĳ�ʼ����ΪL" << C1.GetLength() << '\t' << C2.GetLength() << endl;
	cout << "C1��C2�ĳ�ʼ����Ϊ: " << C1.GetSize() << '\t' << C2.GetSize() << endl;
	cout << endl;

	cout << "��Ԫ����ӣ� " << endl;

	for (int i = 1; i <= 10; i++)
	{
		C1.AddTrail(2 * i);
		C2.AddTrail(i*i + 0.1);
	}

	cout << "C1������Ԫ��Ϊ�� " ;
	C1.ShowValues();
	cout << "C2������Ԫ��Ϊ��" ;
	C2.ShowValues();
	cout<< endl;


	cout << "��Ԫ�ز�����ԣ� " << endl;

	C1.InsertAt(5, 11);
	C2.InsertAt(7, 22.2);
	cout << "C1������Ԫ��Ϊ�� ";
	C1.ShowValues();
	cout << "C2������Ԫ��Ϊ��";
	C2.ShowValues();
	cout << endl;


	cout << "����ɾ��Ԫ�ز��ԣ�" << endl;
	C1.RemoveAt(3, 2);
	C2.RemoveAt(4);
	cout << "C1������Ԫ��Ϊ�� ";
	C1.ShowValues();
	cout << "C2������Ԫ��Ϊ��";
	C2.ShowValues();
	cout << endl;

	system("pause");
	return EXIT_SUCCESS;
}