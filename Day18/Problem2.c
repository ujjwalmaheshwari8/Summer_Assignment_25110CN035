// wap to selection sort
#include <stdio.h>
int main() {
    int arr[100], n, i, j, min_idx, temp;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Selection sort
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // Swap arr[i] and arr[min_idx]
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
    // Print the sorted array
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}