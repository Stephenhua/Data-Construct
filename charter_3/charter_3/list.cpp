
/*
/=================
//ListNodeģ����
//=================

typedef int Rank;//��			
# define LListNodePosi(T) ListNode<T>* //�б�ڵ�λ��

template <typename T>struct ListNode//�б�ڵ�ģ����
{
	T data;
	ListModePosi(T)pred;
	ListNodePosi(T) succ;//��ֵ��ǰ��������

	ListNode(){}//���header��trailer�Ĺ���
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL) :data(e), pred(p), succ(){}//Ĭ�Ϲ�����
	//�����ӿ�
	ListNodePosi(T) insertAsPred(T const& e);//������ǰ�ڵ�֮ǰ�½ڵ�
	ListModePosi(T) insertAsSucc(T const& e);//���浱ǰ�Ӵ�֮��Ĳ����½ڵ�
};

//=================
//ͷ��β�ڵ�
//=================
template <typename T> void List<T>::init()//�б��ʼ�����ڴ����б������ͳһ����
{
	header = new ListNode<T>;//����ͷ�ڱ��ڵ�
	trailer = new ListNode<T>��//����β�ڱ��ڵ�
		header->succ = trailer; header->pred =NULL;
	trailer->pred = header; trailer->succ = NULL;
	_size = 0;//��¼��ģ
}

//=================
//���ȵ�λ�õ�ת��
//=================
template<typename T>//�����±��ʶ������ͨ����ֱ�ӷ����б�ڵ�

T& List<T>::operator[](Rank r) const
{
	ListNodePosi(T) p = first();//���׽ڵ㴥��
	while (0 < r--)p = p->succ;//˳���r���ڵ����
	return p->data;//Ŀ��ڵ㣬�������������ڵ�Ԫ��
}
//=================
//����
//=================
template <typename T>//�������б��ڽڵ�pǰ���У��ҵ�����e�������
LListNodePosi(T) List<T>::find(T const&, int n, ListNodePosi(T) p)const
{
	while (0 < n--)//����p�������n��ǰ������������
	{
		if (e == (p = p->pred)->data)//���ȶԣ�ֱ�����л�ΧԽ��
			return p;
	}
	return NULL;//ʧ��ʱ����NULL
}

//=================
//����
//=================

template <typename T> ListNodePosi(T) List<T>::insertAsFirst(T const& e)//e��Ϊ�׽ڵ����
{
	_size++;
	return header->insertAsSucc(e);
}

template <typename T> ListNodePosi(T) List<T>::insertAsLast(T const & e)//e��Ϊĩβ�ڵ����
{
	_size++;
	return trailer->insertAsPred(e);
}

template <typename T> ListNodePosi(T) List(T)::insert A(ListNodePosi(T) p, T cosnt & e)//e��Ϊp�ĺ�̲���
{
	_size++;
	return p->insertAsSucc(e);
}

template <typename T >ListNodePosi(T) List(T)::insert B(ListNodePosi(T) p, T const &e)//e��Ϊp��ǰ������
{
	_size++;
	return p->insertAsPred(e);
}

//=================
//ǰ����
template <typename T>
ListNodePosi(T) ListNode<T>::insertAsPred(T const & e)
{
	ListNodePosi(T) x = new ListNode(e, pred, this);//�����µĽڵ�
	pred->succ = x;//��������ڵ�
	pred = x;
	return x;//�����½ڵ��λ��
}
template <typename T >
{
	ListNodePosi(T) ListNode<T>::insertAsSuxx(T const& e)
	{
		ListNodePosi(T) x = new ListNode(e, this, succ);//�����µĽڵ�
		succ->pred = x;//������������
		succ = x;
		return x;//�����½ڵ��λ��
	}
}


void insert(node * &head, char keyWord, char newdata)
{
	node *newnode = new node;//�����µĽڵ�
	newnode->data = newdata;//�½ڵ������
	node *pGuard = search(head, keyWord);//pGuard�ǲ���λ��ǰ�Ľڵ�ָ��
	if (head == NULL || pGuard == NULL)//�������û�нڵ�����Ҳ����ؼ��ֽڵ�
	{
		newnode->next = head;//����
		head = newnode;//���
	}
	else
	{//������pGuard֮��
		newnode->next = pGuard->next;//����
		pGuard->next = newnode;//���
	}
}
//===================================
//�ڵ�ɾ����ʵ��˵��
//====================================
void Delete(node *&head, char keyword)//����Ҫ������ͷָ�룬������head����
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
					p = pGuard->next;//��̽ڵ��Ǵ�ɾ���Ľڵ�
					pGuard->next = p->next;//����
					delete p;//���
					cout <<" The deleted node is " << keyWord << endl;
					return;
				}
				pGuard = pGuard->next;
			}
		}
	}
	cout << "The keyword node is not found or the link list is empty" << endl;
}

template <typename T>//�б��ڲ������������б���λ��p���λ��
void List<T>::copyNodes(ListNodePosi(T) p, int n)
{
	init();//����ͷ��β�ڱ�������ʼ��
	while (n--)
	{
		insertAsLast(p->data; p = p->succ;)//������p��n��һ����Ϊĩ�ڵ���룻
	}
}
*/

# include <iostream>
# include <malloc.h>
# include <ostream>

using namespace std;

typedef int DataType;
//������������ݽṹ
typedef struct node{
	DataType data;
	struct node *next;
}LNode,* LinkList;


//β�巨��������
LinkList Tail_Creat_LinkList()
{
	LinkList H;
	H = (LinkList)malloc(sizeof(LNode));
	if (!H)
	{
		cout << "����ռ�ʧ��!";
		return 0;
	}
	H->next = NULL;
	cout << "���뵥����Ԫ�أ������������";
	LinkList  p, r;
	p = r = (LinkList)malloc(sizeof(LNode));//����malloc������ϵͳ�������һ���ڵ�
	cin >> p->data;//����ڵ��ֵ
	p->next = nullptr;//���½ڵ�����Ϊ��ֵ

	while (p->data >= 0)//����ڵ��ֵ����0
	{
		if (!H->next)
		{
			H->next = p;//�ձ������ͷ
		}
		else
		{
			r->next = p;//�ǿգ�����β��
		}
		r = p;

		p = (LinkList)malloc(sizeof(LNode));//��һ���½ڵ�
		cin >> p->data;
		p->next = NULL;
	}
	return H;//��������ͷָ��
}
//��������
LinkList CCopy_LinkList(LinkList H)
{
	LinkList G;
	G = (LinkList)malloc(sizeof(LNode));
	if (!G)
	{
		cout << "����ռ�ʧ�ܣ�";
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
	LinkList Tail_Create_Linklist();//��������
	LinkList CCopy_LinkList(LinkList H);
	void Show(LinkList H);

	LinkList H = Tail_Create_Linklist();//��������
	cout << " ���˳����Ϊ�� ";
	Show(H);

	LinkList G = CCopy_LinkList(H);//��������
	cout << "\n\n������Ƶ�˳���Ϊ��";
	Show(G);

	return 0;
}

template <typename T> T List<T>::remove(LietNodePosi(T) p)
{
	T e = p->data;//���ݴ�ɾ���ڵ����ֵ
	p->pred->succ = p->succ;//��̡�ǰ��
	p->succ->pred = p->pred;//�ͷŽڵ㣬���¹�ģ
	delete p;
	_size--;
	return e;//���ر�����ֵ
}

//===========================================
//��������
//=============================================
template <typename T > List <T>::~List()//�б�������
{
	clear();
	delete header;//����б��ͷ�ͷ��β�ڱ��ڵ㣻
	delete trailer;
}
template <typename T> int List<T>::clear()//����б�
{
	int oldSize = _size;
	while (0 < _size)//����ɾ���׽ڵ㣬ֱ���б���
		remove(header->succ);
	return oldSize;
}

//======================================
//Ψһ��
//======================================
template <typename T> int List<T>::deduplicate()//�޳��б���ظ��ڵ�
{
	if (_size < 2)return 2;//�б���Ȼ���ظ�
	int oldSize = _size;//��¼ԭʼ��ģ
	ListNodePosi(T) p = header; Rank r = 0;//p���׽ڵ㿪ʼ
	while (tralier != (p = p->succ))//����ֱ�ӵ�ĩ�ڵ�
	{
		ListNodePosi(T) q = find(p->data, r, p);
		q ? remove(q) : r++;//�����ڣ�ֱ��ɾ���������ȼ�һ

	}
	return oldSize - _size;//�б��ģ�仯������ɾ��������
}

template <typename T > void List<T> ::traverse(void(*vist) (T&))//����ָ�뺯�����б���
{
	for (ListNodePosi(T) p = header->succ; p != tralier; p = p->succ)
		vist(p->data);
}

template <typename T> template <typename  VST>//Ԫ�����ͣ�������
void List<T>::traverse(VST& visit)//�����������ƽ��б���
{
	for (ListNodePosi(T) p = header->succ; p != tralier; p = p->succ)
		visit(p->data);
}

//==========================================
//�����б�Ψһ��
//=========================================
template <typename T >int List<T>::uniquify()//�����޳��ظ�Ԫ�أ�Ч�ʸ���
{
	if (_size < 2)return 0;//ƽ���б���Ȼ���ظ�
	int oldSize = _size;//��¼ԭʼ��ģ
	ListNodePosi(T) p = first(); ListNodePosi(T) q;//pΪ���׶���㣬qΪ����
	while (tralier != (q = p->succ))//����������ڵĽڵ�
		if (p->data != q->data)//������룬��ת����һ������
			p = q;
		else
			remove(q);//�������ͬ����ɾ������
	return oldSize - _size;//�б��ģ������������ɾ��Ԫ�ص�����
}