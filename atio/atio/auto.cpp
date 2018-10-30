# include <iostream>
//atoi()函数将字符串转换为整型数
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


//Atoi 算法的实现

class Solution{
public:
	int myAtoi(string str)
	{
		int i = 0;
		int sign = 1;
		long long atoi = 0;
		while (str[i] == ' ')
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while (str[i] == '0')
		{
			i++;
		}
		int digit = 0;
		while (str[i] >= '0'&& str[i] <= '9')
		{
			atoi = atoi * 10 + (str[i] - '0');
			i++;
			digit++;
			if (digit > 10)
				return sign == 1 ? INT_MAX : INT_MIN;
			return atoi;
		}
		if (atoi > INT_MAX)
			return INT_MAX;
		return atoi;
	}
};

//算法实现二

class Solution{
public:
	int convert(string str, int start_pos, int end_pos, bool neg)
	{
		int mul = 1;
		if (neg)
			mul = -1;
		long ans = 0;
		long maxi = INT_MAX;
		long mini = (long)-1 * (long)INT_MIN;
		for (int i = start_pos; i < end_pos; i++)
		{
			ans = ans * 10 + ((double)str[i] - '0');
			if (neg)
			{
				if ((long)-1 * ans <= INT_MIN)
				{
					return INT_MIN;
				}
			}
			else
			{
				if (ans >= INT_MAX)
				{
					return INT_MAX;
				}
			}
		}
		return (int)ans*mul;
	}
	int myAtoi(string str)
	{
		if (str.size() == 0)
		{
			return 0;
		}
		int start_pos = 0;
		bool neg = false;
		while (start_pos < str.size())
		{
			if (str[start_pos] == ' ') start_pos++;
			else if (str[start_pos] == '-' || str[start_pos] == '+' || str[start_pos] >= '9' || str[start_pos] <= '0') break;

			else
				return 0;
		}
		if (str[start_pos] == '-')
			neg = true;
		if (str[start_pos] == '-' || str[start_pos] == '+')
			start_pos++;
		if (start_pos >= str.size()) return 0;

		int end_pos = start_pos;
		while(end_pos < str.size())
			{
				if (str[end_pos] >= '0'&&str[end_pos] <= '9') end_pos++;
				else
					break;
		      }
		if (start_pos == end_pos)
			return 0;
		return convert(str, start_pos, end_pos, neg);

	}
};