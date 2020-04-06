#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

//��ʼ��
void StackInit(Stack* S)
{
	S->array = (Type*)malloc(sizeof(Type) * FIRST_CAPACITY);
	S->size = 0;
	S->capacity = FIRST_CAPACITY;
}

//��ջ
void StackPush(Stack* S, Type data)
{
	if (S->size == S->capacity)
	{
		S->capacity = FIRST_CAPACITY + NEW_CAPACITY;
		S->array = (Type*)realloc(S->array, sizeof(Type) * S->capacity);
	}

	S->array[S->size++] = data;
}

//��ջ
void StackPop(Stack* S)
{
	if (S->size == 0)
	{
		return;
	}

	S->size--;
}

//��ȡջ��Ԫ��
Type GetTopElement(Stack* S)
{
	return S->array[S->size - 1];
}

//��ȡջ����ЧԪ�ظ���
size_t StackSize(Stack* S)
{
	return S->size;
}

//�п�
int StackEmpty(Stack* S)
{
	if (S->size == 0)
	{
		return 0;
	}

	return 1;
}

//��ӡ
void StackPrint(Stack* S)
{
	for (size_t i = 0; i < S->size; i++)
	{
		printf("%d ", S->array[i]);
	}
	printf("\n");
}

//����
void StackDestroy(Stack* S)
{
	free(S->array);
	S->array = NULL;
	S->size = S->capacity = 0;
}
