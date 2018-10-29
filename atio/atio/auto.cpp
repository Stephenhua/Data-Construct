# include <iostream>

using namespace std;
int atoi_my(const char *str)
{
	int s = 0;
	bool flag = false;
	while (*str == ' ')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			flag = true;
		str++;
	}
	

	while (*str >= '0'&&*str <= '9')
	{
		s = s * 10 + *str - '0';
		str++;
		if (s < 0)
		{
			s = 2147483647;
			break;
		}
	}
	return s*(flag ? -1 : 1);
}
int main()
{
	char *s1 = "333640";
	char *s2 = "-12345";
	char *s3 = "123.1231";

	int sum1 = atoi(s1);
	int sum_1 = atoi_my(s1);
	cout << "atoi: :" << sum1 << endl;
	cout << " atio_my:" << sum_1 << endl;

	int sum2 = atoi(s2);
	int sum_2 = atoi_my(s2);
	cout << "atoi: :" << sum2 << endl;
	cout << " atio_my:" << sum_2 << endl;

	int sum3 = atoi(s3);
	int sum_3 = atoi_my(s3);
	cout << "atoi: :" << sum3 << endl;
	cout << " atio_my:" << sum_3 << endl;


	system("pause");
	return (0);
}