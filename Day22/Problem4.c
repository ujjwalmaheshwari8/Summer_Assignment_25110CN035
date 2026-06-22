// wap to remove spaces from a string
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';
    char result[100]; // To store the string without spaces
    int j = 0; // Index for result array
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') { // If the character is not a space
            result[j++] = str[i]; // Add it to the result
        }
    }
    result[j] = '\0'; // Null-terminate the result string
    printf("String without spaces: %s\n", result);
    return 0;
}