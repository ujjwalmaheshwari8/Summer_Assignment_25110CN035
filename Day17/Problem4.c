// wap to find common elements in two arrays
#include <stdio.h>
int main() {
    int arr1[100], arr2[100], common_arr[100];
    int n1, n2, i, j, k = 0;
    printf("Enter the number of elements in the first array: ");
    scanf("%d", &n1);
    printf("Enter the elements of the first array: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number of elements in the second array: ");
    scanf("%d", &n2);
    printf("Enter the elements of the second array: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    // Find common elements
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                common_arr[k] = arr1[i];
                k++;
                break;
            }
        }
    }
    // Print the common elements
    printf("Common elements in both arrays: ");
    for (i = 0; i < k; i++) {
        printf("%d ", common_arr[i]);
    }
    printf("\n");
    return 0;
}