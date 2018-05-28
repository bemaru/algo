#include <stdio.h>
#include <vector>

std::vector<int> result(9999, -1);


class Solution {

    public:
    enum STATE { READY,RUNNING };
    Solution()
    {
        result[0] = 0;
        result[1] = 1;
        result[2] = 2;
    }
    
    int climbStairs(int n) 
    {
        if (result[n] == -1)
            return result[n] = climbStairs(n - 1) + climbStairs(n - 2);
        else 
            return result[n];
    }
};

void main()
{   
    int n = 4;
    printf("%d\n", Solution().climbStairs(n));
    return;
}