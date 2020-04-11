#define _CRT_SECURE_NO_WARNINGS 1
#include"Queue Stack.h"

void QueueInit(Queue* q)
{
	q->head = q->tail = NULL;
	q->size = 0;
}

QNode* CreateQNode(QSDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->next = NULL;
	node->data = data;

	return node;
}

void QueuePush(Queue* q, QSDataType data)
{
	QNode* node = CreateQNode(data);
	if (q->head == NULL)
	{
		q->head = node;
		q->tail = node;
	}
	else
	{
		q->tail->next = node;
		q->tail = node;

	}
	q->size++;
}

void QueuePop(Queue* q)
{
	if (q->head == NULL)
	{
		return;
	}

	QNode* next = q->head->next;
	free(q->head);
	q->head = next;
	if (q->head == NULL)
	{
		q->tail = NULL;
	}
	q->size--;
}

QSDataType GetHead(Queue* q)
{
	return q->head->data;
}

QSDataType GetTail(Queue* q)
{
	return q->tail->data;
}

int QueueEmtpy(Queue* q)
{
	if (q->head == NULL)
	{
		return 1;
	}

	return 0;
}

int QueueSize(Queue* q)
{
	return q->size;
}

void QueueDestory(Queue* q)
{
	QNode* cur = q->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->head = q->tail = NULL;
	q->size = 0;
}

QStack* StackCreate() {
	QStack* obj = (QStack*)malloc(sizeof(QStack));
	QueueInit(&obj->q);

	return obj;
}

void StackPush(QStack* obj, QSDataType x) {
	QueuePush(&obj->q, x);
}

int StackPop(QStack* obj) {
	int size = QueueSize(&obj->q);
	while (size > 1)
	{
		int top = GetHead(&obj->q);
		QueuePop(&obj->q);
		QueuePush(&obj->q, top);
		size--;
	}

	int ret = GetHead(&obj->q);
	QueuePop(&obj->q);

	return ret;
}

int StackTop(QStack* obj) {
	return GetTail(&obj->q);
}

int StackEmpty(QStack* obj) {
	return QueueEmtpy(&obj->q);
}

void StackDestory(QStack* obj) {
	QueueDestory(&obj->q);
	free(obj);
}