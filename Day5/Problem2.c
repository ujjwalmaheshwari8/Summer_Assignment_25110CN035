// wap to check strong number
#include <stdio.h>
int main()
{
    int num, originalNum, digit, sum = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    originalNum = num;
    while (num > 0)
    {
        digit = num % 10;
        sum += factorial(digit);
        num /= 10;
    }
    if (sum == originalNum)
    {
        printf("%d is a strong number.", originalNum);
    }
    else
    {
        printf("%d is not a strong number.", originalNum);
    }
    return 0;
}
int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}