
# include <iostream>
# include <queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	//TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Soultion
{
public:
	bool isSameTree(TreeNode *p, TreeNode *q)
	{
		if ( !p  && !q)return true;
		if ((p&&!q) || (!p&&q) || (p->val != q->val)) return false;
		return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
	}
};

void CreateBiTree(TreeNode* & T)
{
	char c;
	cin >> c;
	if ('#' == c)
	{
		T = NULL;
	}
	else
	{
		T = new TreeNode;
		T->val = c;
		CreateBiTree(T->left);
		CreateBiTree(T->right);
	}
}
void BiTreeprint(TreeNode *T)
{
	if (T)
	{
		cout << T->val << " ";
		BiTreeprint(T->left);
		BiTreeprint(T->left);
	}
}
int main()
{
	TreeNode *a, *b;
	Soultion Sol;
	cout << "Please input aTree: " << endl;

	CreateBiTree(a);
	BiTreeprint(a);
	cout << "please inpu bTree: " << endl;
	CreateBiTree(b);
	BiTreeprint(b);
	cout << "Creat Tree successful! " << endl;
	if (Sol.isSameTree(a, b) ==true)
		return true;
	else
		return false;
	system("pause");
	return EXIT_SUCCESS;

}
/*
//==========================================����ͷ��
#include <iostream>
using namespace std;

struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;//���Һ���
};
BiTNode*T;
void CreateBiTree(BiTNode* &T);
void Inorder(BiTNode* &T);
void PreOrderTraverse(BiTNode* &T);
void Posorder(BiTNode* &T);
   //===========================================������
int main(){
	cout << "����һ����������A->Z�ַ������������ݣ��á�#����ʾ����:" << endl;
	CreateBiTree(T);
	cout << "����ݹ������" << endl;
	PreOrderTraverse(T);
	cout << endl;
	cout << "����ݹ������" << endl;
	Inorder(T);
	cout << endl;
	cout << "����ݹ������" << endl;
	Posorder(T);
	cout << endl;
	system("pause");
	return 1;
}
//=============================================����ݹ鴴����������
void CreateBiTree(BiTNode* &T){
	//����������������н���ֵ��һ���ַ������ո��ַ����������
	//������������ʾ������T��
	char ch;
	if ((ch = getchar()) == '#')T = NULL;//����getchar����Ϊ��������׼�⺯��
	else{
		T = new BiTNode;//�����µ�����
		T->data = ch;//��getchar�������������
		CreateBiTree(T->lchild);//�ݹ鴴��������
		CreateBiTree(T->rchild);//�ݹ鴴��������
	}
}//CreateTree
//===============================================����ݹ����������
void PreOrderTraverse(BiTNode* &T){
	//����ݹ����������
	if (T){//����㲻Ϊ�յ�ʱ��ִ��
		cout << T->data;
		PreOrderTraverse(T->lchild);//
		PreOrderTraverse(T->rchild);
	}
	else cout << "";
}//PreOrderTraverse
//================================================�������������
void Inorder(BiTNode* &T){//����ݹ����������
	if (T){//bt=null�˲�
		Inorder(T->lchild);//�������������
		cout << T->data;//���ʲ���
		Inorder(T->rchild);//�������������
	}
	else cout << "";
}//Inorder
//=================================================����ݹ����������
void Posorder(BiTNode* &T){
	if (T){
		Posorder(T->lchild);//����ݹ����������
		Posorder(T->rchild);//����ݹ����������
		cout << T->data;//���ʸ����
	}
	else cout << "";
}
//=================================================
*/