#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;
typedef struct QNode
{
	QDataType data;
	struct QNode* next;
}QNode;
typedef struct Queue
{
	QNode* head;
	QNode* tail;
}Queue;

//��ʼ��
void QueueInit(Queue* Q);

//�����ڵ�
QNode* CreateQNode(QDataType data);

//���
void QueuePush(Queue* Q, QDataType data);

//����
void QueuePop(Queue* Q);

//��ȡ����Ԫ��
QDataType QueueHeadElement(Queue* Q);

//��ȡ��βԪ��
QDataType QueueTailElement(Queue* Q);

//����Ԫ�ظ���
int QueueSize(Queue* Q);

//�п�
int QueueEmpty(Queue* Q);

//����
void QueueDestroy(Queue* Q);

