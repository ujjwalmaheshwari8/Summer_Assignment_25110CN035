// wap to sort names alphabetically
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void sortNames(char names[][100], int n) {
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                // Swap names[i] and names[j]
                strcpy(temp, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], temp);
            }
        }
    }
}   
int main() {
    char names[5][100] = {"John", "Alice", "Bob", "Diana", "Charlie"};
    int n = 5;

    sortNames(names, n);

    printf("Sorted names:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}