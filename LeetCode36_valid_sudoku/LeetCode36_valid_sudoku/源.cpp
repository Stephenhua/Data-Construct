# include <iostream>
# include <vector>
# include <algorithm>
# include <set>//set������ʾÿ��Ԫ��������һ�Σ����Ҵ�С�Ѿ����к�
using namespace std;
bool isValidSudoku(vector<vector<char>>& board)
{
	int m = board.size();
	int n = board.size();
	vector<set<char>> row(m);
	vector<set<char>> col(m);
	vector <set<char>> grid(m);

	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (board[i][j] != '.')
			{
				char c = board[i][j];
				if (row[i].find(c) == row[i].end())//find �������ڲ���������Ԫ�س��ֵĵ�һ��λ��
				{
					row[i].insert(c);//insert��ʾ���뵽���鵱��
				}
				else
				{
					return false;
				}
				if (col[j].find(c) == col[j].end())
				{
					col[j].insert(c);
				}
				else
				{
					return false;
				}

				int ind = (i / 3) * 3 + j / 3;
				if (grid[ind].find(c) == grid[ind].end())
				{
					grid[ind].insert(c);
				}
				else
				{
					return false;
				}
			}
		}
	}
	return true;
}