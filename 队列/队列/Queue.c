#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//初始化
void QueueInit(Queue* Q)
{
	Q->head = Q->tail = NULL;
}

//创建节点
QNode* CreateQNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));

	node->next = NULL;
	node->data = data;

	return node;
}

//入队
void QueuePush(Queue* Q, QDataType data)
{
	QNode* node = CreateQNode(data);

	if (!Q->head)
	{
		Q->head = Q->tail = node;
	}

	Q->tail->next = node;
	Q->tail = node;
}

//出队
void QueuePop(Queue* Q)
{
	if (!Q->head)
	{
		return;
	}

	QNode* next = Q->head->next;
	free(Q->head);
	Q->head = next;

	if (!Q->head)
	{
		Q->tail = NULL;
	}
}

//获取队首元素
QDataType QueueHeadElement(Queue* Q)
{
	return Q->head->data;
}

//获取队尾元素
QDataType QueueTailElement(Queue* Q)
{
	return Q->tail->data;
}

//队列元素个数
int QueueSize(Queue* Q)
{
	int count = 0;
	QNode* cur = Q->head;

	while (cur)
	{
		cur = cur->next;
		count++;
	}

	return count;
}

//判空
int QueueEmpty(Queue* Q)
{
	if (!Q->head)
	{
		return 1;
	}

	return 0;
}

//销毁
void QueueDestroy(Queue* Q)
{
	QNode* next;

	while (Q->head)
	{
		next = Q->head->next;
		free(Q->head);
		Q->head = next;
	}
}

