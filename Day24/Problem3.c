// wap to find longest word
#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "The quick brown fox jumps over the lazy dog";
    char *word = strtok(str, " ");
    char longestWord[100] = "";
    while (word != NULL) {
        if (strlen(word) > strlen(longestWord)) {
            strcpy(longestWord, word);
        }
        word = strtok(NULL, " ");
    }
    printf("Longest word: %s\n", longestWord);
    return 0;
}