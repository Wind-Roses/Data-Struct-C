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

//初始化队列
void QueueInit(Queue* q);

//创建节点
QNode* CreateQNode(QSDataType data);

//入队
void QueuePush(Queue* q, QSDataType data);

//出队
void QueuePop(Queue* q);

//获取队首元素
QSDataType GetHead(Queue* q);

//获取队尾元素
QSDataType GetTail(Queue* q);

//队列判空
int QueueEmtpy(Queue* q);

//队列长度
int QueueSize(Queue* q);

//销毁队列
void QueueDestory(Queue* q);

//初始化栈
QStack* StackCreate();

//入栈
void StackPush(QStack* obj, QSDataType x);

//出栈
int StackPop(QStack* obj);

//获取栈顶元素
int StackTop(QStack* obj);

//栈判空
int StackEmpty(QStack* obj);

//销毁栈
void StackDestory(QStack* obj);