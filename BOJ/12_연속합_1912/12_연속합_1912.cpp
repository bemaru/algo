// 12_������_1912.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

