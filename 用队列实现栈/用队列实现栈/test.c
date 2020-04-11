#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue Stack.h"

void test()
{
	QStack* obj = StackCreate();

	for (int i = 0; i < 11; i++)
	{
		StackPush(obj, i);
	}

	while (StackEmpty(obj) != 1)
	{
		printf("%d ",StackTop(obj));
		StackPop(obj);
	}

	StackDestory(obj);
}

int main()
{
	test();

	system("pause");
	return 0;
}