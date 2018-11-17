# include <iostream>
# include <vector>
# include <string>
# include <windows.h>

using namespace std;

int strStr(string haystack, string needle)
{
	if (needle.empty())
		return 0;
	int m = haystack.size(), n = needle.size();
	if (m < n)
		return -1;
	for (int i = 0; i <= m - n; i++)
	{
		int j = 0;
		for (int j = 0; j < n; j++)
		{
			if (haystack[i + j] != needle[j])
				break;
		}
		if (j == n)
			return i;
	}
	return -1;
}

int main()
{
	string a1, a2;
	double time = 0, counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	cin >> a1 >> a2;
	cout << "Please input a1: " << a1 << endl;
	cout << "Please inout a2:" << a2 << endl;
	strStr(a1, a2);
	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout << "程序执行时间为：" << time * 1000 << "ms" << endl;
	system("pause");
	return EXIT_SUCCESS;
	

}