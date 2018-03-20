/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.


Example:

Input: "cbbd"

Output: "bb"
*/
#include <string>
#include <algorithm>
using namespace std;


class Solution {
    int index;
    int maxLen = 0;
    int oddLen = -1;
    int evenLen = 0;
    public:
    string longestPalindrome(string s) {

        for (int i = 0; i < s.length(); i++) {

            oddLen = -1;
            evenLen = 0;

            for (int j = 0; j<=s.length() / 2 && s[i - j] == s[i + j]; j++) {
                oddLen += 2;

                if (oddLen > maxLen) {
                    maxLen = oddLen;
                    index = i - j;
                }
            }
            

            for (int j = 1; j <= s.length() / 2 && s[i - j + 1] == s[i + j]; j++) {
                evenLen += 2;
                
                if (evenLen > maxLen) {
                    maxLen = evenLen;
                    index = i - j+1;
                }
            }
        }

        return s.substr(index,maxLen);
    }
};

void main()
{
    string s = "dacabzzazzc";
    printf("%s\n", Solution().longestPalindrome(s).c_str());
}