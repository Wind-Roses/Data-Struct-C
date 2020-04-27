#pragma once

#include"Binary.h"

#define STACK_SPACE 10

typedef TNode* SDataType;
typedef struct Stack
{
	SDataType* array;
	int size;
	int capacity;
}Stack;

//建立
void StackInit(Stack* s);

//入栈
void StackPush(Stack* s, SDataType data);

//出栈
void StackPop(Stack* s);

//获取栈顶元素
SDataType GetTopElement(Stack* s);

//判空
int StackEmpty(Stack* s);
