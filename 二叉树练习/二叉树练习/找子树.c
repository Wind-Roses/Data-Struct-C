#define _CRT_SECURE_NO_WARNINGS 1
#include<stdbool.h>

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;

};

bool isSameTree(struct TreeNode* s, struct TreeNode* t) {
	if (!s && !t)
		return true;
	if (!s || !t)
		return false;
	return s->val == t->val
		&& isSameTree(s->left, t->left)
		&& isSameTree(s->right, t->right);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (!t)
		return true;
	if (!s)
		return false;

	return isSameTree(s, t)
		|| isSubtree(s->left, t)
		|| isSubtree(s->right, t);
}