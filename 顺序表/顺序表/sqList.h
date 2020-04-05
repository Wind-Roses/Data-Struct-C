#pragma once
#include<stdio.h>
#include<stdlib.h>

#define SQLIST_SPACE 20
#define NEW_SPACE 4

typedef int DataType;
typedef struct SqList
{
	DataType* array;
	size_t size;
	size_t capacity;
}sqList;

//初始化
void SqListInit(sqList* sl);
//扩容
void Expand(sqList* sl);
//在pos位置插入
void sqListInsert(sqList* sl, int pos, DataType value);
//头插
void HeadPush(sqList* sl, DataType value);
//尾插
void TailPush(sqList* sl, DataType value);
//在pos位置删除
void sqListDelete(sqList* sl, int pos);
//头删
void HeadPop(sqList* sl);
//尾删
void TailPop(sqList* sl);
//查找
int SqListFind(sqList* sl, DataType value);
//打印
void SqListPrint(sqList* sl);