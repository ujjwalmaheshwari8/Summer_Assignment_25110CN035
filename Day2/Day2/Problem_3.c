// WAP to find the product of digits of a number.
#include <stdio.h>
int main() {
    int a;
    int product=1;
    printf("Enter a number: ");
    scanf("%d", &a);
    while(a!=0){
        product*=a%10;
        a/=10;
    }
    printf("Product of digits: %d\n", product);
}