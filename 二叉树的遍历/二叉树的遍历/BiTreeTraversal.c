#define _CRT_SECURE_NO_WARNINGS 1
#include"BiTreeTraversal.h"

//��ȡ������������
int GetTNodeNume(TreeNode* root)
{
	if (!root)
		return 0;
	return GetTNodeNume(root->left) + GetTNodeNume(root->right) + 1;
}

//ǰ�����
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

//�������
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

//�������
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
