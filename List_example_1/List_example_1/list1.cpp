# include <iostream>
# include "list.h"

using namespace std;

template<class CElemType>
CList<CElemType>::CList()
{
	m_nSize = 0;
	m_nLength = INIT_SIZE;
	m_pElem = new CElemType[INIT_SIZE];
}

template<class CElemType>
CList<CElemType>::~CList()
{
	delete[] m_pElem;
}

template<class CElemType>
 int CList<CElemType>::GetLength()
{
	return m_nLength;
}

template<class CElemType>
int  CList<CElemType>::GetSize()
{
	return m_nSize;
}

template<class CElemType>
CElemType CList<CElemType>::GetAt(int nIndex)
{
	return m_pElem[nIndex];
}



template<class CElemType>
 
void  CList<CElemType>::SetAt(int nIndex, CElemType e)
{
	m_pElem[nIndex] = e;
}


template<class CElemType>
int CList<CElemType>::AddTrail(CElemType e)
{
	return InsertAt(GetSize(), e);
}

template<class CElemType>
int CList<CElemType>::InsertAt(int nIndex, CElemType e)
{
	if (nIndex > GetSize())
	{
		cout << "索引超出范围，未插入任何元素" << endl;
		return -1;
	}

	if (GetSize() == GetLength())
	{
		CElemType *p = new CElemType[GetSize() + INCERMENT_SIZE];

		for (int i = 0; i < nIndex; i++)
		{
			p[i] = m_pElem[i];
		}

		for (int i = nIndex; i < GetSize(); i++)
		{
			p[i + 1] = m_pElem[i];
		}

		delete[]m_pElem;
		m_nLength += INCERMENT_SIZE;
		m_pElem = p;
		delete[]p;
	}
	else
	{
		for (int i = GetSize() - 1; i >= nIndex; i--)
		{
			m_pElem[i + 1] = m_pElem[i];

		}
	}

	m_pElem[nIndex] = e;
	m_nSize++;
	return nIndex;
}

template<class CElemType>
void CList<CElemType>::RemoveAt(int nIndex, int nCounter)
{
	if (nIndex > GetSize() - 1 || nIndex + nCounter >= GetSize())
	{
		cout << "索引超出范围，未删除任何元素" << endl;
		return;
	}

	for (int i = nIndex; i <= nIndex + nCounter; i++)
	{
		m_pElem[i] = m_pElem[i + nCounter];
	}

	m_nSize -= nCounter;
	if (GetLength() > INIT_SIZE&&GetLength() - GetSize() >= INCERMENT_SIZE)
	{
		int N = GetSize() + (GetLength() - GetSize()) % INCERMENT_SIZE;
		CElemType *p = new CElemType[N];
		for (int i = 0; i < GetSize(); i++)
		{
			p[i] = m_pElem[i];
			delete[]m_pElem;
			m_pElem = p;
			m_nLength = N;

		}
		delete[]p;
	}
}

template<class CElemType>
void CList<CElemType>::ShowValues()
{
	if (GetSize() == 0)
	{
		cout << "表中无元素： " << endl;

	}
	else
	{
		for (int i = 0; i < GetSize(); i++)
		{
			cout << m_pElem[i] << ' ';
			if (((i + 1) % 15) == 0 && i != GetSize() - 1)
				{
					cout << endl;
                  }
		}
		cout << endl;
	}
}
