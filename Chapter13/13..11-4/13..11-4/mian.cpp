#include <iostream>
#include <string>
#include "Port.h"

int main(){
	//≤‚ ‘≥Ã–Ú

		Port port1("gallo", "tawny", 20);
		cout << port1 << endl << endl;
		VintagePort vp("gallo", "vintage", 24, "Old Velvet", 16);
		VintagePort vp2(vp);
		cout << vp2 << endl << endl;
		VintagePort vp3;
		vp3 = vp;
		cout << vp3 << endl << endl;

		Port * p_port;
		p_port = &port1;
		p_port->show();
		cout << endl;
		p_port = &vp;
		p_port->show();
		cout << endl;
		system("pause");
		return 0;

}