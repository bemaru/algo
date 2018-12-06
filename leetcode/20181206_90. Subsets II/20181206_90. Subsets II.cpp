// 20181206_90. Subsets II.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <vector>

using namespace std;
//bool finished = false; /* ��� Ǯ�̸� ã�Ҵ��� ���� */
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
    int c[MAXCANDIDATES];   /* ���� ��ġ�� �� �� �ִ� �ĺ� ��ġ*/
    int ncandidates;        /* ���� ��ġ�� �� �� �ִ� �ĺ� ����*/
    

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
            //if (finished) return;   /* ���� ������ */
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

