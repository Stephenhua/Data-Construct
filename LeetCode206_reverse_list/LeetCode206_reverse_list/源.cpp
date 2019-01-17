# include <iostream>
# include <algorithm>
using namespace std;
struct ListNode{
	int val;
	ListNode *next;

	ListNode(int x) :val(x), next(NULL){}
};

ListNode * reverseList(ListNode* head)//µü´ú·¨
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	else
	{
		ListNode *p1 = head;
		ListNode *p2 = head->next;
		ListNode*p3 = p2->next;
		while (p2)
		{
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
		}
		head->next = NULL;
		head = p1;
		return head;
	}
}

ListNode* reverseList(ListNode* head)//µÝ¹é·¨
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	else
	{
		ListNode* new_head = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return new_head;
	}
}