#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

void testLink()
{
	Link L;

	LinkInit(&L);

	for (int i = 1; i < 10; i++)
	{
		//HeadPush(&L, i);
		TailPush(&L, i);
	}
	LinkPrint(&L);

	HeadPop(&L);
	LinkPrint(&L);

	TailPop(&L);
	LinkPrint(&L);

	Node* pos = LinkFind(&L, 5);
	printf("%d\n", pos->data);

	LinkInsert(pos, 100);
	LinkPrint(&L);

	LinkDelete(pos->prev);
	LinkPrint(&L);

	LinkDestroy(&L);
}

int main()
{
	testLink();

	system("pause");
	return 0;
}