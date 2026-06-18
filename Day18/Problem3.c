// wap to binary search
#include <stdio.h>
int main() {
    int arr[100], n, i, key, low, high, mid, found = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array (sorted order): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    // Binary search
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            found = 1;
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    if (found) {
        printf("Element %d found at index %d\n", key, mid);
    } else {
        printf("Element %d not found in the array\n", key);
    }
    
    return 0;
}