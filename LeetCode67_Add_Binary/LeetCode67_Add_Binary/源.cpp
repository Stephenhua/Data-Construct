#  include <iostream>
# include <string >

using namespace std;

string addBinary1(string a, string b)
{
	int m = a.size();
	int n = b.size();
	int carry = 0;
	string res = "";
	while (m&&n)
	{
		m--; n--;
		int cur = carry + a[m] + a[n] - '0' - '0';
		if (cur % 2)
		{
			res = "1" + res;
		}
		else
		{
			res = "0" + res;
		}
		carry = cur > 1;
	}

	while (m)
	{
		m--;
		int cur = carry + a[m] - '0';
		if (cur % 2)
		{
			res = "1" + res;
		}
		else
		{
			res = "0" + res;
		}
		carry = cur > 1;
	}
	while (n)
	{
		n--;
		int cur = carry + a[n] - '0';
		if (cur % 2)
		{
			res = "1" + res;
		}
		else
		{
			res = "0" + res;
		}
		carry = cur > 1;
	}
	if (carry)
	{
		res = "1" + res;
	}
	return res;
}


string addBinary2(string a, string b)
{
	string res = "";
	int m = a.size() - 1, n = b.size() - 1, carry = 0;
	while (m >= 0 || n >= 0)
	{
		int p = m >= 0 ? a[m--] - '0' : 0;
		int q = n >= 0 ? b[n--] - '0' : 0;
		int sum = p + q + carry;
		res = to_string(sum % 2) + res;
		carry = sum / 2;
	}
	return carry == 1 ? "1" + res : res;
}
int main()
{
	string a = "1111", b = "1010";
	string c,d;
	c=addBinary1(a, b);
	d = addBinary2(a, b);
	cout << c <<" "<<d<<endl;
	
	system("pasue");
	return EXIT_SUCCESS;
}