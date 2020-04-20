#pragma once
#include<stdio.h>

typedef int TDataType;
typedef struct TreeNode
{
	TDataType data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//获取二叉树结点个数
int GetTNodeNume(TreeNode* root);

//前序遍历
void PreorderTraversal(TreeNode* root);

//中序遍历
void InorderTraversal(TreeNode* root);

//后序遍历
void PostorderTraversal(TreeNode* root);
