#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int Type;
typedef struct Node
{
	Type data;
	struct Node* next;
	struct Node* prev;
}Node;
typedef struct Link
{
	Node* head;
}Link;

//��ʼ��
void LinkInit(Link* L);

//�����ڵ�
Node* CreateNode(Type data);

//ͷ��
void HeadPush(Link* L, Type data);

//β��
void TailPush(Link* L, Type data);

//��posλ��ǰ����
void LinkInsert(Node* pos, Type data);

//ͷɾ
void HeadPop(Link* L);

//βɾ
void TailPop(Link* L);

//ɾ��posλ��Ԫ��
void LinkDelete(Node* pos);

//����
Node* LinkFind(Link* L, Type data);

//��ӡ
void LinkPrint(Link* L);

//����
void LinkDestroy(Link* L);
