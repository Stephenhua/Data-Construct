#include <string>
# include <iostream>
using namespace std;
struct Dis{//��¼��㵽ÿһ����������·����Ϣ
	string path;
	int value;
	bool visit;
	Dis()
	{
		visit = false;
		value = 0;
		path = "";
	}
};

class Graph_DG{
private:
	int vexnum;//ͼ�Ķ������
	int edge;//ͼ�ı���
	int **arc;//�ڽӾ���Ϊ��ά���飬��СΪ������*���������洢������Ϊ�ߵ�Ȩֵ�����Ҿ���Խ���Ԫ�ؾ�Ϊ0��
	Dis *dis;//��¼�����������·������Ϣ
public:
	Graph_DG(int vexnum, int edge);//���캯��
	~Graph_DG();//��������
	bool check_edge_value(int start, int end, int weight);//��������ı���Ϣ�Ƿ�Ϸ��������1��ʼ���
	void creatGraph();//��������ͼ
	void print();//��ӡ�ڽӾ���
	void Dijkstra(int begin);//������·��
	void print_path(int);//��ӡ���·��
};