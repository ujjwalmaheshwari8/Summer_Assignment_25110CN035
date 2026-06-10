// wap to print reverse star pattern
// ********* 
//  ******* 
//   ***** 
//    *** 
//     * 
#include <stdio.h>
int main() {
    int rows;
    rows=5; // You can change this value to print more or fewer rows
    for (int i = rows; i >= 1; i--) {
        for (int j = 1; j <= rows - i; j++) {
            printf("  ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}