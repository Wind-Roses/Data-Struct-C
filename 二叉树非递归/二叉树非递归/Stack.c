#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//����
void StackInit(Stack* s)
{
	s->array = (SDataType*)malloc(sizeof(SDataType) * STACK_SPACE);
	s->capacity = STACK_SPACE;
	s->size = 0;
}

//��ջ
void StackPush(Stack* s, SDataType data)
{
	if (s->size == s->capacity)
	{
		s->capacity *= 2;
		s->array = (SDataType*)realloc(s->array, sizeof(SDataType) * s->capacity);
	}

	s->array[s->size++] = data;
}

//��ջ
void StackPop(Stack* s)
{
	if (s->size == 0)
		return;

	s->size--;
}

//��ȡջ��Ԫ��
SDataType GetTopElement(Stack* s)
{
	return s->array[s->size - 1];
}

//�п�
int StackEmpty(Stack* s)
{
	if (s->size == 0)
		return 1;
	return 0;
}