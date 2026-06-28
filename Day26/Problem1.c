// wap to create number guessing game
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int number, guess, attempts = 0;
    // Generate a random number
    srand(time(0));
    number = rand() % 100 + 1;
    printf("=== Number Guessing Game ===\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("Try to guess it!\n");
    do{
        printf("\nEnter your guess: ");
        scanf("%d", &guess);
        attempts++;
        if (guess > number){
            printf("Too High! Try again.\n");
        }
        else if (guess < number){
            printf("Too Low! Try again.\n");
        }
        else{
            printf("\n Congratulations! You guessed the correct number.\n");
            printf("You guessed it in %d attempts.\n", attempts);
        }
    }
    while (guess != number);
    return 0;
}