#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    public:

    map<int, bool> visited;
    int arrayNesting(vector<int>& nums) {
        int visitLenMax = 0;

        for (int i = 0; i < nums.size(); i++) 
        {
            int z = i;
            int visitLen = 0;
            while (!visited[z]) 
            {
                visited[z] = true;
                z = nums[z];
                visitLen++;
            }
            visitLenMax = max(visitLenMax, visitLen);
        }
        return visitLenMax;
    }
};

void main()
{
    return; 
}