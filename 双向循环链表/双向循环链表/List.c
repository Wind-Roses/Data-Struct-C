#define _CRT_SECURE_NO_WARNINGS 1
#include"List.h"

//��ʼ��
void LinkInit(Link* L)
{
	L->head = (Node*)malloc(sizeof(Node));

	L->head->data = 0;
	L->head->next = L->head;
	L->head->prev = L->head;
}

//�����ڵ�
Node* CreateNode(Type data)
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->next = NULL;
	node->prev = NULL;

	return node;
}

//ͷ��
void HeadPush(Link* L, Type data)
{
	/*Node* node = CreateNode(data);
	Node* next = L->head->next;

	node->next = next;
	L->head->next = node;

	next->prev = node;
	node->prev = L->head;*/

	LinkInsert(L->head->next, data);
}

//β��
void TailPush(Link* L, Type data)
{
	/*Node* node = CreateNode(data);
	Node* last = L->head->prev;

	last->next = node;
	node->next = L->head;

	node->prev = last;
	L->head->prev = node;*/

	LinkInsert(L->head, data);
}

//��posλ��ǰ����
void LinkInsert(Node* pos, Type data)
{
	Node* node = CreateNode(data);
	Node* prev = pos->prev;

	prev->next = node;
	node->next = pos;

	pos->prev = node;
	node->prev = prev;
}

//ͷɾ
void HeadPop(Link* L)
{
	if (L->head->next == L->head)
	{
		return;
	}

	/*Node* cur = L->head->next;
	Node* next = cur->next;

	L->head->next = next;
	next->prev = L->head;

	free(cur);*/

	LinkDelete(L->head->next);
}

//βɾ
void TailPop(Link* L)
{
	if (L->head->next == L->head)
	{
		return;
	}

	/*Node* last = L->head->prev;
	Node* prev = last->prev;

	L->head->prev = prev;
	prev->next = L->head;

	free(last);*/

	LinkDelete(L->head->prev);
}

//ɾ��posλ��Ԫ��
void LinkDelete(Node* pos)
{
	if (pos->next == pos)
	{
		return;
	}

	Node* next = pos->next;
	Node* prev = pos->prev;

	prev->next = next;
	next->prev = prev;

	free(pos);
}

//����
Node* LinkFind(Link* L, Type data)
{
	Node* cur = L->head->next;

	while (cur != L->head)
	{
		if (cur->data == data)
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

//��ӡ
void LinkPrint(Link* L)
{
	Node* cur = L->head->next;

	while (cur != L->head)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//����
void LinkDestroy(Link* L)
{
	Node* cur = L->head->next;

	while (cur != L->head)
	{
		Node* next = cur->next;

		free(cur);
		cur = next;
	}

	free(L->head);
	L->head = NULL;
}