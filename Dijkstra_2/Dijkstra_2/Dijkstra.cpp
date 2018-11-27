# include"Dijkstra.h"
Graph_DG::Graph_DG(int vexnum, int edge)
{
	this->vexnum = vexnum;//初始化顶点数和边数
	this->edge = edge;//边数
	arc = new int*[this->vexnum];//内存分配在堆上，堆上的是非连续内存，可以分配较大的内存，int a[]表示分配在栈上，连续内存并且连续
	dis = new Dis[this->vexnum];
	for (int i = 0; i < this->vexnum; i++)
	{
		arc[i] = new int[this->vexnum];//由于矩阵表示通常使用两层表示，这表示一个行中存在多少个元素
		for (int k = 0; k < this->vexnum; k++)
		{
			arc[i][k] = INT_MAX;
		}
	}
}

Graph_DG::~Graph_DG()
{
	delete[] dis;
	for (int i = 0; i < this->vexnum; i++)
	{
		delete this->arc[i];
	}
	delete arc;
}


bool Graph_DG::check_edge_value(int start, int end, int weight)//判断每次输入的信息是否合法，顶点从1开始编号
{
	if (start < 1 || end<1 || start>vexnum ||end>vexnum|| weight < 0)
	{
		return false;
	}
	return true;
}

void Graph_DG::creatGraph(){
	cout << "请输入每条边的起点和终点（顶点编号从一开始）以及其权重：" << endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count != this->edge)//首选判断边的信息是否合法
	{
		cin >> start >> end >> weight;
		while (!this->check_edge_value(start, end, weight))
		{
			cout << "输入的边的信息不和法，请重新输入：" << endl;
			cin >> start >> end >> weight;
		}
		arc[start - 1][end - 1] = weight;//对邻接矩阵对应上的点进行赋值
		++count;
	}
}

void Graph_DG::print(){
	cout << "邻接矩阵为：" << endl;
	int count_row = 0;//打印行的标签
	int count_col = 0;//打印列的标签
	while (count_row != this->vexnum)
	{
		count_col = 0;
		while (count_col != this->vexnum)
		{
			if (arc[count_row][count_col] == INT_MAX)
			{
				cout << "∞" << " ";
			}
			else
			{
				cout << arc[count_row][count_col] << " ";
				
			}
			++count_col;
		}
		cout << endl;
		++count_row;
	}
}


void Graph_DG::Dijkstra(int begin)
{
	//初始化dis数组
	int i;
	for (i = 0; i < this->vexnum; ++i)
	{
		//设置当前路径
		dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	//设置起点到起点的路径为0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;
	

	int count = 1;
	//计算剩余顶点的最短路径即this->vexnum个顶点
	while (count != this->vexnum)
	{
		int temp = 0;//用于保存当前dis数组中最小的下标
		int min = INT_MAX;//记录当前的最小值
		for (i = 0; i < this->vexnum; i++)
		{
			if (!dis[i].visit&&dis[i].value < min)
			{
				min = dis[i].value;
				temp = i;
			}
		}

		dis[temp].visit = true;
		++count;
		for (int i = 0; i < this->vexnum; i++)
		{
			if (!dis[i].visit&&arc[temp][i] != INT_MAX && (dis[temp].value + arc[temp][i]) < dis[i].value)
			//如果新得到的边可以影响其他访问的顶点，那就更新它的最短路径和长度
			{
				dis[i].value = dis[temp].value + arc[temp][i];
				dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);

			}
		}
	}
}


void Graph_DG::print_path(int begin)//打印最短路径
{
	string str;
	str = "v" + to_string(begin);
	cout << "以" << str << "为起点的图的最短路径为：" << endl;
	for (int i = 0; i != this->vexnum; i++)
	{
		if (dis[i].value != INT_MAX)
		{
			cout << dis[i].path << " = " << dis[i].value << endl;
		}
		else
		{
			cout << dis[i].path << " 是无最短路径的 " << endl;
		}
		
	}
}