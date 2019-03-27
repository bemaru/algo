#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int a[2][100001] = {};
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &a[i][j]);

        int d[2][100001] = {};
        d[0][1] = a[0][1];
        d[1][1] = a[1][1];

        for (int i = 2; i <= n; i++)
        {
            d[0][i] = max(d[1][i - 1], d[1][i - 2]) + a[0][i];
            d[1][i] = max(d[0][i - 1], d[0][i - 2]) + a[1][i];
        }

        int result = max(d[0][n], d[1][n]);
        printf("%d\n", result);
    }
    return 0;
}

//https://m.blog.naver.com/occidere/220786307316