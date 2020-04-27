#define _CRT_SECURE_NO_WARNINGS 1

#include"Queue.h"

//��ʼ��
void QueueInit(Queue* q)
{
	q->front = (QNode*)malloc(sizeof(QNode));

	q->tail = q->front;
	q->front->next = NULL;
}

//�����ڵ�
QNode* CreateQNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));

	node->data = data;
	node->next = NULL;

	return node;
}

//���
void QueuePush(Queue* q, QDataType data)
{
	QNode* node = CreateQNode(data);

	q->tail->next = node;
	q->tail = node;
}

//����
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

//�п�
int QueueEmpty(Queue* q)
{
	if (q->front == q->tail)
		return 1;
	return 0;
}

//��ȡ����Ԫ��
QDataType GetFrontElement(Queue* q)
{
	return q->front->next->data;
}