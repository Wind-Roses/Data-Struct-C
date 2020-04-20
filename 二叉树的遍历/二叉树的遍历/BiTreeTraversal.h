#pragma once
#include<stdio.h>

typedef int TDataType;
typedef struct TreeNode
{
	TDataType data;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

//��ȡ������������
int GetTNodeNume(TreeNode* root);

//ǰ�����
void PreorderTraversal(TreeNode* root);

//�������
void InorderTraversal(TreeNode* root);

//�������
void PostorderTraversal(TreeNode* root);
