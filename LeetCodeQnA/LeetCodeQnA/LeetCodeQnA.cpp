// LeetCodeQnA.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	LinkedListNode l;
	ListNode *head = new ListNode(1);
	//head=l.AddItemToLinkedList(head, 1);
	l.PrintLinkedList(head);
	//head=l.AddItemToLinkedList(head,2);
	//l.detectCycle(head);
	//l.hasCycle(head);

	//l.hasCycle(head);
	
	//l.removeElements(head, 2);
	//ListNode* temp = l.removeElements(head, 2);

	ListNode* x = l.getIntersectionNode(nullptr, head);

	//ListNode *head2 = l.CreateLinkedListFromArray(arr);

	return 0;
}

