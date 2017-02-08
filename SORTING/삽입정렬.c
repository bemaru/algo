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

//���� : http://hahahoho5915.tistory.com/8
void insertionSort(int arr[],int size) {

	int temp = 0;//�ڸ��� ã�� ���Ե� ��
	int j = 0;

	for (int i = 1; i < size; i++) { // temp���� �̱� ���� for��, 2��° �ε������� ���۵ȴ�.
		temp = arr[i];
		for (j = i - 1; j >= 0 && temp < arr[j]; j--){ // ���ĵ� ��, temp ��ĭ�Ʒ� �ε������� �Ʒ��� ��
			arr[j + 1] = arr[j];//�ϳ��� ���������� ġ���.	
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