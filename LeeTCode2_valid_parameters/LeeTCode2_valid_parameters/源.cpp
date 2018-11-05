# include <iostream>
# include <stack>
# include <algorithm>
# include <vector>
# include <deque>


using namespace std;

int main()
{

	//=================================================
	//初始化
	deque<int> mydeque(2, 100);//表示大小为2，初始值为100
	vector<int> myvector(2, 200);//表示大小为2.初始值为200

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
		mystack1.push(i);//将元素压入栈顶
	}
	cout << "stack size: " << mystack1.size() << "\n";//输出栈的元素
	while (!mystack1.empty())
	{
		sum += mystack1.top();//返回栈顶元素
		cout << " " << mystack1.top();
		mystack1.pop();//删除栈顶元素
	}
	cout << "\n";
	cout << "  toatal = " << sum << endl;
	system("pause");
	return EXIT_SUCCESS;
}