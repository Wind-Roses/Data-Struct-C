#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue of Stack.h"

void StackInit(Stack* s, int k)
{
	s->arr = (SQDataType*)malloc(sizeof(SQDataType) * k);
	s->size = 0;
	s->capacity = k;
}

void StackPush(Stack* s, SQDataType data)
{
	if (s->size == s->capacity)
	{
		s->capacity = s->capacity * 2;
		s->arr = (SQDataType*)realloc(s->arr, sizeof(SQDataType) * s->capacity);
	}

	s->arr[s->size++] = data;
}

void StackPop(Stack* s)
{
	if (s->size)
	{
		s->size--;
	}
}

SQDataType GetTop(Stack* s)
{
	return s->arr[s->size - 1];
}

int StackEmpty(Stack* s)
{
	if (s->size == 0)
	{
		return 1;
	}

	return 0;
}

void StackDestroy(Stack* s)
{
	free(s->arr);
	s->arr = NULL;
	s->capacity = s->size = 0;
}

SQueue* QueueCreate() {
	SQueue* obj = (SQueue*)malloc(sizeof(SQueue));
	StackInit(&obj->pushStack, 10);
	StackInit(&obj->popStack, 10);

	return obj;
}

void QueuePush(SQueue* obj, SQDataType x) {
	StackPush(&obj->pushStack, x);
}

int QueuePop(SQueue* obj) {
	if (StackEmpty(&obj->popStack))
	{
		while (StackEmpty(&obj->pushStack) != 1)
		{
			int top = GetTop(&obj->pushStack);
			StackPop(&obj->pushStack);
			StackPush(&obj->popStack, top);
		}
	}
	int ret = GetTop(&obj->popStack);
	StackPop(&obj->popStack);

	return ret;
}

int QueuePeek(SQueue* obj) {
	if (StackEmpty(&obj->popStack))
	{
		while (StackEmpty(&obj->pushStack) != 1)
		{
			int top = GetTop(&obj->pushStack);
			StackPop(&obj->pushStack);
			StackPush(&obj->popStack, top);
		}
	}
	return GetTop(&obj->popStack);
}

int QueueEmpty(SQueue* obj) {
	return StackEmpty(&obj->popStack) && StackEmpty(&obj->pushStack);
}

void QueueFree(SQueue* obj) {
	StackDestroy(&obj->pushStack);
	StackDestroy(&obj->popStack);
	free(obj);
}