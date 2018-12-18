# include <iostream>
using namespace std;
class solution{
public :
	void merge(int nums1[], int m, int nums2[],int n)
	{
		int i = m - 1, j = n - 1, writeIdx = m + n - 1;
		while (i >= 0 && j >= 0)
		{
			nums1[writeIdx--] == nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];

		}
		while (j >= 0)
		{
			nums1[writeIdx--] = nums2[j--];
		}
	}
};
int main()
{
	solution sols;
	int len;
	//cout << "Please input the length of array :" << endl;
	//cin >> len;
	//int *ptr= new int[len];
	int ptr[] = { 2, 3, 4, 0, 0, 0 };
	
	int nums1[] = { 10, 12, 13 };
	int m = 6, n = 3;
	sols.merge(ptr, m, nums1, n);
	for (int i = 0; i < 10; i++)
	{
		cout << ptr[i] << endl;
	}
	system("pause");
	return EXIT_SUCCESS;
}