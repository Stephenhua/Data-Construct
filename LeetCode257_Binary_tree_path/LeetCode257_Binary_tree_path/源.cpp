#include <iostream>
#include <vector>
# include <string>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
};

class Solution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> res;
		if (root == NULL) return res;
		binaryTreePathsCore(root, res, to_string(root->val));
		return res;
	}

	void binaryTreePathsCore(TreeNode *root, vector<string> &str, string strpath)
	{
		if (root->left == NULL &root->right == NULL)
		{
			str.push_back(strpath);
			return;

		}
		if (root->left != NULL)
		{
			binaryTreePathsCore(root->left, str, strpath + "->" + to_string(root->left->val));
		}
		if (root->right != NULL)
		{
			binaryTreePathsCore(root->right, str, strpath + "->" + to_string(root->right->val));
		}
	}
};