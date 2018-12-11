# include <iostream>
# include <vector>
# include <windows.h>
using namespace std;
class Solution{
public:
	int climbStairs(int n)
	{
		vector <int> dp(n + 1, 0);
		dp[0] = 1, dp[1] = 1;
		for (int i = 2; i < n + 1; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
		}
		return dp[n];
	}
};
int main()
{
	Solution sol1;
	double time = 0;
	double couns = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndtime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	int c,d;
	cin >> c;
	cout << sol1.climbStairs(c) << endl;
	QueryPerformanceCounter(&nEndtime);
	time = (double)(nEndtime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart;
	cout << "程序执行时间：" << time * 1000 << "ms" << endl;
	system("pause");
	return EXIT_SUCCESS;
}