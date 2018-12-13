#  include <iostream>
# include <list>
using namespace std;
/*
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL){ }
};
class Soultion{
public:
	ListNode* deleteDuplicates(ListNode* head)
	{
		ListNode* first = head;
		ListNode * current = first;
		if (first == 0)
		{
			return head;
		}
		while (true)
			{
				while (current->val == first->val)
				{
					current = current->next;
					if (current == 0)
					{
						first->next = 0;
						return head;
					}
				}
				first->next = current;
				first = first->next;

}
	}
};
*/

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(NULL) {}
	ListNode(int x, ListNode *next) :val(x), next(next) {}
	ListNode() :next(NULL){}
}str[100];
ListNode *deleteDuplicates(ListNode *head)
{
	while (head &&head->next)
	{
		if (head->val == head->next->val){
			head->next = head->next->next;
		}
		else
		{
			head = head->next;
		}
	}
	return head;
}

void testAsignPoint(ListNode *head)
{
	printf(" assign begin =%0x\n", head);
	head = head->next;
	printf(" assign begin = %0x\n", head);
}

void myprintf(ListNode* head)
{
	while (head != NULL)
	{
		printf("%d", head->val);
		head = head->next;
	}
	printf("\n");
}


void testAsignPointAgain(unsigned int addr)
{
	printf(" assign begin = %0x\n", addr);
	addr = (unsigned int)((ListNode *)addr)->next;
	printf("  assign begin = %0x\n", addr);
}
void test(ListNode* ptest) {


	printf("ptest begin=%0x\n", ptest);//28fef0
	testAsignPoint(ptest);
	printf("one ptest =%0x\n", ptest);//28fef0
	printf("same as before code");
	testAsignPointAgain((unsigned int)(ptest));
	printf("one ptest =%0x\n", ptest);//28fef0

	printf("ptest=%0x\n", ptest);

	myprintf(ptest);
	deleteDuplicates(ptest);
	printf("ptest=%0x\n", ptest);
	myprintf(ptest);
}

void testSample(){
	ListNode three(1, NULL);
	ListNode two(0, &three);
	ListNode one(0, &two);
	test(&one);

}

int main() {
	int n = 10;
	for (int i = 0; i<n; i++) {
		str[i].val = i / 2;
		str[i].next = &str[i + 1];
	}
	str[n].val = n / 2;
	str[n].next = NULL;
	printf("deleteDuplicates begin\n");
	myprintf(str);
	deleteDuplicates(&str[0]);
	myprintf(str);
	printf("deleteDuplicates end\n");
	printf("\n");
	printf("test Asign Point begin\n");
	testSample();
	printf("test Asign Point begin\n");
	system("pause");
	return 0;
}