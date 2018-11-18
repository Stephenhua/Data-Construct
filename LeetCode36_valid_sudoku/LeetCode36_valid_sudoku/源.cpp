# include <iostream>
# include <vector>
# include <algorithm>
# include <set>//set函数表示每个元素最多出现一次，并且大小已经排列好
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
				if (row[i].find(c) == row[i].end())//find 函数用于查找数组中元素出现的第一个位置
				{
					row[i].insert(c);//insert表示插入到数组当中
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