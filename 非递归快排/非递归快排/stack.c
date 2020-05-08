#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"

//��ʼ��
void stackInit(Stack* s, int size)
{
	s->array = (SType*)malloc(sizeof(SType) * size);
	s->size = 0;
	s->capacity = size;
}

//��ջ
void stackPush(Stack* s, SType data)
{
	if (s->size == s->capacity)
	{
		s->capacity *= 2;
		s->array = (SType*)realloc(s->array, sizeof(SType) * s->capacity);
	}

	s->array[s->size++] = data;
}

//��ջ
void stackPop(Stack* s)
{
	if (s->size == 0)
		return;

	s->size--;
}

//��ȡջ��Ԫ��
SType getTop(Stack* s)
{
	return s->array[s->size - 1];
}

//�п�
int stackEmpty(Stack* s)
{
	if (s->size == 0)
		return 1;
	return 0;
}
