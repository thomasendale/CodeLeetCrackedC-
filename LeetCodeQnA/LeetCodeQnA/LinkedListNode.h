#include "ListNode.h"
#pragma once
class LinkedListNode
{
public:
	LinkedListNode();
public:
	ListNode* reverseList(ListNode* head);
	ListNode* AddItemToLinkedList(ListNode* head,int data);
	void PrintLinkedList(ListNode* head);
	ListNode* detectCycle(ListNode *head);
	bool hasCycle(ListNode *head);
	ListNode* removeElements(ListNode* head, int val);
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB);
	int Count(ListNode*head);
	~LinkedListNode();
};

