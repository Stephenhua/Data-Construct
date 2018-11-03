
#ifndef Node_H_ 

# include <string>
# include <iostream>
class Node
{
private:
	std::string  m_strName;
	int m_iAge;
public:
	Node();
	~Node();
	bool operator == (const Node &n)const;
};
# endif