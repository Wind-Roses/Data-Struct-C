#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Swap(int* arr, int parent, int child)
{
	int tmp = arr[child];
	arr[child] = arr[parent];
	arr[parent] = tmp;
}

void ShiftDown(int* arr, int size, int parent)
{
	int child = 2 * parent + 1;

	while (child < size)
	{
		if (child + 1 < size && arr[child] < arr[child + 1])
			child++;
		if (arr[child] > arr[parent])
		{
			Swap(arr, parent, child);

			parent = child;
			child = 2 * parent + 1;
		}
		else
			break;
	}
}

void HeapSort(int* arr, int size)
{
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		ShiftDown(arr, size, parent);
	}

	while (size > 0)
	{
		Swap(arr, 0, size - 1);
		size--;
		ShiftDown(arr, size, 0);
	}
}

int main()
{
	int array[] = { 30, 45, 15, 35, 36, 18, 53, 72, 48, 93 };
	int size = sizeof(array) / sizeof(array[0]);

	HeapSort(array, size);

	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}