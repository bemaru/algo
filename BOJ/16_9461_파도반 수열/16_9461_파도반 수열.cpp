// 16_9461_�ĵ��� ����.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

auto padovan(int k)
{
    vector<unsigned long long> p(k + 1);
    p = {0,1,1,1,2,2};

    for (int i = 6; i <= k; i++)
    {
        p[i] = p[i - 1] + p[i - 5];
    }

    return p[k];
}

int main()
{
    int T;
    cin >> T;

    int i;
    while(T--)
    {
        cin >> i;
        cout << padovan(i) << endl;
    }
    
    return 0;
}

