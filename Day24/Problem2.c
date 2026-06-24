// wap to compress a string
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void compressString(char *str) {
    int len = strlen(str);
    if (len == 0) return;
    char *compressed = (char *)malloc(2 * len + 1); // Allocate space for compressed string
    if (!compressed) return; // Memory allocation failed
    int count = 1;
    int index = 0;
    for (int i = 0; i < len; i++) {
        if (i < len - 1 && str[i] == str[i + 1]) {
            count++;
        } else {
            compressed[index++] = str[i];
            if (count > 1) {
                char countStr[12];
                sprintf(countStr, "%d", count);
                strcat(compressed, countStr);
            }
            count = 1;
        }
    }
    compressed[index] = '\0';
    // Copy the compressed string back to the original string
    strcpy(str, compressed);
    free(compressed);
}

int main() {
    char str[] = "aabcccccaaa";
    printf("Original string: %s\n", str);
    compressString(str);
    printf("Compressed string: %s\n", str);
    return 0;
}