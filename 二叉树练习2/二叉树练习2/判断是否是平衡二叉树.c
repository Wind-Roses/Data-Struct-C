#define _CRT_SECURE_NO_WARNINGS 1

#include<stdbool.h>
#include<stdio.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

};

int getHigh(struct TreeNode* root)
{
	if (!root)
		return 0;

	int left_high = getHigh(root->left);
	int right_high = getHigh(root->right);

	return left_high > right_high ? left_high + 1 : right_high + 1;
}

bool isBalanced(struct TreeNode* root) {
	if (!root)
		return true;

	return abs(getHigh(root->left) - getHigh(root->right)) < 2
		&& isBalanced(root->left)
		&& isBalanced(root->right);
}