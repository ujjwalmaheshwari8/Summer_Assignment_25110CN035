// wap to recursive reverse number
#include <stdio.h>
int reverseNumber(int n, int reversed) {
    if (n == 0)
        return reversed;
    else {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        return reverseNumber(n / 10, reversed);
    }
}
int main(){
    int n, reversed = 0;
    printf("Enter a number: ");
    scanf("%d", &n);
    reversed = reverseNumber(n, reversed);
    printf("Reversed number: %d", reversed);
    return 0;
}