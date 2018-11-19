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
	cout << "set 的size值为： " << s.size() << endl;
	cout << "set 的maxsize值为： " << s.max_size() << endl;
	cout << "set 的第一元素为： " << *s.begin() << endl;
	cout << "set 中的最后一个元素是： " << *s.end() << endl;


 
	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)//此处已经根据大小进行排序，begin和end都表示元素的地址
	{
		cout << *it << endl;
	}
	
	s.clear();
	if (s.empty())
	{
		cout << "set 为空!!" << endl;
	}
	cout << "set 的size值为:" << s.size() << endl;
	cout << "set 中的maxsize为：L" << s.max_size() << endl;

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