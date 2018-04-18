#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct Center {
    int i;
    int j;
    Center(int i, int j) :i(i), j(j) {};
};
class Solution {
    public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
                  
        int result = 0;
        if (N % 2 == 0)
        {
            vector<int> v;
            v.push_back(find(N - 1, Center(N / 2 - 1, N / 2 - 1), mines));
            v.push_back(find(N - 1, Center(N / 2 - 1, N / 2), mines));
            v.push_back(find(N - 1, Center(N / 2, N / 2 - 1), mines));
            v.push_back(find(N - 1, Center(N / 2, N / 2), mines));
            return *max_element(v.begin(), v.end());
        }
        else
        {
            return find(N, Center(N/2,N/2), mines);
        }
        
    }

    int find(int N, Center c, vector<vector<int>>& mines)
    {
        if (N < 0)
            return 0;

        bool hasMine = false;

        
        for (auto mine : mines) {
            if (N == 1) 
            {
                if (c.i == mine[0] && c.j == mine[1]) {
                    hasMine = true;
                    break;
                }
            }
            else 
            {
                if ( ( mine[0]>=(c.i-N/2) && mine[0]<=(c.i+N/2) && mine[1]>=(c.j-N/2) && mine[1]<=(c.j+N/2)) 
                    && (c.i == mine[0] || c.j == mine[1]) ) 
                {
                    hasMine = true;
                    break;
                }
            }
        }

        
        

        if (hasMine == false) {
            return N / 2 + 1;
        }

        vector<int> v;
        
        v.push_back(find(N - 2, Center(c.i - 1, c.j - 1), mines));
        v.push_back(find(N - 2, Center(c.i - 1, c.j), mines));
        v.push_back(find(N - 2, Center(c.i - 1, c.j + 1), mines));

        v.push_back(find(N - 2, Center(c.i, c.j - 1), mines));
        v.push_back(find(N - 2, Center(c.i, c.j), mines));
        v.push_back(find(N - 2, Center(c.i, c.j + 1), mines));

        v.push_back(find(N - 2, Center(c.i + 1, c.j - 1), mines));
        v.push_back(find(N - 2, Center(c.i + 1, c.j), mines));
        v.push_back(find(N - 2, Center(c.i + 1, c.j + 1), mines));

        return *max_element(v.begin(), v.end());
    }
};

void main()
{
 
    /*vector < vector<int>> mines = { {0,0},{0,1},{1,0} };
    printf("%d\n", Solution().orderOfLargestPlusSign(2, mines));*/

    /*vector < vector<int>> mines = { { 0,0 },{ 0,1 },{ 0,2 },{ 0,3 },{ 1,0 },{ 1,1 },{ 1,2 },{ 1,3 },{ 1,4 },{ 2,2 },{ 2,4 },{ 3,0 },{ 3,2 },{ 3,3 },{ 3,4 },{ 4,0 },{ 4,1 },{ 4,2 },{ 4,3 },{ 4,4 } };

    printf("%d\n", Solution().orderOfLargestPlusSign(5, mines));*/

    

    /*vector < vector<int>> mines = { { 0, 2 },{ 0,3 },{ 2,2 },{ 2,4 },{ 4,0 },{ 4,1 },{ 4,2 },{ 4,4 } };
    printf("%d\n", Solution().orderOfLargestPlusSign(5, mines));*/

    vector < vector<int>> mines = { { 0, 1 },{ 0,2 },{ 0,3 },{ 0,4 },{ 1,0 },{ 1,1 },{ 1,2 },{ 1,3 },{ 1,4 },{ 2,0 },{ 2,1 },{ 2,3 },{ 2,4 },{ 3,1 },{ 3,2 },{ 3,3 },{ 3,4 },{ 4,0 },{ 4,1 },{ 4,2 },{ 4,3 },{ 4,4 } };
    printf("%d\n", Solution().orderOfLargestPlusSign(5, mines));
    
}