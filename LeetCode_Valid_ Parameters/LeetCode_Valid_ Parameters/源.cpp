# include <windows.h>
# include <iostream>
# include <stack>
# include <string>
# include <unordered_map>
# include <algorithm>

using namespace std;

bool isValid(string s)//�Լ���д
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
	LARGE_INTEGER nFerq;//�����������ʱ��Ķ���
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFerq);//�߾���ʱ����ƺ�������ʱ��clockΪ��λ��ͨ��
	//ͨ��rdtsc��ȡ�����������жϽ��У�������ϵͳʱ���൱��ʱ��������Ϊ���뼶
	QueryPerformanceFrequency(&nBeginTime);
	
	string a = "()(){}[][]{}";
	
	//cout << isValid(a);
	cout << isValid1(a);
	QueryPerformanceFrequency(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFerq.QuadPart;
	cout << "������������ʱ�䣺 " << time << endl;
	system("pause");
	return EXIT_SUCCESS;
}
