# include <iostream>
# include <stack>
# include <algorithm>
# include <vector>
# include <deque>


using namespace std;

int main()
{

	//=================================================
	//��ʼ��
	deque<int> mydeque(2, 100);//��ʾ��СΪ2����ʼֵΪ100
	vector<int> myvector(2, 200);//��ʾ��СΪ2.��ʼֵΪ200

	stack<int> first;
	stack<int> second(mydeque);

	stack<int, vector<int> > third;
	stack<int, vector<int>> fourth(myvector);
	//==================================================
	cout << "size of first:" << (int)first.size() << endl;
	cout << "size of second" << (int)second.size() << endl;
	cout << "size of third" << (int)third.size() << endl;
	cout << "size of fouth:" << (int)fourth.size() << endl;
	//===================================================
	stack<int>mystack1;
	int sum = 0;
	for (int i = 1; i <= 10; i++)
	{
		mystack1.push(i);//��Ԫ��ѹ��ջ��
	}
	cout << "stack size: " << mystack1.size() << "\n";//���ջ��Ԫ��
	while (!mystack1.empty())
	{
		sum += mystack1.top();//����ջ��Ԫ��
		cout << " " << mystack1.top();
		mystack1.pop();//ɾ��ջ��Ԫ��
	}
	cout << "\n";
	cout << "  toatal = " << sum << endl;
	system("pause");
	return EXIT_SUCCESS;
}