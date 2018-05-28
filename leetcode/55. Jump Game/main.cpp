#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    bool canJump(vector<int>& nums) {

        int n = 0;
        int i = 0;
        for (; i < nums.size(); i++)
        {
            if (n < i)
            {
                break;
            }
            n = max(i + nums[i], n);
            
            
        }      
        return i >= nums.size();
    }
};

void main()
{
    vector<int> nums = {2,3,1,1,4};
    //vector<int> nums = { 3,2,1,0,4 };
    printf("%d",Solution().canJump(nums));
    return;
}