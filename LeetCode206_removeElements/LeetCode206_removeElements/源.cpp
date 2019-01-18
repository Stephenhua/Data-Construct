# include <iostream>
# include <algorithm>
# include <vector>
using namespace std;
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){}
};
//===============
//遍历节点
//================
ListNode* removeElements(ListNode* head, int val)
{
	ListNode *dummy=new ListNode(-1),*pre=dummy;//定义一个空的指针节点，放在前面
	dummy->next = head;//dummy指针指向下一个头节点
	while (pre->next)//判断下一个节点是否为空
	{
		if (pre->next->val == val)//如果查找到了符合原节点的值，则进行下一步的判断
		{
			ListNode *t = pre->next;//建立新的节点指针
			pre->next = t->next;//将前一个节点的连接指向下下一个节点，跳过中间相等的节点
			t->next = NULL;//将t的下一个指针指向空指针
		}
		else 
		{
			pre = pre->next;//如果不是当前节点的指针，则指向下一个节点的指针
		}
	}
	return dummy->next;
}
//=============================
//递归调用
//==============================

LsitNdode * removeElements(ListNode* head, int val)
{
	if (!head)
		return NULL;
	head->next = removeElements(head->next, val);
	return head->val == val ? head->next : head;
}
//=============================
//遍历节点
//==============================
class Solution{
public:
	ListNode * removeElements(ListNode *head, int val)
	{
		if (head == NULL)
			return head;
		//判断开头的节点，如果头节点与val值相等，那么将其删除，结点值不相等
		while ((head != NULL)&&( head->val == val))
			head = head.val;
		if (head == NULL)
		{
			return head;
		}
		//建立两个链表指针，分别指向当前节点和下一个节点
		ListNode *temp = head->next;
		ListNode* pre = head;

		while (temp != NULL)//判断当前节点是否为空
		{
			if (temp->next == NULL)//如果当前节点的下一个节点为空，那么执行下面操作
			{
				if (temp->val != val)
					break;
				pre->next = NULL;
				break;
			}
			if ((temp != NULL) && (temp->val == val))//如果节点处于中间位置，则执行下面的操作
			{
				int value = temp->next->val;
				temp->val = value;;
				temp->next = temp->next->next;
			}
			else
			{
				pre = temp;
				temp = temp->next;
			}
		}
		return head;

	}
};

//=========================================
//遍历节点
//=========================================
struct ListNode* removeElements(struct ListNode *head, int val)
{
	struct ListNode* cur = head;
	struct ListNode * prev = NULL;
	struct ListNode* next;
	
	while (cur)
	{
		if (cur->val == val)
		{
			next = cur->next;
			free(cur);
			cur = next;
			if (prev = NULL)
			{
				head = next;
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
		return head;

	}
}