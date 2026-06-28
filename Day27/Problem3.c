// wap to create salary management system
#include <stdio.h>

struct Employee
{
    int id;
    char name[50];
    float basicSalary;
    float hra;
    float da;
    float grossSalary;
};

int main()
{
    struct Employee emp[100];
    int n = 0, choice, i, id, found;

    do
    {
        printf("\n===== SALARY MANAGEMENT SYSTEM =====\n");
        printf("1. Add Employee Salary\n");
        printf("2. Display All Salary Records\n");
        printf("3. Search Employee Salary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Employee ID: ");
            scanf("%d", &emp[n].id);

            printf("Enter Employee Name: ");
            scanf("%s", emp[n].name);

            printf("Enter Basic Salary: ");
            scanf("%f", &emp[n].basicSalary);

            // Calculate HRA (20%) and DA (10%)
            emp[n].hra = emp[n].basicSalary * 0.20;
            emp[n].da = emp[n].basicSalary * 0.10;

            // Calculate Gross Salary
            emp[n].grossSalary = emp[n].basicSalary + emp[n].hra + emp[n].da;

            printf("Salary record added successfully!\n");
            n++;
            break;

        case 2:
            if (n == 0)
            {
                printf("\nNo salary records available.\n");
            }
            else
            {
                printf("\n----- Salary Records -----\n");
                printf("ID\tName\tBasic\tHRA\tDA\tGross\n");

                for (i = 0; i < n; i++)
                {
                    printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",
                           emp[i].id,
                           emp[i].name,
                           emp[i].basicSalary,
                           emp[i].hra,
                           emp[i].da,
                           emp[i].grossSalary);
                }
            }
            break;

        case 3:
            printf("\nEnter Employee ID to Search: ");
            scanf("%d", &id);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (emp[i].id == id)
                {
                    printf("\nEmployee Salary Details\n");
                    printf("ID           : %d\n", emp[i].id);
                    printf("Name         : %s\n", emp[i].name);
                    printf("Basic Salary : %.2f\n", emp[i].basicSalary);
                    printf("HRA          : %.2f\n", emp[i].hra);
                    printf("DA           : %.2f\n", emp[i].da);
                    printf("Gross Salary : %.2f\n", emp[i].grossSalary);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Employee record not found.\n");
            }
            break;

        case 4:
            printf("Thank you for using the Salary Management System.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}