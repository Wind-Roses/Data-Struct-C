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

//初始化
void QueueInit(Queue* Q);

//创建节点
QNode* CreateQNode(QDataType data);

//入队
void QueuePush(Queue* Q, QDataType data);

//出队
void QueuePop(Queue* Q);

//获取队首元素
QDataType QueueHeadElement(Queue* Q);

//获取队尾元素
QDataType QueueTailElement(Queue* Q);

//队列元素个数
int QueueSize(Queue* Q);

//判空
int QueueEmpty(Queue* Q);

//销毁
void QueueDestroy(Queue* Q);

