# include "stack.h"
# include <iostream>
# include <cctype>

int main()
{
	using namespace std;
	stack st;
	char ch;
	unsigned long po;
	cout << "Please enter A to add a purchase order,\n" << "P to process a P0,P1,P2 or quit " << endl;
	while (cin >> ch&&toupper(ch) != 'Q')
	{
		while (cin.get() != '\n')
		{
			continue;
		}
		if (!isalpha(ch))
		{
			cout << '\a';
			continue;
		}

		switch (ch)
		{
		case 'A':
		case 'a':cout << "Enter a P0 number to add:";
			cin >> po;
			if (st.isfull())
			{
				cout << "stack already full\n";

			}
			else{
				st.pop(po);
			}
			break;
		case 'P':
		case 'p':
			if (st.isempty()){
			cout << "stack already full" << endl;
			}
			else{
				st.pop(po);
				cout << "P0#" << po << "poped\n" << endl;
				
			}
			break;

		}
		cout << "please eneter A to add a purcahse order ,\n";
	}

	cout << "Bye\n";
	system("pause");
	return 0;

}