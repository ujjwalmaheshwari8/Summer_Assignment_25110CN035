// wap to reverse a string
#include <stdio.h>
int main() {
    char str[100], rev[100];
    int length = 0;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Calculate length of the string
    for (int i = 0; str[i] != '\0'; i++) {
        length++;
    }
    // Reverse the string
    for (int i = 0; i < length - 1; i++) { // Exclude the newline character
        rev[i] = str[length - 2 - i]; // Start from the end of the string
    }
    rev[length - 1] = '\0'; // Null-terminate the reversed string
    printf("Reversed string: %s\n", rev);
    return 0;
}