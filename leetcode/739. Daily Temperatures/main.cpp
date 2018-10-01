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
            for (int t = temps[i] + 1; t <= 100; t++)  // 자신과의 비교범위는 나보다 높은 온도들
            {
                earliest = min(earliest, next[t]); // 나보다 높은 온도에 체크된것, 그리고 그 인덱스가 가장 작은
            }
            if (earliest != INT_MAX) waits[i] = earliest - i;
            next[temps[i]] = i;//다음 날들의 온도들의 인덱스를 저장
        }
        return waits;
    }
};

void main()
{
    
}