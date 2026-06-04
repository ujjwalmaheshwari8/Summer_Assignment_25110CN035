//WAP TO PRINT ARMSTRONG NUMBERS IN AN INTERVAL
#include <stdio.h>
int main() {
    int lower, upper, i, original, remainder, result;
    printf("Enter the lower and upper limits: ");
    scanf("%d %d", &lower, &upper);
    printf("Armstrong numbers between %d and %d are: ", lower, upper);
    for(i = lower; i <= upper; i++) {
        original = i;
        result = 0;
        while (original != 0) {
            remainder = original % 10;
            result += remainder * remainder * remainder;
            original /= 10;
        }
        if (result == i) {
            printf("%d ", i);
        }
    }
    return 0;
}