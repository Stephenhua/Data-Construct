# include <iostream>
# include <stack>

using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};

class Solution
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (!headA &&!headB)
			return NULL;

		int lenA = getLength(headA), lenB = getLength(headB);//caclculate A , B length;
		if (lenA - lenB > 0)//find the same node 
		{ 
			for (int i = 0; i < lenA - lenB; i++)
			{
				headA = headA->next;
			}
		}
		else
		{
			for (int i = 0; i < lenB - lenA;i++)
			{
				headB = headB->next;
			}
		}
		while (headA&&headB&&headA != headB)//if A and B is not euqal ,the nullptr is next move;
		{
			headA = headA->next;
			headB = headB->next;
		}
		return (headA &&headB) ? headA : headB;//if A and B is same ,retun the value of node ;
	}
	int getLength(ListNode * head)
	{
		int count = 0;
		while (head)
		{
			count++;
			head = head->next;
		}
		return count;
	}
};


class Solution1
{
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (!headA || !headB)
			return NULL;
		ListNode *a = headA, *b = headB;
		while (a != b)
		{
			a = a ? a->next : headB;
			b = b ? b->next : headA;
		}
		return a;
	}
};