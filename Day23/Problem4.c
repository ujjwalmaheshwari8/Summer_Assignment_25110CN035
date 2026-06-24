// wap to find maximum occurring character.
#include <stdio.h>
#include <string.h>
int main()
{
    char str[100];
    int freq[256] = {0};
    int i, max_freq = 0, max_char;
    printf("Enter a string: ");
    gets(str);
    // Count frequency of each character
    for (i = 0; str[i] != '\0'; i++)
    {
        freq[str[i]]++;
    }
    // Find maximum occurring character
    for (i = 0; i < 256; i++)
    {
        if (freq[i] > max_freq)
        {
            max_freq = freq[i];
            max_char = i;
        }
    }
    printf("Maximum occurring character is: %c\n", max_char);
    return 0;
}