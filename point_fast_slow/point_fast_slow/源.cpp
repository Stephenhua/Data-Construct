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
//�ж������Ƿ���ڻ�
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
		slow = slow->next;//��ָ��ÿһ��ǰ��һ��
		fast = fast->next->next;//��ָ��ÿһ��ǰ������
		if (slow == fast)//��������������ڻ�
		{
			return true;
		}
	}
	return false;
}

//=============================
//Ѱ���������λ��
//=============================
while (fast &&slow)
{
	if (fast->next == NULL)//���fast����һ���ڵ�Ϊ�սڵ㣬���ʾΪ����������λ�������׵õ�
	{
		return slow->data;
	}
	else if (fast->next != NULL&&fast->next->next == NULL)//��������Ϊż����ʱ������λ��Ϊ�м�����ֵ�����ƽ��
	{

		return (slow->data + slow->next->data) / 2;
	}
	else//�����Ҫ��������ѭ����
	{
		fast = fast->next->next;
		slow = slow->next;

	}

}

//=============================
//��������еĵ�����K���ڵ�
//=============================

ListNode *RGETKthNode(ListNode *pHead, undigned int k)
{
	if (k == 0 || pHead == NULL)//��1��ʼ���м�������kΪ0��������Ϊ�շ���NULL��
	{
		return NULL;
	}
	ListNode *pAhead = pHead;
	ListNode *pBehind = pHead;
	for (int i = 0; i < k - 1; i++)
	{
		pAhead = pAhead->next;
		if (pAhead == NULL)//��������С��kʱ�򣬷���null
			return NULL;
	}
	while (pAhead->next != NULL)//ǰ������ָ��ͬʱ�ߣ�֪��ǰ����Ǹ�ָ���ߵ����ʱ����ô�����ָ�����ָ����kd��λ��
	{
		pBehind = pBehead->next;
		pAhead = pHead->next;

	}

	return pBehind;//�����ָ����ָ���λ�þ��ǵ�����K���ڵ�
}

//=============================
//�ж������Ƿ�Ϊ��״����������ڻ�����ô�Ҵ����
//=============================

node* findLoopPort(node *head)
{
	node *fast, *slow;
	fast = slow = head;
	while (fast&&fast->next)
	{
		//��һ�����ж������Ƿ���ڻ�
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)//������ڻ�
		{
			break;
		}
	}
	if ((fast == NULL) && (fast->next == NULL))
	{
		//�������ڻ�
		return NULL;
	}

	//Ѱ�һ�����ڵ�
	slow = head;//��slow�ص��������㣬fast����������
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}
//=============================
//�ж������������Ƿ��ཻ������ཻ���ҵ����ǵĵ�һ��������
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

		//*p����ָ��̵�����qָ�򳤵�����

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
		while (p�� = q)
		{
			p = p->next;
			q = q->next;
		}
		printf("�ཻ�ĵ�һ���ڵ���: %d\n", p->data);
	}

}