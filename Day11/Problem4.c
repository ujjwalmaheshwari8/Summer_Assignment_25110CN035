// wap to write function to find factorial 
#include <stdio.h>
int factorial(int n) {
    if (n == 0 || n == 1)
        return 1; // Factorial of 0 and 1 is 1
    else
        return n * factorial(n - 1); // Recursive call
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num < 0)
        printf("Factorial is not defined for negative numbers.");
    else
        printf("Factorial of %d is: %d", num, factorial(num));
    return 0;
}