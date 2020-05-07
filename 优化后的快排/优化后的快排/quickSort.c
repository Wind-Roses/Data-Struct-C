#define _CRT_SECURE_NO_WARNINGS 1

#include"quickSort.h"

void swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

//�Ż�����β���м�λ������ֵѡ���м��ֵ����ֵ
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

//hora��
int partion1(int* array, int begin, int end)
{
	//����ֵ�ŵ�begin��
	axialValue(array, begin, end);
	int key = array[begin];
	int start = begin;

	//����
	while (begin < end)
	{
		//�Ӻ���ǰ�ҵ�һ��С��key��ֵ
		while (array[end] >= key && begin < end)
			end--;
		//��ǰ����ҵ�һ������key��ֵ
		while (array[begin] <= key && begin < end)
			begin++;

		//����begin��end
		swap(array, begin, end);
	}
	//��begin==endʱ������key�ʹ�λ�õ�ֵ
	swap(array, start, begin);

	return begin;
}

//�ڿӷ�
int partion2(int* array, int begin, int end)
{
	//����ֵ�ŵ�begin��
	axialValue(array, begin, end);
	int key = array[begin];

	//����
	while (begin < end)
	{
		//�Ӻ���ǰ�ҵ�һ��С��key��λ��
		while (array[end] >= key && begin < end)
			end--;
		array[begin] = array[end];
		//��ǰ����ҵ�һ������key��ֵ
		while (array[begin] <= key && begin < end)
			begin++;
		array[end] = array[begin];
	}
	//���key�ŵ�����λ��
	array[begin] = key;

	return begin;
}

//ǰ��ָ�뷨
int partion3(int* array, int begin, int end)
{
	//����ֵ�ŵ�begin��
	axialValue(array, begin, end);
	int prev = begin;        //���һ��С�ڻ�׼ֵ��λ��
	int cur = prev + 1;      //��һ��С�ڻ�׼ֵ��λ��
	int key = array[begin];

	while (cur <= end)
	{
		//���curС�ڻ�׼ֵ������prev��cur��������ֵ����
		if (array[cur] < key && ++prev != cur)
			swap(array, prev, cur);
		//����
		//cur����key��cur��ǰ��
		//curС��key, prev��cur������һ����ǰ
		cur++;
	}
	//����key��prev
	swap(array, begin, prev);

	return prev;
}

void quickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;

	//��һ����ֵ
	int keyPos = partion3(array, begin, end);

	quickSort(array, begin, keyPos - 1);
	quickSort(array, keyPos + 1, end);
}