#pragma once

#include"Binary.h"

#define QUEUE_SPACE 10

typedef TNode* QDataType;
typedef struct QNode
{
	QDataType data;
	struct QNode* next;
}QNode;
typedef struct Queue
{
	QNode* front;
	QNode* tail;
}Queue;

//��ʼ��
void QueueInit(Queue* q);

//���
void QueuePush(Queue* q, QDataType data);

//����
void QueuePop(Queue* q);

//�п�
int QueueEmpty(Queue* q);

//��ȡ����Ԫ��
QDataType GetFrontElement(Queue* q);
