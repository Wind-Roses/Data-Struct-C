#define _CRT_SECURE_NO_WARNINGS 1

#include"stack.h"

//初始化
void stackInit(Stack* s, int size)
{
	s->array = (SType*)malloc(sizeof(SType) * size);
	s->size = 0;
	s->capacity = size;
}

//入栈
void stackPush(Stack* s, SType data)
{
	if (s->size == s->capacity)
	{
		s->capacity *= 2;
		s->array = (SType*)realloc(s->array, sizeof(SType) * s->capacity);
	}

	s->array[s->size++] = data;
}

//出栈
void stackPop(Stack* s)
{
	if (s->size == 0)
		return;

	s->size--;
}

//获取栈顶元素
SType getTop(Stack* s)
{
	return s->array[s->size - 1];
}

//判空
int stackEmpty(Stack* s)
{
	if (s->size == 0)
		return 1;
	return 0;
}
