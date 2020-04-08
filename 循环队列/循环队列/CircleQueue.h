#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int CDataType;
typedef struct CircleQueue
{
	CDataType* array;
	int front;
	int rear;
	int capacity;
}CircleQueue;

//��ʼ��
void CircleQueueInit(CircleQueue* cq, int k);

//���
void CircleQueuePush(CircleQueue* cq, CDataType data);

//����
void CircleQueuePop(CircleQueue* cq);

//��ȡ����Ԫ��
CDataType GetFrontElement(CircleQueue* cq);

//��ȡ��βԪ��
CDataType GetRearElement(CircleQueue* cq);

//��ЧԪ�ظ���
int CircleQueueSize(CircleQueue* cq);

//�п�
int CircleQueueEmpty(CircleQueue* cq);

//����
int CircleQueueFull(CircleQueue* cq);

//����
void CircleQueueDestroy(CircleQueue* cq);
