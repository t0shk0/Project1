#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

List BuildOneTwoThree() {
	List temp = NULL;

	Push(&temp, 3);
	Push(&temp, 2);
	Push(&temp, 1);
	
	return temp;
}

int Length(List head) {
	int count = 0;
	List current = head;

	while(current != NULL) {
		count++;
		current = current->next;
	}

	return count;
}

void Push(List *head, int data) {
	List temp = NULL;

	temp->data = data;
	temp->next = *head;

	*head = temp;
}

void DeleteNode(List *head, int data) {
	List temp = *head, prev;

	if(temp != NULL && temp->data == data) {
		*head = temp->next; 
		free(temp);

		return;
	}

	while(temp != NULL && temp->data != data) {
		prev = temp;
		temp = temp->next;
	} 

	if(temp == NULL) {
		printf("ERROR! Key doesnt exist!");

		return;
	}

	prev->next = temp->next;
	free(temp);
}

int Count(List head, int searchFor) {
	int count = 0;
	List current = head;

	while(current != NULL) {
		if(current->data == searchFor) { count++; }
		current = current->next;
	}

	return count;
}

int GetNth(List head, int index) {
	int i = 0;
	List current = head;

	while(current != NULL) {
		if(i == index) { break; }
		current = current->next;
		i++;
	}

	if(current != NULL) { return current->data; } 
	else { return -1; }
}

void DeleteList(List *headRef) {
	List prev;

	while(prev = *headRef) {
		*headRef = prev->next;
		free(prev);
	}

	*headRef = NULL;
}

int Pop(List *headRef) {
	if(headRef == NULL) { return -1; }

	int result = (*headRef)->data;
	List temp = (*headRef)->next;

	free(*headRef);

	*headRef = temp;

	return result;
}

void InsertNth(List *headRef, int index, int data) {
	List toBeInserted = NULL;

	toBeInserted->data = data;
	toBeInserted->next = NULL;

	if(*headRef == NULL) {
		*headRef = toBeInserted;
	} else if(index == 0) {
		toBeInserted->next = *headRef;
		*headRef = toBeInserted;
	} else {
		int i = 1;
		List temp = *headRef;

		while(temp != NULL) {
			if(i == index) {
				toBeInserted->next = temp->next;
				temp->next = toBeInserted;
			}
			temp = temp->next;
			i++;
		}
	}
}

void SortedInsert(List *headRef, List newNode) {
	if(*headRef == NULL || (*headRef)->data >= newNode->data) {
		newNode->next = *headRef;
		*headRef = newNode;
	} else {
		List temp = *headRef;

		while(temp->next != NULL && temp->next->data < newNode->data) {
			temp = temp->next;
		}

		newNode->next = temp->next;
		temp->next = newNode;
	}
}

void InsertSort(List *headRef) {
	List list = *headRef, result = NULL, temp;

	while(list != NULL) {
		temp = list->next;
		SortedInsert(&result, list);
		list = temp;
	}
	 
	*headRef = result;
}

void Append(List *aRef, List *bRef) {
	if(*aRef == NULL) {
		*aRef = *bRef;
	} else {
		List temp = *aRef;

		while(temp->next != NULL) {
			temp = temp->next;
		}

		temp->next = *bRef;
	}

	*bRef = NULL;
}

void FrontBackSplit(List source, List *frontRef, List *backRef) {
	int size = Length(source);

	if(size < 2) {
		*frontRef = source;
		*backRef = NULL;
	} else {
		List temp = source;
		int i;

		for(i = 0; i < (size - 1) / 2; i++) {
			temp = temp->next;
		}

		*frontRef = source;
		*backRef = temp->next;
		temp->next = NULL;
	}
}

void RemoveDuplicates(List head) {
	List list = head;

	if(head == NULL) { return; }

	while(list->next != NULL) {
		if(list->data == (list->next)->data) {
			List temp = (list->next)->next;
			free(list->next);
			list->next = temp;
		} else {
			list = list->next;
		}
	}
}

void MoveNode(List *destRef, List *sourceRef) {
	if(*sourceRef == NULL) { return; }

	List list = *sourceRef;
	*sourceRef = (*sourceRef)->next;

	list->next = *destRef;
	*destRef = list;
}

void AlternatingSplit(List source, List *aRef, List *bRef) {
	while(source != NULL) {
		MoveNode(&(*aRef), &source);
		if(source != NULL) {
			MoveNode(&(*bRef), &source);
		}
	}
}

List ShuffleMerge(List a, List b) {
	
}

void ChangeToNull(List *head) {
	*head = NULL;
}

List AddAtHead() {
	List head = NULL;
	int i;

	for(i = 5; i > 0; i--) {
		Push(&head, i);
	}
	
	return head;
}

void AddAtEnd(List * head, int data) {
	List temp = *head, prev;

	while(temp != NULL) {
		prev = temp;
		temp = temp->next;
	}

	Push(&(prev->next), data);
}

List BuildWithSpecialCase() {

	List head = NULL, tail;
	int i;

	Push(&head, 1);
	tail = head;

	for(i = 2; i < 6; i++) {
		Push(&(tail->next), i);
		tail = tail->next;
	}

	return head;
}

List BuildWithDummyNode() {
	Node dummy, *tail = &dummy;

	int i;
	dummy.next = NULL;

	for(i = 1; i < 6; i++) {
		Push(&(tail->next), i);
		tail = tail->next;
	}

	return dummy.next;
}

List BuildWithLocalRef() {
	List head = NULL, *lastPtrRef = &head;
	int i;

	for(i = 1; i < 6; i++) {
		Push(lastPtrRef, i);
		lastPtrRef = &((*lastPtrRef)->next); 							
	}

	return head;
}

void PrintList(List node) {
	while(node != NULL) {
		printf(" %d ", node->data);
		node = node->next;
	}

	printf("\n");
}