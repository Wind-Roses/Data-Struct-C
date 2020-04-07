#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

//��ʼ��
void QueueInit(Queue* Q)
{
	Q->head = Q->tail = NULL;
}

//�����ڵ�
QNode* CreateQNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));

	node->next = NULL;
	node->data = data;

	return node;
}

//���
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

//����
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

//��ȡ����Ԫ��
QDataType QueueHeadElement(Queue* Q)
{
	return Q->head->data;
}

//��ȡ��βԪ��
QDataType QueueTailElement(Queue* Q)
{
	return Q->tail->data;
}

//����Ԫ�ظ���
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

//�п�
int QueueEmpty(Queue* Q)
{
	if (!Q->head)
	{
		return 1;
	}

	return 0;
}

//����
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

