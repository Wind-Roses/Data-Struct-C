#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void test()
{
	Heap hp;
	HDataType arr[11] = { 100, 50, 30, 20, 25, 18, 10, 5, 15, 21, 23 };

	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HeapPrint(&hp);

	HeapPush(&hp, 4);
	HeapPrint(&hp);

	while (HeapEmpty(&hp) != 1)
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
}

int main()
{
	test();

	system("pause");
	return 0;
}