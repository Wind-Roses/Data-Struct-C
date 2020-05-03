#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

void test()
{
	int array[] = { 5,1,9,6,2,4,8,3,7,0 };
	int size = sizeof(array) / sizeof(array[0]);

	/*BubbleSort(array, size);
	Print(array, size);*/

	QuickSort(array, 0, size - 1);
	Print(array, size);
}

int main()
{
	test();

	system("pause");
	return 0;
}