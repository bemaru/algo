#include "stdafx.h"
/*
unordered_set 예외처리추가
테스트 1 〉	통과 (0.30ms, 3.86MB)
테스트 2 〉	통과 (0.01ms, 3.86MB)
테스트 3 〉	통과 (0.01ms, 3.8MB)
테스트 4 〉	통과 (3.64ms, 4.32MB)
테스트 5 〉	통과 (2.40ms, 3.92MB)
테스트 6 〉	통과 (0.08ms, 3.78MB)
테스트 7 〉	통과 (0.09ms, 3.85MB)

unordered_set
테스트 1 〉	통과 (0.38ms, 3.84MB)
테스트 2 〉	통과 (0.01ms, 3.87MB)
테스트 3 〉	통과 (0.01ms, 3.87MB)
테스트 4 〉	통과 (5.15ms, 4.21MB)
테스트 5 〉	통과 (3.28ms, 3.88MB)
테스트 6 〉	통과 (0.10ms, 3.88MB)
테스트 7 〉	통과 (0.10ms, 3.85MB)

set
테스트 1 〉	통과 (0.43ms, 3.96MB)
테스트 2 〉	통과 (0.01ms, 3.81MB)
테스트 3 〉	통과 (0.01ms, 3.86MB)
테스트 4 〉	통과 (7.33ms, 4.57MB)
테스트 5 〉	통과 (4.94ms, 4.24MB)
테스트 6 〉	통과 (0.10ms, 3.82MB)
테스트 7 〉	통과 (0.10ms, 3.86MB)

vector
테스트 1 〉	통과 (0.13ms, 3.89MB)
테스트 2 〉	통과 (0.00ms, 3.84MB)
테스트 3 〉	통과 (0.01ms, 3.83MB)
테스트 4 〉	통과 (10.59ms, 12.1MB)
테스트 5 〉	통과 (9.43ms, 11.5MB)
테스트 6 〉	통과 (0.02ms, 3.87MB)
테스트 7 〉	통과 (0.02ms, 3.76MB)
*/


#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

unordered_set<int> operate(unordered_set<int> operands1, unordered_set<int> operands2)
{
    unordered_set<int> result;
    for (auto operand1 : operands1) 
    {
        for (auto operand2 : operands2) 
        {
            result.insert(operand1 + operand2);
            
            if (operand1 - operand2 > 0) 
            {
                result.insert(operand1 - operand2);
            }
            
            result.insert(operand1 * operand2);
            
            if (operand2>0) 
            {
                result.insert(operand1 / operand2);
            }
        }
    }
    return result;
}

int solution(int N, int number) 
{
    vector<unordered_set<int>> result(9);

    for (int i = 1; i <= 8; i++) 
    {
        unordered_set<int> subResult;
        if (i == 1) 
        {
            subResult.insert(N);
        }
        else 
        {
            for (int j = 1; j <= i / 2; j++) 
            {
                unordered_set<int> subsub = operate(result[i - j], result[j]);
                subResult.insert(subsub.begin(), subsub.end());
            }
            
            int base = 1;
            for (int j = 1; j < i; j++) 
            {
                base *= 10;
                base += 1;
            }
            subResult.insert(base*N);
        }

        for (auto sr : subResult) 
        {
            if (sr == number) 
            {
                return i;
            }
        }

        result[i] = subResult;
    }
    
    return -1;
}

void main()
{
    printf("sol : %d",solution(5, 12));
}

