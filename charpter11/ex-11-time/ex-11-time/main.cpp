#include<iostream>
#include "time.h"
int main(){
	using namespace std;
	Time weeding(4, 35);
	Time waxing(3, 58);
	Time total;
	Time diff;
	Time  adjusted;

	cout << "weeding time is :" << endl;
	weeding.show();
	
	cout << "Waxing time is ";
	waxing.show();
	cout << endl;

	cout << "total work time is:";
	total = weeding + waxing;
	total.show();
	cout << endl;

	cout << " work time is:";
	diff = weeding - waxing;
	diff.show();
	cout << endl;

	adjusted = total*1.5;
	cout << "adjusted time =";
	adjusted.show();
	cout << endl;

	system("pause");
	return 0;

}