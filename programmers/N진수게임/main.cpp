#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string convert(int n, int base) 
{
    if (n == 0) 
    {
        return "0";
    }

    static string hexdigit = "0123456789ABCDEF";
    string result = "";
    while (n > 0) 
    {
        result += hexdigit[n%base];
        n /= base;
    }
    std::reverse(result.begin(),result.end());
    return result;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string seq = "";
    for (int i = 0; i < t*m; i++) 
    {
        seq += convert(i, n);
    }

    for (int i = p-1; i < t*m; i+=m) 
    {
        answer+=seq[i];
    }

    return answer;
}

void main() 
{
    int n, t, m, p;
    n = 16;
    t = 16;
    m = 2;
    p = 1;

    solution(n, t, m, p);
    
}