// WAP to reverse a number.
#include <stdio.h>
int main() {
    int a;
    int reverse = 0;
    printf("Enter a number: ");
    scanf("%d", &a);
    while(a != 0) {
        reverse = reverse * 10 + a % 10;
        a /= 10;                        
    }
    printf("Reversed number: %d\n", reverse);

    return 0;
}