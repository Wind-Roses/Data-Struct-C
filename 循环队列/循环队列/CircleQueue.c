#define _CRT_SECURE_NO_WARNINGS 1
#include"CircleQueue.h"

//初始化
void CircleQueueInit(CircleQueue* cq, int k)
{
	cq->array = (CDataType*)malloc(sizeof(CDataType) * (k + 1));

	cq->capacity = k;
	cq->front = cq->rear = 0;
}

//入队
void CircleQueuePush(CircleQueue* cq, CDataType data)
{
	if (cq->rear == cq->capacity)
	{
		cq->rear = 0;
		cq->array[cq->rear++] = data;
	}
	else
	{
		cq->array[cq->rear++] = data;
	}
}

//出队
void CircleQueuePop(CircleQueue* cq)
{
	if (cq->front == cq->capacity)
	{
		cq->front = 0;
	}
	else
	{
		cq->front++;
	}
}

//获取队首元素
CDataType GetFrontElement(CircleQueue* cq)
{
	return cq->array[cq->front];
}

//获取队尾元素
CDataType GetRearElement(CircleQueue* cq)
{
	if (cq->rear == 0)
	{
		return cq->array[cq->capacity];
	}

	return cq->array[cq->rear - 1];
}

//有效元素个数
int CircleQueueSize(CircleQueue* cq)
{
	return (cq->rear - cq->front + cq->capacity + 1) % (cq->capacity + 1);
}

//判空
int CircleQueueEmpty(CircleQueue* cq)
{
	if (cq->front == cq->rear)
	{
		return 1;
	}

	return 0;
}

//判满
int CircleQueueFull(CircleQueue* cq)
{
	if ((cq->rear - cq->front + cq->capacity + 1) % (cq->capacity + 1) == cq->capacity)
	{
		return 1;
	}

	return 0;
}

//销毁
void CircleQueueDestroy(CircleQueue* cq)
{
	free(cq->array);
}