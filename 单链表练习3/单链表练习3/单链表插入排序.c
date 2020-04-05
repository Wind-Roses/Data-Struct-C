#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//对链表进行插入排序

struct ListNode {
	int val;
	struct ListNode *next;
	
};

struct ListNode* insertionSortList(struct ListNode* head) {
	struct ListNode *prev, *cur, *next, *front;

	if (!head || !head->next)
	{
		return head;
	}

	struct ListNode* newH = (struct ListNode*)malloc(sizeof(struct ListNode));
	newH->next = head;
	prev = head;
	cur = head->next;

	while (cur)
	{
		if (cur->val >= prev->val)
		{
			prev = prev->next;
			cur = cur->next;
		}
		else
		{
			next = cur->next;
			head = newH->next;
			front = newH;

			while (cur->val >= head->val)
			{
				head = head->next;
				front = front->next;
			}

			front->next = cur;
			cur->next = head;
			prev->next = next;
			cur = next;
		}
	}

	head = newH->next;
	free(newH);

	return head;
}