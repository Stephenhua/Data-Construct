# include <iostream>
# include <vector>
using namespace std;
int maxSubArray(vector<int>& nums)
{
	int max_so_far = INT_MIN, max_ending_here = 0;
	int size = nums.size();
	for (int i = 0; i < size; i++)
	{
		max_ending_here = max_ending_here + nums[i];
		if (max_so_far < max_ending_here)
		{
			max_so_far = max_ending_here;
		}
		if (max_ending_here < 0)
		{
			max_ending_here = 0;
		}
		return max_so_far;
	}
}


int main()
{
	vector<int> a = { 0, -4, 4, 3,  6, 2, -3, 8 };
	cout << maxSubArray(a) << endl;
	system("pause");
	return EXIT_SUCCESS;
}