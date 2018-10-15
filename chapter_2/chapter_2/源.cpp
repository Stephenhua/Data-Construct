/*
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
//================================
//有序性甄别
//================================

template <typename T >int  Vector <T>::disordered() const//返回向量中逆序相邻严肃对的总数
{
	int n = 0;//计数器
	for (int i = 1; i < _size; i++)//逐一检查_size -1对相邻元素；
	{
		if (_elem[i - 1] > _elem[i])//逆序则计数
			n++;
	}
	return n;
}
//================================
//唯一化
//================================
//低效率版，时间复杂度大，实际采用的迭代法进行操作

template <typename T> int Vector <T>::uniquify()
{
	int oldSize = _size; int i = 1;//当前比对元素的指，起始于首元素
	while (i < _size)//从前向后逐一比对各元素相邻元素
	{
		_elem[i - 1] = _elem[i] ? remove(i) : i++;//若雷同，则删除后者，否则，转置后一元素

	}
	return oldSize - _size;//返回删除相同的元素的总数
}

//高效的迭代
template <typename T> int Vector <T>::uniquify()//有序向量重复元素剔除算法
{
	Rank i = 0, j = 0;//各对互异“相邻”元素的秩
	while (++J < _size)//逐一扫描，直至末元素
	{
		if (_elem[i] != _elem[j])//跳过雷同者
			_elem[++i] = _elem[j];

	}
	_size = ++i;
	shrink();//直接删除尾部从多余元素
	return j - i;//向量规模变化量，即被删除的总数
}

//================================
//查找
//================================

template <typename T>//在有序向量的区间[lo,hi)内，确定不大于e的最后就一个节点的秩
Rank Vector <T>::search(T const & e, Rank lo, Rank hi)const
{
	return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);//按照50%的概率随机数使用二分查找或者Fibonacci查找

}

template <typename T > static Rank binSeatch(T* A, T const& e, Rank lo, Rnak hi)//二叉树进行查找
{
	while (lo < hi)//每一次迭代需要进行两次比教判断，有三个分支
	{
		Rank mi = (lo + hi) >> 1;//以中心为轴线
		if (e < A[mi]) hi = mi;//深入前半段【lo,mi】继续查找
		else if (A[mi] < e) lo = mi + 1;//深入后半段继续进行查找
		else return mi;//在Mi处命中
	}
	return -1;//如果查找失败，简单的返回-1但是不能之处失败的位置
}

# include <iostream>
using namespace std;

int binSearch(int *A, int e, int lo, int hi)
{
	int mi;
	while (lo < hi)
	{
		mi = (lo + hi) / 2;
		if (e < A[mi])
			hi = mi;
		else if (e>A[mi])
			lo = mi + 1;
		else
			return mi;
	}
	return -1;
}

int main()
{
	int a[100];
	for (int i = 0; i < 100; i++)
	{
		a[i] = i+1;
	}
	cout << binSearch(a, 101, 0, 100) << endl;
	cout << binSearch(a, 48, 0, 100) << endl;
	system("pause");
	return 0;

}


# include "..\fibonnacci\Fib.h"//引入Fib数列
template <typename T> static Rank fibSearch(T *A, T const & e, Rank lo, Rank hi)
{
	Fib fib(hi - lo);//创建一个fib数列。
	while (lo < hi)//每一步迭代要做两次比较判断
	{
		while (hi - lo < fib.get()) fib.prev();//同向前顺序查找--至多迭代几次
		Rank m1 = lo + fib.get() - 1;//确定如Fib(k)-1的轴点
		if (e < A[mi]) hi = mi;//深入前半段继续进行查找
		else if (A[mi] < e) lo = mi + 1;//深入后半段继续进行查找
		else  return mi;
	}
	return -1;

}

class Fib//fibonacci数列类
{
private:
	int f, g;//f=fib(k-1),g=gib(k),均为int型，容易数值会溢出
public:
	Fib(int n)//初始化不小于n的最小fibonacci项
	{
		f = 1;
		g = 0;
		while (g < n)
		{
			next();
		}
	}
	int get(){ return g; }//获取当前Fiberonnacci项
	int next(){ g += f; f = g - f; return g; }//转至下一fibbonacci项
	int prev(){ f = g - f; g -= f; return g; }//转至上一fibbonacci项
};
//================================
//二分法查找算法
//================================

template  <typename T > static Rank binSearch(T *A, T const & e, Rank lo, Rank hi)
{
	while (1 < hi - lo)
	{
		Rank mi = (lo + hi) >> 1;//以中点为轴点
		(e < A[mi]) ? hi = mi : lo = mi;//经过比较后，确定深入[lo,mi]或者[mi,hi]
	}
	return (e == A[lo]) ? lo : -1;
}

template  <typename T > static Rank binSearch(T *A, T const & e, Rank lo, Rank hi)
{
	while (lo < hi)//每一步迭代仅需做一次比较判断，有两个分支
	{
		Rank mi = (lo + hi) >> 1;//以中心为中点
		(e < A[mi]) ? hi = mi : lo = mi + 1;//经过比较之后确定深入【lo,mi）或者(mi,hi]
	}
	return --lo;//循环结束时，lo大于e的元素的最小秩，故lo-1即不大于e的元素的最大秩，
	//有多个命中元素时，总能保证返回指的最大者，查找失败时，能够返回失败的位置
}

//================================
//向量排序器接口
//================================
template <typename T> void  Vector <T>::sort(Rank lo, Rank hi)//向量区间【lo,hi】排序，随机选取排序算法，
{
	stitch(rand() % 5)
	{
		case 1:bubbleSort(lo, si); break;//起泡排序
		case 2:selectSort(lo, hi); break;//选择排序
		case 3:mergeSort(lo, hi); break;//归并排序
		case 4:heapSort(lo, hi); break;//堆排序
		case 5:quickSort(lo, hi); break;//快速排序
	}
}

//起泡排序算法
void bubllesortA(int A[], int n)
{
	bool sorted = false;//整体进行排序，首先假定尚未排序
	while (!sorted)//早尚未确认已全局排序之前，逐趟进行扫描交换
	{
		sorted = true;//假定已经排序
		for (int i = 1; i < n; i++)//自左向右逐对检查当前范围A[0,n]内的个相邻元素
		{
			if (A[i - 1] > A[i])//如果A[i-1]和A[i]逆序，则进行交换；因为整体排序不能保证，需要清除排序标志符sorted
			{
				swap(A[i - 1] > A[i]);
				sorted = false;

			}
		}
		n--;//莫元素必然就位，可以缩短排序序列的有效长度
	}
}//借助bool类型，可以及时提前退出，可以避免做n-1趟交换
//================================
//基于遍历实现向量的decrease（）功能
//================================
template <typename T > struct Decrease//函数对象：递减一个T类对象
{
	virtual void operator ()(T &e)//假设T可以直接递减或者已重载--
	{
		e--;
	}
};

template <typename T> void decrease(Vector <T>& V)//统一递减向量向量的元素
{
	V.traverse(Decrease<T>());//与Decrease《t》()为基本操作进行遍历
}

//================================
//基于遍历实现向量的double（）功能
//================================
template <typename T>struct Double//函数对象：倍增一个T类对象
{
	virtual void operator ()(T &e)//假设T可以直接进行倍增
	{
		e *= 2;
	}
};

template <typename T> void double(Vector<T> &V)//统一加倍向量中的各元素
{
	V.traverse(Double <T>());//以Double《T》为基本操作进行遍历
}
//================================
//二维向量的查找
//================================
saddleback(int A[n][], x)
{
	int i = 0;//不变性：有效查找范围始终为左上角的子矩阵
	int j = binSearch(A[0][], x);//借助二分查找，在O(logn)时间内，从A的第0行找到不大于x的最大者
	while (i < n&&-1 < j)//反复根据A[i][j]与x的比较结果，不断收缩查找范围A[i,n)【0，就）
	{
		if (A[i][j] < x)//矩形区域的底边向上移动
			i++;
		else if (x < A[i][j])//矩形区域的右边左移
			j--;
		else//
		{
			report(A[i][j])//报告房钱命中的元素，矩形区域的底边上移，右边左移
			i++;
			j--;
		}
	}
}

package niuke;

public class Finder
{
	public int[] findElement(int[][] mat, int n, int m, int x)
	{
		if (mat == null || n == 0 || m == 0)
			return null;
		int[] ret = new int[2];
		int row = 0, column = m - 1;
		while (row < n&&column >= 0)
		{
			if (mat[row][column] == x)
			{
				ret[0] = row;
				ret[1] = column;
				return ret;
			}
			else if (mat[row][column]>x)
			{
				--column;
			}
			else
				++row;
		}
		return null;
	}
	public static void main(String[] args)
	{
		int[][] mat = { { 1, 2, 8, 9 }, { 2, 4, 9, 12 }, { 4, 5, 6, 10 }, { 6, 8, 11, 15 } };
		Finder fi = new Finder();
		int[] ret = fi.findElement(mat, 4, 4, 7);
		system.out.println(Arrays.toString(ret));
	 
	 
	}
}

# include <iostream>
using namespace std;
int arr[7] = { 2, 3, 1, 0, 2, 5, 3 };
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
bool duplicate(int array[], int length, int *duplication)
{
	if (array == NULL || length<0)
	{
		return false;
	}
	for (int i = 0; i < length; i++)
	{
		if (array[i]<0 || array[i]>length - 1)
		{
			return false;
		}
	}
	for (int i = 0; i < length; ++i)
	{
		while (array[i]!=i)
		{
			if (array[i] == array[array[i]])
			{
				*duplication = array[i];
				return true;
			}
			swap(array[i], array[array[i]]);
		}
	}
	return false;
}
int main()
{
	int result;
	bool res;
	res = duplicate(arr, 7, &result);
	if (res)
		cout << "重复的数是： " << result << endl;
	else
		cout << "数据里面没有重复的数" << endl;
	system("pause");
	return 0;
}

//================================
//归并排序
//================================
template <typename T >//向量归并排序
void Vector <T>::mergeSort::mergeSort(Rank lo, Rank hi)
{
	if (hi - lo < 2)return;//单元素期间自然有序
	int mi = (lo + hi) / 2;//以中点为界
	mergeSort(lo, mi);//第一个序列进行排序
	mergeSort(mi, hi);//第二个序列进行排序
	merge(lo, mi, hi);//归并
}

template <typename T >//有序向量归并
void Vector<T>::merge(Rank lo, Rank mi, Rank hi)//各自有序子向量[lo,mi）和【密，hi）
{
	T *A = _elem + lo;//合并之后的向量A
	int lo = mi - lo;//前子向量B[0，lb]=_elem[lo,mi)
	T* B = new T[lb];//
	for (Rank i = 0; i < lb; B[i] = A[i++])//复制前子向量
		int lc = hi - mi;
	T*C = _elem + mi;//后子向量C[0,lc)=_elem[mi,hi)
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc))//B[j]he C[j]中的小着续至A末尾
	{
		if ((j < lb) && (!(k < lc) || (B[j] <= C[k])))//
			A[i++] = B[j++];
		if ((k < lc) && (!(j < lb) || (c[k] < B[j])))//
			A[i++] = C[j++];
	}
	delete[]B;//释放空间B
}
*/

# include <iostream>
# include <vector>
# include<algorithm>

using namespace std;

void merge(vector <int >& nums, int l1, int r1,int l2, int r2)
{
	int i = l1;//左半部分起始位置
	int j = l2;//右半部分起始位置
	int n = (r1 - l1 + 1) + (r2 - l2 + 1);//要合并元素的数量
	vector<int> temp(n);//辅助数组
	int k = 0;//辅助元素的起始位置
	while (i <= r1&&j <= r2)//挑选两部分最小的一个复制到辅助数组中
	{
		if (nums[i] < nums[j])
		{
			temp[k++] = nums[i++];
		}
		else
		{
			temp[k++] = nums[j++];
		}
	}
	//如果还有剩余，则直接放入到辅助数组中
	while (i <= r1)
	{
		temp[k++] = nums[i++];
	}
	while (j <= r2)
	{
		temp[k++] = nums[j++];
	}
	//更新原始数组元素
	for (int i = 0; i < n; i++)
	{
		nums[l1 + i] = temp[i];
	}
}
//二路合并的递归实现
void MergerSort(vector<int>& nums, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) >> 1;//分割序列
		MergerSort(nums, start, mid);//对元素左半部分进行归并排序
		MergerSort(nums, mid + 1, end);//对元素有右半部分进行排序
		merge(nums, start, mid, mid + 1, end);//合并已有元素的两个序列

	}
}
//递归排序的迭代实现
void MergerSort1(vector<int>& nums, int start, int end)
{
	int n = nums.size();
	if (start < end)
	{
        //step 为组内的元素个数，
		for (int step = 2; step / 2 < n; step *= 2)
		{//每step 个元素一组，组内前step/2和后step/2个元素进行合并
			for (int i = 0; i < n; i += step)
			{
				int mid = i + step / 2 - 1;
				if (mid + 1 < n)
				{
					merge(nums, i,mid, mid + 1, min(i + step - 1, n - 1));
				}
			}
		}
	}
}\


int main()
{
	vector<int >nums{ 1, 4, 3, 6, 2, 8, 5 };
	MergerSort(nums, 0, 6);
	//MergeSort1(nums, 0,6);
	for (auto x : nums)
		cout << x << " ";
	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}