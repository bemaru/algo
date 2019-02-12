#include <stdio.h>

int main()
{
    int input;
    scanf("%d", &input);

    int dp[1000] = {};
    dp[0] = 1, dp[1] = 1;

    for (int i = 2; i <= input; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2])%10007;
    }

    printf("%d", dp[input]);
    return 0;
}