
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