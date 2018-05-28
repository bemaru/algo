#include <stdio.h>
#include <algorithm>
// https://app.codility.com/demo/results/trainingN257MW-X5K/
int solution(int N) 
{
    int cnt = 0;
    int max = 0;
    int oneCount = 0;

    while (N > 0) 
    {
        if (N & 1)
        { 
            oneCount++;
            if (oneCount > 1)
            {
                max = std::max(cnt, max);
            }
            
            
            cnt = 0;

        }
        else 
        {
            cnt++;
        }
       
        printf("%d", N & 1);

        N >>= 1;
        
    }
    return max;   
}

void main()
{
    //printf("\n%d\n", solution(529));
    printf("\n%d\n",solution(1));
    
}