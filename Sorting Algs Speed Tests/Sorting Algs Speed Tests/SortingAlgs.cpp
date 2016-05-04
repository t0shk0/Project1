#include <stdio.h>
#include <time.h>
#include <string.h>
#include "SortingAlgs.h"

//Printing the array to the console
void PrintArray(int arr[], int size) {
	int i;

	for(i = 0; i < size; i++) { printf("%d ", arr[i]); }

	printf("\n");
}

//Coping every integer from 'from' array to 'to' array
void CopyArray(int to[], int from[], int size) {
	int i;

	for(i = 0; i < size; i++) { to[i] = from[i]; }
}

//Printing the time taken for the sorting algorithms to complete
void MeasureTime(void(*func)(Data *), int arr[], int arrSize) {
	clock_t begin, end;
	double timeSpent;

	Data tempData;
	CopyArray(tempData.arr, arr, arrSize);
	tempData.arrSize = arrSize;

	//MergeSort Data -->
	tempData.first = 0;
	tempData.last = arrSize - 1;
	//<--

	//Begin counting millisecs
	begin = clock();
	(*func)(&tempData);
	//Stops the counter
	end = clock();


	timeSpent = (double)(end - begin);

	printf("%s for %d numbers -> Time: %f millisecs, Iterations: %d\n", 
		tempData.funcName, arrSize, timeSpent, tempData.loopIterats);
	//PrintArray(tempData.arr, arrSize);
}

//Sorting int arrays via InsertionSort algorithm
void InsertionSort(Data *data) {
	const char * tempName = __func__;
	int valToInsert, holePos, i;

	//Adding extra time to the final results
	strcpy_s((*data).funcName, 20, tempName);

	for(i = 1; i < (*data).arrSize; i++) {
		valToInsert = (*data).arr[i];
		holePos = i;

		while(holePos > 0 && (*data).arr[holePos - 1] > valToInsert) {
			(*data).arr[holePos] = (*data).arr[holePos - 1];
			holePos--;

			(*data).loopIterats++;
		}

		if(holePos != i) { (*data).arr[holePos] = valToInsert; }
	}
}

//Sorting int arrays via SelectionSort algorithm
void SelectionSort(Data *data) {
	const char * tempName = __func__;
	int indexMin, i, j;

	//Adding extra time to the final results
	strcpy_s((*data).funcName, 20, tempName);

	for(i = 0; i < (*data).arrSize - 1; i++) {
		indexMin = i;

		for(j = i + 1; j < (*data).arrSize; j++) {
			if((*data).arr[j] < (*data).arr[indexMin]) {
				indexMin = j;
			}

			(*data).loopIterats++;
		}

		if(indexMin != i) {
			int temp = (*data).arr[indexMin];
			(*data).arr[indexMin] = (*data).arr[i];
			(*data).arr[i] = temp;
		}
	}
}

//Sorting int arrays via BubbleSort algorithm
void BubbleSort(Data *data) {
	const char * tempName = __func__;
	int temp, i, j;
	bool swap = false;

	//Adding extra time to the final results
	strcpy_s((*data).funcName, 20, tempName);

	for(i = 0; i < (*data).arrSize - 1; i++) {
		swap = false;

		for(j = 0; j < (*data).arrSize - 1 - i; j++) {
			if((*data).arr[j] > (*data).arr[j + 1]) {
				temp = (*data).arr[j];
				(*data).arr[j] = (*data).arr[j + 1];
				(*data).arr[j + 1] = temp;

				swap = true;
			}
			(*data).loopIterats++;
		}

		if(!swap) { break; }
	}
}

//Merging Sort Functions -->
void MergeSort(Data *data) {
	const char * tempName = __func__;
	int mid;
	Data tempData;

	//Adding extra time to the final results
	strcpy_s((*data).funcName, 20, tempName);

	if((*data).first < (*data).last) {
		mid = ((*data).first + (*data).last) / 2;
		tempData = *data;
		(*data).last = mid;

		MergeSort(data);

		(*data).first = mid + 1;
		(*data).last = tempData.last;

		MergeSort(data);
		Merge((*data).arr, (*data).tempArr, tempData.first, mid, (*data).last);
	} else {
		return;
	}

	(*data).loopIterats++;
}

//Merging the parts into a sorted array
void Merge(int arr[], int tempArr[], int low, int mid, int high) {
	int l1, l2, i;

	for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++) {
		if(arr[l1] <= arr[l2]) {
			tempArr[i] = arr[l1++];
		} else {
			tempArr[i] = arr[l2++];
		}
	}

	while(l1 <= mid) { tempArr[i++] = arr[l1++]; }

	while(l2 <= high) { tempArr[i++] = arr[l2++]; }

	for(i = low; i <= high; i++) { arr[i] = tempArr[i]; }
}
//<-- Merging Sort Functions