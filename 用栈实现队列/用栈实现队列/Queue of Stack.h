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

//��ʼ��ջ
void StackInit(Stack* s, int k);

//��ջ
void StackPush(Stack* s, SQDataType data);

//��ջ
void StackPop(Stack* s);

//��ȡջ��Ԫ��
SQDataType GetTop(Stack* s);

//ջ�п�
int StackEmpty(Stack* s);

//����ջ
void StackDestroy(Stack* s);

//��������
SQueue* QueueCreate();

//���
void QueuePush(SQueue* obj, SQDataType x);

//����
int QueuePop(SQueue* obj);

//��ȡ����Ԫ��
int QueuePeek(SQueue* obj);

//�����п�
int QueueEmpty(SQueue* obj);

//���ٶ���
void QueueFree(SQueue* obj);