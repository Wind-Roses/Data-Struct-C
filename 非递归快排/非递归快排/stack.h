#pragma once

#include"quickSort.h"

typedef int SType;
typedef struct Stack
{
	SType* array;
	int size;
	int capacity;
}Stack;

//��ʼ��
void stackInit(Stack* s, int size);

//��ջ
void stackPush(Stack* s, SType data);

//��ջ
void stackPop(Stack* s);

//��ȡջ��Ԫ��
SType getTop(Stack* s);

//�п�
int stackEmpty(Stack* s);
