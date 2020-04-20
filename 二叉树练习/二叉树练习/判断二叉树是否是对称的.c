#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

};

bool Process(struct TreeNode* p, struct TreeNode* q) {
	if (!p && !q)
		return true;
	if (!p || !q)
		return false;
	return p->val == q->val
		&& Process(p->left, q->right)
		&& Process(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
	if (!root)
		return true;
	return Process(root->left, root->right);
}