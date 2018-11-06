# include <iostream>
# include <list>
# include <algorithm>
using namespace std;

/*
LsitNode* mergeTwoLists(ListNode * l1, ListNode* l2)
{
	ListNoe *dummy = new ListNode(-1), *cur = dummy;
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			cur->next=l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}
		
	}
	cur = cur->next;
	return dummy->next;
}
LsitNode* mergeTwoLists(ListNode * l1, ListNode* l2)
{
	if (!l1)return l2;
	if (!l2) return l1;
	if (l1->val < l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}
*/
int main()
{
	list(int) l1= { 1, 2, 3, 6 };
	list(int) l2 = { 2, 4, 6 };
	ListNoe *dummy = new ListNode(-1), *cur = dummy;
	while (l1&&l2)
	{
		if (l1->val < l2->val)
		{
			cur->next = l1;
			l1 = l1->next;
		}
		else
		{
			cur->next = l2;
			l2 = l2->next;
		}

	}
	cur = cur->next;
	return dummy->next;
	for (iter = dummy.begin(); iter != dummy.end(); iter++)
	{
		cout << *dummy;
	}

}