# include"Dijkstra.h"
Graph_DG::Graph_DG(int vexnum, int edge)
{
	this->vexnum = vexnum;//��ʼ���������ͱ���
	this->edge = edge;//����
	arc = new int*[this->vexnum];//�ڴ�����ڶ��ϣ����ϵ��Ƿ������ڴ棬���Է���ϴ���ڴ棬int a[]��ʾ������ջ�ϣ������ڴ沢������
	dis = new Dis[this->vexnum];
	for (int i = 0; i < this->vexnum; i++)
	{
		arc[i] = new int[this->vexnum];//���ھ����ʾͨ��ʹ�������ʾ�����ʾһ�����д��ڶ��ٸ�Ԫ��
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


bool Graph_DG::check_edge_value(int start, int end, int weight)//�ж�ÿ���������Ϣ�Ƿ�Ϸ��������1��ʼ���
{
	if (start < 1 || end<1 || start>vexnum ||end>vexnum|| weight < 0)
	{
		return false;
	}
	return true;
}

void Graph_DG::creatGraph(){
	cout << "������ÿ���ߵ������յ㣨�����Ŵ�һ��ʼ���Լ���Ȩ�أ�" << endl;
	int start;
	int end;
	int weight;
	int count = 0;
	while (count != this->edge)//��ѡ�жϱߵ���Ϣ�Ƿ�Ϸ�
	{
		cin >> start >> end >> weight;
		while (!this->check_edge_value(start, end, weight))
		{
			cout << "����ıߵ���Ϣ���ͷ������������룺" << endl;
			cin >> start >> end >> weight;
		}
		arc[start - 1][end - 1] = weight;//���ڽӾ����Ӧ�ϵĵ���и�ֵ
		++count;
	}
}

void Graph_DG::print(){
	cout << "�ڽӾ���Ϊ��" << endl;
	int count_row = 0;//��ӡ�еı�ǩ
	int count_col = 0;//��ӡ�еı�ǩ
	while (count_row != this->vexnum)
	{
		count_col = 0;
		while (count_col != this->vexnum)
		{
			if (arc[count_row][count_col] == INT_MAX)
			{
				cout << "��" << " ";
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
	//��ʼ��dis����
	int i;
	for (i = 0; i < this->vexnum; ++i)
	{
		//���õ�ǰ·��
		dis[i].path = "v" + to_string(begin) + "-->v" + to_string(i + 1);
		dis[i].value = arc[begin - 1][i];
	}
	//������㵽����·��Ϊ0
	dis[begin - 1].value = 0;
	dis[begin - 1].visit = true;
	

	int count = 1;
	//����ʣ�ඥ������·����this->vexnum������
	while (count != this->vexnum)
	{
		int temp = 0;//���ڱ��浱ǰdis��������С���±�
		int min = INT_MAX;//��¼��ǰ����Сֵ
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
			//����µõ��ı߿���Ӱ���������ʵĶ��㣬�Ǿ͸����������·���ͳ���
			{
				dis[i].value = dis[temp].value + arc[temp][i];
				dis[i].path = dis[temp].path + "-->v" + to_string(i + 1);

			}
		}
	}
}


void Graph_DG::print_path(int begin)//��ӡ���·��
{
	string str;
	str = "v" + to_string(begin);
	cout << "��" << str << "Ϊ����ͼ�����·��Ϊ��" << endl;
	for (int i = 0; i != this->vexnum; i++)
	{
		if (dis[i].value != INT_MAX)
		{
			cout << dis[i].path << " = " << dis[i].value << endl;
		}
		else
		{
			cout << dis[i].path << " �������·���� " << endl;
		}
		
	}
}