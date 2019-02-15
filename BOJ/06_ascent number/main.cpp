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
        for (int j = 0; j <= 9; j++) //���� 0���� ������ �� �ִ�.
        {
            for (int k = 0; k <= j; k++) // ����n�� j�� ������ �������� ���� = n-1������ j���� �۰ų� ���� ������ �� �������� ��
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