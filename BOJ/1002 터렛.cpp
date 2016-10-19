//http://mathbang.net/101
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int myAbs(int n) {
	return n >= 0 ? n : -n;
}

int main()
{
	int x1 = 0, y1 = 0, r1 = 0;
	int x2 = 0, y2 = 0, r2 = 0;
	
	float d= 0.0;
	
	int T = 0;
	
	scanf("%d", &T);

	int* result=new int[T];
	for (int i = 0; i < T; i++){
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		d = sqrt(pow(float(x1 - x2), 2) + pow(float(y1 - y2), 2));
		if (d == 0 && r1 == r2)
			result[i] = -1;
		else if (myAbs(r1 - r2) < d && d < r1 + r2)
			result[i] = 2;
		else if (d == r1 + r2 || d == myAbs(r1 - r2))
			result[i] = 1;
		else
			result[i] = 0;
	}

	for (int i = 0; i < T; i++)
		printf("%d\n", result[i]);

	delete(result);

	return 0;
}