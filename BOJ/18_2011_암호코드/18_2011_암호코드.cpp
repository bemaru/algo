// 18_2011_암호코드.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> dp(5000,-1);

    string code;
    cin >> code;

    int mod = 1000000;
    
    for (auto c : code) 
    {
        auto i = c - '0';
        if (!(i >= 1 && i <= 9)) 
        {
            cout << 0;
            return 0;
        }
    }

    dp[0] = 1;
    dp[1] = dp[0] + (stoi(code.substr(0, 2)) <= 26 ? 1 : 0);
        
    for (int i = 2; i < code.length(); i++) 
    {
        dp[i] = (dp[i - 1] + (stoi(code.substr(i - 1, 2)) <= 26 ? dp[i - 2] : 0))%mod;
    }

    cout << dp[code.length()-1] << endl;
    return 0;
}
    

