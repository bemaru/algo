// 12_연속합_1912.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
//https://1ilsang.blog.me/221384920352
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    vector<int> d(n);
    d[0] = a[0];
    for (int i = 1; i < n; i++) 
        d[i] = max(a[i], d[i - 1] + a[i]);

    cout << *max_element(d.begin(), d.end());
    return 0;
}

