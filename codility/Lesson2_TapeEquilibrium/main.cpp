#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
    int sumA = 0;
    int sumB = 0;

    int indexA = 0;
    int indexB = A.size() - 1;

    
    while (indexA < indexB) 
    {
        if (sumA <= sumB) 
        {
            sumA += A[indexA++];
        }
        else 
        {
            sumB += A[indexB--];
        }
    }

    return abs(sumA - sumB);
}

void main()
{
    
}