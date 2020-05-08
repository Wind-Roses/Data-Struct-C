#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

//初始化
void queueInit(Queue* q)
{
	q->front = (QNode*)malloc(sizeof(QNode));
	q->front->next = NULL;
	q->rear = q->front;
}

//入队
void queuePush(Queue* q, QType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;

	q->rear->next = node;
	q->rear = node;
}

//出队
void queuePop(Queue* q)
{
	if (q->front->next == NULL)
		return;

	QNode* node = q->front->next;
	q->front->next = node->next;
	free(node);

	if (q->front->next == NULL)
		q->rear = q->front;
}

//获取队首元素
QType getFront(Queue* q)
{
	return q->front->next->data;
}

//判空
int queueEmpty(Queue* q)
{
	if (q->front->next == NULL)
		return 1;
	return 0;
}
