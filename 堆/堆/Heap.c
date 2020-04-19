#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

//堆创建
void HeapCreate(Heap* hp, HDataType* arr, int size)
{
	hp->array = (HDataType*)malloc(sizeof(HDataType) * size);
	memcpy(hp->array, arr, sizeof(HDataType) * size);
	hp->size = hp->capacity = size;

	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		LittleShiftDown(hp->array, size, parent);
	}
}

//交换
void Swap(HDataType* array, int parent, int child)
{
	HDataType tmp = array[parent];
	array[parent] = array[child];
	array[child] = tmp;
}

//小根堆向下调整算法
void LittleShiftDown(HDataType* array, size_t size, int parent)
{
	int child = 2 * parent + 1;

	while (child < size)
	{
		if (array[child] > array[child + 1] && child + 1 < size)
			child++;
		if (array[parent] > array[child])
		{
			Swap(array, parent, child);

			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

//小根堆向上调整算法
void LittleShiftUp(HDataType* array, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (array[child] < array[parent])
		{
			Swap(array, parent, child);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

//获取堆顶元素
HDataType HeapTop(Heap* hp)
{
	return hp->array[0];
}

//进堆
void HeapPush(Heap* hp, HDataType data)
{
	if (hp->size == hp->capacity)
	{
		hp->capacity *= 2;
		hp->array = (HDataType*)realloc(hp->array,sizeof(HDataType) * hp->capacity);
	}

	hp->array[hp->size++] = data;
	LittleShiftUp(hp->array, (int)hp->size - 1);
}

//出堆
void HeapPop(Heap* hp)
{
	if (hp->size > 0)
	{
		Swap(hp->array, 0, (int)hp->size - 1);

		hp->size--;

		LittleShiftDown(hp->array, hp->size, 0);
	}
}

//判空
int HeapEmpty(Heap* hp)
{
	if (hp->size == 0)
		return 1;
	return 0;
}

//堆打印
void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->size; i++)
	{
		printf("%d ", hp->array[i]);
	}
	printf("\n");
}