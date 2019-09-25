#include <iostream>
#include "brass.h"

int main(){
	using std::endl;
	using std::cout;

	Brass Piggy("Porcelot Pigg", 318299, 4000.0);
	BrassPlus Hoggy("Horatio Hogg", 382888, 3000.0);
	Piggy.viewAcct();
	cout << endl;

	Hoggy.viewAcct();
	cout << endl;

	cout << "Deposit $1000 into the Hogg Account :\n";
	Hoggy.Deposit(1000);
	cout << "New Balance :$" << Hoggy.Balance() << endl;

	cout << "WithDrawing $4200 from the Pigg Account :\n";
	Piggy.WithDrow(4200);

	cout << "Piggy account balance :$" << Piggy.Balance() << endl;

	cout << "Withdrawing $4200 fromg the Hogg Account :\n";
	Hoggy.WithDraw(4200);
	Hoggy.viewAcct();

	system("pause");
	return 0;
}