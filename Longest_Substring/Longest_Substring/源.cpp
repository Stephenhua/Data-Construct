# include <iostream>
# include <string.h>
# include <algorithm>
using namespace std;

	int lengthOfLongestSubstring(string s) {
		int m[256] = { 0 }, res = 0, left = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (m[s[i]] == 0 || m[s[i]] < left) {
				res = max(res, i - left + 1);
			}
			else {
				left = m[s[i]];
			}
			m[s[i]] = i + 1;
		}
		return res;
	}
	int main()
	{
		char a[] = "abacddfefsfdsfgsgefsfsgdfafafdf";
		cout<<lengthOfLongestSubstring(a)<<endl;
		system("pause");
		return EXIT_SUCCESS;

	}
