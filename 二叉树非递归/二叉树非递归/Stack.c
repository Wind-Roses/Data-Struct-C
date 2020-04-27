#define _CRT_SECURE_NO_WARNINGS 1

#include"Stack.h"

//建立
void StackInit(Stack* s)
{
	s->array = (SDataType*)malloc(sizeof(SDataType) * STACK_SPACE);
	s->capacity = STACK_SPACE;
	s->size = 0;
}

//入栈
void StackPush(Stack* s, SDataType data)
{
	if (s->size == s->capacity)
	{
		s->capacity *= 2;
		s->array = (SDataType*)realloc(s->array, sizeof(SDataType) * s->capacity);
	}

	s->array[s->size++] = data;
}

//出栈
void StackPop(Stack* s)
{
	if (s->size == 0)
		return;

	s->size--;
}

//获取栈顶元素
SDataType GetTopElement(Stack* s)
{
	return s->array[s->size - 1];
}

//判空
int StackEmpty(Stack* s)
{
	if (s->size == 0)
		return 1;
	return 0;
}