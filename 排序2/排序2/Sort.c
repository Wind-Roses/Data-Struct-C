#define _CRT_SECURE_NO_WARNINGS 1

#include"Sort.h"

//����
void Swap(int* array, int i, int j)
{
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

//ð������
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

//��һ�ֻ��ַ�����hora��
int Partion1(int* array, int begin, int end)
{
	int key = begin;

	//�ظ����ҽ�����ֱ��begin����end
	while (begin < end)
	{
		//�ȴӺ���ǰ�ҵ�һ��С��key��ֵ
		while (end > begin && array[end] >= array[key])
			end--;
		//�ٴ�ǰ����ҵ�һ������key��ֵ
		while (begin < end && array[begin] <= array[key])
			begin++;

		//����ֵ���н���
		Swap(array, begin, end);
	}

	//���keyλ�õ�ֵ��beginλ�û���
	Swap(array, key, begin);

	return begin;
}

//��ӷ�
int Partion2(int* array, int begin, int end)
{
	int key = array[begin];

	while (begin < end)
	{
		//�Ӻ���ǰ�����ҵ���һ��С��key��ֵ��λ��
		while (begin < end && array[end] >= key)
			end--;
		//���
		array[begin] = array[end];

		//��ǰ����ҵ���һ������key��ֵ��λ��
		while (begin < end && array[begin] <= key)
			begin++;
		//���
		array[end] = array[begin];
	}

	//�����beginλ�õ�ֵ����key
	array[begin] = key;

	return begin;
}

//ǰ��ָ�뷨
int Partion3(int* array, int begin, int end)
{
	int prev = begin;     //���һ��С��keyֵ��λ��
	int cur = prev + 1;   //��һ��С��keyֵ��λ��
	int key = array[begin];

	//cur�����
	while (cur <= end)
	{
		//���cur��keyС������prev��cur����������֤��prev��cur֮���д���key��ֵ
		//�ʵ�һ������key��ֵ��cur����
		if (array[cur] < key && ++prev != cur)
			Swap(array, prev, cur);

		cur++;
	}

	Swap(array, begin, prev);

	return prev;
}

//��������
void QuickSort(int* array, int begin, int end)
{
	if (begin >= end)
		return;

	//һ������
	int ret = Partion3(array, begin, end);

	//����keyֵ��������
	//�������
	QuickSort(array, begin, ret - 1);
	//�ұ�����
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