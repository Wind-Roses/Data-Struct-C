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

//����������
TNode* BinaryTreeCreate(TNode* root, TDataType* arr, int* idx);

//�ǵݹ�ǰ�����
void PreorderTraversal(TNode* root);

//�ǵݹ��������
void OrdinalTraversal(TNode* root);

//�ǵݹ�������
void PostorderTraversal(TNode* root);

//�������
void SequenceTraversal(TNode* root);

//�ж��Ƿ�����ȫ������
int IsComplete(TNode* root);
