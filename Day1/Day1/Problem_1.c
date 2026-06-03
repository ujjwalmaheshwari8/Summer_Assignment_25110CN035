#include <stdio.h>
int main() {
    int a;
    int sum=0;
    printf("enter the number: ");
    scanf("%d", &a);    
    for(int i=0;i<=a;i++){
        sum=sum+i;
    }
    printf("The sum is: %d\n", sum);
    return 0;
}