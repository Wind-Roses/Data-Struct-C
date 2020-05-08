#define _CRT_SECURE_NO_WARNINGS 1

#include"queue.h"

//��ʼ��
void queueInit(Queue* q)
{
	q->front = (QNode*)malloc(sizeof(QNode));
	q->front->next = NULL;
	q->rear = q->front;
}

//���
void queuePush(Queue* q, QType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;

	q->rear->next = node;
	q->rear = node;
}

//����
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

//��ȡ����Ԫ��
QType getFront(Queue* q)
{
	return q->front->next->data;
}

//�п�
int queueEmpty(Queue* q)
{
	if (q->front->next == NULL)
		return 1;
	return 0;
}
