# include <iostream>
# include <string.h>
# include <algorithm>
# include <unordered_map>
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
		vector<int >list;
		list.push_back(5);
		list.push_back(14);
		list.push_back(34);
		list.push_back(22);
		list.push_back(39);
		list.push_back(5);
		unordered_map<int, int> map;
		for (int i = 0; i < list.size(); i++)
		{
			map[i] = list[i];
		}
		cout << map[0] << endl;
		//for (std::unordered_map<int, int >::iterator i = map.begin; i != map.end(); i++)
		//{
		//	cout << i->first << ' ' << i->second << endl;

		//}
		if (map.find(3) != map.end())
		{
			cout << "find key= " << map.find(3)->first << " , value=" << map.find(3)->second << endl;
		}
		if (map.count(5) > 0)
		{
			cout << "find 5: " << map.count(5) << endl;
		}
		char a[] = "abacddfefsfdsfgsgefsfsgdfafafdf";
		cout<<lengthOfLongestSubstring(a)<<endl;
		system("pause");
		return EXIT_SUCCESS;

	}
