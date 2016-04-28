#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/*
Length

Returns the number of nodes in the list.
*/
int Length(List head) {
	int count;
	Assign(count, 0);

	while(head != NULL) {
		count++;
		Assign(head, head->next);
	}

	return count;
}

/*
Push

Adds a new node at the head of the list
*/
void Push(List *head, int data) {
	List temp;

	Assign(temp, (List)malloc(sizeof(Node)));
	Assign(temp->data, data);
	Assign(temp->next, *head);

	Assign(*head, temp);
}

/*
DeleteNode

Deletes a node from the list by a given data
*/
void DeleteNode(List *head, int data) {
	List temp, prev;
	Assign(temp, *head);

	if(temp != NULL && temp->data == data) {
		Assign(*head, temp->next);
		free(temp);

		return;
	}

	while(temp != NULL && temp->data != data) {
		Assign(prev, temp);
		Assign(temp, temp->next);
	} 

	if(temp == NULL) { return; }

	Assign(prev->next, temp->next);
	free(temp);
}

/*
Count

Counts the number of times a given int occurs in a list.
*/
int Count(List head, int searchFor) {
	int count;
	Assign(count, 0);

	while(head != NULL) {
		if(head->data == searchFor) { count++; }
		Assign(head, head->next);
	}

	return count;
}

/*
GetNth

Takes a linked list and an integer index and returns the data
value stored in the node at that index position
*/
int GetNth(List head, int index) {
	int i;
	Assign(i, 0);

	while(head != NULL) {
		if(i == index) { break; }

		Assign(head, head->next);
		i++;
	}

	if(head != NULL) { return head->data; }
	else { return -1; }
}

/*
DeleteList

Takes a list, deallocates all of its memory and sets its
head pointer to NULL
*/
void DeleteList(List *headRef) {
	List temp;

	while(Assign(temp, *headRef)) {
		Assign(*headRef, temp->next);
		free(temp);
	}

	ChangeToNull(&(*headRef));
}

/*
Pop

Takes a non-empty list, deletes the head node, 
and returns the head node's data
*/
int Pop(List *headRef) {
	if(headRef == NULL) { return -1; }

	int result;
	List temp;

	Assign(result, (*headRef)->data);
	Assign(temp, (*headRef)->next);

	free(*headRef);

	Assign(*headRef, temp);

	return result;
}

/*
InsertNth

Inserts a new node at any index within a list
*/
void InsertNth(List *headRef, int index, int data) {
	List toBeInserted;

	Assign(toBeInserted, (List)malloc(sizeof(Node)));

	Assign(toBeInserted->data, data);
	Assign(toBeInserted->next, NULL);

	if(*headRef == NULL) {
		Assign(*headRef, toBeInserted);
	} else if(index == 0) {
		Assign(toBeInserted->next, *headRef);
		Assign(*headRef, toBeInserted);
	} else {
		int i;
		List temp;

		Assign(i, 1);
		Assign(temp, *headRef);

		while(temp != NULL) {
			if(i == index) {
				Assign(toBeInserted->next, temp->next);
				Assign(temp->next, toBeInserted);
			}
			Assign(temp, temp->next);
			i++;
		}
	}
}

/*
SortedInsert

Given a list that is sorted in increasing order, and a single node, 
inserts the node into the correct sorted position in the list
*/
void SortedInsert(List *headRef, List newNode) {
	if(*headRef == NULL || (*headRef)->data >= newNode->data) {
		Assign(newNode->next, *headRef);
		Assign(*headRef, newNode);
	} else {
		List temp;
		Assign(temp, *headRef);

		while(temp->next != NULL && temp->next->data < newNode->data) {
			Assign(temp, temp->next);
		}

		Assign(newNode->next, temp->next);
		Assign(temp->next, newNode);
	}
}


/*
InsertSort

Given a list, rearranges its nodes so they are sorted in increasing order
*/
void InsertSort(List *headRef) {
	List result, temp;

	Assign(result, NULL);

	while(*headRef != NULL) {
		Assign(temp, (*headRef)->next);
		SortedInsert(&result, *headRef);
		Assign(*headRef, temp);
	}
	 
	Assign(*headRef, result);
}

/*
Append

Takes two lists, 'a' and 'b', appends 'b' onto the end of 'a',
and then sets 'b' to NULL
*/
void Append(List *aRef, List *bRef) {
	if(*aRef == NULL) {
		Assign(*aRef, *bRef);
	} else {
		List temp;
		Assign(temp, *aRef);

		while(temp->next != NULL) {
			Assign(temp, temp->next);
		}

		Assign(temp->next, *bRef);
	}

	ChangeToNull(&(*bRef));
}

/*
FrontBackSplit

Given a list, split it into two sublists — one for the front half, 
and one for the back half. If the number of elements is odd, the extra 
element should go in the front list.
*/
void FrontBackSplit(List source, List *frontRef, List *backRef) {
	int size;
	Assign(size, Length(source));

	if(size < 2) {
		Assign(*frontRef, source);
		ChangeToNull(&(*backRef));
	} else {
		List temp;
		int i;

		Assign(temp, source);
		Assign(size, (size - 1) / 2);

		for(i = 0; i < size; i++) {
			Assign(temp, temp->next);
		}

		Assign(*frontRef, source);
		Assign(*backRef, temp->next);
		Assign(temp->next, NULL);
	}
}

/*
RemoveDuplicates

Takes a list sorted in increasing order and deletes any 
duplicate nodes from the list
*/
void RemoveDuplicates(List head) {
	if(head == NULL) { return; }

	while(head->next != NULL) {
		if(head->data == (head->next)->data) {
			List temp;

			Assign(temp, (head->next)->next);
			free(head->next);
			Assign(head->next, temp);
		} else {
			Assign(head, head->next);
		}
	}
}

/*
MoveNode

Takes two lists, removes the front node from the second list and pushes
it onto the front of the first
*/
void MoveNode(List *destRef, List *sourceRef) {
	if(*sourceRef == NULL) { return; }

	List list;

	Assign(list, *sourceRef);
	Assign(*sourceRef, (*sourceRef)->next);

	Assign(list->next, *destRef);
	Assign(*destRef, list);
}


/*
AlternatingSplit

Takes one list and divides up its nodes to make two smaller lists. 
The sublists should be made from alternating elements in the original
list
*/
void AlternatingSplit(List source, List *aRef, List *bRef) {
	while(source != NULL) {
		MoveNode(&(*aRef), &source);
		if(source != NULL) {
			MoveNode(&(*bRef), &source);
		}
	}
}

/*
ShuffleMerge

Given two lists, merge their nodes together to make one list, 
taking nodes alternately between the two lists


Version 1: with Recusion
List ShuffleMerge(List a, List b) {
	List newList, temp;

	if(a != NULL && b != NULL) {
		Assign(temp, ShuffleMerge(a->next, b->next));

		Assign(newList, a);
		Assign(a->next, b);
		Assign(b->next, temp);

		return newList;
	}

	if(a == NULL) { return b; }
	else { return a; }
}

ShuffleMerge Version 2: without Recursion */
List ShuffleMerge(List a, List b) {
	List newList, *end;
	Assign(end, &newList);

	while(true) {
		if(a != NULL && b != NULL) {
			MoveNode(end, &a);
			Assign(end, &((*end)->next));
			MoveNode(end, &b);
			Assign(end, &((*end)->next));
		} else if(a == NULL) {
			Assign(*end, b);
			break;
		} else {
			Assign(*end, a);
			break;
		}
	}

	return newList;
}

/*
SortedMerge

Takes two lists, each of which is sorted in increasing order, 
and merges the two together into one list which is in increasing order
*/
List SortedMerge(List a, List b) {
	List newList, *end;
	Assign(end, &newList);

	while(true) {
		if(a == NULL) {
			Assign(*end, b);
			break;
		} else if(b == NULL) {
			Assign(*end, a);
			break;
		}

		if(a->data > b->data) { MoveNode(end, &b); } 
		else { MoveNode(end, &a); }

		Assign(end, &((*end)->next));
	}

	return newList;
}

/*
MergeSort

Splits the list into two smaller lists, recursively sort those lists, 
and finally merge the two sorted lists together into a single sorted list
*/
void MergeSort(List *headRef) {
	List temp, a, b;

	Assign(temp, *headRef);

	if((temp == NULL) || (Length(temp) <= 1)) { return; }

	FrontBackSplit(temp, &a, &b);

	MergeSort(&a);
	MergeSort(&b);

	Assign(*headRef, SortedMerge(a, b));
}

/*
SortedIntersect

Given two lists sorted in increasing order, creates and returns a 
new list representing the intersection of the two lists
*/
List SortedIntersect(List a, List b) {
	List result;
	Assign(result, NULL);

	while(a != NULL && b != NULL) {
		if(a->data == b->data) {
			Push(&result, a->data);

			Assign(a, a->next);
			Assign(b, b->next);
		} else if(a->data > b->data) {
			Assign(b, b->next);
		} else {
			Assign(a, a->next);
		}
	}

	return result;
}

/*
Reverse

Reverses a list
*/
void Reverse(List *headRef) {
	List result;
	Assign(result, NULL);

	while(*headRef != NULL) {
		MoveNode(&result, headRef);
	}

	Assign(*headRef, result);
}

/*
RecursiveReverse

Reverses a list by recursion
*/
void RecursiveReverse(List *headRef) {
	List temp, result;

	if(*headRef == NULL) { return; }

	Assign(temp, *headRef);
	Assign(result, temp->next);

	if(result == NULL) { return; }
	
	RecursiveReverse(&result);

	Assign((temp->next)->next, temp);
	ChangeToNull(&(temp->next));

	Assign(*headRef, result);
}

/*
ChangeToNull

Change the passed in head pointer to be NULL
Uses a reference pointer to access the caller's memory
*/
void ChangeToNull(List *head) {
	Assign(*head, NULL);
}

/*
PrintList

Print a list members one by one
*/
void PrintList(List node) {
	while(node != NULL) {
		printf(" %d ", node->data);
		node = node->next;
	}

	printf("\n");
}

/*
BuildOneTwoThree

Build 3 nodes with integers from 1 to 3 for testing purposes
*/
List BuildOneTwoThree() {
	List temp;
	Assign(temp, NULL);

	Push(&temp, 3);
	Push(&temp, 2);
	Push(&temp, 1);

	return temp;
}

/*
AddAtHead

Builds up a list by adding 5 nodes at its "head end" with Push()
*/
List AddAtHead() {
	List head;
	int i;

	Assign(head, NULL);

	for(i = 5; i > 0; i--) {
		Push(&head, i);
	}
	
	return head;
}

/*
AddAtEnd

Adding nodes at the "tail end" of the given list
*/
void AddAtEnd(List *head, int data) {
	if(*head == NULL || Length(*head) < 1) {
		Push(&(*head), data);
		return;
	}

	List temp, prev;
	Assign(temp, *head);

	while(temp != NULL) {
		Assign(prev, temp);
		Assign(temp, temp->next);
	}

	Push(&(prev->next), data);
}

/*
BuildWithSpecialCase

Building up the list of 5 nodes by appending the nodes to the tail end
*/
List BuildWithSpecialCase() {

	List head, tail;
	int i;

	Assign(head, NULL);

	Push(&head, 1);
	Assign(tail, head);

	for(i = 2; i < 6; i++) {
		Push(&(tail->next), i);
		Assign(tail, tail->next);
	}

	return head;
}

/*
BuildWithDummyNode

Building up the list of 5 nodes by using a temporary
dummy node at the head of the list during the computation
*/
List BuildWithDummyNode() {
	Node dummy, *tail;
	int i;

	Assign(tail, &dummy);
	Assign(dummy.next, NULL);

	for(i = 1; i < 6; i++) {
		Push(&(tail->next), i);
		Assign(tail, tail->next);
	}

	return dummy.next;
}

/*
BuildWithLocalRef

Building up the list of 5 nodes by using a local "reference pointer" which 
always points to the lastpointer in the list instead of to the last node
*/
List BuildWithLocalRef() {
	List head, *lastPtrRef;
	int i;

	Assign(head, NULL);
	Assign(lastPtrRef, &head);

	for(i = 1; i < 6; i++) {
		Push(lastPtrRef, i);
		Assign(lastPtrRef, &((*lastPtrRef)->next));
	}

	return head;
}