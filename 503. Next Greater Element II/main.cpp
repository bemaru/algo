#include <stdio.h>
#include <vector>

using namespace std;

class Solution {

    //TODO : 느림, 스택적용 필요
    public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> result(n, -1);

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < i + n; j++)
            {
                if (nums[i] < nums[j%n])
                {
                    result[i] = nums[j%n];
                    break;
                }
            }
        }

        return result;

    }
};

void main()
{
    vector<int> nums = { 5,4,3,2,1 };
    Solution().nextGreaterElements(nums);
    return;
}