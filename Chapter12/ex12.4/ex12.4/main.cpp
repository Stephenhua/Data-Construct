#include<iostream>
#include <cstring>
#include "String1.h"

const int ArSize = 10;
const int MAxLen = 81;
int main(){
	using namespace std;
	String name;
	cout << "Hi, what's your name ?" << endl;
	cin >> name;

	cout << name << ",please enter up to " << ArSize << "Short saying <empty lint to quit>:\n";
	
	String sayings[ArSize];
	char temp[MAxLen];
	int i;
	for (i = 0; i < ArSize; i++){
		cout << i + 1 << ":";
		cin.get(temp, MAxLen);
		while (cin&&cin.get() != '\n') 
		    continue;
		if (!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}

	int total = i;

	if (total > 0){
		cout << "Here are your sayings:\n";
		for (int i = 0; i < total; i++){
			cout << sayings[i][0] << ":" << sayings[i] << endl;
	    }

		int shorest = 0;
		int first = 0;
		for (int i = 0; i < total; i++){
			if (sayings[i].length() < sayings[shorest].length())
				shorest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}

		cout << "Shorest saying :\n" << sayings[shorest] << endl;
		cout << "First saying:\n" << sayings[first] << endl;
		cout << "This programe used " << String::HowMany() <<" String object .Bye\n"<<endl;

	}
	else{
		cout << "No input!bye.\n";
	}
	system("pause");
	return 0;
	
}