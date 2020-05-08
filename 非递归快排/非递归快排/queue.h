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

//初始化
void queueInit(Queue* q);

//入队
void queuePush(Queue* q, QType data);

//出队
void queuePop(Queue* q);

//获取队首元素
QType getFront(Queue* q);

//判空
int queueEmpty(Queue* q);
