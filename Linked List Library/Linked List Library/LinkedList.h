#pragma once

struct Node {
	int data;
	struct Node *next;
};

typedef Node * List;

List BuildOneTwoThree();

int Length(List);
void Push(List *, int);
void DeleteNode(List *, int);
int Count(List, int);
int GetNth(List, int);
void DeleteList(List *);
int Pop(List *);
void InsertNth(List *, int, int);
void SortedInsert(List *, List);
void InsertSort(List *);
void Append(List *, List *);
void FrontBackSplit(List, List *, List *);
void RemoveDuplicates(List);
void MoveNode(List *, List *);
void AlternatingSplit(List, List *, List *);
List ShuffleMerge(List, List);

void PrintList(List);

void ChangeToNull(List *);
List AddAtHead();
void AddAtEnd(List *, int);
List BuildWithSpecialCase();
List BuildWithDummyNode();
List BuildWithLocalRef();