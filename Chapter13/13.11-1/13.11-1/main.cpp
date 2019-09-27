#include <iostream>
#include <string>
#include "cd.h"
using namespace std;

void Bravo(const Cd & disk)
{
	disk.report();
}

int main(){
	
		Cd c1("Beatles", "Capitol", 14, 35.5);
		Cd2 c2 = Cd2("Piano Sonata in B flat, Fantasia in C",
			"Alfred Brendel", "Philips", 2, 57.17);
		Cd *pcd = &c1;

		cout << "Using object directly:\n";
		c1.report();
		c2.report();

		cout << "Using type cd * pointer to objects:\n";
		pcd->report();
		pcd = &c2;
		pcd->report();

		cout << "Calling a function with a Cd reference argument:\n";
		Bravo(c1);
		Bravo(c2);

		cout << "Testing assignment: \n";
		Cd2 copy;
		copy = c2;
		copy.report();
	system("pause");
	return 0;	
}

