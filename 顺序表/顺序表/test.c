#define _CRT_SECURE_NO_WARNINGS 1
#include"sqList.h"

int main()
{
	sqList sl;

	SqListInit(&sl);

	for (int i = 0; i < 30; i++)
	{
		//HeadPush(&sl, i);
		TailPush(&sl, i);
	}

	sqListInsert(&sl, 1, 3);
	sqListDelete(&sl, 2);
	HeadPop(&sl);
	TailPop(&sl);

	SqListPrint(&sl);

	system("pause");
	return 0;
}