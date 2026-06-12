// wap to find largest prime factor of a number
#include <stdio.h>
int main()
{
    int num, largest = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 2; i <= num; i++)
    {
        while (num % i == 0)
        {
            largest = i;
            num /= i;
        }
    }
    if (largest != 0)
    {
        printf("Largest prime factor is: %d", largest);
    }
    else
    {
        printf("No prime factors found.");
    }
    return 0;
}