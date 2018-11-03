# include <algorithm>
# include <vector>
# include <iostream>
# include <list>
using namespace std;
int main()
{
	vector<int > vi1, vi2;
	list<int > lit1;
	for (int i = 0; i < 10; i++)
	{
		vi1.push_back(i);
		vi2.push_back(i);
		lit1.push_back(i);
	}
	if (equal(vi1.begin(), vi1.end(), vi2.begin()))
		cout << "vi1 equal vi2\n" << endl;
	else
		cout << "vi1 not equal vi2\n" << endl;
	if (equal(vi1.begin() + 5, vi1.end(), vi2.begin()))
		cout << "vi1 equal vi2\n" << endl;
	else
		cout << "vi2 not equal vi2\n" << endl;

	if (equal(vi1.begin(), vi1.end(), lit1.begin()))
		cout << "vi1 equal lit1\n" << endl;
	else
		cout << "vi1 not equal lit1\n" << endl;
	system("pause");
	return EXIT_SUCCESS;
}