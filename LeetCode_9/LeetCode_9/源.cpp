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

static auto x = [](){
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	return 0;
}();

bool isPalidrome2(int x)
{
	int reverNum = 0;
	if (x < 0 || (x % 10 == 0 && x != 0))
	{
		return false;
	}
	if (x < 10)
	{
		return true;
	}
	while (x > reverNum)
	{
		reverNum = reverNum * 10 + x % 10;
		x /= 10;
	}
	return x == reverNum || x == reverNum / 10;
}

int main()
{
	int b;
	cin >> b;
	cout << isPalindrone(b) << endl;
	cout << isPalindrone1(b) << endl;
	cout << isPalidrome2(b) << endl;
	system("pause");
	return (0);
}
