// wap to check string rotation
#include <stdio.h>
#include <string.h>

int isRotation(char s1[], char s2[]) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    // If lengths are not equal, they cannot be a rotation
    if (len1 != len2) {
        return 0; // 0 means False
    }

    // Try to find the starting character of s2 inside s1
    for (int i = 0; i < len1; i++) {
        
        // If we find a character in s1 that matches the start of s2
        if (s1[i] == s2[0]) {
            int match = 1; // Assume it's a match until proven otherwise
            
            // Check the rest of the characters
            for (int j = 0; j < len1; j++) {
                int s1_index = i + j;
                
                // If index goes past the end of s1, wrap it around to the start
                if (s1_index >= len1) {
                    s1_index = s1_index - len1;
                }
                
                // Compare characters
                if (s1[s1_index] != s2[j]) {
                    match = 0; // Mismatch found
                    break;
                }
            }
            
            // If the inner loop finished and all characters matched
            if (match == 1) {
                return 1; // 1 means True
            }
        }
    }

    return 0; // No rotation found
}

int main() {
    char string1[] = "waterbottle";
    char string2[] = "erbottlewat";

    if (isRotation(string1, string2)) {
        printf("Yes, it is a rotation.\n");
    } else {
        printf("No, it is not a rotation.\n");
    }

    return 0;
}