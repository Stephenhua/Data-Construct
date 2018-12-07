# include <iostream>
# include <vector>
using namespace std;
vector <int> plusOne(vector<int>& digits)
{
	for (int i = digits.size() - 1; i >= 0; i--)
	{
		if (digits[i] == 9)
		{
			digits[i] = 0;
			if (i == 0)
			{
				vector<int> res(digits.size() + 1, 0);
				res[0] = 1;
				return res;
			}
		}
		else
		{
			digits[i] = digits[i] + 1;
			break;
		}
	}
	return digits;
}
int main()
{
	vector <int > a = { 13456 };
	vector<int > b;
	b=plusOne(a);
	for (vector<int>::iterator it = b.begin(); it != b.end(); it++)//vecotor 输出的表达式
	{
		cout << *it << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}