#include "stdafx.h"
/*
unordered_set ����ó���߰�
�׽�Ʈ 1 ��	��� (0.30ms, 3.86MB)
�׽�Ʈ 2 ��	��� (0.01ms, 3.86MB)
�׽�Ʈ 3 ��	��� (0.01ms, 3.8MB)
�׽�Ʈ 4 ��	��� (3.64ms, 4.32MB)
�׽�Ʈ 5 ��	��� (2.40ms, 3.92MB)
�׽�Ʈ 6 ��	��� (0.08ms, 3.78MB)
�׽�Ʈ 7 ��	��� (0.09ms, 3.85MB)

unordered_set
�׽�Ʈ 1 ��	��� (0.38ms, 3.84MB)
�׽�Ʈ 2 ��	��� (0.01ms, 3.87MB)
�׽�Ʈ 3 ��	��� (0.01ms, 3.87MB)
�׽�Ʈ 4 ��	��� (5.15ms, 4.21MB)
�׽�Ʈ 5 ��	��� (3.28ms, 3.88MB)
�׽�Ʈ 6 ��	��� (0.10ms, 3.88MB)
�׽�Ʈ 7 ��	��� (0.10ms, 3.85MB)

set
�׽�Ʈ 1 ��	��� (0.43ms, 3.96MB)
�׽�Ʈ 2 ��	��� (0.01ms, 3.81MB)
�׽�Ʈ 3 ��	��� (0.01ms, 3.86MB)
�׽�Ʈ 4 ��	��� (7.33ms, 4.57MB)
�׽�Ʈ 5 ��	��� (4.94ms, 4.24MB)
�׽�Ʈ 6 ��	��� (0.10ms, 3.82MB)
�׽�Ʈ 7 ��	��� (0.10ms, 3.86MB)

vector
�׽�Ʈ 1 ��	��� (0.13ms, 3.89MB)
�׽�Ʈ 2 ��	��� (0.00ms, 3.84MB)
�׽�Ʈ 3 ��	��� (0.01ms, 3.83MB)
�׽�Ʈ 4 ��	��� (10.59ms, 12.1MB)
�׽�Ʈ 5 ��	��� (9.43ms, 11.5MB)
�׽�Ʈ 6 ��	��� (0.02ms, 3.87MB)
�׽�Ʈ 7 ��	��� (0.02ms, 3.76MB)
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

