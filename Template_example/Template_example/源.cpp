# include <iostream>
# include "ClassTemplate.h"
using namespace std;
/*
template<class T >//����ģ���д��
T min(T x, T y)
{
	return (x < y ? x : y);
}

void main()
{
	int n1 = 2, n2 = 10;
	double d1 = 1.5, d2 = 1.2;
	cout << "��С����: " << min(n1, n2) << endl;
	cout << "��Сʵ���� " << min(d1, d2) << endl;
	system("pause");
	
}
*/

void main()
{
	myClass<int, int > class1(3, 5);
	class1.show();
	myClass<int, char> class2 (3, 'a');
	class2.show();
	myClass<double, int> class3(2.9, 3);

	class3.show();
	system("pause");
}