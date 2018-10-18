//=================
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
//=================
template <typename T>
ListNodePosi(T)ListNode<T>::insert
