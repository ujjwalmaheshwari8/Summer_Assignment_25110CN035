// wap to find column wise sum
#include <stdio.h>
int main() {
    int a[10][10], r, c, i, j;
    int colSum[10];
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    // Calculate column-wise sum
    for (j = 0; j < c; j++) {
        colSum[j] = 0;
        for (i = 0; i < r; i++) {
            colSum[j] += a[i][j];
        }
    }
    // Print column-wise sums
    printf("Column-wise sums:\n");
    for (j = 0; j < c; j++) {
        printf("Column %d: %d\n", j + 1, colSum[j]);
    }
    return 0;
}