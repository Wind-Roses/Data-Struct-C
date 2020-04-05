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

//��ʼ��
void SqListInit(sqList* sl);
//����
void Expand(sqList* sl);
//��posλ�ò���
void sqListInsert(sqList* sl, int pos, DataType value);
//ͷ��
void HeadPush(sqList* sl, DataType value);
//β��
void TailPush(sqList* sl, DataType value);
//��posλ��ɾ��
void sqListDelete(sqList* sl, int pos);
//ͷɾ
void HeadPop(sqList* sl);
//βɾ
void TailPop(sqList* sl);
//����
int SqListFind(sqList* sl, DataType value);
//��ӡ
void SqListPrint(sqList* sl);