// wap to remove duplicate characters
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void removeDuplicates(char *str) {
    int len = strlen(str);
    if (len == 0) return;
    char *unique = (char *)malloc(len + 1);
    if (!unique) return;
    int index = 0;
    for (int i = 0; i < len; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < index; j++) {
            if (unique[j] == str[i]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            unique[index++] = str[i];
        }
    }
    unique[index] = '\0';
    strcpy(str, unique);
    free(unique);
}

int main() {
    char str[] = "programming";
    printf("Original string: %s\n", str);
    removeDuplicates(str);
    printf("String after removing duplicates: %s\n", str);
    return 0;
}