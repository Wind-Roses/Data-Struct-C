#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue of Stack.h"

void test()
{
	SQueue* obj = QueueCreate();

	for (int i = 0; i < 10; i++)
	{
		QueuePush(obj, i);
	}

	while (QueueEmpty(obj) != 1)
	{
		printf("%d ", QueuePeek(obj));
		QueuePop(obj);
	}

	QueueFree(obj);
}

int main()
{
	test();

	system("pause");
	return 0;
}