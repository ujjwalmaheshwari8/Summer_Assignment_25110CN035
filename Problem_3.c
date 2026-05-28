#include <stdio.h>
int main() {
    int a;
    int factorial=1;
    printf("enter the number: ");
    scanf("%d", &a);    
    for(int i=1;i<=a;i++){
       factorial=factorial*i;
    }
    printf("The factorial is: %d\n", factorial);
    return 0;
}