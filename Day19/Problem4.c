// wap to find diagonal sum
#include <stdio.h>
int main()
{
    int a[10][10], r, c, i, j, sum = 0;
    printf("Enter the number of rows and columns of matrix: ");
    scanf("%d %d", &r, &c);
    printf("Enter the elements of matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    // finding diagonal sum
    for (i = 0; i < r; i++)
        sum += a[i][i];
    // printing the result
    printf("Diagonal sum of the matrix: %d\n", sum);
    return 0;
}