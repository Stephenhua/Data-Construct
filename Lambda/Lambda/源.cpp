# include <iostream>
# include <vector>
# include<algorithm>
using namespace std;
bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	vector<int> myvec{ 3, 2, 4, 6, 2, 1 };
	vector<int> lbvec(myvec);
	sort(myvec.begin(), myvec.end(), cmp);
	cout << "predicate function:" << endl;
	for (int it : myvec)
		cout << it << ' ';
	cout << endl;

	sort(lbvec.begin(), lbvec.end(), [](int a, int b)->bool{return a < b; });//Lambda ±í´ïÊ½£¬
	cout << "predicate function:" << endl;
	for (int it : myvec)
		cout << it << ' ';
	cout << endl;
	system("pause");
	return EXIT_SUCCESS;

}