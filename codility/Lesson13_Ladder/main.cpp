#include <stdio.h>
#include <vector>

using namespace std;

std::vector<int> cache(9999, -1);

int ascend_ways(int N)
{
    if (cache[N] == -1)
        return cache[N] = ascend_ways(N - 1) + ascend_ways(N - 2);
    else
        return cache[N];
}

vector<int> solution(vector<int> &A, vector<int> &B) 
{
    cache[1] = 1;
    cache[2] = 2;

    vector<int> result;

    int size= A.size();

    for (int i = 0; i < size; i++) 
        result.emplace_back(ascend_ways(A[i]) % static_cast<int>(pow(2, B[i])));

    return result;
}

void main()
{
    
    vector<int> A = { 4,4,5,5,1 };
    vector<int> B = {3,2,4,3,1};
    for (auto i : solution(A, B)) 
    {
        printf("%d\n", i);
    }

    
}