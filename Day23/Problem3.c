// wap to check anagram strings
#include <stdio.h>
#include <string.h>
int main()
{
    char str1[100], str2[100];
    int freq1[256] = {0}, freq2[256] = {0};
    int i, len1, len2;
    printf("Enter first string: ");
    gets(str1);
    printf("Enter second string: ");
    gets(str2);
    len1 = strlen(str1);
    len2 = strlen(str2);
    if (len1 != len2)
    {
        printf("Strings are not anagrams.\n");
        return 0;
    }
    for (i = 0; i < len1; i++){
        freq1[str1[i]]++;
        freq2[str2[i]]++;
    }
    for (i = 0; i < 256; i++)
    {
        if (freq1[i] != freq2[i])
        {
            printf("Strings are not anagrams.\n");
            return 0;
        }
    }
    printf("Strings are anagrams.\n");
    return 0;
}