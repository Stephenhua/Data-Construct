#  include <iostream>
# include <string>
# include <vector >
using namespace std;

int lengthOfLastWord(string s)
{
	int res = 0;
	int left = 0;
	int right = s.size()-1;
	if ( s.length() == 0)
		return 0;
	while (s[right] == ' ') --right;
	for (int i = right; i >= 0;i--)
	{
		if (s[i] != ' ')
			res++;
		else if (s[i] == ' '&& res!=0)
		{
			return res;
		}
	}
	return res;
}

int lengthOfLastWord1(string s)
{
	int res =0;
	for (int i =0; i < s.size(); i++)
	{
		if (s[i] != ' ')
		{
			if (i != 0 && s[i - 1] == ' ')
				res = 1;
			else
				++res;
		}
	}
	return res;
}

int lengthOfLastWord2(string s)
{
	int right = s.size()-1;
	int res = 0;
	while (right >= 0 && s[right] == ' ')
		--right;
	while (right >= 0 && s[right] != ' '){
		--right;
		++res;
	}
	return res;
}
int main()
{
	string a = "I love you ";
	cout << lengthOfLastWord(a) << endl;
	cout << lengthOfLastWord1(a) << endl;
	cout << lengthOfLastWord2(a) << endl;

	system("pause");
	return EXIT_SUCCESS;
}