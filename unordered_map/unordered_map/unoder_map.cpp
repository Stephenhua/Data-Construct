# include"unordered_map.h"
Node::Node() :m_iAge(0)
{}
Node::~Node() {}

bool Node::operator==(const Node & n)const 

{
	if (n.m_iAge == m_iAge && m_strName == n.m_strName)
	{
		return true;
	}
	return false;

}