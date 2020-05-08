#pragma once

#include"quickSort.h"

typedef int QType;
typedef struct QNode
{
	QType data;
	struct QNode* next;
}QNode;
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;

//��ʼ��
void queueInit(Queue* q);

//���
void queuePush(Queue* q, QType data);

//����
void queuePop(Queue* q);

//��ȡ����Ԫ��
QType getFront(Queue* q);

//�п�
int queueEmpty(Queue* q);
