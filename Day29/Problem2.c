// wap to create menu driven array operational system
#include <stdio.h>

#define MAX_SIZE 100

// Function prototypes
int stringLength(char str[]);
void stringCopy(char dest[], char src[]);
void stringConcat(char dest[], char src[]);
int stringCompare(char str1[], char str2[]);
void reverseString(char str[]);

int main() {
    char str1[MAX_SIZE], str2[MAX_SIZE], target[MAX_SIZE * 2];
    int choice, result;

    do {
        // Display Menu
        printf("\n=================================");
        printf("\n   STRING OPERATIONS SYSTEM      ");
        printf("\n=================================");
        printf("\n1. Find Length of a String");
        printf("\n2. Copy String");
        printf("\n3. Concatenate (Join) Two Strings");
        printf("\n4. Compare Two Strings");
        printf("\n5. Reverse a String");
        printf("\n6. Exit");
        printf("\n---------------------------------");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        
        // Consume the leftover newline character from the buffer
        while (getchar() != '\n'); 

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%[^\n]", str1); // Reads string with spaces
                printf("Length of the string: %d\n", stringLength(str1));
                break;

            case 2:
                printf("Enter source string to copy: ");
                scanf("%[^\n]", str1);
                stringCopy(target, str1);
                printf("String copied successfully!\n");
                printf("Original: %s\nTarget Destination: %s\n", str1, target);
                break;

            case 3:
                printf("Enter first string: ");
                scanf("%[^\n]", str1);
                while (getchar() != '\n'); // Clear buffer
                printf("Enter second string to append: ");
                scanf("%[^\n]", str2);
                
                stringCopy(target, str1); // Copy first string to target
                stringConcat(target, str2); // Append second string to target
                printf("Concatenated String: %s\n", target);
                break;

            case 4:
                printf("Enter first string: ");
                scanf("%[^\n]", str1);
                while (getchar() != '\n'); // Clear buffer
                printf("Enter second string: ");
                scanf("%[^\n]", str2);
                
                result = stringCompare(str1, str2);
                if (result == 0)
                    printf("Strings are completely equal.\n");
                else if (result > 0)
                    printf("First string is lexicographically greater.\n");
                else
                    printf("Second string is lexicographically greater.\n");
                break;

            case 5:
                printf("Enter a string to reverse: ");
                scanf("%[^\n]", str1);
                reverseString(str1);
                printf("Reversed String: %s\n", str1);
                break;

            case 6:
                printf("Exiting system. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// 1. Function to calculate string length
int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// 2. Function to copy string (src to dest)
void stringCopy(char dest[], char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0'; // Crucial: Don't forget to null-terminate!
}

// 3. Function to concatenate string (src onto the end of dest)
void stringConcat(char dest[], char src[]) {
    int dest_len = stringLength(dest);
    int i = 0;
    
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0'; // Null-terminate the combined string
}

// 4. Function to compare two strings lexicographically
int stringCompare(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i]; // Returns difference of ASCII values
        }
        i++;
    }
    return str1[i] - str2[i]; 
}

// 5. Function to reverse a string in-place
void reverseString(char str[]) {
    int i = 0;
    int j = stringLength(str) - 1;
    char temp;
    
    while (i < j) {
        // Swap characters
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}