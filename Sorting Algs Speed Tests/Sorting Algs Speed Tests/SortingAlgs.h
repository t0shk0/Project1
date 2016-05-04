#pragma once

struct Data {
	//Integer array to be sorted
	int arr[1024];

	//Size of the integer array
	int arrSize;

	//Name of the called function
	char funcName[20];

	//Number of the iterations which sorting algorithms make
	int loopIterats = 0;

	//MergeSort Data
	//First and Last elements of the array
	int first, last;
	//Temporary array used for the merging
	int tempArr[1024];
};

//Finds the length of array of type 'type': int, double..
#define ArrSize(array, type) (sizeof((array))/sizeof((array)[0]))

//Prints all the elements of an array
void PrintArray(int [], int);

//Copies one array to another
void CopyArray(int[], int[], int);

//Printing the time taken for the sorting algorithms to complete
void MeasureTime(void(*)(Data *), int [], int);

//Sorting int arrays via InsertionSort algorithm
void InsertionSort(Data *);

//Sorting int arrays via SelectionSort algorithm
void SelectionSort(Data *);

//Sorting int arrays via BubbleSort algorithm
void BubbleSort(Data *);

//Merg sorting functions
//Sorting int arrays vie MergeSort alogrithm
void MergeSort(Data *);

//Merging the parts into a sorted array
void Merge(int [], int [], int, int, int);