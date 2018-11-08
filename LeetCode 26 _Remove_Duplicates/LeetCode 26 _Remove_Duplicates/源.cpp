# include <iostream>
# include <vector>
# include <algorithm>
# include <windows.h>
using namespace std;
int removeDuplicates(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	int length = 1;
	int pre = nums[0];

	for (unsigned int i = 1; i < nums.size(); ++i)
	{
		if (nums[i] != pre)
		{
			nums[length] = nums[i];
			length++;
			pre = nums[i];
		}
	}
	return length;

}
int main()
{
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime);
	vector<int> A = {1,2,3,4,4,4,4,5,6,6,6,6,7,7,7,8,8};
	
	cout << removeDuplicates(A) << endl;

	QueryPerformanceCounter(&nEndTime);
	time = (double)(nEndTime.QuadPart-nBeginTime.QuadPart);
	cout << "Program execution time:" << time * 1000 << " ms" << endl;

	system("pause");
	return EXIT_SUCCESS;
}