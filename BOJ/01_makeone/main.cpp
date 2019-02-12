// 20190212_1463_1로만들기.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
//https://www.acmicpc.net/submit/1463


static int min_cnt = 999999999;

void makeone(int i, int cnt)
{
    if (cnt > min_cnt)
        return;
    //printf("%d ", i);
    if (i == 1)
    {
        //printf("cnt : %d\n", cnt);
        min_cnt = std::min(min_cnt, cnt);
        return;
    }

    if (i % 3 == 0)
    {
        makeone(i / 3, cnt + 1);
    }

    if (i % 2 == 0)
    {
        makeone(i / 2, cnt + 1);
    }

    makeone(i - 1, cnt + 1);
}

int solution(int i)
{
    int result = 0;

    makeone(i, 0);
    //printf("min : %d\n", min_cnt);
    printf("%d", min_cnt);

    return result;
}


int main()
{
    int input;
    scanf("%d", &input);
    solution(input);
    return 0;
}

