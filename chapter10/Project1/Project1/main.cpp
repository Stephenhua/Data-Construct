#include <iostream>
#include <string>
#include "stcok.h"

using namespace std;
int main()
{

	cout << "using constructors to create new objects\n";
	Stock stock1("Nmew", 12, 30.0);
	stock1.show();
	Stock stock2 = Stock("Nike", 15, 45.0);
	stock2.show();
	
	cout << "Assiging stock1 to stokc2 :\n";
	stock2 = stock1;
	stock1.show();
	stock2.show();

	cout << "Using a constractor to rest an object\n";
	stock1 = Stock("Nify", 10, 50.0);
	cout << "Revised stock1:\n";
	stock1.show();

	Stock stocks[4] = {
		Stock("nanosta", 23, 43),
		Stock("Bon", 21, 32),
		Stock("Nike", 84, 90),
		Stock("Fleep", 43, 89)
	};
	int st;
	for (st = 0; st < 4; st++)
	{
		stocks[st].show();
	}

	 const Stock *top = &stocks[0];
	for (int st = 1; st < 4; st++)
	{
		top = &top->topval(stocks[st]);
	}

	cout << "The valueable holding :\n";
	top->show();


	system("pause");
	return 0;

}