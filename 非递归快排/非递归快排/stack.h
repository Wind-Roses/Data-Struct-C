#pragma once

#include"quickSort.h"

typedef int SType;
typedef struct Stack
{
	SType* array;
	int size;
	int capacity;
}Stack;

//初始化
void stackInit(Stack* s, int size);

//入栈
void stackPush(Stack* s, SType data);

//出栈
void stackPop(Stack* s);

//获取栈顶元素
SType getTop(Stack* s);

//判空
int stackEmpty(Stack* s);
