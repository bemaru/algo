// 20181206_90. Subsets II.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>

using namespace std;
//bool finished = false; /* 모든 풀이를 찾았는지 여부 */
static const int MAXCANDIDATES = 100;

bool is_a_solution(int k, int n)
{
    return k == n;
}

void construct_candidates(int c[], int *ncandidates)
{
    c[0] = true;
    c[1] = false;
    *ncandidates = 2;
}

void process_solution(int a[], int k)
{
    int i;
    printf("{");
    for (int i = 1; i <= k; i++)
    {
        if (a[i] == true)
        {
            printf(" %d", i);
        }
    }
    printf(" }\n");
}

void backtrack(int a[], int k, int n)
{
    int c[MAXCANDIDATES];   /* 다음 위치가 될 수 있는 후보 위치*/
    int ncandidates;        /* 다음 위치가 될 수 있는 후보 개수*/
    

    if (is_a_solution(k, n))
    {
        process_solution(a, k);
    }
    else
    {
        k = k + 1;
        
        printf("k : %d\n", k);
        c[0] = 1;
        c[1] = 0;
        ncandidates = 2;
        //construct_candidates(c, &ncandidates);
        for (int i = 0; i < ncandidates; i++)
        {
            a[k] = c[i];
            backtrack(a, k, n);
            //if (finished) return;   /* 일찍 종료함 */
        }
    }
}

class Solution {

    public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> vv;
        return vv;
    }

};

int main()
{

    int a[4] = { 1,2,3};
    backtrack(a, 0, 3);

}

