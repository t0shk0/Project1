#include <stdio.h>
#include <time.h>
#include "SortingAlgs.h"
#include "TestArrays.h"

int main() {
	const int sizeOfRandom = ArrSize(random, int),
		sizeOfNearSorted = ArrSize(nearSorted, int),
		sizeOfBigRandom = ArrSize(bigRandom, int);

	/* Test 1: Testing InsertionSort on both arrays */

	MeasureTime(InsertionSort, bigRandom, sizeOfBigRandom);
	MeasureTime(InsertionSort, nearSorted, sizeOfNearSorted);

	printf("\n");

	/* Test 2: Testing SelectionSort on both arrays */

	MeasureTime(SelectionSort, bigRandom, sizeOfBigRandom);
	MeasureTime(SelectionSort, nearSorted, sizeOfNearSorted);

	printf("\n");

	/* Test 3: Testing BubbleSort on both arrays */

	MeasureTime(BubbleSort, bigRandom, sizeOfBigRandom);
	MeasureTime(BubbleSort, nearSorted, sizeOfNearSorted);

	printf("\n");

	/* Test 4: Testing MergeSort on both arrays */

	MeasureTime(MergeSort, bigRandom, sizeOfBigRandom);
	MeasureTime(MergeSort, nearSorted, sizeOfNearSorted);

	printf("\n");

	return 0;
}