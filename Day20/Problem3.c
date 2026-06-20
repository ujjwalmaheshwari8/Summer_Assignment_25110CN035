// wap to find row wise sum
#include <stdio.h>
int main() {
    int a[10][10], r, c, i, j;
    int rowSum[10];
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    // Calculate row-wise sum
    for (i = 0; i < r; i++) {
        rowSum[i] = 0;
        for (j = 0; j < c; j++) {
            rowSum[i] += a[i][j];
        }
    }
    // Print row-wise sums
    printf("Row-wise sums:\n");
    for (i = 0; i < r; i++) {
        printf("Row %d: %d\n", i + 1, rowSum[i]);
    }
    return 0;
}