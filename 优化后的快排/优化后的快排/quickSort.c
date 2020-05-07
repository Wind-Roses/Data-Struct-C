#define _CRT_SECURE_NO_WARNINGS 1

#include"quickSort.h"

void swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

//优化，首尾和中间位置三个值选择中间的值做轴值
void axialValue(int* array, int begin, int end)
{
	int mid = begin + (end - begin) / 2;

	if (array[begin] < array[mid])
	{
		if (array[mid] <= array[end])
		{
			swap(array, begin, mid);
			return;
		}
		else
		{
			if (array[begin] < array[end])
			{
				swap(array, begin, end);
				return;
			}
			return;
		}
	}
	else if (array[begin] > array[mid])
	{
		if (array[begin] <= array[end])
			return;
		else
		{
			if (array[mid] < array[end])
			{
				swap(array, begin, end);
				return;
			}
			else
			{
				swap(array, begin, mid);
				return;
			}
		}
	}
	else
		return;
}

//hora法
int partion1(int* array, int begin, int end)
{
	//将轴值放到begin处
	axialValue(array, begin, end);
	int key = array[begin];
	int start = begin;

	//排序
	while (begin < end)
	{
		//从后向前找第一个小于key的值
		while (array[end] >= key && begin < end)
			end--;
		//从前向后找第一个大于key的值
		while (array[begin] <= key && begin < end)
			begin++;

		//交换begin和end
		swap(array, begin, end);
	}
	//当begin==end时，交换key和此位置的值
	swap(array, start, begin);

	return begin;
}

//挖坑法
int partion2(int* array, int begin, int end)
{
	//将轴值放到begin处
	axialValue(array, begin, end);
	int key = array[begin];

	//排序
	while (begin < end)
	{
		//从后向前找第一个小于key的位置
		while (array[end] >= key && begin < end)
			end--;
		array[begin] = array[end];
		//从前向后找第一个大于key的值
		while (array[begin] <= key && begin < end)
			begin++;
		array[end] = array[begin];
	}
	//最后将key放到结束位置
	array[begin] = key;

	return begin;
}

//前后指针法
int partion3(int* array, int begin, int end)
{
	//将轴值放到begin处
	axialValue(array, begin, end);
	int prev = begin;        //最后一个小于基准值的位置
	int cur = prev + 1;      //下一个小于基准值的位置
	int key = array[begin];

	while (cur <= end)
	{
		//如果cur小于基准值，并且prev与cur不连续，值互换
		if (array[cur] < key && ++prev != cur)
			swap(array, prev, cur);
		//否则
		//cur大于key，cur向前走
		//cur小于key, prev和cur连续，一起向前
		cur++;
	}
	//交换key和prev
	swap(array, begin, prev);

	return prev;
}

void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;

	//上一个轴值
	int keyPos = partion3(array, begin, end);

	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}