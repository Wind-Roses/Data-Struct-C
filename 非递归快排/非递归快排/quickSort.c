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

//优化begin mid end三值取中值
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
		//从后向前找第一个小于key的值
		while (begin < end && array[end] >= key)
			end--;
		//从前向后找第一个大于key的值
		while (begin < end && array[begin] <= key)
			begin++;
		//两值交换
		swap(array, begin, end);
	}
	//start与begin交换
	swap(array, start, begin);

	return begin;
}

int partion2(int* array, int begin, int end)
{
	axialValue(array, begin, end);

	int key = array[begin];

	while (begin < end)
	{
		//从后向前找第一个小于key的值
		while (begin < end && array[end] >= key)
			end--;
		//赋给begin
		array[begin] = array[end];
		//从前向后找第一个大于key的值
		while (begin < end && array[begin] <= key)
			begin++;
		//赋给end
		array[end] = array[begin];
	}
	//把key赋给begin
	array[begin] = key;

	return begin;
}

int partion3(int* array, int begin, int end)
{
	axialValue(array, begin, end);

	int prev = begin;      //最后一个小于基准值的位置
	int cur = prev + 1;    //下一个小于基准值的位置
	int key = array[begin];

	while (cur <= end)
	{
		//cur小于key，并且，prev cur不连续
		if (array[cur] < key && ++prev != cur)
		{
			swap(array, prev, cur);
		}
		//如果连续就一起向后，如果大于则cur向后
		cur++;
	}
	//begin和prev交换
	swap(array, begin, prev);

	return prev;
}

//栈实现
//void quickSort(int* array, int begin, int end)
//{
//	Stack s;
//
//	stackInit(&s, end + 1);
//
//	//左右区间入栈，并进行第一次排序
//	if (begin < end)
//	{
//		stackPush(&s, end);
//		stackPush(&s, begin);
//	}
//
//	//当栈不空，继续入栈
//	while (stackEmpty(&s) != 1)
//	{
//		//获取栈顶区间
//		begin = getTop(&s);
//		stackPop(&s);
//		end = getTop(&s);
//		stackPop(&s);
//
//		//划分
//		int keyPos = partion3(array, begin, end);
//
//		//先入右区间
//		//如果剩1个元素，则不需要排序
//		if (keyPos + 1 < end)
//		{
//			stackPush(&s, end);
//			stackPush(&s, keyPos + 1);
//		}
//		//再入左区间
//		//如果剩1个元素，不需排序
//		if (begin < keyPos - 1)
//		{
//			stackPush(&s, keyPos - 1);
//			stackPush(&s, begin);
//		}
//	}
//}

//队列实现
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
		//获取队首区间
		begin = getFront(&q);
		queuePop(&q);
		end = getFront(&q);
		queuePop(&q);

		//排序
		int keyPos = partion3(array, begin, end);

		//左区间先入队
		if (begin < keyPos - 1)
		{
			queuePush(&q, begin);
			queuePush(&q, keyPos - 1);
		}
		//右区间入队
		if (keyPos + 1 < end)
		{
			queuePush(&q, keyPos + 1);
			queuePush(&q, end);
		}
	}
}