#include <iostream>
#include "dma.h"

int main(){
	using namespace std;
	baseDMA shirt("Protablely", 8);
	lacksDMA ballon("red", "Blimpo", 4);
	hasDMA map("Mercator", "Buffalo keys", 5);
	cout << "Display shit £º\n";
	cout << shirt << endl;
	cout << "Display ballon :\n";
	cout << ballon << endl;
	cout << "Displaying Mercator :\n";
	cout << map << endl;

	lacksDMA balloon2(ballon);
	cout << "Reslut of lacksDMA copy:\n";
	cout << balloon2 << endl;

	hasDMA map2;
	map2 = map;
	cout << "Reslue of hasDMA assigment :\n";
	cout << map2 << endl;
	
	system("pause");
	return 0;
}