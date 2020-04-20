#define _CRT_SECURE_NO_WARNINGS 1
#include"BiTreeTraversal.h"

//获取二叉树结点个数
int GetTNodeNume(TreeNode* root)
{
	if (!root)
		return 0;
	return GetTNodeNume(root->left) + GetTNodeNume(root->right) + 1;
}

//前序遍历
void PreorderTraversal(TreeNode* root)
{
	if (root)
	{
		printf("%d ", root->data);
		PreorderTraversal(root->left);
		PreorderTraversal(root->right);
	}

	return;
}

//中序遍历
void InorderTraversal(TreeNode* root)
{
	if (root)
	{
		InorderTraversal(root->left);
		printf("%d ", root->data);
		InorderTraversal(root->right);
	}

	return;
}

//后序遍历
void PostorderTraversal(TreeNode* root)
{
	if (root)
	{
		PostorderTraversal(root->left);
		PostorderTraversal(root->right);
		printf("%d ", root->data);
	}

	return;
}
