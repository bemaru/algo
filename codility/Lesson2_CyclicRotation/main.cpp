#include <stdio.h>
#include <vector>
using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    vector<int> S(n,0);
    
    K = K % n;
    for (int i = 0; i < n; i++) 
    {
        S[i] = A[(n-K+i) %n];
    }

    return S;
}

void main()
{
    vector<int> A = { 3, 8, 9, 7, 6 };
    vector<int> S = solution(A, 3);
    for (auto a : S) 
    {
        printf("%d, ", a);
    }
}