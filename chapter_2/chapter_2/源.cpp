
//-----------------------------------
//基于复制的构造方法
//-----------------------------------
template <typename T >//元素类型
void Vector<T>::copyFrom(T const *A, Rank 1o, Rank hi)//以数组区间A[lo，hi]为蓝本复制向量
{
	_elem = new T[_capacity = 2 * (hi - lo)]; _size = 0;//分配空间，规模清零
	while (lo < hi)//A[hi，lo]内的元素之一复制到_elem[0,hi-ki]
	{
		_elem[_size++] = A[lo++];
	}
}
//重载向量复制操作符
template<typename T> Vector<T>::operator =(Vector <T>const &V)
{
	if (_elem ) delete[] _elem;//释放原有的内容
	copyFrom(V._elem, 0, V.size());//整体复制
	return *this;//返回当前对象的应用，以便链式赋值
}
//----------------------
//扩容
//----------------------

template <typename T> void  Vector<T>::expend()//向量空间不足时扩容
{
	if (_size < _capacity) retrun;//尚未满员时，不必扩容
	if (_capacity < DEFAULT_CAPACITY)_capacity = DEFAULT_CAPACITY；//不低于最小容量
	{
		T* oldElem = _elem;
		_elem = new T[_capacity <<= 1];//容量加倍
	}
	for (int i = 0; i < _size; i++)
	{
		_elem[i] = oldElem[i];//复制原向量内容，
	}
	delete[]oldElem;//释放原空间
}
//-------------------------------
//缩容
//-------------------------------
template <typename T > void Vector <T>::shrink()//装填因子因为过小时压缩向量所占空间
{
	if (_capacity < DEFAULT_CAOACITY << 1) return;//不致收缩到DEFAULT_CAPACITY
	if (_size << 2 >_capacity)return;//以25% 为界
	T* oldElem = _elem; _elem = new T[_capacity >>= 1];//容量减半
	for (int i = 0; i < _size; i++）//复制原向量内容
		_elem[i] = oldElem[i];
	delete[] oldElem;//释放空间
}

//--------------------------------
//直接引用元素
//--------------------------------
template <typename T >T& Vevtor<T>::operator[](Rank r)const //重载下标操作符
{
	return _elem[r];
}

//--------------------------------
//置乱算法
//--------------------------------
template <typename T> void permute(Vector <T>)&V//随机置乱向量，使各元素等概率出现于位置
{
	for (int i = V.size(); i > 0; i--)//自后向前
	{
		swap(v[i - 1], v[rand() % i]);//V[i-1]与V[0,i)中某一元素交换
	}
}