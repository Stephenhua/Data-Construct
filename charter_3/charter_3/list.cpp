
/*
/=================
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
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const & e)
{
	ListNodePosi(T) x = new ListNode(e, pred, this);//创建新的节点
	pred->succ = x;//设置正相节点
	pred = x;
	return x;//返回新节点的位置
}
template <typename T >
{
	ListNodePosi(T) ListNode<T>::insertAsSuxx(T const& e)
	{
		ListNodePosi(T) x = new ListNode(e, this, succ);//创建新的节点
		succ->pred = x;//设置逆向连接
		succ = x;
		return x;//返回新节点的位置
	}
}


void insert(node * &head, char keyWord, char newdata)
{
	node *newnode = new node;//建立新的节点
	newnode->data = newdata;//新节点的数据
	node *pGuard = search(head, keyWord);//pGuard是插入位置前的节点指针
	if (head == NULL || pGuard == NULL)//如果链表没有节点或者找不到关键字节点
	{
		newnode->next = head;//先连
		head = newnode;//后断
	}
	else
	{//插入在pGuard之后
		newnode->next = pGuard->next;//先连
		pGuard->next = newnode;//后段
	}
}
//===================================
//节点删除的实例说明
//====================================
void Delete(node *&head, char keyword)//可能要操作表头指针，所以用head引用
{
	if (head != NULL)
	{
		node *p;
		node *pGuard = head;
		if (head-> == keyward)
		{
			p = head;
			head = head->next;
			delete p;
			cout << "The deleted node is " << keyWord << endl;
			return;
		}
		else
		{
			while (pGuard->next != NULL)
			{
				if (pGuard->next->data == keyword)
				{
					p = pGuard->next;//后继节点是待删除的节点
					pGuard->next = p->next;//先连
					delete p;//后断
					cout <<" The deleted node is " << keyWord << endl;
					return;
				}
				pGuard = pGuard->next;
			}
		}
	}
	cout << "The keyword node is not found or the link list is empty" << endl;
}

template <typename T>//列表内部方法：复制列表中位置p起的位置
void List<T>::copyNodes(ListNodePosi(T) p, int n)
{
	init();//创建头，尾哨兵并作初始化
	while (n--)
	{
		insertAsLast(p->data; p = p->succ;)//将起自p的n项一次作为末节点插入；
	}
}
*/

# include <iostream>
# include <malloc.h>
# include <ostream>

using namespace std;

typedef int DataType;
//定义链表的数据结构
typedef struct node{
	DataType data;
	struct node *next;
}LNode,* LinkList;


//尾插法创建链表
LinkList Tail_Creat_LinkList()
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (!H)
	{
		cout << "申请空间失败!";
		return 0;
	}
	H->next = NULL;
	cout << "输入单链表元素（负数结果）：";
	LinkList  p, r;
	p = r = (LinkList)malloc(sizeof(LNode));//利用malloc函数向系统申请分配一个节点
	cin >> p->data;//输入节点的值
	p->next = nullptr;//将新节点设置为空值

	while (p->data >= 0)//输入节点的值大于0
	{
		if (!H->next)
		{
			H->next = p;//空表，介入表头
		}
		else
		{
			r->next = p;//非空，接入尾表
		}
		r = p;

		p = (LinkList)malloc(sizeof(LNode));//下一个新节点
		cin >> p->data;
		p->next = NULL;
	}
	return H;//返回链表头指针
}
//单链表复制
LinkList CCopy_LinkList(LinkList H)
{
	LinkList G;
	G = (LinkList)malloc(sizeof(LNode));
	if (!G)
	{
		cout << "申请空间失败！";
		return 0;
	}
	G->next = NULL;

	LinkList p, r, h = H->next;
	r = (LinkList)malloc(sizeof(LNode));

	while (h)
	{
		p = (LinkList)malloc(sizeof(LNode));
		p->data = h->data;
		p->next = NULL;

		if (!G->next)
		{
			G->next = p;
		}
		else
		{
			r->next = p;
		}
		r = p;
		h = h->next;
	}
	return G;
}
void Show(LinkList H)
{
	LinkList p = H->next;
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
}
int main()
{
	LinkList Tail_Create_Linklist();//函数声明
	LinkList CCopy_LinkList(LinkList H);
	void Show(LinkList H);

	LinkList H = Tail_Create_Linklist();//创建链表
	cout << " 输出顺序标表为： ";
	Show(H);

	LinkList G = CCopy_LinkList(H);//复制链表
	cout << "\n\n输出复制的顺序表为：";
	Show(G);

	return 0;
}

template <typename T> T List<T>::remove(LietNodePosi(T) p)
{
	T e = p->data;//备份带删除节点的数值
	p->pred->succ = p->succ;//后继、前驱
	p->succ->pred = p->pred;//释放节点，更新规模
	delete p;
	_size--;
	return e;//返回备份数值
}

//===========================================
//析构函数
//=============================================
template <typename T > List <T>::~List()//列表析构器
{
	clear();
	delete header;//清空列表，释放头，尾哨兵节点；
	delete trailer;
}
template <typename T> int List<T>::clear()//清空列表
{
	int oldSize = _size;
	while (0 < _size)//反复删除首节点，直至列表变空
		remove(header->succ);
	return oldSize;
}

//======================================
//唯一化
//======================================
template <typename T> int List<T>::deduplicate()//剔除列表的重复节点
{
	if (_size < 2)return 2;//列表自然无重复
	int oldSize = _size;//记录原始规模
	ListNodePosi(T) p = header; Rank r = 0;//p从首节点开始
	while (tralier != (p = p->succ))//依次直接到末节点
	{
		ListNodePosi(T) q = find(p->data, r, p);
		q ? remove(q) : r++;//若存在，直接删除，否则秩加一

	}
	return oldSize - _size;//列表规模变化，即被删除的数量
}

template <typename T > void List<T> ::traverse(void(*vist) (T&))//借助指针函数进行遍历
{
	for (ListNodePosi(T) p = header->succ; p != tralier; p = p->succ)
		vist(p->data);
}

template <typename T> template <typename  VST>//元素类型，操作器
void List<T>::traverse(VST& visit)//借助函数机制进行遍历
{
	for (ListNodePosi(T) p = header->succ; p != tralier; p = p->succ)
		visit(p->data);
}

//==========================================
//有序列表唯一化
//=========================================
template <typename T >int List<T>::uniquify()//成批剔除重复元素，效率更高
{
	if (_size < 2)return 0;//平凡列表自然无重复
	int oldSize = _size;//记录原始规模
	ListNodePosi(T) p = first(); ListNodePosi(T) q;//p为各阶段起点，q为其后继
	while (tralier != (q = p->succ))//反复考察紧邻的节点
		if (p->data != q->data)//如果互译，则转向下一个区段
			p = q;
		else
			remove(q);//如果有雷同，则删除后者
	return oldSize - _size;//列表规模变量化，即被删除元素的总数
}