#include <cstdio>
#include "LinkedList.h"

int main() {
	//Testing 

	//Test 1

	//List head;
	//int len;
	//head = AddAtHead(); // Start with {1, 2, 3}
	//PrintList(head);
	//Push(&head, 13); // Push 13 on the front, yielding {13, 1, 2, 3}
	//				 // (The '&' is because head is passed
	//				 // as a reference pointer.)
	//PrintList(head);
	//Push(&(head->next), 42); // Push 42 into the second position
	//						 // yielding {13, 42, 1, 2, 3}
	//						 // Demonstrates a use of '&' on
	//						 // the .next field of a node.
	//						 // (See technique #2 below.)
	//PrintList(head);
	//len = Length(head);

	//DeleteNode(&head, 3);

	//PrintList(head);


	//Test 2

	/*List test = AddAtHead();
	PrintList(test);*/

	//List myList = BuildOneTwoThree(); 
	//int count = Count(myList, 2);

	//List myList2 = BuildOneTwoThree(); 
	//PrintList(myList2);
	//int lastNode = GetNth(myList2, 1);

	//List myList3 = BuildOneTwoThree();
	//DeleteList(&myList3); 


	//Test 3

	//List head = BuildOneTwoThree(); // build {1, 2, 3}
	//int a = Pop(&head); // deletes "1" node and returns 1
	//int b = Pop(&head); // deletes "2" node and returns 2
	//int c = Pop(&head); // deletes "3" node and returns 3
	//int len = Length(head); // the list is now empty, so len == 0


	//Test 4

	//List head = NULL; // start with the empty list
	//InsertNth(&head, 0, 13); // build {13)
	//PrintList(head);
	//InsertNth(&head, 1, 42); // build {13, 42}
	//PrintList(head);
	//InsertNth(&head, 1, 5); // build {13, 5, 42}
	//PrintList(head);
	//DeleteList(&head); // clean up after ourselves
	//PrintList(head);


	//Test 5

	/*List head = NULL;
	Push(&head, 8);
	Push(&head, 6);
	Push(&head, 5);
	PrintList(head);

	List newNode = NULL;
	Push(&newNode, 7);
	PrintList(newNode);

	SortedInsert(&head, newNode);
	PrintList(head);*/


	//Test 6

	/*List head = NULL;
	Push(&head, 93);
	Push(&head, 6);
	Push(&head, 67);
	Push(&head, 8);
	Push(&head, 201);
	Push(&head, 14);
	Push(&head, 8);
	Push(&head, 51);
	Push(&head, 0);
	PrintList(head);

	InsertSort(&head);
	PrintList(head);*/


	//Test 7

	/*List a = NULL;
	Push(&a, 3);
	Push(&a, 2);
	Push(&a, 1);

	PrintList(a);

	List b = NULL;
	Push(&b, 6);
	Push(&b, 5);
	Push(&b, 4);

	PrintList(b);

	Append(&a, &b);

	PrintList(a);*/


	//Test 8

	/*List longL = NULL;
	Push(&longL, 67);
	Push(&longL, 56);
	Push(&longL, 201);
	Push(&longL, 14);
	Push(&longL, 8);

	PrintList(longL);
	printf("\n");

	List a = NULL, b = NULL;

	FrontBackSplit(longL, &a, &b);

	PrintList(a);
	PrintList(b);*/


	//Test 9

	/*List longL = NULL;
	Push(&longL, 5);
	Push(&longL, 4);
	Push(&longL, 4);
	Push(&longL, 3);
	Push(&longL, 2);
	Push(&longL, 1);

	PrintList(longL);

	RemoveDuplicates(longL);

	PrintList(longL);*/


	//Test 10

	//List a = BuildOneTwoThree(); // the list {1, 2, 3}
	//List b = BuildOneTwoThree();
	//MoveNode(&a, &b);

	//PrintList(a);
	//PrintList(b);



	//Test 11

	/*List head = NULL;
	Push(&head, 5);
	Push(&head, 4);
	Push(&head, 3);
	Push(&head, 2);
	Push(&head, 1);

	PrintList(head);

	List a = NULL, b = NULL;

	AlternatingSplit(head, &a, &b);

	PrintList(a);
	PrintList(b);*/


	//Test 12
	
	/*List a = NULL;
	a = BuildOneTwoThree();

	PrintList(a);

	List b = NULL;
	Push(&b, 1);
	Push(&b, 13);
	Push(&b, 7);

	PrintList(b);

	List c = NULL;
	c = ShuffleMerge(a, b);

	PrintList(c);*/


	//Test 13

	/*List a = NULL;
	a = BuildOneTwoThree();

	PrintList(a);

	List b = NULL;
	Push(&b, 13);
	Push(&b, 7);
	Push(&b, 1);

	PrintList(b);

	List c = NULL;
	c = SortedMerge(a, b);

	PrintList(c);*/


	//Test 14

	/*List head = NULL;

	Push(&head, 93);
	Push(&head, 5);
	Push(&head, 67);
	Push(&head, 8);
	Push(&head, 201);
	Push(&head, 14);
	Push(&head, 51);
	Push(&head, 0);

	PrintList(head);
	printf("\n");

	MergeSort(&head);
	PrintList(head);*/


	//Test 15

	/*List a = NULL, b = NULL;
	Push(&a, 5);
	Push(&a, 4);
	Push(&a, 3);
	Push(&a, 2);
	Push(&a, 1);

	PrintList(a);

	Push(&b, 67);
	Push(&b, 4);
	Push(&b, 3);
	Push(&b, 2);
	Push(&b, 0);

	PrintList(b);

	List c = NULL;
	c = SortedIntersect(a, b);

	PrintList(c);*/


	//Test 16

	//List head;
	//head = BuildOneTwoThree();
	//Reverse(&head);
	//// head now points to the list {3, 2, 1}
	//PrintList(head);
	//DeleteList(&head); // clean up after ourselves


	//Test 17

	//List head;
	//head = AddAtHead();
	//RecursiveReverse(&head);
	//// head now points to the list {3, 2, 1}
	//PrintList(head);
	//DeleteList(&head); // clean up after ourselves

	List a = BuildWithDummyNode();
	PrintList(a);

	return 0;
}