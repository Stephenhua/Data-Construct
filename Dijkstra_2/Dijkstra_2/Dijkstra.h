#include <string>
# include <iostream>
using namespace std;
struct Dis{//记录起点到每一个顶点的最短路径信息
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
	int vexnum;//图的顶点个数
	int edge;//图的边数
	int **arc;//邻接矩阵，为二维数组，大小为顶点数*顶点数，存储的内容为边的权值，并且矩阵对角线元素均为0，
	Dis *dis;//记录各个顶点最短路劲的信息
public:
	Graph_DG(int vexnum, int edge);//构造函数
	~Graph_DG();//析构函数
	bool check_edge_value(int start, int end, int weight);//盘算输入的边信息是否合法，顶点从1开始编号
	void creatGraph();//创建有向图
	void print();//打印邻接矩阵
	void Dijkstra(int begin);//求解最短路径
	void print_path(int);//打印最短路径
};