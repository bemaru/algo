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
        //dp[i] = 1; // 원소가 있다면 길이는 1부터 시작
        dp[i] = arr[i];

        for (int j = 0; j < i; j++) // 자신 이전의 값을 순회
        {
            if (arr[i] > arr[j])    // 이전 값이 자신보다 작다면
            {
                dp[i] = max(dp[i], dp[j] + arr[i]);
                //dp[i] = max(dp[i], dp[j] + 1); // 이전 값 인덱스의 dp를 증가시켜 갱신한다. 단, 가장 큰 dp에서.
            }
        }
    }
    
    cout << *max_element(dp.begin(), dp.end());
    
    return 0;
}