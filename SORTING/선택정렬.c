#include <stdio.h>

void swap(int* a, int* b){
	int tmp;
	
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void printArray(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//http://hsp1116.tistory.com/33
void selectionSort_(int arr[],int size) {
	
	for (int i = 0; i < size-1; i++) {

		for (int j = i + 1; j < size; j++) {

			if (arr[i] >= arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

//tmp 임시변수를 사용으로 개선
void selectionSort(int arr[], int size) {

	int tmp;
	for (int i = 0; i < size - 1; i++) {
		tmp = i;
		for (int j = i + 1; j < size; j++) {

			if (arr[tmp] >= arr[j]) {	
				tmp = j;// 더 작은값 의 인덱스를 찾아서

			}
			swap(&arr[i], &arr[tmp]);
		}
	}
}

int main() {

	int arr[10] = { 6, 3, 4, 1, 8, 10, 9, 5, 2, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);	

	printArray(arr, size);
	selectionSort(arr, size);
	printArray(arr, size);
	
	return 0;
}