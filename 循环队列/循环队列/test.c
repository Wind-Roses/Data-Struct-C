#define _CRT_SECURE_NO_WARNINGS 1
#include"CircleQueue.h"

void test()
{
	CircleQueue cq;
	int i = 0;

	CircleQueueInit(&cq, 5);

	while (CircleQueueFull(&cq) != 1)
	{
		CircleQueuePush(&cq, i);
		i++;
	}
	printf("队中元素个数：%d\n", CircleQueueSize(&cq));

	while (CircleQueueEmpty(&cq) != 1)
	{
		printf("%d ", GetFrontElement(&cq));
		CircleQueuePop(&cq);
	}

	CircleQueueDestroy(&cq);
}

int main()
{
	test();

	system("pause");
	return 0;
}