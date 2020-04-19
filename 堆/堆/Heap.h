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

//堆创建
void HeapCreate(Heap* hp, HDataType* arr, int size);

//小根堆向下调整算法
void LittleShiftDown(HDataType* array, size_t size, int parent);

//小根堆向上调整算法
void LittleShiftUp(HDataType* array, int child);

//获取堆顶元素
HDataType HeapTop(Heap* hp);

//进堆
void HeapPush(Heap* hp, HDataType data);

//出堆
void HeapPop(Heap* hp);

//判空
int HeapEmpty(Heap* hp);

//堆打印
void HeapPrint(Heap* hp);