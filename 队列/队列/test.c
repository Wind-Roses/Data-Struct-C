#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue.h"

void test()
{
	Queue Q;

	QueueInit(&Q);

	for (int i = 1; i <= 10; i++)
	{
		QueuePush(&Q, i);
	}

	printf("%d\n", QueueSize(&Q));

	while (QueueEmpty(&Q) != 1)
	{
		printf("%d ", QueueHeadElement(&Q));
		QueuePop(&Q);
	}
	printf("\n");

	QueueDestroy(&Q);
}

int main()
{
	test();

	system("pause");
	return 0;
}