#define _CRT_SECURE_NO_WARNINGS 1
#include"CircleQueue.h"

//��ʼ��
void CircleQueueInit(CircleQueue* cq, int k)
{
	cq->array = (CDataType*)malloc(sizeof(CDataType) * (k + 1));

	cq->capacity = k;
	cq->front = cq->rear = 0;
}

//���
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

//����
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

//��ȡ����Ԫ��
CDataType GetFrontElement(CircleQueue* cq)
{
	return cq->array[cq->front];
}

//��ȡ��βԪ��
CDataType GetRearElement(CircleQueue* cq)
{
	if (cq->rear == 0)
	{
		return cq->array[cq->capacity];
	}

	return cq->array[cq->rear - 1];
}

//��ЧԪ�ظ���
int CircleQueueSize(CircleQueue* cq)
{
	return (cq->rear - cq->front + cq->capacity + 1) % (cq->capacity + 1);
}

//�п�
int CircleQueueEmpty(CircleQueue* cq)
{
	if (cq->front == cq->rear)
	{
		return 1;
	}

	return 0;
}

//����
int CircleQueueFull(CircleQueue* cq)
{
	if ((cq->rear - cq->front + cq->capacity + 1) % (cq->capacity + 1) == cq->capacity)
	{
		return 1;
	}

	return 0;
}

//����
void CircleQueueDestroy(CircleQueue* cq)
{
	free(cq->array);
}