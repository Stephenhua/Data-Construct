
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
//================================
//���������
//================================

template <typename T >int  Vector <T>::disordered() const//����������������������Ե�����
{
	int n = 0;//������
	for (int i = 1; i < _size; i++)//��һ���_size -1������Ԫ�أ�
	{
		if (_elem[i - 1] > _elem[i])//���������
			n++;
	}
	return n;
}
//================================
//Ψһ��
//================================
//��Ч�ʰ棬ʱ�临�Ӷȴ�ʵ�ʲ��õĵ��������в���

template <typename T> int Vector <T>::uniquify()
{
	int oldSize = _size; int i = 1;//��ǰ�ȶ�Ԫ�ص�ָ����ʼ����Ԫ��
	while (i < _size)//��ǰ�����һ�ȶԸ�Ԫ������Ԫ��
	{
		_elem[i - 1] = _elem[i] ? remove(i) : i++;//����ͬ����ɾ�����ߣ�����ת�ú�һԪ��

	}
	return oldSize - _size;//����ɾ����ͬ��Ԫ�ص�����
}

//��Ч�ĵ���
template <typename T> int Vector <T>::uniquify()//���������ظ�Ԫ���޳��㷨
{
	Rank i = 0, j = 0;//���Ի��조���ڡ�Ԫ�ص���
	while (++J < _size)//��һɨ�裬ֱ��ĩԪ��
	{
		if (_elem[i] != _elem[j])//������ͬ��
			_elem[++i] = _elem[j];

	}
	_size = ++i;
	shrink();//ֱ��ɾ��β���Ӷ���Ԫ��
	return j - i;//������ģ�仯��������ɾ��������
}

//================================
//����
//================================

template <typename T>//����������������[lo,hi)�ڣ�ȷ��������e������һ���ڵ����
Rank Vector <T>::search(T const & e, Rank lo, Rank hi)const
{
	return (rand() % 2) ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);//����50%�ĸ��������ʹ�ö��ֲ��һ���Fibonacci����

}

template <typename T > static Rank binSeatch(T* A, T const& e, Rank lo, Rnak hi)//���������в���
{
	while (lo < hi)//ÿһ�ε�����Ҫ�������αȽ��жϣ���������֧
	{
		Rank mi = (lo + hi) >> 1;//������Ϊ����
		if (e < A[mi]) hi = mi;//����ǰ��Ρ�lo,mi����������
		else if (A[mi] < e) lo = mi + 1;//������μ������в���
		else return mi;//��Mi������
	}
	return -1;//�������ʧ�ܣ��򵥵ķ���-1���ǲ���֮��ʧ�ܵ�λ��
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


# include "..\fibonnacci\Fib.h"//����Fib����
template <typename T> static Rank fibSearch(T *A, T const & e, Rank lo, Rank hi)
{
	Fib fib(hi - lo);//����һ��fib���С�
	while (lo < hi)//ÿһ������Ҫ�����αȽ��ж�
	{
		while (hi - lo < fib.get()) fib.prev();//ͬ��ǰ˳�����--�����������
		Rank m1 = lo + fib.get() - 1;//ȷ����Fib(k)-1�����
		if (e < A[mi]) hi = mi;//����ǰ��μ������в���
		else if (A[mi] < e) lo = mi + 1;//������μ������в���
		else  return mi;
	}
	return -1;

}

class Fib//fibonacci������
{
private:
	int f, g;//f=fib(k-1),g=gib(k),��Ϊint�ͣ�������ֵ�����
public:
	Fib(int n)//��ʼ����С��n����Сfibonacci��
	{
		f = 1;
		g = 0;
		while (g < n)
		{
			next();
		}
	}
	int get(){ return g; }//��ȡ��ǰFiberonnacci��
	int next(){ g += f; f = g - f; return g; }//ת����һfibbonacci��
	int prev(){ f = g - f; g -= f; return g; }//ת����һfibbonacci��
};
//================================
//���ַ������㷨
//================================

template  <typename T > static Rank binSearch(T *A, T const & e, Rank lo, Rank hi)
{
	while (1 < hi - lo)
	{
		Rank mi = (lo + hi) >> 1;//���е�Ϊ���
		(e < A[mi]) ? hi = mi : lo = mi;//�����ȽϺ�ȷ������[lo,mi]����[mi,hi]
	}
	return (e == A[lo]) ? lo : -1;
}

template  <typename T > static Rank binSearch(T *A, T const & e, Rank lo, Rank hi)
{
	while (lo < hi)//ÿһ������������һ�αȽ��жϣ���������֧
	{
		Rank mi = (lo + hi) >> 1;//������Ϊ�е�
		(e < A[mi]) ? hi = mi : lo = mi + 1;//�����Ƚ�֮��ȷ�����롾lo,mi������(mi,hi]
	}
	return --lo;//ѭ������ʱ��lo����e��Ԫ�ص���С�ȣ���lo-1��������e��Ԫ�ص�����ȣ�
	//�ж������Ԫ��ʱ�����ܱ�֤����ָ������ߣ�����ʧ��ʱ���ܹ�����ʧ�ܵ�λ��
}

//================================
//�����������ӿ�
//================================
template <typename T> void  Vector <T>::sort(Rank lo, Rank hi)//�������䡾lo,hi���������ѡȡ�����㷨��
{
	stitch(rand() % 5)
	{
		case 1:bubbleSort(lo, si); break;//��������
		case 2:selectSort(lo, hi); break;//ѡ������
		case 3:mergeSort(lo, hi); break;//�鲢����
		case 4:heapSort(lo, hi); break;//������
		case 5:quickSort(lo, hi); break;//��������
	}
}

//���������㷨
void bubllesortA(int A[], int n)
{
	bool sorted = false;//��������������ȼٶ���δ����
	while (!sorted)//����δȷ����ȫ������֮ǰ�����˽���ɨ�轻��
	{
		sorted = true;//�ٶ��Ѿ�����
		for (int i = 1; i < n; i++)//����������Լ�鵱ǰ��ΧA[0,n]�ڵĸ�����Ԫ��
		{
			if (A[i - 1] > A[i])//���A[i-1]��A[i]��������н�������Ϊ���������ܱ�֤����Ҫ��������־��sorted
			{
				swap(A[i - 1] > A[i]);
				sorted = false;

			}
		}
		n--;//ĪԪ�ر�Ȼ��λ�����������������е���Ч����
	}
}//����bool���ͣ����Լ�ʱ��ǰ�˳������Ա�����n-1�˽���