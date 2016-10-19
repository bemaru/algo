#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int zeroCnt, oneCnt;

int fibonacci(int n) {
	if (n == 0) {
		zeroCnt++;
		//printf("0");
		return 0;
	}
	else if (n == 1) {
		oneCnt++;
		//printf("1");
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}


int main()
{
	int T = 0;
	scanf("%d", &T);
	
	int* input = new int[T];

	for (int i = 0; i < T; i++) {
		scanf("%d", &input[i]);
	}

	for (int i = 0; i < T; i++) {
		fibonacci(input[i]);
		printf("%d %d\n", zeroCnt, oneCnt);
		zeroCnt = oneCnt = 0;
	}
	return 0;
}