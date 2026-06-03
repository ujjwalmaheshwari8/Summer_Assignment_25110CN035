#include <stdio.h>
int main() {
    int a;
    int pallindrome = 0;
    printf("Enter a number: ");
    scanf("%d", &a);
    int temp = a;
    while(temp != 0) {
        pallindrome = pallindrome * 10 + temp % 10;
        temp /= 10;                        
    }
    if(a == pallindrome) {
        printf("The number is a palindrome.\n");
    } else {
        printf("The number is not a palindrome.\n");
    }
    return 0;
}