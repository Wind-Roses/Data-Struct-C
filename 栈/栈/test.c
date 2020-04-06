#define _CRT_SECURE_NO_WARNINGS 1
#include"Stack.h"

void testStack()
{
	Stack S;

	StackInit(&S);

	for (int i = 0; i < 10; i++)
	{
		StackPush(&S, i);
	}
	StackPrint(&S);

	printf("%Iu\n", StackSize(&S));

	while (StackEmpty(&S) != 0)
	{
		printf("%d ", GetTopElement(&S));
		StackPop(&S);
	}
	printf("\n");

	StackDestroy(&S);
}

int main()
{
	testStack();

	system("pause");
	return 0;
}