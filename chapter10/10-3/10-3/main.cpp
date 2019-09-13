#include<iostream>
#include"golf.h"
int main()
{
	Golf g("Alex", 90);
	g.showgolf();
	std::cout << std::endl;
	g.setgolf();
	std::cout << std::endl;

	g.sethandicap(99);
	g.showgolf();
	system("pause");
	return 0;
}