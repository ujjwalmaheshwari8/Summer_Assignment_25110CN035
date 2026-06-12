// wap to print character pyramid
#include <stdio.h>
int main() {
    int rows;
    rows=5; // You can change this value to print more or fewer rows
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        for (int k = 1; k <= i; k++) {
            printf("%c ", 'A' + k - 1);
        }
        for (int l = i - 1; l >= 1; l--) {
            printf("%c ", 'A' + l - 1);
        }
        printf("\n");
    }
    return 0;
}