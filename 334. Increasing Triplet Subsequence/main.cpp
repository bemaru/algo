/*
Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k
such that arr[i] < arr[j] < arr[k] given 0 ¡Â i < j < k ¡Â n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
    public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;
        for (int x : nums) {
            if (x <= first)
                first = x;
            else if (x <= second)
                second = x;
            else
                return true;
        }
        return false;
    }
};

    

void main()
{
    vector<int> nums = {3,4,1,5,2};//false
    //vector<int> nums = { 4,5,1,2,3 };//true


    if (Solution().increasingTriplet(nums)) {
        printf("true\n");
    }
    else {
        printf("false\n");
    }
    return;
}