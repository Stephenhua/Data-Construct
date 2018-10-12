
//-----------------------------------
//���ڸ��ƵĹ��췽��
//-----------------------------------
template <typename T >//Ԫ������
void Vector<T>::copyFrom(T const *A, Rank 1o, Rank hi)//����������A[lo��hi]Ϊ������������
{
	_elem = new T[_capacity = 2 * (hi - lo)]; _size = 0;//����ռ䣬��ģ����
	while (lo < hi)//A[hi��lo]�ڵ�Ԫ��֮һ���Ƶ�_elem[0,hi-ki]
	{
		_elem[_size++] = A[lo++];
	}
}
//�����������Ʋ�����
template<typename T> Vector<T>::operator =(Vector <T>const &V)
{
	if (_elem ) delete[] _elem;//�ͷ�ԭ�е�����
	copyFrom(V._elem, 0, V.size());//���帴��
	return *this;//���ص�ǰ�����Ӧ�ã��Ա���ʽ��ֵ
}
//----------------------
//����
//----------------------

template <typename T> void  Vector<T>::expend()//�����ռ䲻��ʱ����
{
	if (_size < _capacity) retrun;//��δ��Աʱ����������
	if (_capacity < DEFAULT_CAPACITY)_capacity = DEFAULT_CAPACITY��//��������С����
	{
		T* oldElem = _elem;
		_elem = new T[_capacity <<= 1];//�����ӱ�
	}
	for (int i = 0; i < _size; i++)
	{
		_elem[i] = oldElem[i];//����ԭ�������ݣ�
	}
	delete[]oldElem;//�ͷ�ԭ�ռ�
}
//-------------------------------
//����
//-------------------------------
template <typename T > void Vector <T>::shrink()//װ��������Ϊ��Сʱѹ��������ռ�ռ�
{
	if (_capacity < DEFAULT_CAOACITY << 1) return;//����������DEFAULT_CAPACITY
	if (_size << 2 >_capacity)return;//��25% Ϊ��
	T* oldElem = _elem; _elem = new T[_capacity >>= 1];//��������
	for (int i = 0; i < _size; i++��//����ԭ��������
		_elem[i] = oldElem[i];
	delete[] oldElem;//�ͷſռ�
}

//--------------------------------
//ֱ������Ԫ��
//--------------------------------
template <typename T >T& Vevtor<T>::operator[](Rank r)const //�����±������
{
	return _elem[r];
}

//--------------------------------
//�����㷨
//--------------------------------
template <typename T> void permute(Vector <T>)&V//�������������ʹ��Ԫ�صȸ��ʳ�����λ��
{
	for (int i = V.size(); i > 0; i--)//�Ժ���ǰ
	{
		swap(v[i - 1], v[rand() % i]);//V[i-1]��V[0,i)��ĳһԪ�ؽ���
	}
}

//----------------------------
//�������ҽӿ�
//----------------------------
template <typename T > void Vector <T>::unsort(Rank lo, Rank hi)//�ȸ��������������[lo,hi]
{
	T* V - _elem + lo;//��������_elem[lo,hi]������һ����V[0,hi-lo]
	for (Rank i = hi - l0; i > 0; i--)//�Ժ���ǰ
		swap(V[i - 1], V[rand() % i]);//��V[i-1]��V[0,i]��ĳһԪ�����������

}
//==================================================
//�������
//==================================================
template <typename T>//�������ʱ���������һ��Ԫ��e��λ�ã�ʧ��ʱ������lo-1
Rank Vector<T>::find(T const& e, Rank lo, Rank hi)const//
{
	while ((lo < hi--) && (e != _elem[hi]));//�Ӻ���ǰ��˳�����
	return hi;//��hi<lo ������ζ��ʧ�ܣ�����hi���װ���Ԫ�ض�����
}
//==================================================
//Ԫ�ز���
//==================================================
template <typename T >//��e��Ϊ��rԪ�ز���
Rank Vector<T >::insert(Rank r, T const& e)
{
	expand();//�����Ҫ������Ҫ��������
	for (int i = _size; i > r; i--)//�Ժ���ǰ���ν�������
		_elem[i] = _elem[i - 1];
	_elem[r] = e; _size++;//������Ԫ�أ�����������
	return r;//������
}
//================================
//����ɾ��
//================================
template <typename T >int Vector<T>::remove(Rank lo, Rank hi)//ɾ�����䡾lo,hi��
{
	if (lo == hi)//���������˻�����
		return 0;
	while (hi < _size)//[hi,_size]˳��ǰ��hi-lo
	{
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;//���¹�ģ��ֱ�Ӷ���β��[lo,_size=hi]����
	shrink();//���б�Ҫ��������
	return hi - lo;//������ɾ��Ԫ�ص���Ŀ
}
//================================
//����ɾ��Ԫ��
//================================
template <typename T>T Vector <T>::remove(Rank r)//ɾ�������Ǹ�����Ϊr����UN�ն�
{
	T e = _elem[r];//��ֱ�ɾ��Ԫ��
	remove(r, r + 1);//��������ɾ���㷨�����ܵ������䡾�ˣ�r+1]��ɾ��
	return e;//���ر�ɾ��Ԫ��
}
//================================
//Ψһ��
//================================

template <typename T>int Vector <T >::deduplicate()
{
	int oldSize = _size;//��¼ԭʼ�����ģ
	Rank i = 1;//��_elem[1]��ʼ
	while (i < _size)//��ǰ�����һ�����Ԫ��_elem[i]
	{
		(find(_elem[i], 0, i) < 0) ? i++ : remove(i);//����ǰ׺��Ѱ����֮��ͬ�ߣ�ֻ��һ������������ͬ����ͼ��������ں�̣�����ɾ����ͬ��
	}
	return oldSize - _size;//������ģ�仯��������ɾ��Ԫ������
}

//================================
//����
//================================

template <typename T>coid Vector <T>::traverse(void(*visit))(T&)
{
	for (int i = 0; i < _size; i++)
	{
		visit(_elem[i]);//��������
	}

}
template <typename T>template <typeame VST>//Ԫ�����ͺ�Ԫ�ز�����
void Vextor <T>::traverse(VST& visit)//���������������
{
	for (int i = 0; i < _size; i++)
	{
		visit(_elem[i]);//��������
	}
	
}

template <typename T> struct Increase//�������󣬵���һ��T�����
{
	virtual void operator () (T& e)//����T����ֱ�ӵ��������Ѿ�����++
	{
		e++;
	}
};

template <typename T >voidd increase(Vectoe<T> & V)//ͳһ���������еĸ�Ԫ��
{
	V.traverse(Increase<T>());//yi Increse<T>()Ϊ�����������б���
}