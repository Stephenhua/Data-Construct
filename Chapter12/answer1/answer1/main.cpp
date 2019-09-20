#include"answer.h"
# include <iostream>
using namespace std;
void answer1(){
	Cow cow1("he", "music", 400);
	Cow cow2("ha", "sport", 90);
	Cow cow3("hh", "basketball", 320);
	Cow cow4(cow1);
	Cow cow5 = cow3;

	cow1.ShowCow();
	cow2.ShowCow();
	cow3.ShowCow();
	cow4.ShowCow();
	cow5.ShowCow();
	system("pause");
	
}