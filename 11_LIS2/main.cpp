#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> dp(n);

    for (int i = 0; i < n; i++)
    {
        //dp[i] = 1; // ���Ұ� �ִٸ� ���̴� 1���� ����
        dp[i] = arr[i];

        for (int j = 0; j < i; j++) // �ڽ� ������ ���� ��ȸ
        {
            if (arr[i] > arr[j])    // ���� ���� �ڽź��� �۴ٸ�
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
                //dp[i] = max(dp[i], dp[j] + 1); // ���� �� �ε����� dp�� �������� �����Ѵ�. ��, ���� ū dp����.
            }
        }
    }
    
    cout << *max_element(dp.begin(), dp.end());
    
    return 0;
}