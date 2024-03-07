/*
	Copyright Shaquille Miller
	COP3502C-24Spring 0023 
	Lab #7
*/
#include <stdio.h>

void bubbleSort(int* arr, int size);
void selectionSort(int* arr, int size);


void printArr(int* arr, int size) {
	printf("\n");
	for (int i = 0;i < size;i++) {
		printf("%d, ", arr[i]);
	}
}

int main() {
	//Made two of each array to use in the different sorts
	int array1_bubble[] = { 97 , 16 , 45 , 63 , 13 , 22 , 7 , 58 , 72 };
	int array1_selection[] = { 97 , 16 , 45 , 63 , 13 , 22 , 7 , 58 , 72 };

	int array2_bubble[] = { 90 , 80 , 70 , 60 , 50,  40,  30 , 20  ,10 };
	int array2_selection[] = { 90 , 80 , 70 , 60 , 50,  40,  30 , 20  ,10 };

	int n = 9;

	//Bubbles
	printf("\narray1 ");
	bubbleSort(array1_bubble, n);
	printf("\narray2 ");
	bubbleSort(array2_bubble, n);

	//Selection
	printf("\narray1 ");
	selectionSort(array1_selection, n);
	printf("\narray2 ");
	selectionSort(array2_selection, n);

}


void bubbleSort(int* arr, int size) {
	printf(" bubble sort:\n");
	//Use an array to track how much each number has been swapped
	int countSwapArr[9] = { 0,0,0,0,0,0,0,0,0 };
	int totalSwaps = 0;

	for (int i = 0;i < size - 1;i++) {
		for (int j = 0;j < size - 1 - i;j++) {
			if (arr[j] > arr[j + 1]) {
				//incriment and swap swapCount Array first
				countSwapArr[j]++;
				countSwapArr[j + 1]++;
				int tempCount = countSwapArr[j];
				countSwapArr[j] = countSwapArr[j + 1];
				countSwapArr[j + 1] = tempCount;

				//swap actual array
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				totalSwaps += 1;
			}
		}

	}

	//Print the swap count
	for (int i = 0;i < size;i++) {
		printf("%d: %d\n", arr[i], countSwapArr[i]);
	}
	printf("%d\n", totalSwaps);
}

void selectionSort(int* arr, int size) {
	printf(" selection  sort:\n");
	//Use an array to track how much each number has been swapped
	int countSwapArr[9] = { 0,0,0,0,0,0,0,0,0 };
	int totalSwaps = 0;

	for (int i = 0;i < size - 1;i++) {
		int minIndex = i;

		for (int j = i + 1;j < size;j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			//incriment and swap swapCount Array first
			countSwapArr[i]++;
			countSwapArr[minIndex]++;
			int tempCount = countSwapArr[i];
			countSwapArr[i] = countSwapArr[minIndex];
			countSwapArr[minIndex] = tempCount;

			//Swap actual value
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;

			totalSwaps += 1;
		}
	}

	//Print the swap count
	for (int i = 0;i < size;i++) {
		printf("%d: %d\n", arr[i], countSwapArr[i]);
	}
	printf("%d\n", totalSwaps);
}