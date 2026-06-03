// WAP TO CALCULATE GCD OF TWO NUMBERS
#include <stdio.h>
int main() {
    int a,b;
    int gcd;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b); // Calculate GCD using Euclidean algorithm
    int x = a, y = b;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    gcd = x;
    printf("GCD of %d and %d is: %d\n", a, b, gcd);      
    return 0;
}