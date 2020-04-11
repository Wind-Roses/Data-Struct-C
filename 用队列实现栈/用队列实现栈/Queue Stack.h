#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int QSDataType;
typedef struct QNode
{
	QSDataType data;
	struct QNode* next;
}QNode;
typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;
typedef struct {
	Queue q;
} QStack;

//��ʼ������
void QueueInit(Queue* q);

//�����ڵ�
QNode* CreateQNode(QSDataType data);

//���
void QueuePush(Queue* q, QSDataType data);

//����
void QueuePop(Queue* q);

//��ȡ����Ԫ��
QSDataType GetHead(Queue* q);

//��ȡ��βԪ��
QSDataType GetTail(Queue* q);

//�����п�
int QueueEmtpy(Queue* q);

//���г���
int QueueSize(Queue* q);

//���ٶ���
void QueueDestory(Queue* q);

//��ʼ��ջ
QStack* StackCreate();

//��ջ
void StackPush(QStack* obj, QSDataType x);

//��ջ
int StackPop(QStack* obj);

//��ȡջ��Ԫ��
int StackTop(QStack* obj);

//ջ�п�
int StackEmpty(QStack* obj);

//����ջ
void StackDestory(QStack* obj);