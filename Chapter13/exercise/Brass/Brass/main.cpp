#include<iostream>
#include"brass.h"
using namespace std;
/*
int main()
{
	Brass Riggy("Porcelot Pigg", 381299, 4000.0);
	BrassPlus Jason("Jason_hua", 382288, 3000.00);
	Riggy.ViewAcct();
	cout << endl;
	Jason.ViewAcct();
	cout << endl;
	cout << "Deposting $1000 into the Hogg Account .\n";
	Jason.Deposit(1000);
	cout << "New balance :$" << Jason.Balance() << endl;
	cout << "Withdrowing $4200 from the Hogg Account ;";
	Jason.Withdrow(4200);
	Jason.ViewAcct();
	system("pause");
	return EXIT_SUCCESS;
}
*/
const int Clients = 4;
int main()
{
	Brass *p_clients[Clients];
	string temp;
	long tempnum;
	double tempbal;
	char kind;
	for (int i = 0; i < Clients; i++)
	{
		cout << "Enter client's name :";
		getline(cin, temp);
		cout << "Enter client's account number : ";
		cin >> tempnum;
		cout << "Enter opening balance : $ ";
		cin >> tempbal;
		cout << "Enter 1 for Brass count or Enter 2 for BrassPlus Account :";
		while (cin >> kind && (kind != '1'&&kind != '2'))
		{
			cout << "Enter either 1 or 2 :";
		}
		if (kind == '1')
		{
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		}
		else
		{
			double tmax, trate;
			cout << "Enter the overdraft limits :$";
			cin >> tmax;
			cout << "Enter the interest rate as a decimal fraction:";
			cin >> trate;
			p_clients[i] = new BrassPlus(temp, tempnum, tempbal, tmax, trate);
		}
		while (cin.get() != '\n')
		{
			continue;
		}
	}
	cout << endl;
	for (int i = 0; i < Clients; i++)
	{
		p_clients[i]->ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < Clients; i++)
	{
		delete p_clients[i];
	}
	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}