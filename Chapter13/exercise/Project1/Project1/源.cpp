#include<iostream>
#include<algorithm>
#include<stdio.h>
#include <vector>
#include<string>
using namespace std;

bool cmp(const pair<int, char> a, const pair<int, char> b) {
	return a.first<b.first;//�Զ���ıȽϺ���
}

int main()
{
	vector<pair<int, char>> p;
	p.push_back(make_pair(10, 'a'));
	p.push_back(make_pair(9, 'c'));
	p.push_back(make_pair(10, 't'));
	p.push_back(make_pair(17, 'y'));
	p.push_back(make_pair(10, 'b'));

	sort(p.begin(), p.end(), cmp);//���յ�һ��Ԫ������
	for (auto i = 0; i<p.size(); i++)
		cout << p[i].first << "    " << p[i].second << endl;
	system("pause");

	return 0;
}