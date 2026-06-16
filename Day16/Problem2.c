// wap to find maximum frequency element
#include <stdio.h>
int main() {
    int arr[100];
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    // Find the maximum frequency element
    int max_count = 0;
    int max_element = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > max_count) {
            max_count = count;
            max_element = arr[i];
        }
    }
    printf("The maximum frequency element is: %d with frequency: %d\n", max_element, max_count);
    return 0;
}