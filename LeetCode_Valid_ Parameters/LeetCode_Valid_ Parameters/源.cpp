# include <windows.h>
# include <iostream>
# include <stack>
# include <string>
# include <unordered_map>
# include <algorithm>

using namespace std;

bool isValid(string s)//自己编写
{
	stack<char> parenthess;
	for (unsigned int i = 0; i <=s.size()-1; ++i)
	{
		if (s[i] == '(' || s[i] == '[' || s[i] == '{')
		{
			parenthess.push(i);
		}
		else
		{
			if (parenthess.empty())
				return false;
			if (s[i] == ')'&&parenthess.top() != '(') return false;
			if (s[i] == '['&&parenthess.top() != '[')return false;
			if (s[i] == '{'&&parenthess.top() != '}') return false;
			parenthess.pop();
		}
	}
	return parenthess.empty();
}

bool isValid1(string s)
{
	unordered_map<char, char> m{ { ')', '(' }, { ']', '[' }, { '}', '{' } };
	stack<char> my_stack;
	for (auto c : s)
	{
		if (m.find(c) != m.end())
		{
			if (my_stack.empty() || my_stack.top() != m[c])
			{
				return false;
			}
			else
			{
				my_stack.pop();
			}
		}
		else
		{
			my_stack.push(c);
		}
		
	}
	return my_stack.empty();
}

int main()
{
	double time = 0;
	LARGE_INTEGER nFerq;//计算程序所花时间的定义
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFerq);//高精度时间控制函数，以时间clock为单位，通过
	//通过rdtsc读取，而不采用中断进行，精度与系统时间相当，时间数量级为毫秒级
	QueryPerformanceFrequency(&nBeginTime);
	
	string a = "()(){}[][]{}";
	
	//cout << isValid(a);
	cout << isValid1(a);
	QueryPerformanceFrequency(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFerq.QuadPart;
	cout << "程序运行所需时间： " << time << endl;
	system("pause");
	return EXIT_SUCCESS;
}
