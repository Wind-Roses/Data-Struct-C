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

//����
void StackInit(Stack* s);

//��ջ
void StackPush(Stack* s, SDataType data);

//��ջ
void StackPop(Stack* s);

//��ȡջ��Ԫ��
SDataType GetTopElement(Stack* s);

//�п�
int StackEmpty(Stack* s);
