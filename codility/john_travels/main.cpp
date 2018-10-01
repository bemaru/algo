#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;
map<int, int> B2C_DP;
map<int, int> A2C_DP;

int countOfRange(int start, int end, vector<int> &V)
{
    int count = 0;
    for (auto i : V)
    {
        if (i >= end) 
        {
            break;
        }

        if (i > start)
        {
            count++;
        }
    }

    return count;
}

int countOfRange2(int start, int end, vector<int> &V) 
{
    int count = 0;
    for (auto i : V)
    {
        if (i >= end)
        {
            break;
        }

        if (i > start)
        {
            count+= B2C_DP[i];
        }
    }

    return count;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    // write your code in C++14 (g++ 6.2.0)
    
    
    


    // find b to c
    int size = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    sort(C.begin(), C.end());


    // make b2c dp
    

    int end = std::numeric_limits<int>::max();
    int start;

    for (int i = size-1; i >= 0; i--) 
    {
         start = B[i];
        
        if (i == size-1) 
        {
            B2C_DP[start] = countOfRange(start, end, C);
        }
        else 
        {
            B2C_DP[start] = countOfRange(start, end, C) + B2C_DP[end];
        }
        
        end = start;
        //printf("B2C_DP : %d\n", B2C_DP[start]);
    }


    // make a2b dp

    
    int result = 0;

    end = std::numeric_limits<int>::max();

    for (int i = size - 1; i >= 0; i--) 
    {
        start = A[i];

        if (i == size - 1)
        {
            A2C_DP[start] = countOfRange2(start, end, B);
        }
        else
        {
            A2C_DP[start] = countOfRange2(start, end, B) + A2C_DP[end];
        }

        end = start;
        //printf("A2C_DP : %d\n", A2C_DP[start]);
        result += A2C_DP[start];
    }
    
    return result;

}

void main()
{
    /*vector<int> A = { 29,50 };
    vector<int> B = { 61,37 };
    vector<int> C = { 38,70 };*/

    vector<int> A = { 29,29 };
    vector<int> B = { 61,61 };
    vector<int> C = { 70,70 };

    printf("sol : %d\n",solution(A, B, C));;

    
}
