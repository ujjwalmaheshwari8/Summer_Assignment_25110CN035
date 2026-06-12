// wap to write function to check prime
#include <stdio.h>
int isPrime(int n) {
    if (n <= 1)
        return 0; // Not prime
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0; // Not prime
    }
    return 1; // Prime
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPrime(num))
        printf("%d is a prime number.", num);
    else
        printf("%d is not a prime number.", num);
    return 0;
}