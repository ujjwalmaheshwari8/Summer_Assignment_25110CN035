// wap to print hollow square pattern
#include <stdio.h>
int main() {
    int size;
    size=5; // You can change this value to print a larger or smaller square
    for (int i = 1; i <= size; i++) {
        for (int j = 1; j <= size; j++) {
            if (i == 1 || i == size || j == 1 || j == size) {
                printf("* ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    return 0;
}