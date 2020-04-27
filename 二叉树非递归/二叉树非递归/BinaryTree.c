#define _CRT_SECURE_NO_WARNINGS 1

#include"Binary.h"
#include"Stack.h"
#include"Queue.h"

//����������
TNode* BinaryTreeCreate(TNode* root, TDataType* arr, int* idx)
{
	if (!arr)
		return NULL;
	if (arr[*idx] == '#')
	{
		(*idx)++;
		return NULL;
	}

	root = (TNode*)malloc(sizeof(TNode));

	root->val = arr[*idx];
	(*idx)++;
	root->left = BinaryTreeCreate(root->left, arr, idx);
	root->right = BinaryTreeCreate(root->right, arr, idx);

	return root;
}

//�ǵݹ�ǰ�����
void PreorderTraversal(TNode* root)
{
	TNode* cur = root;
	Stack s;

	StackInit(&s);

	while (cur || !StackEmpty(&s))
	{
		while (cur)
		{
			printf("%c", cur->val);
			StackPush(&s, cur);
			cur = cur->left;
		}

		TNode* top = GetTopElement(&s);
		StackPop(&s);

		cur = top->right;
	}
	printf("\n");

}

//�ǵݹ��������
void OrdinalTraversal(TNode* root)
{
	TNode* cur = root;
	Stack s;

	StackInit(&s);

	while (cur || !StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}

		TNode* top = GetTopElement(&s);
		printf("%c", top->val);
		StackPop(&s);

		cur = top->right;
	}
	printf("\n");

}

//�ǵݹ�������
void PostorderTraversal(TNode* root)
{
	TNode* cur = root;
	TNode* prev = NULL;
	Stack s;

	StackInit(&s);

	while (cur || !StackEmpty(&s))
	{
		while (cur)
		{
			StackPush(&s, cur);
			cur = cur->left;
		}

		TNode* top = GetTopElement(&s);

		if (top->right == NULL || top->right == prev)
		{
			printf("%c", top->val);
			StackPop(&s);

			prev = top;
		}
		else
			cur = top->right;
	}
	printf("\n");

}

//�������
void SequenceTraversal(TNode* root)
{
	Queue q;

	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		TNode* front = GetFrontElement(&q);
		printf("%c", front->val);
		QueuePop(&q);

		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");
}

//�ж��Ƿ�����ȫ������
int IsComplete(TNode* root)
{
	Queue q;

	QueueInit(&q);

	if (root)
		QueuePush(&q, root);
	else
		return 1;

	while (!QueueEmpty(&q))
	{
		TNode* front = GetFrontElement(&q);

		if (front != NULL)
		{
			QueuePop(&q);

			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
		else
		{
			QueuePop(&q);
			break;
		}
	}

	QNode* cur = q.front->next;
	while (cur)
	{
		if (cur->data != NULL)
			return 0;

		cur = cur->next;
	}

	return 1;
}