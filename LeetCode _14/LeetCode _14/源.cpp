# include <algorithm>
# include <iostream>
# include <string >
# include <vector>
# include <time.h>
#include <windows.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
	if (strs.empty())
		return " ";
	string res = "";
	for (int j = 0; j < strs[0].size(); ++j)
	{
		char c = strs[0][j];
		for (int i = 1; i < strs.size(); ++i)
		{
			if (j >= strs[i].size() || strs[i][j] != c)
				return res;
		}
		 res.push_back(c);
	}
	return res;

}


string longestCommonPrefix2(vector<string>& strs)
{
	if (strs.empty())
		return "";
	for (int j = 0; j < strs[0].size(); ++j)
	{
		for (int i = 0; i < strs.size() - 1; ++i)
		{
			if (j >= strs[i].size() || j >= strs[i + 1].size() || strs[i][j] != strs[i + 1][j])
			{
				return strs[i].substr(0, j);
			}
		}

	}
	return strs[0];
}

int main()
{
	double time = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);


	/*DWORD star_time = GetTickCount();//���м�������ʱ��Ŀ�ʼֵ
	vector<string> A = { "abc", "abk", "ab" };//�������� = �������� 
	string s = longestCommonPrefix(A);//vector����ֵΪ�ַ�����������Ҫ����string���͵�����
	cout << s << endl;
	DWORD end_time = GetTickCount();//���м���ʱ�����ֵֹ
	cout << "�����������ʱ��Ϊ��" << (end_time - star_time) << "ms" << endl;
	*/

	//DWORD star_time = GetTickCount();//���м�������ʱ��Ŀ�ʼֵ
	vector<string> B = { "abbbbbbbbbbbbbbbbbbbbbbbbbbbbbccccccccccccccccccccccccc", "abbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbcccccccccccccccccccccccccc"};//�������� = �������� 
	string v = longestCommonPrefix(B);//vector����ֵΪ�ַ�����������Ҫ����string���͵�����
	cout << v << endl;
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout << "cheng xu zhi xing shijian " << time * 1000 << "ms" << endl;
	//DWORD end_time = GetTickCount();//���м���ʱ�����ֵֹ
	//cout << "2 ��������ʱ��Ϊ��" << (end_time - star_time) << "ms" << endl;
	for (int i = 0; i < 10; ++i)
	{
		cout << i << " " ;
	}
	/*for (int j = 0; j < 10; j++)
	{
		cout << j << endl;
	}
	*/
	system("pause");
	return EXIT_SUCCESS;

}