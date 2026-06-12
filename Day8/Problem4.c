// wap to print repeated number pattern
#include <stdio.h>
int main() {
    int rows;
    rows=5; // You can change this value to print more or fewer rows
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}