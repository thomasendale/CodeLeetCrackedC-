#include "stdafx.h"
#include <iostream>
#include <string>
#include "LinkedListNode.h"
#include <array>
using namespace std;

LinkedListNode::LinkedListNode() {};

//Question: Reverse a linked List, 8 ms solution and passed all test cases and accepted.
ListNode* LinkedListNode::reverseList(ListNode* head)
{
	if (!head) return head;
	ListNode *prev = head, *current = head, *temp = nullptr;
	while (current)
	{
		current = current->next;
		prev->next = temp;
		temp = prev;
		prev = current;
	}
	return temp;
}
ListNode* LinkedListNode::AddItemToLinkedList(ListNode* head,int data)
{
	ListNode* newNode=new ListNode(data);
	if (!head) return newNode;
	ListNode* current = head;
	while ( current->next )
	{
		current = current->next;
	}
	current->next = newNode;
	return head;
}
void LinkedListNode::PrintLinkedList(ListNode* head)
{
	while (head)
	{
		std::cout<<	head->val << ",";
		head = head->next;
	}
}
//Question: Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
ListNode* LinkedListNode::detectCycle(ListNode* head)
{
	if (head == nullptr || head->next == nullptr) return nullptr;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			fast = head;
			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	}
	return nullptr;
}
//Question:Given a linked list, determine if it has a cycle in it.
//Follow up :
//Can you solve it without using extra space ?
bool LinkedListNode::hasCycle(ListNode *head) {
	if (head == nullptr || head->next == nullptr) return nullptr;
	ListNode* slow = head;
	ListNode* fast = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}
	}
	return false;
}
//Question:Remove all elements from a linked list of integers that have value val.
//Example
//Given : 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
//	Return: 1 --> 2 --> 3 --> 4 --> 5
ListNode* LinkedListNode::removeElements(ListNode* head, int val)
{
	if (head == nullptr) return nullptr;
	//if (head->next == nullptr && head->val != val) return head;
	ListNode* current = head;
	ListNode* prev    = head;
	while (current != nullptr)
	{
		if (current->val == val)
		{
			if (head->val == val)
			{
				head = current->next;
				prev = head;
				current= nullptr;
				current = head;
			}
			else
			{
				prev->next = current->next;
				current = nullptr;
				current = prev;
			}
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
	return head;
}
/*
Write a program to find the node at which the intersection of two singly linked lists begins.
For example, the following two linked lists:
A:          a1 → a2
					↘
						c1 → c2 → c3
					↗
B:     b1 → b2 → b3
begin to intersect at node c1.
Notes:
If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Credits:
*/
ListNode* LinkedListNode::getIntersectionNode(ListNode *headA, ListNode *headB)
{
	int count1 = this->Count(headA);
	int count2 = this->Count(headB);
	int diff = abs(count1-count2);
	if (count1 > count2)
	{
		while (diff > 0)
		{
			headA = headA->next;
			diff--;
		}
	}
	else if ( count2 >count1)
	{
		while (diff > 0)
		{
			headB = headB->next;
			diff--;
		}
	}
	while (headA!=nullptr)
	{
		if (headA == headB) return headA;
		headA = headA->next;
		headB = headB->next;
	}
	return nullptr;
}

//helper function given a linked list, it'll return the number of elements in the list;
int LinkedListNode::Count(ListNode* head)
{
	int count = 0;
	ListNode* current = head;
	while (current != nullptr)
	{
		current = current->next;
		count++;
	}
	return count;
}
LinkedListNode::~LinkedListNode(){};
