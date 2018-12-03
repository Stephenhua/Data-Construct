# include <iostream>
# include <string>
using namespace std;

string countAndSay(int n)
{
	if (n == 1)
	{
		return "1";
	}
	string res, s = "1";
	while (n > 1)
	{
		int count = 1;
		int i = 0;
		for (i = 1; i < s.size(); i++)
		{
			if (s[i] == s[i - 1])
			{
				count++;
			}
			else
			{
				res += to_string(count);
				res.push_back(s[i - 1]);
				count = 1;
			}
		}
		res += to_string(count);
		res.push_back(s[i - 1]);
		s = res;
		res = "";
		n--;
	}
	return s;
}

string countAndSay1(int n) {
	if (n <= 0) return "";
	string res = "1";
	while (--n)
	{
		string cur = "";
		for (int i = 0; i < res.size(); ++i)
		{
			int cnt = 1;
			while (i + 1 < res.size() && res[i] == res[i + 1])
			{
				++cnt;
				++i;
			}
			cur += to_string(cnt) + res[i];
		}
		res = cur;
	}
	return res;
}
int main()
{
	int n;
	cin >> n;
	cout << countAndSay(n) << endl;
	cout << countAndSay1(n) << endl;
	system("pause");
	return EXIT_SUCCESS;
}