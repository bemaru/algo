#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    public:
    vector<int> dailyTemperatures(vector<int>& temps) {

        int n = temps.size();

        vector<int> waits(n, 0);
        vector<int> next(101, INT_MAX); // next day with with certain temperature.

        for (int i = n - 1; i >= 0; i--) 
        {
            int earliest = INT_MAX;
            for (int t = temps[i] + 1; t <= 100; t++)  // �ڽŰ��� �񱳹����� ������ ���� �µ���
            {
                earliest = min(earliest, next[t]); // ������ ���� �µ��� üũ�Ȱ�, �׸��� �� �ε����� ���� ����
            }
            if (earliest != INT_MAX) waits[i] = earliest - i;
            next[temps[i]] = i;//���� ������ �µ����� �ε����� ����
        }
        return waits;
    }
};

void main()
{
    
}