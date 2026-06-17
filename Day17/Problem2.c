// wap to union of arrays
#include <stdio.h>
int main() {
    int arr1[100], arr2[100], union_arr[200];
    int n1, n2, i, j, k;
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
    // Copy first array to union array
    for (i = 0; i < n1; i++) {
        union_arr[i] = arr1[i];
    }
    k = n1;
    // Add elements from second array if not already present
    for (j = 0; j < n2; j++) {
        int is_duplicate = 0;
        for (i = 0; i < k; i++) {
            if (arr2[j] == union_arr[i]) {
                is_duplicate = 1;
                break;
            }
        }
        if (!is_duplicate) {
            union_arr[k] = arr2[j];
            k++;
        }
    }
    // Print the union array
    printf("Union of arrays: ");
    for (i = 0; i < k; i++) {
        printf("%d ", union_arr[i]);
    }
    printf("\n");
    return 0;
}