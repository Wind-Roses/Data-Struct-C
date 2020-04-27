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

//初始化
void QueueInit(Queue* q);

//入队
void QueuePush(Queue* q, QDataType data);

//出队
void QueuePop(Queue* q);

//判空
int QueueEmpty(Queue* q);

//获取队首元素
QDataType GetFrontElement(Queue* q);
