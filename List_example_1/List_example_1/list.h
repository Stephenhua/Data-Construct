#ifndef LIST_H_
#define LIST_H_
template < class CElemType>
class CList
{
public://��������
	enum
	{
		INIT_SIZE=20,//���Ա��ʼ�ռ䳤�ȣ�Ԫ�ظ�����
		INCERMENT_SIZE =10//�����ռ䳤�ȣ�Ԫ�ظ�����
	};
	//��Ա����
private:
	CElemType *m_pElem;//���Ա�˳��ṹ�Ļ�ַ
	int m_nSize;//���Ա�ǰ����
	int m_nLength;//Ϊ���Ա����Ĵ洢�ռ䳤��
	//��Ա����
public:
	CList();//���캯��
	~CList();//��������
	int GetSize();//��ȡ���Ա�ǰ����
	int GetLength();//��ȡ���Ա����Ĵ洢����
	CElemType GetAt(int nIndex);//����Ԫ��
	void SetAt(int nIndex, CElemType e);//�޸�Ԫ��
	int InsertAt(int nIndex, CElemType e);//���ƶ�λ�ò���Ԫ�أ�����������
	int AddTrail(CElemType e);//��Ԫ��e���뵽���Ա��β��
	int AddHead(CElemType e);//��Ԫ��e���뵽���Ա��ͷ��
	void RemoveAt(int nIndex, int nCounter = 1);//��ָ��λ��ɾ����Counter
	void ShowValues();//��ʾ�б��е�����Ԫ��
};

#endif