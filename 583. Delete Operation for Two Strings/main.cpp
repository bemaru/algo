#include <stdio.h>
#include <assert.h>
#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <locale>
#include <vector>

using namespace std;

/*
Given two words word1 and word2, 
find the minimum number of steps required to make word1 and word2 the same, 
where in each step you can delete one character in either string.

Example 1:
Input: "sea", "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Note:
The length of given words won't exceed 500.
Characters in given words can only be lower-case letters.
*/

// 가장 긴 똑같은 것을 찾으면?

// A utility function to find maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}
/* Returns length of longest common substring of X[0..m-1]
and Y[0..n-1] */
    int LCSubStr(string& X,string& Y)
    {
        int totalResult = 0;
        printf("LCSubStr : ");
        // Create a table to store lengths of longest common suffixes of
        // substrings.   Notethat LCSuff[i][j] contains length of longest
        // common suffix of X[0..i-1] and Y[0..j-1]. The first row and
        // first column entries have no logical meaning, they are used only
        // for simplicity of program
        int m = X.size();
        int n = Y.size();

        int** LCSuff = new int*[m+1];
        for (int i = 0; i < m + 1; ++i)
            LCSuff[i] = new int[n+1];
        int result = 0;  // To store length of the longest common substring

                         /* Following steps build LCSuff[m+1][n+1] in bottom up fashion. */
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                    LCSuff[i][j] = 0;

                else if (X[i - 1] == Y[j - 1])
                {
                    printf("%c", X[i - 1]);
                    totalResult++;
                    LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                    result = max(result, LCSuff[i][j]);
                }
                else LCSuff[i][j] = 0;
            }
        }
        printf("\n");
        return result;
        //return totalResult;
    }

        class Solution {


            public:
            int minDistance(string word1, string word2) {
                int d = 0;
                printf("1:%s\n", word1.c_str());
                printf("2:%s\n", word2.c_str());

                size_t prevSize = word1.size();
                word1.erase(std::remove_if(word1.begin(),
                    word1.end(),
                    [&](unsigned char x) {return word2.find(x) == string::npos; }), word1.end());
                printf("word1 erase count = %d\n", prevSize - word1.size());
                d += (prevSize - word1.size());

                prevSize = word2.size();
                word2.erase(std::remove_if(word2.begin(),
                    word2.end(),
                    [&](unsigned char x) {return word1.find(x) == string::npos; }), word2.end());

                printf("word2 erase count = %d\n", prevSize - word2.size());
                d += (prevSize - word2.size());

                printf("1:%s\n", word1.c_str());
                printf("2:%s\n", word2.c_str());
        
                printf("d = %d\n", d);
        
        
                /*int k = 0;
                while (word1.size() > 0 && word2.size() > 0 && k < word1.size() && k< word2.size() )
                {
                    if (word1[k] != word2[k]) 
                    {
                        string* temp = &word1;
                        if (word1.size() < word2.size())
                            temp = &word2;

                        temp->erase(temp->begin() + k);
                        d++;
                        continue;
                    }
                    k++;
                }

                d += abs(static_cast<int>(word1.size() - word2.size()));*/
                printf("LCSubStr : %d\n",LCSubStr(word1, word2));
        
                d += word1.size() + word2.size() - (2 * (LCSubStr(word1, word2)));


                printf("finish\n");
                printf("1:%s\n", word1.c_str());
                printf("2:%s\n", word2.c_str());
                return d;
            }
        };

void main()
{
    //string word1 = "horse";
    //string word2 = "ros";

    string word1 = "mart";
    string word2 = "karma";
    
 
    

    
    
    

    printf("result : %d\n", Solution().minDistance(word1, word2));;
    return;
}