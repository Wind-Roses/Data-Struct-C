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

//初始化
void CircleQueueInit(CircleQueue* cq, int k);

//入队
void CircleQueuePush(CircleQueue* cq, CDataType data);

//出队
void CircleQueuePop(CircleQueue* cq);

//获取队首元素
CDataType GetFrontElement(CircleQueue* cq);

//获取队尾元素
CDataType GetRearElement(CircleQueue* cq);

//有效元素个数
int CircleQueueSize(CircleQueue* cq);

//判空
int CircleQueueEmpty(CircleQueue* cq);

//判满
int CircleQueueFull(CircleQueue* cq);

//销毁
void CircleQueueDestroy(CircleQueue* cq);
