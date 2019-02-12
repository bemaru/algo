#include <stdio.h>

int main() 
{
    int n;
    scanf("%d", &n);

    int dp[12] = {1,1,2,4,7};

    for (int i = 5; i <= n; i++) 
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    printf("%d\n", dp[n]);
    return 0;
}