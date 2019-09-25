# include <iostream>
# include <algorithm>
# include <stdio.h>
# include <vector>
# include <map>

using namespace std;
struct cmp{
	bool operator()(pair<int, double> a, pair<int, double> b)
	{
		if (a.second == b.second)
		{
			return a.first > b.first;
		}
		return a.second > b.second;//自定义的比较函数
	}
};
int main()
{
	vector <pair<int, double>> temp_count;
	vector<int>  temp_count_2;
	vector <pair<int, double>>::iterator temp_countIt;
	for (int i = 0; i < 5; i++)
	{
		int temp;
		cin >> temp;
		temp_count_2.push_back(temp);
		temp_count.push_back(make_pair(i + 1, temp));
	}

	sort(temp_count.begin(), temp_count.end(), cmp());
	for (int i = 0; i < 5; i++)
	{
		cout << "The first number is :" << temp_count[i].first << "The second number is " << temp_count[i].second << endl;
	}

	auto min_ID = min_element(temp_count_2.begin(), temp_count_2.end());//最小ID算法
	auto max_ID = max_element(temp_count_2.begin(), temp_count_2.end());
	int temp_NodeID = (*min_ID);
	int temp_Max_number = (*max_ID);
	cout << "The mininum number is:" << temp_NodeID << endl;
	cout << "The max number is :" << temp_Max_number << endl;
	system("pause");
	return 0;
}