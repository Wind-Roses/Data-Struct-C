#define _CRT_SECURE_NO_WARNINGS 1

#include"quickSort.h"

void test()
{
	int array[] = { 5,3,9,2,6,7,8,4,1,0 };
	int size = sizeof(array) / sizeof(array[0]);

	quickSort(array, 0, size - 1);
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

int main()
{
	test();

	system("pause");
	return 0;
}