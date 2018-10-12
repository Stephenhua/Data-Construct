
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

//----------------------------
//区间置乱接口
//----------------------------
template <typename T > void Vector <T>::unsort(Rank lo, Rank hi)//等概论随机置乱区间[lo,hi]
{
	T* V - _elem + lo;//将自向量_elem[lo,hi]视作另一向量V[0,hi-lo]
	for (Rank i = hi - l0; i > 0; i--)//自后向前
		swap(V[i - 1], V[rand() % i]);//将V[i-1]与V[0,i]中某一元素是随机交换

}
//==================================================
//无序查找
//==================================================
template <typename T>//无序查找时，返回最后一个元素e的位置，失败时，返回lo-1
Rank Vector<T>::find(T const& e, Rank lo, Rank hi)const//
{
	while ((lo < hi--) && (e != _elem[hi]));//从后向前，顺序查找
	return hi;//若hi<lo ，则意味着失败；否则hi即米昂中元素而的秩
}
//==================================================
//元素插入
//==================================================
template <typename T >//将e作为秩r元素插入
Rank Vector<T >::insert(Rank r, T const& e)
{
	expand();//如果需要，首先要进行扩容
	for (int i = _size; i > r; i--)//自后向前依次进行扩容
		_elem[i] = _elem[i - 1];
	_elem[r] = e; _size++;//置入新元素，并更新容量
	return r;//返回秩
}
//================================
//区间删除
//================================
template <typename T >int Vector<T>::remove(Rank lo, Rank hi)//删除区间【lo,hi】
{
	if (lo == hi)//单独考虑退化问题
		return 0;
	while (hi < _size)//[hi,_size]顺次前移hi-lo
	{
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;//更新规模，直接丢弃尾部[lo,_size=hi]区间
	shrink();//若有必要，则缩容
	return hi - lo;//返货被删除元素的数目
}
//================================
//单独删除元素
//================================
template <typename T>T Vector <T>::remove(Rank r)//删除想来那个中秩为r的亚UN苏俄，
{
	T e = _elem[r];//别分被删除元素
	remove(r, r + 1);//调用区间删除算法，都能掉对区间【人，r+1]的删除
	return e;//返回被删除元素
}
//================================
//唯一化
//================================

template <typename T>int Vector <T >::deduplicate()
{
	int oldSize = _size;//记录原始数组规模
	Rank i = 1;//从_elem[1]开始
	while (i < _size)//自前向后逐一考察各元素_elem[i]
	{
		(find(_elem[i], 0, i) < 0) ? i++ : remove(i);//在其前缀中寻找与之雷同者（只多一个），若无雷同者则就继续考察期后继，否则删除雷同者
	}
	return oldSize - _size;//向量规模变化量，即被删除元素总数
}

//================================
//遍历
//================================

template <typename T>coid Vector <T>::traverse(void(*visit))(T&)
{
	for (int i = 0; i < _size; i++)
	{
		visit(_elem[i]);//遍历向量
	}

}
template <typename T>template <typeame VST>//元素类型和元素操作器
void Vextor <T>::traverse(VST& visit)//借助函数对象机制
{
	for (int i = 0; i < _size; i++)
	{
		visit(_elem[i]);//遍历向量
	}
	
}

template <typename T> struct Increase//函数对象，递增一个T类对象
{
	virtual void operator () (T& e)//假设T可以直接递增或者已经重载++
	{
		e++;
	}
};

template <typename T >voidd increase(Vectoe<T> & V)//统一递增想想中的各元素
{
	V.traverse(Increase<T>());//yi Increse<T>()为基本操作进行遍历
}