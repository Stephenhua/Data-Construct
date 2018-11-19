# include <iostream>
# include <set>
# include <string>

using namespace std;
/*
int main()
{
	set<int> s;
	s.insert(1);
	s.insert(2);
	s.insert(9);
	s.insert(7);
	cout << "set ��sizeֵΪ�� " << s.size() << endl;
	cout << "set ��maxsizeֵΪ�� " << s.max_size() << endl;
	cout << "set �ĵ�һԪ��Ϊ�� " << *s.begin() << endl;
	cout << "set �е����һ��Ԫ���ǣ� " << *s.end() << endl;


 
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)//�˴��Ѿ����ݴ�С��������begin��end����ʾԪ�صĵ�ַ
	{
		cout << *it << endl;
	}
	
	s.clear();
	if (s.empty())
	{
		cout << "set Ϊ��!!" << endl;
	}
	cout << "set ��sizeֵΪ:" << s.size() << endl;
	cout << "set �е�maxsizeΪ��L" << s.max_size() << endl;

	system("pause");
	return EXIT_SUCCESS;
}
*/

struct info
{
	string name;
	double score;
	bool operator <(const info &a) const
	{
		return a.score < score;
	}
};

int main()
{
	set<info> s;
	info inf;
	inf.name = "Jack";
	inf.score = 80;
	s.insert(inf);
	inf.name = "Tom";
	inf.score = 99;
	s.insert(inf);
	inf.name = "Jason";
	inf.score = 98;
	s.insert(inf);

	set<info>::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		cout << (*it).name << " : " << (*it).score << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}