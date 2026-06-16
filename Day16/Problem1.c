// wap to find missing number in array
#include <stdio.h>
int main() {
    int arr[100];
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array (from 1 to %d): ", n);
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &arr[i]);
    }
    // Calculate the expected sum of numbers from 1 to n
    int expected_sum = n * (n + 1) / 2;
    // Calculate the actual sum of the input numbers
    int actual_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        actual_sum += arr[i];
    }
    // The missing number is the difference between expected and actual sums
    int missing_number = expected_sum - actual_sum;
    printf("The missing number is: %d\n", missing_number);
    return 0;
}