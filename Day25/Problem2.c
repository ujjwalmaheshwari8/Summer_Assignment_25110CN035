// wap to find common character in strings
#include <stdio.h>
#include <string.h>

int main() {
    char str1[] = "hello";
    char str2[] = "world";
    char common[100];
    int k = 0;

    for (int i = 0; i < strlen(str1); i++) {
        for (int j = 0; j < strlen(str2); j++) {
            if (str1[i] == str2[j]) {
                common[k++] = str1[i];
                break;
            }
        }
    }
    common[k] = '\0';

    printf("Common characters: %s\n", common);

    return 0;
}