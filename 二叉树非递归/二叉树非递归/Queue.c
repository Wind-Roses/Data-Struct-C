#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//初始化
void QueueInit(Queue* q)
{
	q->front = (QNode*)malloc(sizeof(QNode));

	q->tail = q->front;
	q->front->next = NULL;
}

//创建节点
QNode* CreateQNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));

	node->data = data;
	node->next = NULL;

	return node;
}

//入队
void QueuePush(Queue* q, QDataType data)
{
	QNode* node = CreateQNode(data);

	q->tail->next = node;
	q->tail = node;
}

//出队
void QueuePop(Queue* q)
{
	if (q->front == q->tail)
		return;

	QNode* cur = q->front->next;
	q->front->next = cur->next;
	free(cur);

	if (q->front->next == NULL)
		q->tail = q->front;
}

//判空
int QueueEmpty(Queue* q)
{
	if (q->front == q->tail)
		return 1;
	return 0;
}

//获取队首元素
QDataType GetFrontElement(Queue* q)
{
	return q->front->next->data;
}