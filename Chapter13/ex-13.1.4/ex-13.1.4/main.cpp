#include <iostream>
#include "tabteen.h"

int main(void){
	using namespace std;
	TableTennisPlayer player("Jason", "hua", false);
	RatedPlayer rplayer(1140, "Nalode", "jdgg", true);

	rplayer.Name();
	if (rplayer.HasTable()){
		cout << ":has a table\n";
	}
	else{
		cout << "has not table ;\n";
	}

	player.Name();
	if (player.HasTable()){
		cout << "has a table";
	}
	else{
		cout << ": has not a table ;";
	}

	rplayer.Name();
	cout << "Rating is :" << rplayer.Rating() << endl;

	RatedPlayer rplayer2(1212, player);
	cout << "Name :";
	rplayer2.Name();
	cout << ";Rating :" << rplayer2.Rating() << endl;
	system("pause");
	return 0;
}