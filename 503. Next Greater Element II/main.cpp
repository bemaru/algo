#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
    
    public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> sorted = nums;
        std::sort(sorted.begin(), sorted.end());
        
        for (auto x : sorted) 
        {
            printf("%d ", x);
        }

        vector<int> result;

        bool found;
        for (auto a : nums) 
        {
            found = false;
            for (auto b : sorted) 
            {
                if (a < b) 
                {
                    printf("%d\n", b);
                    result.emplace_back(b);
                    found = true;
                    break;
                }
            }
            if (found == false)
            {
                result.emplace_back(-1);
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