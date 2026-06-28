// wap to create voting eligibility system
#include <stdio.h>

int main(){
    int age;
    printf("=== Voting Eligibility System ===\n");
    printf("Enter your age: ");
    scanf("%d", &age);
    if (age < 0){
        printf("Invalid age entered.\n");
    }
    else if (age >= 18){
        printf("Congratulations! You are eligible to vote.\n");
    }
    else{
        printf("Sorry! You are not eligible to vote.\n");
        printf("You can vote after %d year(s).\n", 18 - age);
    }
   return 0;
}