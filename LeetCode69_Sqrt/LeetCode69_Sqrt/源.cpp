# include <iostream>
# include <climits>
# include <cmath>
using namespace std;

class Soultion{//使用牛顿迭代的方法进行计算，
public:
	int mySqrt(int x)
	{
		if (x < 0)
			return INT_MIN;
		if (x == 0)
			return 0;
		double pre = 0;
		double res = 1;
		while (abs(res - pre)>0.00000001)
		{
			pre = res;
			res = (res + x / res)/2;
		}
		return int(res);
	}
};
class Solution1{
public:
	int mySqrt(int x)
	{
		long l = 0, r = x;
		while (l < r)
		{
			long mid = l + (r - 1) / 2;
			if ((mid*mid) <= x && ((mid + 1)*(mid + 1)>x))
				return mid;
			else  if ((mid*mid) <= x)
				l = mid + 1;
			else
				r = mid - 1;
		}
		return l;
	}
};
int mySqrt(int x)
{
	if (x <= 1) return x;
	int left = 0, right = x;
	while (left < right)
	{
		int mid = left + (right + left) / 2;
		if (x / mid >= mid) left = mid + 1;
		else right = mid;
	}
	return right - 1;
}
int main()
{

	int a = 7;
	int a2 = 222222;
	Soultion sol;
	Solution1 sol1;
	int res1 = sol.mySqrt(a2);
	int res2 = sol1.mySqrt(a2);
	//int b = mySqrt(a);
	//printf("%d \n", b);
	//cin >> a;
	
	//cout<<b<<endl;
	printf("%d \n", res1);
	printf("%d \n", res2);
	system("pause");
	return EXIT_SUCCESS;
}