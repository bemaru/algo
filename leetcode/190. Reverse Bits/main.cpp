#include <stdio.h>
#include <stdint.h>

class Solution {
    public:
    uint32_t  reverseBits(uint32_t n) {
        uint32_t reverse = 0;
        for (int i = 0; i < 32; i++)
            reverse = (reverse << 1) + (n >> i & 1);

        return reverse;
    }
};

void printBin(uint32_t value)
{
    for (int i = 31; i >= 0; i--) 
    {
        printf("%d", (value&(1 << i))?1:0);
    }
    printf("\n");
}

void main()
{
    uint32_t input = 43261596;
    printBin(input);
    printBin(Solution().reverseBits(input));
    //printBin(result);
    
}