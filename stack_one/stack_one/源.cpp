# include <iostream>
# include <stack>
# include <string>
# include "stacktp.h"
# include <cctype>

using namespace std;

/*int main()
{
	stack<string> ss;
	string s;
	while (cin >> s)
	{
		ss.push(s);
	}
	while (!ss.empty())
	{
		cout << ss.top();
		ss.pop();
		if (!ss.empty())
			cout << ' ';
	}

	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}
*/

int main()
{
	Stack<std::string> st;
	char ch;
	std::string po;
	cout << "Please enter A to add a purchase order ,\n"
	<< "P to process a P0,or Q to quit .\n";
	while (cin >> ch&&std::toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
			continue;
		if (!std::isalpha(ch))
		{
			cout << "\a";
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a':cout << "Enter a P0 number to add :";
			cin >> po;
			if (st.isfull())
			{
				cout << "Stach already full\n";
			
			}
			else
			{
				st.push(po);
			}
			break;
		case'P':
		case'p':
			if (st.isfull())
				cout << "Stack already empty\n";
			else
			{
				st.pop(po);
				cout << "PO#" << po <<"poped\n";
				break;
			}
		}

		cout << "Please enter A to add a purchase order,\n " << "p to process a Po ,or Q t quit";

	}
	cout << "Bye\n";
	return EXIT_SUCCESS;
}