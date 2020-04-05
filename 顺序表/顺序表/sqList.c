#define _CRT_SECURE_NO_WARNINGS 1
#include"sqList.h"

void SqListInit(sqList* sl)
{
	sl->array = (DataType*)malloc(sizeof(DataType) * SQLIST_SPACE);
	if (sl->array == NULL)
	{
		return;
	}

	sl->size = 0;
	sl->capacity = SQLIST_SPACE;
}

void Expand(sqList* sl)
{
	if (sl->size == sl->capacity)
	{
		sl->capacity += NEW_SPACE;
		sl->array = (DataType*)realloc(sl->array, sizeof(DataType) * sl->capacity);
		if (sl->array == NULL)
		{
			return;
		}
	}
}

void sqListInsert(sqList* sl, int pos, DataType value)
{
	size_t count = sl->size;

	Expand(sl);

	if (pos < 0 || pos > sl->size)
	{
		return;
	}
	
	while (count > pos)
	{
		sl->array[count] = sl->array[count - 1];
		count--;
	}
	sl->array[pos] = value;

	sl->size++;
}

void HeadPush(sqList* sl, DataType value)
{
	sqListInsert(sl, 0, value);
}

void TailPush(sqList* sl, DataType value)
{
	sqListInsert(sl, (int)sl->size, value);
}

void sqListDelete(sqList* sl, int pos)
{
	if (pos < 0 || pos >= sl->size)
	{
		return;
	}

	while (pos < sl->size - 1)
	{
		sl->array[pos] = sl->array[pos + 1];
		pos++;
	}
	sl->size--;
}

void HeadPop(sqList* sl)
{
	sqListDelete(sl, 0);
}

void TailPop(sqList* sl)
{
	sqListDelete(sl, (int)sl->size - 1);
}

int SqListFind(sqList* sl, DataType value)
{
	int count = 0;

	while (count < sl->size)
	{
		if (sl->array[count] == value)
		{
			return count;
		}

		count++;
	}

	return -1;
}

void SqListPrint(sqList* sl)
{
	for (int i = 0; i < sl->size; i++)
	{
		printf("%d ", sl->array[i]);
	}
	printf("\n");
}