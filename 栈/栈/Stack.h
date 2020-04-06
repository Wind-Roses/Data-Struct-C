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

//��ʼ��
void StackInit(Stack* S);

//��ջ
void StackPush(Stack* S, Type data);

//��ջ
void StackPop(Stack* S);

//��ȡջ��Ԫ��
Type GetTopElement(Stack* S);

//��ȡջ����ЧԪ�ظ���
size_t StackSize(Stack* S);

//�п�
int StackEmpty(Stack* S);

//��ӡ
void StackPrint(Stack* S);

//����
void StackDestroy(Stack* S);
