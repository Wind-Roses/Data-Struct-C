#pragma once
#include<stdio.h>
#include<stdlib.h>

#define FIRST_CAPACITY 20
#define NEW_CAPACITY 4

typedef int Type;
typedef struct Stack
{
	Type* array;
	size_t size;
	size_t capacity;
}Stack;

//初始化
void StackInit(Stack* S);

//进栈
void StackPush(Stack* S, Type data);

//退栈
void StackPop(Stack* S);

//获取栈顶元素
Type GetTopElement(Stack* S);

//获取栈中有效元素个数
size_t StackSize(Stack* S);

//判空
int StackEmpty(Stack* S);

//打印
void StackPrint(Stack* S);

//销毁
void StackDestroy(Stack* S);
