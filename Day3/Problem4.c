// WAP TO CALCULATE LCM OF TWO NUMBERS
#include <stdio.h>
int main() {
    int a,b;
    int gcd, lcm;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b); // Calculate GCD using Euclidean algorithm
    int x = a, y = b;
    while (y != 0) {
        int temp = y;
        y = x % y;
        x = temp;
    }
    gcd = x;
    lcm = (a * b) / gcd;    // Calculate LCM using the relationship between GCD and LCM
    printf("LCM of %d and %d is: %d\n", a, b, lcm);
    return 0;
}