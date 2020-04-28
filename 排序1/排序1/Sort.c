#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

//≤Â»Î≈≈–Ú
void InsertSort(int* array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int start = end + 1;
		int key = array[start];

		while (array[end] > key && end >= 0)
		{
			array[start--] = array[end--];
		}
		array[end + 1] = key;
	}
}

//œ£∂˚≈≈–Ú
void ShellSort(int* array, int n)
{
	int grap = n;
	
	while (grap > 1)
	{
		grap = grap / 2;

		for (int i = 0; i < n - grap; i++)
		{
			int end = i;
			int start = end + grap;
			int key = array[start];

			while (array[end] > key && end >= 0)
			{
				array[start] = array[end];
				end = end - grap;
				start = start - grap;
			}

			array[end + grap] = key;
		}
	}
}

//—°‘Ò≈≈–Ú
void SelectSort(int* array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int begin = i;
		int min = begin;

		for (int j = begin; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}

		Swap(array, min, begin);
	}
}

//”≈ªØ—°‘Ò≈≈–Ú
void BinarySelectSort(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		int begin = i;
		int end = n - i - 1;
		int min = begin;
		int max = end;

		for (int j = begin; j <= end; j++)
		{
			if (array[j] < array[min])
				min = j;
			if (array[j] > array[max])
				max = j;
		}

		Swap(array, begin, min);

		if (begin == max)
			max = min;

		Swap(array, end, max);
	}
}

void ShiftDown(int* array, int parent, int size)
{
	int child = parent * 2 + 1;

	while (child < size)
	{
		if (child + 1 < size && array[child] > array[child + 1])
			child++;
		if (array[parent] > array[child])
			Swap(array, parent, child);

		parent = child;
		child = parent * 2 + 1;

	}
}

//∂—≈≈–Ú
void HeapSort(int* array, int size)
{
	int* arr = (int*)malloc(sizeof(int) * size);
	int n = size;

	memcpy(arr, array, sizeof(int) * size);

	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		ShiftDown(arr, parent, size);
	}

	for (int i = 0; i < n && size >= 0; i++)
	{
		array[i] = arr[0];

		Swap(arr, 0, size - 1);
		size--;
		ShiftDown(arr, 0, size);
	}

	free(arr);
}

void Print(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
