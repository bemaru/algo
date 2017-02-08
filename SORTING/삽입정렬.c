#include <stdio.h>

void swap(int* a, int*b){
	int tmp;
	tmp = *a;
	*a = *b;
	*b = *a;
}

void printArray(int arr[], int size) {

	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//참고 : http://hahahoho5915.tistory.com/8
void insertionSort(int arr[],int size) {

	int temp = 0;//자리를 찾아 삽입될 값
	int j = 0;

	for (int i = 1; i < size; i++) { // temp값을 뽑기 위한 for문, 2번째 인덱스부터 시작된다.
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--){ // 정렬된 곳, temp 한칸아래 인덱스부터 아래로 비교
			arr[j + 1] = arr[j];//하나씩 오른쪽으로 치운다.	
		}
		arr[j + 1] = temp;
	}

}

int main(){
	int arr[10] = { 6, 3, 4, 1, 8, 10, 9, 5, 2, 7 };
	int size = sizeof(arr) / sizeof(arr[0]);

	printArray(arr, size);
	insertionSort(arr, size);
	printArray(arr, size);
	return 0;
}