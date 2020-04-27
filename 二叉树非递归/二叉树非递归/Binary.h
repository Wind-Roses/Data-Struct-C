#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef char TDataType;
typedef struct TNode
{
	TDataType val;
	struct TNode* left;
	struct TNode* right;
}TNode;

//二叉树建立
TNode* BinaryTreeCreate(TNode* root, TDataType* arr, int* idx);

//非递归前序遍历
void PreorderTraversal(TNode* root);

//非递归中序遍历
void OrdinalTraversal(TNode* root);

//非递归后序遍历
void PostorderTraversal(TNode* root);

//层序遍历
void SequenceTraversal(TNode* root);

//判断是否是完全二叉树
int IsComplete(TNode* root);
