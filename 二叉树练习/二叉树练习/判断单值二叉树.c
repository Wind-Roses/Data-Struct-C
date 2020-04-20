#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};

bool isUT(struct TreeNode* root, int val)
{
	if (!root)
		return true;
	return root->val == val
		&& isUT(root->left, val)
		&& isUT(root->right, val);
}

bool isUnivalTree(struct TreeNode* root) {
	return isUT(root, root->val);
}