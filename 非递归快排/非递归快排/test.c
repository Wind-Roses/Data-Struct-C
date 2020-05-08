#define _CRT_SECURE_NO_WARNINGS 1

#include"quickSort.h"

void test()
{
	int array[] = { 5,6,1,4,9,7,3,2,8,0 };
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