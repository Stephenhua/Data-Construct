//=================
//ListNode模板类
//=================

typedef int Rank;//秩			
# define LListNodePosi(T) ListNode<T>* //列表节点位置

template <typename T>struct ListNode//列表节点模板类
{
	T data;
	ListModePosi(T)pred;
	ListNodePosi(T) succ;//数值，前驱，后驱

	ListNode(){}//针对header和trailer的构造
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL) :data(e), pred(p), succ(){}//默认构造器
	//操作接口
	ListNodePosi(T) insertAsPred(T const& e);//紧靠当前节点之前新节点
	ListModePosi(T) insertAsSucc(T const& e);//紧随当前接待之后的插入新节点
};

//=================
//头和尾节点
//=================
template <typename T> void List<T>::init()//列表初始化，在创建列表对象是统一调用
{
	header = new ListNode<T>;//创建头哨兵节点
	trailer = new ListNode<T>；//创建尾哨兵节点
		header->succ = trailer; header->pred =NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;//记录规模
}

//=================
//由秩到位置的转换
//=================
template<typename T>//重载下标标识符，以通过秩直接访问列表节点

T& List<T>::operator[](Rank r) const
{
	ListNodePosi(T) p = first();//从首节点触发
	while (0 < r--)p = p->succ;//顺序第r个节点既是
	return p->data;//目标节点，返回其中所存在的元素
}
//=================
//查找
//=================
template <typename T>//在无序列表内节点p前驱中，找到等于e的最后者
LListNodePosi(T) List<T>::find(T const&, int n, ListNodePosi(T) p)const
{
	while (0 < n--)//对于p的最近的n个前驱，从右向左
	{
		if (e == (p = p->pred)->data)//诸葛比对，直至命中或范围越界
			return p;
	}
	return NULL;//失败时返回NULL
}

//=================
//插入
//=================

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e)//e作为首节点插入
{
	_size++;
	return header->insertAsSucc(e);
}

template <typename T> ListNodePosi(T) List<T>::insertAsLast(T const & e)//e做为末尾节点插入
{
	_size++;
	return trailer->insertAsPred(e);
}

template <typename T> ListNodePosi(T) List(T)::insert A(ListNodePosi(T) p, T cosnt & e)//e作为p的后继插入
{
	_size++;
	return p->insertAsSucc(e);
}

template <typename T >ListNodePosi(T) List(T)::insert B(ListNodePosi(T) p, T const &e)//e作为p的前驱插入
{
	_size++;
	return p->insertAsPred(e);
}

//=================
//前插入
//=================
template <typename T>
ListNodePosi(T)ListNode<T>::insert
