#include <iostream>
#include <vector>
using namespace std;
struct TreeNode{
	int val;
	TreeNode *right;
	TreeNode *left;
	TreeNode(int x) :val(x), right(NULL), left(NULL){}
};

class Solution {
public:
	int tilt = 0;
	int findTilt(TreeNode* root) {
		sum(root);
		return tilt;
	}
	int sum(TreeNode * root)
	{
		if (root == NULL)
		{
			return 0;
		}
		int left = sum(root->left);
		int right = sum(root->right);
		tilt += left>right ? left - right : right - left;
		return left + right + root->val;
	}
};
