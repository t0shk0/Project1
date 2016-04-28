#pragma once

#define Assign(a, b) (a = b)

/* The Node structure */
struct Node {
	int data;
	struct Node *next;
};

/* List type */
typedef Node * List;

/*
Length

Returns the number of nodes in the list.
*/
int Length(List);

/*
Push

Adds a new node at the head of the list
*/
void Push(List *, int);

/*
DeleteNode

Deletes a node from the list by a given data
*/
void DeleteNode(List *, int);

/*
Count

Counts the number of times a given int occurs in a list.
*/
int Count(List, int);

/*
GetNth

Takes a linked list and an integer index and returns the data
value stored in the node at that index position
*/
int GetNth(List, int);

/*
DeleteList

Takes a list, deallocates all of its memory and sets its
head pointer to NULL
*/
void DeleteList(List *);

/*
Pop

Takes a non-empty list, deletes the head node,
and returns the head node's data
*/
int Pop(List *);

/*
InsertNth

Inserts a new node at any index within a list
*/
void InsertNth(List *, int, int);

/*
SortedInsert

Given a list that is sorted in increasing order, and a single node,
inserts the node into the correct sorted position in the list
*/
void SortedInsert(List *, List);

/*
InsertSort

Given a list, rearranges its nodes so they are sorted in increasing order
*/
void InsertSort(List *);

/*
Append

Takes two lists, 'a' and 'b', appends 'b' onto the end of 'a',
and then sets 'b' to NULL
*/
void Append(List *, List *);

/*
FrontBackSplit

Given a list, split it into two sublists — one for the front half,
and one for the back half. If the number of elements is odd, the extra
element should go in the front list.
*/
void FrontBackSplit(List, List *, List *);

/*
RemoveDuplicates

Takes a list sorted in increasing order and deletes any
duplicate nodes from the list
*/
void RemoveDuplicates(List);

/*
MoveNode

Takes two lists, removes the front node from the second list and pushes
it onto the front of the first
*/
void MoveNode(List *, List *);

/*
AlternatingSplit

Takes one list and divides up its nodes to make two smaller lists.
The sublists should be made from alternating elements in the original
list
*/
void AlternatingSplit(List, List *, List *);

/*
ShuffleMerge

Given two lists, merge their nodes together to make one list,
taking nodes alternately between the two lists
*/
List ShuffleMerge(List, List);

/*
SortedMerge

Takes two lists, each of which is sorted in increasing order,
and merges the two together into one list which is in increasing order
*/
List SortedMerge(List, List);

/*
MergeSort

Splits the list into two smaller lists, recursively sort those lists,
and finally merge the two sorted lists together into a single sorted list
*/
void MergeSort(List *);

/*
SortedIntersect

Given two lists sorted in increasing order, creates and returns a
new list representing the intersection of the two lists
*/
List SortedIntersect(List, List);

/*
Reverse

Reverses a list
*/
void Reverse(List *);

/*
RecursiveReverse

Reverses a list by recursion
*/
void RecursiveReverse(List *);

/*
ChangeToNull

Change the passed in head pointer to be NULL
Uses a reference pointer to access the caller's memory
*/
void ChangeToNull(List *);

/*
PrintList

Print a list members one by one
*/
void PrintList(List);

/*
BuildOneTwoThree

Build 3 nodes with integers from 1 to 3 for testing purposes
*/
List BuildOneTwoThree();

/*
AddAtHead

Builds up a list by adding 5 nodes at its "head end" with Push()
*/
List AddAtHead();

/*
AddAtEnd

Adding nodes at the "tail end" of the given list
*/
void AddAtEnd(List *, int);

/*
BuildWithSpecialCase

Building up the list of 5 nodes by appending the nodes to the tail end
*/
List BuildWithSpecialCase();

/*
BuildWithDummyNode

Building up the list of 5 nodes by using a temporary
dummy node at the head of the list during the computation
*/
List BuildWithDummyNode();

/*
BuildWithLocalRef

Building up the list of 5 nodes by using a local "reference pointer" which
always points to the lastpointer in the list instead of to the last node
*/
List BuildWithLocalRef();