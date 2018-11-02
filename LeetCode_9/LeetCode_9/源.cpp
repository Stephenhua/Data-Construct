# include <iostream>
#  include <algorithm>
# include <string>
using namespace std;


int isPalindrone(int x)
{
	if (x < 0)return false;
	int div = 1;
	while (x / div >= 10)
		div *= 10;
	while (x > 0)
	{
		int left = x / div;
		int right = x % 10;
		if (left != right) return false;
		x = (x%div) / 10;
		div /= 100;
	}
	return true;
}
int isPalindrone1(int x)
{
	if (x < 0)
		return false;
	int res = 0;
	int sources = x;
	while (x != 0)
	{
		res = res * 10 + x % 10;
	    x /= 10;
	}
	if (res == sources)
		return true;
	else
		return false;


}
int main()
{
	int b;
	cin >> b;
	cout << isPalindrone(b) << endl;
	cout << isPalindrone1(b) << endl;
	system("pause");
	return (0);
}
