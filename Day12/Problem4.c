// wap to write function for perfect number
#include <stdio.h>
int isPerfect(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0)
            sum += i; // Add the divisor to the sum
    }
    return (sum == n); // A perfect number is equal to the sum of its proper divisors
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPerfect(num))
        printf("%d is a perfect number.", num);
    else
        printf("%d is not a perfect number.", num);
    return 0;
}