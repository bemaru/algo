//https://leetcode.com/problems/champagne-tower/description/
/*
We stack glasses in a pyramid, where the first row has 1 glass, 
the second row has 2 glasses, and so on until the 100th row.  
Each glass holds one cup (250ml) of champagne.

Then, some champagne is poured in the first glass at the top.  
When the top most glass is full, any excess liquid poured will fall equally 
to the glass immediately to the left and right of it. 
When those glasses become full, any excess champagne will fall equally 
to the left and right of those glasses, and so on.  
(A glass at the bottom row has it's excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  
After two cups of champagne are poured, the two glasses on the second row are half full.  
After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  
After four cups of champagne are poured, the third row has the middle glass half full, 
and the two outside glasses are a quarter full, as pictured below.

Now after pouring some non-negative integer cups of champagne, 
return how full the j-th glass in the i-th row is (both i and j are 0 indexed.)


Example 1:
Input: poured = 1, query_glass = 1, query_row = 1
Output: 0.0
Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.

Example 2:
Input: poured = 2, query_glass = 1, query_row = 1
Output: 0.5
Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.
 

Note:
poured will be in the range of [0, 10 ^ 9].
query_glass and query_row will be in the range of [0, 99].
*/

#include <vector>
using namespace std;


/*class Solution {
    
    public:
    double champagneTower(int poured, int query_row, int query_glass) 
    {
        vector<vector<double>> pyramid;

        for (int i = 0; i <= query_row; i++) 
        {
            vector<double> row;
            for (int j = 0; j <= i; j++) {
                row.push_back(0.0);
            }
            
            
            pyramid.push_back(row);
        }
       
        pour(poured, 0, 0, pyramid);
        
        printPyramid(pyramid);
        return pyramid[query_row][query_glass];
    }

    void pour(double poured, int i, int j, vector<vector<double>>& pyramid) 
    {
        double& cup = pyramid[i][j];
        
        if (cup < 1) {
            double need = 1.0 - cup;
            
            if (poured >= need) {
                cup += need;
                poured -= need;
            }
            else 
            {
                cup += poured;
                poured = 0;
            }
        }

        if (poured > 0) {
            pour(poured / 2, i + 1, j, pyramid);
            pour(poured / 2, i + 1, j + 1, pyramid);
        }
    }
};


#include <stdio.h>

int main()
{
    int poured = 6;
    int query_row = 4;
    int query_glass = 0;

    Solution().champagneTower(poured, query_row, query_glass);
    return 0;
}*/

#include <string>
#include <iostream>

const int kMaxRow = 100;

void printPyramid(double p[][kMaxRow+1],int row)
{
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= i; j++) 
        {
            printf("%f ", p[i][j]);
        }
        printf("\n");
    }
    
}



class Solution {
 
    public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        double pyramid[kMaxRow + 1][kMaxRow + 1] = {};
        
        pyramid[0][0] = poured;
        for (int i = 0; i <kMaxRow; i++) {
            for (int j = 0; j <= i; j++) {
                if (pyramid[i][j] >= 1) {
                    pyramid[i + 1][j] += (pyramid[i][j] - 1) / 2;
                    pyramid[i + 1][j+1] += (pyramid[i][j] - 1) / 2;
                    pyramid[i][j] = 1;
                }
            }
        }
        return pyramid[query_row][query_glass];
    }
};


int main()
{
    int poured = 4;
    int query_row = 2;
    int query_glass = 1;


    Solution().champagneTower(poured, query_row, query_glass);
    return 0;
}