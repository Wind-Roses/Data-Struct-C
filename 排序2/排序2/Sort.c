#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

//交换
void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

//冒泡排序
void BubbleSort(int* array, int n)
{
	int flag = 0;

	for (int end = n - 1; end > 0; end--)
	{
		for (int j = 0; j < end; j++)
		{
			if (array[j] > array[j + 1])
			{
				Swap(array, j, j + 1);
				flag = 1;
			}
		}

		if (flag == 0)
			break;
	}
}

//第一种划分方法：hora法
int Partion1(int* array, int begin, int end)
{
	int key = begin;

	//重复查找交换，直到begin等于end
	while (begin < end)
	{
		//先从后向前找第一个小于key的值
		while (end > begin && array[end] >= array[key])
			end--;
		//再从前向后找第一个大于key的值
		while (begin < end && array[begin] <= array[key])
			begin++;

		//将两值进行交换
		Swap(array, begin, end);
	}

	//最后将key位置的值与begin位置互换
	Swap(array, key, begin);

	return begin;
}

//填坑法
int Partion2(int* array, int begin, int end)
{
	int key = array[begin];

	while (begin < end)
	{
		//从后向前遍历找到第一个小于key的值的位置
		while (begin < end && array[end] >= key)
			end--;
		//填坑
		array[begin] = array[end];

		//从前向后找到第一个大于key的值的位置
		while (begin < end && array[begin] <= key)
			begin++;
		//填坑
		array[end] = array[begin];
	}

	//最后让begin位置的值等于key
	array[begin] = key;

	return begin;
}

//前后指针法
int Partion3(int* array, int begin, int end)
{
	int prev = begin;     //最后一个小于key值的位置
	int cur = prev + 1;   //下一个小于key值的位置
	int key = array[begin];

	//cur向后走
	while (cur <= end)
	{
		//如果cur比key小，并且prev与cur不连续，则证明prev与cur之间有大于key的值
		//故第一个大于key的值与cur交换
		if (array[cur] < key && ++prev != cur)
			Swap(array, prev, cur);

		cur++;
	}

	Swap(array, begin, prev);

	return prev;
}

//快速排序
void QuickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;

	//一轮排完
	int ret = Partion3(array, begin, end);

	//根据key值分两部分
	//左边排序
	QuickSort(array, begin, ret - 1);
	//右边排序
	QuickSort(array, ret + 1, end);
}

void Print(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}