#define _CRT_SECURE_NO_WARNINGS 1

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	
};

void Process(struct TreeNode* root)
{
	if (!root)
		return;

	struct TreeNode* tmp = root->left;
	root->left = root->right;
	root->right = tmp;

	Process(root->left);
	Process(root->right);
}

struct TreeNode* invertTree(struct TreeNode* root) {
	Process(root);

	return root;
}
