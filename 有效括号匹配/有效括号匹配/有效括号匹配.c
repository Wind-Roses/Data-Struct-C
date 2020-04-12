#define _CRT_SECURE_NO_WARNINGS 1
#include"ÓÐÐ§À¨ºÅÆ¥Åä.h"

void StackInit(Stack* s, int k)
{
	s->arr = (DataType*)malloc(sizeof(DataType) * k);
	s->size = 0;
	s->capacity = k;
}

void StackPush(Stack* s, DataType data)
{
	if (s->size == s->capacity)
	{
		s->capacity = s->capacity * 2;
		s->arr = (DataType*)realloc(s->arr, sizeof(DataType) * s->capacity);
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

DataType GetTop(Stack* s)
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

bool isValid(char * s) {
	Stack st;
	char top;
	char str[][2] = { { '(', ')' },{ '[', ']' },{ '{', '}' } };

	if (s == NULL)
	{
		return false;
	}

	StackInit(&st, 10);

	while (*s != '\0')
	{
		int i = 0;
		for (i = 0; i < 3; i++)
		{
			if (*s == str[i][0])
			{
				StackPush(&st, *s);
				break;
			}
		}

		if (i == 3)
		{
			if (StackEmpty(&st) != 1)
			{
				top = GetTop(&st);
				StackPop(&st);
			}
			else
			{
				top = 0;
			}

			if (*s - 1 == top || *s - 2 == top)
			{
				s++;
				continue;
			}
			else
			{
				return false;
			}
		}

		s++;
	}

	if (StackEmpty(&st))
	{
		return true;
	}

	return false;
}