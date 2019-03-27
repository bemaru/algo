#include <stdio.h>
#include <vector>

using std::vector;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(2, 0));

    dp[1] = { 0, 1 };
    
    for (int i = 2; i <= n; i++) 
    {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }

    unsigned long long sum = 0;
    for (auto i : dp[n])
        sum += i;

    printf("%llu\n", sum);


    /*vector<unsigned long long> d(n + 1);
    d[1] = 1;

    for (int i = 2; i <= n; i++) 
    {
        d[i] = d[i - 2] + d[i - 1];
    }

    printf("%llu\n", d[n]);*/

    return 0;
}