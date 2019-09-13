#include"BankCount.h"
#include <iostream>
#include <string>
int main()
{
	cout << "Bank count information:\n";
	Account b1("Jason", "432123", 313);
	b1.show();
	cout << "Pleae input your save money:\n";
	b1.save(50);
	b1.show();
	b1.take(400);
	b1.show();

	system("pause");
	return 0;
}