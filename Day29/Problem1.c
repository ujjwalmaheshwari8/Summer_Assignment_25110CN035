// wap to create menu driven calculator
#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    do {
        // Displaying the menu options
        printf("\n===========================\n");
        printf("   Menu-Driven Calculator  \n");
        printf("===========================\n");
        printf("1. Addition (+)\n");
        printf("2. Subtraction (-)\n");
        printf("3. Multiplication (*)\n");
        printf("4. Division (/)\n");
        printf("5. Exit\n");
        printf("---------------------------\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // If the user chooses 1-4, ask for the two numbers
        if (choice >= 1 && choice <= 4) {
            printf("Enter two numbers separated by a space: ");
            scanf("%f %f", &num1, &num2);
        }

        // Processing the user's choice
        switch (choice) {
            case 1:
                result = num1 + num2;
                printf("Result: %.2f + %.2f = %.2f\n", num1, num2, result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result: %.2f - %.2f = %.2f\n", num1, num2, result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result: %.2f * %.2f = %.2f\n", num1, num2, result);
                break;
            case 4:
                // Error handling for division by zero
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Result: %.2f / %.2f = %.2f\n", num1, num2, result);
                } else {
                    printf("Error: Division by zero is mathematically undefined!\n");
                }
                break;
            case 5:
                printf("Exiting the calculator. Goodbye!\n");
                break;
            default:
                // Handles any input outside of 1-5
                printf("Invalid choice! Please select a valid option from the menu.\n");
        }
    } while (choice != 5); // The loop continues until the user chooses 5

    return 0;
}