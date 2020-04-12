#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int SQDataType;
typedef struct Stack
{
	SQDataType* arr;
	int size;
	int capacity;
}Stack;
typedef struct SQueue{
	Stack pushStack;
	Stack popStack;
} SQueue;

//初始化栈
void StackInit(Stack* s, int k);

//入栈
void StackPush(Stack* s, SQDataType data);

//出栈
void StackPop(Stack* s);

//获取栈顶元素
SQDataType GetTop(Stack* s);

//栈判空
int StackEmpty(Stack* s);

//销毁栈
void StackDestroy(Stack* s);

//创建队列
SQueue* QueueCreate();

//入队
void QueuePush(SQueue* obj, SQDataType x);

//出队
int QueuePop(SQueue* obj);

//获取队首元素
int QueuePeek(SQueue* obj);

//队列判空
int QueueEmpty(SQueue* obj);

//销毁队列
void QueueFree(SQueue* obj);