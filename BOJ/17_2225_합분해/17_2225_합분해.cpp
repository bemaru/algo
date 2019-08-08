// 17_2225_�պ���.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> table;

int f(int N, int K) 
{
    if (K == 1) {
        return 1;
    }

    if (N == 0) {
        return 1;
    }

    auto cache = table[N][K];
    if (cache != -1)
    {
        return cache;
    }

    long result = 0;
    for (int i = 0; i <= N; i++) 
    {
        result += f(N - i, K - 1);
    }
    
    result = result % 1000000000;

    table[N][K] = result;
    return result;
}

int main()
{
    table.assign(201, vector<int>(201, -1));

    int N, K;

    cin >> N;
    cin >> K;
    cout << f(N, K);
    
    return 0;
}

