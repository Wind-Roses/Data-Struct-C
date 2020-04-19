#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef int HDataType;
typedef struct Heap
{
	HDataType* array;
	size_t size;
	size_t capacity;
}Heap;

//�Ѵ���
void HeapCreate(Heap* hp, HDataType* arr, int size);

//С�������µ����㷨
void LittleShiftDown(HDataType* array, size_t size, int parent);

//С�������ϵ����㷨
void LittleShiftUp(HDataType* array, int child);

//��ȡ�Ѷ�Ԫ��
HDataType HeapTop(Heap* hp);

//����
void HeapPush(Heap* hp, HDataType data);

//����
void HeapPop(Heap* hp);

//�п�
int HeapEmpty(Heap* hp);

//�Ѵ�ӡ
void HeapPrint(Heap* hp);