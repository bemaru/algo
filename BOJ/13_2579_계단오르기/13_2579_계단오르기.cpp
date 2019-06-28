// 13_2579_계단오르기.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
//https://mygumi.tistory.com/100
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    dp[0] = a[0];
    dp[1] = a[0] + a[1];
    dp[2] = max(a[0] + a[2], a[1] + a[2]);

    for (int i = 3; i < n; i++)
    {
        dp[i] = max(dp[i - 3] + a[i] + a[i - 1], dp[i - 2] + a[i]);
    }

    cout << dp[n - 1];
    return 0;
}

