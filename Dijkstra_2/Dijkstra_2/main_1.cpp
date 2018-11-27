# include "Dijkstra.h"
# include <iostream>
//用于检测边数和点数是否有效
//顶点数和边数的关系是：((Vexnum*(Vexnum - 1)) / 2) < edge
bool check(int Vexnum, int edge)
{
	if (Vexnum <= 0 || edge <= 0 || ((Vexnum*(Vexnum - 1)) / 2) < edge)
	{
		return false;
	}
	return true;
}

int main()
{
	int vexnum;
	int edge;
	cout << "输入图的顶点个数和边的条数" << endl;
	cin >> vexnum >> edge;
	while (!check(vexnum, edge))
	{
		cout << "输入的数值不和法，请重新输入： " << endl;
		cin >> vexnum >> edge;
	}
	Graph_DG graph(vexnum, edge);
	graph.creatGraph();
	graph.print();
	graph.Dijkstra(1);
	graph.print_path(1);
	system("pause");
	return EXIT_SUCCESS;
}