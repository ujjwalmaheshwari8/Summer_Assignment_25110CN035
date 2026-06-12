// wap to print number pyramid
#include <stdio.h>
int main() {
    int rows;
    rows=5; // You can change this value to print more or fewer rows
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            printf("%d ", k);
        }
        for (int l = i - 1; l >= 1; l--) {
            printf("%d ", l);
        }
        printf("\n");
    }
    return 0;
}