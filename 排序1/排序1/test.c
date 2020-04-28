#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void test()
{
	int array[] = { 5, 2, 6, 9, 8, 3, 1, 7, 2, 4, 0 };

	//InsertSort(array, sizeof(array) / sizeof(array[0]));
	//ShellSort(array, sizeof(array) / sizeof(array[0]));
	//SelectSort(array, sizeof(array) / sizeof(array[0]));
	//BinarySelectSort(array, sizeof(array) / sizeof(array[0]));
	HeapSort(array, sizeof(array) / sizeof(array[0]));
	Print(array, sizeof(array) / sizeof(array[0]));
}

int main()
{
	test();

	system("pause");
	return 0;
}