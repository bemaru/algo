#include <stdio.h>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> dp(n+1, vector<int>(10, 0));

    for (int i = 0; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= 9; j++) //수는 0으로 시작할 수 있다.
        {
            for (int k = 0; k <= j; k++) // 길이n인 j로 끝나는 오르막수 개수 = n-1길이의 j보다 작거나 같은 오르막 수 개수들의 합
            {
                dp[i][j] += (dp[i - 1][k]) % 10007;
            }       
        }
    }

    long sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += dp[n][i];
    }
    printf("%d", sum % 10007);

    return 0;
}