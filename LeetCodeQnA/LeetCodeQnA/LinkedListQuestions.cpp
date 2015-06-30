#include "stdafx.h"
#include "LinkedListQuestions.h"


LinkedListQuestions::LinkedListQuestions()
{
}
//Question: Reverse LinkedList;
LinkedListNode* LinkedListQuestions::reverseList(LinkedListNode* head)
{
	if (head == NULL) return head;
	LinkedListNode *prev, *current, *temp;
	current = head;
	temp = NULL;
	prev = NULL;
	
	//if (head->GetNext()) return head;
	while (current)
	{
		*prev = *current;
		*current = current->GetNext();
		*temp = *prev;
		prev->SetNext(temp);
		prev->SetNext(current);
	}
	return temp;
}

LinkedListQuestions::~LinkedListQuestions()
{
}
