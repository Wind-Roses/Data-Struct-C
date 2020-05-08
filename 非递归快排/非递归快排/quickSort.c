#define _CRT_SECURE_NO_WARNINGS 1

#include"quickSort.h"
#include"stack.h"
#include"queue.h"

void swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

//�Ż�begin mid end��ֵȡ��ֵ
void axialValue(int* array, int begin, int end)
{
	int mid = begin + (end - begin) / 2;

	if (array[begin] <= array[mid])
	{
		if (array[mid] <= array[end])
		{
			swap(array, begin, mid);
			return;
		}
		else
		{
			if (array[begin] >= array[end])
				return;
			else
			{
				swap(array, begin, end);
				return;
			}
		}
	}
	else
	{
		if (array[mid] >= array[end])
		{
			swap(array, begin, mid);
			return;
		}
		else
		{
			if (array[begin] <= array[end])
				return;
			else
			{
				swap(array, begin, end);
				return;
			}
		}
	}
}

int partion1(int* array, int begin, int end)
{
	axialValue(array, begin, end);

	int key = array[begin];
	int start = begin;

	while (begin < end)
	{
		//�Ӻ���ǰ�ҵ�һ��С��key��ֵ
		while (begin < end && array[end] >= key)
			end--;
		//��ǰ����ҵ�һ������key��ֵ
		while (begin < end && array[begin] <= key)
			begin++;
		//��ֵ����
		swap(array, begin, end);
	}
	//start��begin����
	swap(array, start, begin);

	return begin;
}

int partion2(int* array, int begin, int end)
{
	axialValue(array, begin, end);

	int key = array[begin];

	while (begin < end)
	{
		//�Ӻ���ǰ�ҵ�һ��С��key��ֵ
		while (begin < end && array[end] >= key)
			end--;
		//����begin
		array[begin] = array[end];
		//��ǰ����ҵ�һ������key��ֵ
		while (begin < end && array[begin] <= key)
			begin++;
		//����end
		array[end] = array[begin];
	}
	//��key����begin
	array[begin] = key;

	return begin;
}

int partion3(int* array, int begin, int end)
{
	axialValue(array, begin, end);

	int prev = begin;      //���һ��С�ڻ�׼ֵ��λ��
	int cur = prev + 1;    //��һ��С�ڻ�׼ֵ��λ��
	int key = array[begin];

	while (cur <= end)
	{
		//curС��key�����ң�prev cur������
		if (array[cur] < key && ++prev != cur)
		{
			swap(array, prev, cur);
		}
		//���������һ��������������cur���
		cur++;
	}
	//begin��prev����
	swap(array, begin, prev);

	return prev;
}

//ջʵ��
//void quickSort(int* array, int begin, int end)
//{
//	Stack s;
//
//	stackInit(&s, end + 1);
//
//	//����������ջ�������е�һ������
//	if (begin < end)
//	{
//		stackPush(&s, end);
//		stackPush(&s, begin);
//	}
//
//	//��ջ���գ�������ջ
//	while (stackEmpty(&s) != 1)
//	{
//		//��ȡջ������
//		begin = getTop(&s);
//		stackPop(&s);
//		end = getTop(&s);
//		stackPop(&s);
//
//		//����
//		int keyPos = partion3(array, begin, end);
//
//		//����������
//		//���ʣ1��Ԫ�أ�����Ҫ����
//		if (keyPos + 1 < end)
//		{
//			stackPush(&s, end);
//			stackPush(&s, keyPos + 1);
//		}
//		//����������
//		//���ʣ1��Ԫ�أ���������
//		if (begin < keyPos - 1)
//		{
//			stackPush(&s, keyPos - 1);
//			stackPush(&s, begin);
//		}
//	}
//}

//����ʵ��
void quickSort(int* array, int begin, int end)
{
	Queue q;

	queueInit(&q);

	if (begin < end)
	{
		queuePush(&q, begin);
		queuePush(&q, end);
	}

	while (queueEmpty(&q) != 1)
	{
		//��ȡ��������
		begin = getFront(&q);
		queuePop(&q);
		end = getFront(&q);
		queuePop(&q);

		//����
		int keyPos = partion3(array, begin, end);

		//�����������
		if (begin < keyPos - 1)
		{
			queuePush(&q, begin);
			queuePush(&q, keyPos - 1);
		}
		//���������
		if (keyPos + 1 < end)
		{
			queuePush(&q, keyPos + 1);
			queuePush(&q, end);
		}
	}
}