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
//�����ڵ�
//================
ListNode* removeElements(ListNode* head, int val)
{
	ListNode *dummy=new ListNode(-1),*pre=dummy;//����һ���յ�ָ��ڵ㣬����ǰ��
	dummy->next = head;//dummyָ��ָ����һ��ͷ�ڵ�
	while (pre->next)//�ж���һ���ڵ��Ƿ�Ϊ��
	{
		if (pre->next->val == val)//������ҵ��˷���ԭ�ڵ��ֵ���������һ�����ж�
		{
			ListNode *t = pre->next;//�����µĽڵ�ָ��
			pre->next = t->next;//��ǰһ���ڵ������ָ������һ���ڵ㣬�����м���ȵĽڵ�
			t->next = NULL;//��t����һ��ָ��ָ���ָ��
		}
		else 
		{
			pre = pre->next;//������ǵ�ǰ�ڵ��ָ�룬��ָ����һ���ڵ��ָ��
		}
	}
	return dummy->next;
}
//=============================
//�ݹ����
//==============================

LsitNdode * removeElements(ListNode* head, int val)
{
	if (!head)
		return NULL;
	head->next = removeElements(head->next, val);
	return head->val == val ? head->next : head;
}
//=============================
//�����ڵ�
//==============================
class Solution{
public:
	ListNode * removeElements(ListNode *head, int val)
	{
		if (head == NULL)
			return head;
		//�жϿ�ͷ�Ľڵ㣬���ͷ�ڵ���valֵ��ȣ���ô����ɾ�������ֵ�����
		while ((head != NULL)&&( head->val == val))
			head = head.val;
		if (head == NULL)
		{
			return head;
		}
		//������������ָ�룬�ֱ�ָ��ǰ�ڵ����һ���ڵ�
		ListNode *temp = head->next;
		ListNode* pre = head;

		while (temp != NULL)//�жϵ�ǰ�ڵ��Ƿ�Ϊ��
		{
			if (temp->next == NULL)//�����ǰ�ڵ����һ���ڵ�Ϊ�գ���ôִ���������
			{
				if (temp->val != val)
					break;
				pre->next = NULL;
				break;
			}
			if ((temp != NULL) && (temp->val == val))//����ڵ㴦���м�λ�ã���ִ������Ĳ���
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
//�����ڵ�
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