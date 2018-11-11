# ifndef ClassTemplate_HH
# define ClassTemplate_HH

template<typename T1,typename T2>

class myClass
{
private:
	T1 A;
	T2 B;
public:
	myClass(T1 a, T2 b);
	void show();

};

template <typename T1,typename T2>
myClass<T1, T2>::myClass(T1 a, T2 b) :A(a), B(b){};


template <typename T1,typename T2>
void myClass<T1, T2>::show()
{
	cout << "A=" << A << ",B=" << B << endl;
}

#endif