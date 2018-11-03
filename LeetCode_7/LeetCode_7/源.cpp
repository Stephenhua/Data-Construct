# include <iostream>
# include <math.h>
using namespace  std;
int reverse(int x)//������
{
	int ret = 0;
	bool isNegative = false;
	if (x < 0)
	{
		isNegative = true;
		x *= -1;
	}
	while (x > 0)
	{
		int lastDigit = x % 10;
		if (lastDigit == 0 && ret == 0)
		{
			x = x / 10;
			continue;
		}
		if (ret > (INT_MAX - lastDigit) / 10)
		{
			return 0;
		}
		ret = (ret * 10 + lastDigit);
		x = x / 10;

	}
	return ret*((isNegative) ? -1 : 1);
}
int reverse1(int x) {//�������ַ�ת����ʵ�ַ���һ
		int res = 0;
		while (x != 0) {
			if (abs(res) > INT_MAX / 10) return 0;
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}

int reverse2(int x)
{
	bool a = (x > 0);//�ж�x������
	long x_long = (a) ? x : -x;//ȡ����ֵ
	long ans = 0;
	while (x_long > 0)//��������ȡ�������ȡ���������ȡ����
	{
		if (ans > INT_MAX / 10 || ans < INT_MIN / 10)
		{
			return 0;
		}
		ans = ans * 10 + x_long % 10;
		x_long = x_long / 10;
	}
	return (a) ? ans : -ans;//����ֵ

}

int main()
{
	int x = 432492024;
	cout << reverse(x) << endl;
	cout << reverse1(x) << endl;
	cout << reverse2(x) << endl;
	system("pause");
	return EXIT_SUCCESS;
}