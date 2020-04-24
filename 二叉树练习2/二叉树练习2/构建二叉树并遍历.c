#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

typedef struct TNode
{
	char val;
	struct TNode* left;
	struct TNode* right;
}TNode;

TNode* CreateBinaryTree(char* str, int* idx)
{
	if (str[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}
	else
	{
		TNode* root = (TNode*)malloc(sizeof(TNode));

		root->val = str[*idx];
		(*idx)++;
		root->left = CreateBinaryTree(str, idx);
		root->right = CreateBinaryTree(str, idx);
		return root;
	}
}

void OrdinalTraversal(TNode* root)
{
	if (root)
	{
		OrdinalTraversal(root->left);
		printf("%c ", root->val);
		OrdinalTraversal(root->right);
	}
}

int main()
{
	TNode* root = NULL;
	char str[101] = { 0 };
	int idx = 0;

	scanf("%s", str);

	root = CreateBinaryTree(str, &idx);

	OrdinalTraversal(root);
	printf("\n");

	return 0;
}