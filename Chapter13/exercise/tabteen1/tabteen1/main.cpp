#include<iostream>
#include"tabtenn1.h"
using namespace std;
int main(void)
{
	TableTennisPlayer player1("Tara", "Babo", false);
	RatedPlayer rplayer1(1140, "Malloy", "Duck", true);

	rplayer1.Name();
	if (rplayer1.HasTable())
	{
		cout << ": has a table .\n";
	}
	else
	{
		cout << " has not a table .\n";
	}
	cout << "Name";

	rplayer1.Name();
	cout << ": rating " << rplayer1.Rating() << endl;
	RatedPlayer rplayer2(1212, player1);
	cout << "Name :";
	rplayer2.Name();
	cout << ": Rating : " << rplayer2.Rating() << endl;
	system("pause");
	return EXIT_SUCCESS;
}