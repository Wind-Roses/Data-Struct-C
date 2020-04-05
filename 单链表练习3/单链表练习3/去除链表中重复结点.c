#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。
//例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

struct ListNode{
	int val;
	struct ListNode *next;
};

struct ListNode* deleteDuplication(struct ListNode* pHead)
{

	struct ListNode *cur, *prev, *next, *front, *tmp;

	if (!pHead || !pHead->next)
	{
		return pHead;
	}

	front = (struct ListNode*)malloc(sizeof(struct ListNode*));
	front->next = pHead;
	prev = front;
	cur = pHead;
	next = cur->next;

	while (next)
	{
		if (cur->val != next->val)
		{
			next = next->next;
			cur = cur->next;
			prev = prev->next;
		}
		else
		{
			while (next && next->val == cur->val)
			{
				next = next->next;
			}
			while (cur != next)
			{
				tmp = cur->next;
				prev->next = tmp;
				free(cur);
				cur = tmp;
			}
		}

		if (next)
		{
			next = cur->next;
		}
	}

	pHead = front->next;
	free(front);

	return pHead;
}