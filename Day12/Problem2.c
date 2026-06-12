// wap to write function for armstrong
#include <stdio.h>
int isArmstrong(int n) {
    int original = n, sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit * digit; // Cube of the digit
        n /= 10;
    }
    return (original == sum);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isArmstrong(num))
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);
    return 0;
}