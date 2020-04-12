#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef char DataType;
typedef struct Stack
{
	DataType* arr;
	int size;
	int capacity;
}Stack;

void StackInit(Stack* s, int k);

void StackPush(Stack* s, DataType data);

void StackPop(Stack* s);

DataType GetTop(Stack* s);

int StackEmpty(Stack* s);

void StackDestroy(Stack* s);

bool isValid(char * s);