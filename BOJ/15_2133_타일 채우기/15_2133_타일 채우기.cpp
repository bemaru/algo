// 15_2133_타일 채우기.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
//https://mizzo-dev.tistory.com/entry/baekjoon2133
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 0;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2)
    {
        dp[i] = dp[i - 2] * 3;
        for (int j = 4; i - j >= 0; j += 2)
        {
            dp[i] += dp[i - j] * 2;
        }
    }

    cout << dp[n];

    return 0;
}

