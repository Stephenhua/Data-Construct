#ifndef LIST_H_
#define LIST_H_
template < class CElemType>
class CList
{
public://常数定义
	enum
	{
		INIT_SIZE=20,//线性表初始空间长度（元素个数）
		INCERMENT_SIZE =10//新增空间长度（元素个数）
	};
	//成员变量
private:
	CElemType *m_pElem;//线性表顺序结构的基址
	int m_nSize;//线性表当前长度
	int m_nLength;//为线性表分配的存储空间长度
	//成员函数
public:
	CList();//构造函数
	~CList();//析构函数
	int GetSize();//获取线性表当前长度
	int GetLength();//获取线性表分配的存储容量
	CElemType GetAt(int nIndex);//检索元素
	void SetAt(int nIndex, CElemType e);//修改元素
	int InsertAt(int nIndex, CElemType e);//在制定位置插入元素，返回索引号
	int AddTrail(CElemType e);//把元素e加入到线性表的尾部
	int AddHead(CElemType e);//把元素e加入到线性表的头部
	void RemoveAt(int nIndex, int nCounter = 1);//在指定位置删除你Counter
	void ShowValues();//显示列表中的所有元素
};

#endif