// wap to count words in a sentence
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    printf("Enter a sentence: ");
    fgets(str, sizeof(str), stdin);
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';
    int wordCount = 0;
    int inWord = 0; // Flag to indicate if we are inside a word
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && !inWord) {
            inWord = 1; // Start of a new word
            wordCount++;
        } else if (str[i] == ' ') {
            inWord = 0; // End of a word
        }
    }
    printf("Number of words in the sentence: %d\n", wordCount);
    return 0;
}