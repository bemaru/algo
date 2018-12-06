#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
    int search(vector<int>& nums, int target) {
        int result = 0;
        for (auto item : nums)
        {
            if (item == target)
                return result;
            result++;
        }
        return -1;
    }
};

void main()
{
    vector<int> nums = { 4,5,6,7,0,1,2 };
    std::cout << Solution().search(nums, 0) << std::endl;
}