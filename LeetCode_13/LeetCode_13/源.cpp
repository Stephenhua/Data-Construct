# include <algorithm>
# include<iostream>
# include <unordered_map>
# include <string>
using namespace std;

int romanToInt(string s) {
		int res = 0;
		unordered_map<char, int> m{ { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
		for (int i = 0; i < s.size(); ++i) {
			int val = m[s[i]];
			if (i == s.size() - 1 || m[s[i + 1]] <= m[s[i]]) res += val;
			else res -= val;
		}
		return res;
	}
int romanToInt1(string c)//采用无序map用于查找
{
	unordered_map<char, int > roman = { {'I', 1}, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
	int res1 = roman[c.back()];
	for (int i =c.size()-2; i >= 0; i--)
	{
		if (roman[c[i]] < roman[c[i+1]])
		{
			res1 -= roman[c[i]];
		}
		else
		{
			res1 += roman[c[i]];
		}
		
	}
	return res1;
}

class Solution
{
private:
	int RtoI(char roman)
	{
		switch (roman)
		{
		case'I':return 1;
		case'V':return 5;
		case'X':return 10;
		case 'L':return 50;
		case'C':return 100;
		case'D':return 500;
		case'M':return 1000;
		default:return 0;
		}
	}
public:
	int romanToInt2(string s)
	{
		int size = s.size();
		if (size == 0)
			return 0;
		int preValue = RtoI(s[size - 1]);
		int sum = preValue, value;
		for (int i = size - 2; i >= 0; i--)
		{
			value = RtoI(s[i]);
			sum += (value < preValue) ? -value : value;
			preValue = value;
		}
		return  sum ;
	}
};
int  main()
{
	Solution roman;
	string c = "IIIX";
	cout << romanToInt(c) << endl;
	cout << romanToInt1(c) << endl;
	cout<<roman.romanToInt2(c)<<endl;

	system("pause");
	return EXIT_SUCCESS;
}