# include <iostream>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

using namespace std;
typedef struct node
{
	int num;
	struct node *next;
}Node;

//=============================
//判断链表是否存在环
//=============================
bool HasCircle(Node *head)
{
	if (head == NULL)
	{
		return false;
	}
	Node *slow = head, *fast = head;
	while (fast != NULL&&fast->next != NULL)
	{
		slow = slow->next;//慢指针每一次前进一步
		fast = fast->next->next;//快指针每一次前进两步
		if (slow == fast)//相遇，则表明存在环
		{
			return true;
		}
	}
	return false;
}

//=============================
//寻找链表的中位数
//=============================
while (fast &&slow)
{
	if (fast->next == NULL)//如果fast的下一个节点为空节点，则表示为基数，则中位数很容易得到
	{
		return slow->data;
	}
	else if (fast->next != NULL&&fast->next->next == NULL)//对于链表为偶数个时，则中位数为中间两个值得求和平均
	{

		return (slow->data + slow->next->data) / 2;
	}
	else//否则就要进行链表循环，
	{
		fast = fast->next->next;
		slow = slow->next;

	}

}

//=============================
//输出链表中的倒数第K个节点
//=============================

ListNode *RGETKthNode(ListNode *pHead, undigned int k)
{
	if (k == 0 || pHead == NULL)//从1开始进行计数，若k为0或者链表为空返回NULL；
	{
		return NULL;
	}
	ListNode *pAhead = pHead;
	ListNode *pBehind = pHead;
	for (int i = 0; i < k - 1; i++)
	{
		pAhead = pAhead->next;
		if (pAhead == NULL)//当链表长度小于k时候，返回null
			return NULL;
	}
	while (pAhead->next != NULL)//前后两个指针同时走，知道前面的那个指针走到最后时，那么后面的指针则就指向倒数kd的位置
	{
		pBehind = pBehead->next;
		pAhead = pHead->next;

	}

	return pBehind;//后面的指针所指向的位置就是倒数第K个节点
}

//=============================
//判断链表是否为环状链表，如果存在环，那么找打环入口
//=============================

node* findLoopPort(node *head)
{
	node *fast, *slow;
	fast = slow = head;
	while (fast&&fast->next)
	{
		//第一步：判断链表是否存在环
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)//链表存在环
		{
			break;
		}
	}
	if ((fast == NULL) && (fast->next == NULL))
	{
		//链表不存在环
		return NULL;
	}

	//寻找环的入口点
	slow = head;//让slow回到链表的起点，fast留在相遇点
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
//=============================
//判断两个单链表是否相交，如果相交，找到他们的第一个公共点
//=============================

void Is_a2List_Intersect(LinkList L1, Linklsit L2)
{
	if (L1 == NULL || L2 == NULL)
	{
		exit(ERROR);
	}

	LinkList p = L1;
	LinkList q = L2;

	int L1_Length = 0;
	int L2_Length = 0;
	int len = 0;

	while (p->next)
	{
		L1_Length++;
		p = p->next;
	}
	while (q->next)
	{
		L2_Length++;
		q = q->nxt;
	}

	printf("p:%d\n", p);
	printf("q:%d\n", q);

	printf("L1_length:=%d\n", L1_length);
	printf("L2_length: = %d\n", L2_length);

	if (p == q)
	{
		printf("xiang jiao \n");

		//*p重新指向短的链表，q指向长的链表

		if (L1_length > L2_length)
		{
			len = L1_length - L2_length;
			p = L2;
			q = L1;
		}
		else
		{
			len = L2_length - L1_length;
			p = L1;
			q = L2;
		}
		while (len)
		{
			q = q->next;
			len--;
		}
		while (p！ = q)
		{
			p = p->next;
			q = q->next;
		}
		printf("相交的第一个节点是: %d\n", p->data);
	}

}