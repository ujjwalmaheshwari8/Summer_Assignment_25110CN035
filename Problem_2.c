#include <stdio.h>
int main() {
    int a;
    int multiply=1;
    printf("enter the number: ");
    scanf("%d", &a);
    for(int i=1;i<=10;i++){
        multiply=a*i;
        printf("%d X %d = %d\n", a, i, multiply);
    }
    return 0;
}