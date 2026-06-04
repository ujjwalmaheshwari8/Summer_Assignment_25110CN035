// WAP TO CHECK WHETHER A NUMBER IS PRIME OR NOT
#include <stdio.h>
int main() {
    int a;
    int prime = 1; // Assume a is prime until proven otherwise
    printf("Enter a number: ");
    scanf("%d", &a);
    if (a <= 1) {
        prime = 0; // 0 and 1 are not prime
    } else {
        for (int i = 2; i <= a / 2; i++) {
            if (a % i == 0) {
                prime = 0; // a is divisible by i, hence not prime
                break;
            }
        }
    }
    if (prime) {
        printf("%d is a prime number.\n", a);
    } else {
        printf("%d is not a prime number.\n", a);
    }
    return 0;
}