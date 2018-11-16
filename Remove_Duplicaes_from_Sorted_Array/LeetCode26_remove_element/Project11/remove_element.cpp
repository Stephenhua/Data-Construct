# include <iostream>
# include <vector>
using namespace std;

class solutions{
public:
	int removeElement(vector<int >&nums, int val)
	{
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			if (nums[i] == val)
			{
				nums.erase(nums.begin() + i);
				len--;
				i--;
			}
		}
		return len;
	}
};