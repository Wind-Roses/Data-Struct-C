#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node;
typedef struct LinkList
{
	Node* head;
}LinkList;

//初始化
void LinkListInit(LinkList* L);

//创建一个新节点
Node* CreateNewNode(DataType data);

//头插
void HeadPush(LinkList* L, DataType data);

//尾插
void TailPush(LinkList* L, DataType data);

//在pos之后插入节点
void LinkListInsert(Node* pos, DataType data);

//头删
void HeadPop(LinkList* L);

//尾删
void TailPop(LinkList* L);

//删除pos后的节点
void LinkListDelete(Node* pos);

//查找
Node* LinkListFind(LinkList* L, DataType data);

//打印
void LinkListPrint(LinkList* L);

//销毁
void LinkListDestroy(LinkList* L);