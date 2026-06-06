// wap to count set bits in a number
#include <stdio.h>
int main()
{
    int num, count = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    while (num > 0)
    {
        count += num & 1; // Increment count if the least significant bit is set
        num >>= 1; // Right shift the bits to check the next bit
    }
    printf("Number of set bits: %d", count);
    return 0;
}