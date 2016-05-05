#pragma once

//Finds the length of array of type 'type': int, double..
#define ArrSize(array, type) (sizeof((array))/sizeof((array)[0]))

//Defines the max size for the integer arrays
#define ARR_MAX_SIZE 1024

struct Data {
	//Integer array to be sorted
	int arr[ARR_MAX_SIZE];

	//Size of the integer array
	int arrSize;

	//Name of the called function
	char funcName[20];

	//Number of the iterations which sorting algorithms make
	int loopIterats = 0;


	//Data for MergeSort and QuickSort algorithms -->
	//
	//First and Last elements of the array
	int first, last;
	//Temporary array used for the merging
	int tempArr[ARR_MAX_SIZE];

	//<-- Data for MergeSort and QuickSort algorithms
};

//Prints all the elements of an array
void PrintArray(int [], int);

//Copies one array to another
void CopyArray(int[], int[], int);

//Printing the time taken for the sorting algorithms to complete
void MeasureTime(void(*func)(Data *), int [], int);

//Sorting int arrays via InsertionSort algorithm
void InsertionSort(Data *);

//Sorting int arrays via SelectionSort algorithm
void SelectionSort(Data *);

//Sorting int arrays via BubbleSort algorithm
void BubbleSort(Data *);


//Merge sorting functions -->
//
//Sorting int arrays via MergeSort alogrithm
void MergeSort(Data *);

//Merging the parts into a sorted array
void Merge(int [], int [], int, int, int);

//<-- Merge sorting functions


//QuickSort sorting functions -->
//
//Sorting int arrays via QuickSort algorithm
void QuickSort(Data *);

//Partitioning the array of integers
int Partition(int [], int, int, int);

//Swaping two integers from an array
void Swap(int [], int, int);

//<-- QuickSort sorting functions