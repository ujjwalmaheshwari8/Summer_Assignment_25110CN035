// wap to check symmetric matrix
#include <stdio.h>
int main(){
    int a[10][10], r, c, i, j, flag = 1;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);
    if (r != c)    {
        printf("Matrix is not symmetric as it is not square.\n");
        return 0;
    }
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &a[i][j]);
    // checking for symmetry
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            if (a[i][j] != a[j][i])            {
                flag = 0;
                break;
            }
    if (flag)
        printf("The matrix is symmetric.\n");
    else
        printf("The matrix is not symmetric.\n");
    return 0;
}