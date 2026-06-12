// wap to convet binary number to decimal
#include <stdio.h>
int main()
{
    int binary[32], decimal = 0, i = 0;
    printf("Enter a binary number: "); // take input binary digits one by one and make sure last digit is end with -1
    while (1)
    {
        int bit;
        scanf("%d", &bit);
        if (bit == -1)
            break;
        binary[i] = bit;
        i++;
    }
    for (int j = 0; j < i; j++)
    {
        decimal += binary[j] * (1 << (i - j - 1));
    }
    printf("Decimal representation: %d", decimal);
    return 0;
}
