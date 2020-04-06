#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//初始化
void StackInit(Stack* S)
{
	S->array = (Type*)malloc(sizeof(Type) * FIRST_CAPACITY);
	S->size = 0;
	S->capacity = FIRST_CAPACITY;
}

//进栈
void StackPush(Stack* S, Type data)
{
	if (S->size == S->capacity)
	{
		S->capacity = FIRST_CAPACITY + NEW_CAPACITY;
		S->array = (Type*)realloc(S->array, sizeof(Type) * S->capacity);
	}

	S->array[S->size++] = data;
}

//退栈
void StackPop(Stack* S)
{
	if (S->size == 0)
	{
		return;
	}

	S->size--;
}

//获取栈顶元素
Type GetTopElement(Stack* S)
{
	return S->array[S->size - 1];
}

//获取栈中有效元素个数
size_t StackSize(Stack* S)
{
	return S->size;
}

//判空
int StackEmpty(Stack* S)
{
	if (S->size == 0)
	{
		return 0;
	}

	return 1;
}

//打印
void StackPrint(Stack* S)
{
	for (size_t i = 0; i < S->size; i++)
	{
		printf("%d ", S->array[i]);
	}
	printf("\n");
}

//销毁
void StackDestroy(Stack* S)
{
	free(S->array);
	S->array = NULL;
	S->size = S->capacity = 0;
}
