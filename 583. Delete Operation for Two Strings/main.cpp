#include <stdio.h>
#include <assert.h>
#include <string>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <locale>

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

class Solution {

   

    public:
    int minDistance(string word1, string word2) {
        string a = word1;
        string b = word2;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        printf("%s\n", a.c_str());
        printf("%s\n", b.c_str());


        int n = min(a.length(), b.length());
        int i = 0;
        while (a[i] == b[i] && i++ < n);

        printf("%d\n", i);

        printf("%s\n", a.substr(0, i).c_str());
        printf("%s\n", b.substr(0, i).c_str());

        string str = a.substr(0, i).c_str();
        const std::string::size_type size = str.size();
        string chars;

        unsigned short int index = 0;

        for (char c : str)
        {
            if (chars.find(c) != std::string::npos)
            {
                str.erase(str.begin() + index);
                str.resize(size);
            }
            else
            {
                chars.push_back(c);
            }
            ++index;
        }

        str.shrink_to_fit();

        printf("chars %s\n", chars.c_str());


        // 여기서부터 진짜 지우기
        int deleteCount = 0;
        unsigned short int index1 = 0;
        
        const std::string::size_type w1size = word1.size();
        for(auto c:word1)
        {
            
            if (chars.find(c) == std::string::npos && c != '\0')
            {
                word1.erase(word1.begin() + index1);
                word1.resize(w1size);
                deleteCount++;
                
            }
            index1++;
        }
        

        unsigned short int index2 = 0;
        const std::string::size_type w2size = word2.size();
        for(auto c:word2)
        {
            
            if (chars.find(c) == std::string::npos && c!='\0')
            {
                word2.erase(word2.begin() + index2);
                word2.resize(w2size);
                deleteCount++;
            }
            index2++;
        }

        
        printf("delete differents\n");
        printf("1(%d) : %s\n", word1.size(),word1.c_str());
        printf("2(%d) : %s\n", word2.size(),word2.c_str());

      
        
        
        printf("same ( %s )\n", word1 == word2?"true":"false");
        
        while (word1 != word2 && word1.size() > 0 && word2.size() > 0)
        {



            if (word1.size() >= word2.size())
            {
                for (int k = 0; k < word2.size(); k++)
                {
                    if (word1[k] != word2[k])
                    {
                        deleteCount++;
                        word1.erase(word1.begin() + k);
                        break;
                    }
                }

            }
            else
            {
                for (int k = 0; k < word1.size(); k++)
                {
                    if (word1[k] != word2[k])
                    {
                        deleteCount++;
                        word2.erase(word2.begin() + k);
                        break;
                    }
                }
            }
        }

        printf("finish\n");
        printf("1:%s\n", word1.c_str());
        printf("2:%s\n", word2.c_str());
        return deleteCount;
    }
};

void main()
{
    string word1 = "ab";
    string word2 = "bc";

    
 
    

    
    
    

    printf("result : %d\n", Solution().minDistance(word1, word2));;
    return;
}