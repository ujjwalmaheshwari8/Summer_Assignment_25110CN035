// wap to create bank account system
#include <stdio.h>

struct BankAccount
{
    int accountNo;
    char name[50];
    float balance;
};

int main()
{
    struct BankAccount acc;
    int choice;
    float amount;
    int created = 0;

    do
    {
        printf("\n===== BANK ACCOUNT MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Check Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Account Number: ");
            scanf("%d", &acc.accountNo);

            printf("Enter Account Holder Name: ");
            scanf("%s", acc.name);

            printf("Enter Initial Balance: ");
            scanf("%f", &acc.balance);

            created = 1;
            printf("Account created successfully!\n");
            break;

        case 2:
            if (created == 0)
            {
                printf("No account found. Please create an account first.\n");
            }
            else
            {
                printf("\n----- Account Details -----\n");
                printf("Account Number : %d\n", acc.accountNo);
                printf("Account Holder : %s\n", acc.name);
                printf("Balance        : Rs. %.2f\n", acc.balance);
            }
            break;

        case 3:
            if (created == 0)
            {
                printf("No account found. Please create an account first.\n");
            }
            else
            {
                printf("Enter amount to deposit: Rs. ");
                scanf("%f", &amount);

                if (amount > 0)
                {
                    acc.balance += amount;
                    printf("Rs. %.2f deposited successfully.\n", amount);
                }
                else
                {
                    printf("Invalid amount.\n");
                }
            }
            break;

        case 4:
            if (created == 0)
            {
                printf("No account found. Please create an account first.\n");
            }
            else
            {
                printf("Enter amount to withdraw: Rs. ");
                scanf("%f", &amount);

                if (amount <= 0)
                {
                    printf("Invalid amount.\n");
                }
                else if (amount > acc.balance)
                {
                    printf("Insufficient Balance.\n");
                }
                else
                {
                    acc.balance -= amount;
                    printf("Rs. %.2f withdrawn successfully.\n", amount);
                }
            }
            break;

        case 5:
            printf("Thank you for using the Bank Account Management System.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}