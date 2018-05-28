#include <stdio.h>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    
    vector<bool> oddCheck(1000000, false);
        
    for (auto a : A) 
    {
        oddCheck[a] = !oddCheck[a];
    }

    for (auto a : A) 
    {
        if (oddCheck[a])
            return a;
    }
}

void main()
{
    vector<int> A = {9,3,9,3,9,7,9};
    printf("%d\n", solution(A));
}