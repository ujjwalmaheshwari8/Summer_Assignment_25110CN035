// wap to find first repeating character 
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int freq[256] = {0};
    int i, j;
    printf("Enter a string: ");
    gets(str);
    // Count frequency of each character
    for (i = 0; str[i] != '\0'; i++){
        freq[str[i]]++;
    }
    // Find first repeating character
    for (i = 0; str[i] != '\0'; i++){
        if (freq[str[i]] > 1){
            printf("First repeating character is: %c\n", str[i]);
            break;
        }
    }
    return 0;
}