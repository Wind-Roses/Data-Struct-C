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

//初始化
void LinkInit(Link* L);

//创建节点
Node* CreateNode(Type data);

//头插
void HeadPush(Link* L, Type data);

//尾插
void TailPush(Link* L, Type data);

//在pos位置前插入
void LinkInsert(Node* pos, Type data);

//头删
void HeadPop(Link* L);

//尾删
void TailPop(Link* L);

//删除pos位置元素
void LinkDelete(Node* pos);

//查找
Node* LinkFind(Link* L, Type data);

//打印
void LinkPrint(Link* L);

//销毁
void LinkDestroy(Link* L);
