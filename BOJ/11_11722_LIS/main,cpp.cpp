#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

auto lis(const vector<int>& arr, vector<int>& dp)
{
    //vector<int> dp(arr.size());

    for (int i = 0; i < arr.size(); i++)
    {
        dp[i] = 1; // 원소가 있다면 길이는 1부터 시작
        for (int j = 0; j < i; j++) // 자신 이전의 값을 순회
        {
            if (arr[j] < arr[i])    // 이전 값이 자신보다 작다면
            {
                dp[i] = max(dp[i], dp[j] + 1); // 이전 값 인덱스의 dp를 증가시켜 갱신한다. 단, 가장 큰 dp에서.
            }
        }
    }

    for (auto d : dp)
    {
        //cout << d << endl;
    }
    
    return *max_element(dp.begin(), dp.end());
}

void print(const vector<int> &arr)
{
    for (const auto& a : arr)
    {
        cout << a << " ";
    }
    cout << endl;
}
/*
10
1 5 2 1 4 3 4 5 2 1
*/
//http://blog.naver.com/occidere/220852732226
int main()
{
    int n = 0;
    cin >> n;
    vector<int> arr(n);
    

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    //print(arr);
    vector<int> dp1(arr.size());
    lis(arr, dp1);
    //print(dp1);
    //cout << lis(arr, dp1) << endl;

    std::reverse(arr.begin(),arr.end());

    //print(arr);
    vector<int> dp2(arr.size());
    lis(arr, dp2);
    
    std::reverse(dp2.begin(), dp2.end());
    //print(dp2);
    //cout << lis(arr, dp2) << endl;

    vector<int> dp;

    for (int i = 0; i < n; i++)
    {
        dp.emplace_back(dp1[i] + dp2[i]);
    }
   
    cout << *max_element(dp.begin(), dp.end())-1;
    
    
    return 0;
}