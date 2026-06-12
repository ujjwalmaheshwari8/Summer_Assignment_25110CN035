// wap to write to function to find maximum 
#include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int main() {
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    int result = max(num1, num2);
    printf("The maximum of %d and %d is: %d", num1, num2, result);
    return 0;
}