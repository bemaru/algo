#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> dp(101, vector<int>(11, 0));

    for (int i = 1; i <= 9; i++) //(0으로 시작하는 수는 없다.)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = dp[i - 1][1];
        for (int j = 1; j <= 9; j++)
        {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
    }

    long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += dp[n][i];
    }
    printf("%d", sum % 1000000000);

    return 0;
}