/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
An island is surrounded by water 
and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1


Example 2:

11000
11000
00100
00011
Answer: 3

*/

#include <vector>
using namespace std;

class Solution {
    int count = 0;
    public:
    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid,int i,int j) {
        if (i>=0 && i<grid.size() && j>=0 && j < grid[i].size() && grid[i][j] == '1') {
            grid[i][j] = '0';
            dfs(grid, i+1, j);//ก่
            dfs(grid, i, j+1);//กๆ
            dfs(grid, i-1, j);//ก้
            dfs(grid, i, j-1);//ก็
        }
    }
};


void printGird(const vector<vector<char>>& grid)
{
    for (auto v : grid) {
        for (auto c : v)
            printf("%c", c);
        printf("\n");
    }
}

void main()
{
    vector<vector<char>> grid = { 
        { '1','1','0','0','0' },
        { '1','1','0','0','0' },
        { '0','0','1','0','0' }, 
        { '0','0','0','1','1' },
    };;
  
    printGird(grid);
    
    printf("numIslands = %d\n",Solution().numIslands(grid));

    printGird(grid);
    
    return;
}