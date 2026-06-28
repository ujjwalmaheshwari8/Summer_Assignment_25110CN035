// wap to create student record management system
#include <stdio.h>

struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

int main()
{
    struct Student s[100];
    int n = 0, choice, i, roll;
    int found;

    do
    {
        printf("\n===== STUDENT RECORD MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Roll Number: ");
            scanf("%d", &s[n].rollNo);

            printf("Enter Name: ");
            scanf("%s", s[n].name);

            printf("Enter Marks: ");
            scanf("%f", &s[n].marks);

            n++;
            printf("Student record added successfully!\n");
            break;

        case 2:
            if (n == 0)
            {
                printf("\nNo student records found.\n");
            }
            else
            {
                printf("\n----- Student Records -----\n");
                printf("Roll No\tName\tMarks\n");
                for (i = 0; i < n; i++)
                {
                    printf("%d\t%s\t%.2f\n", s[i].rollNo, s[i].name, s[i].marks);
                }
            }
            break;

        case 3:
            if (n == 0)
            {
                printf("\nNo student records available.\n");
                break;
            }

            printf("\nEnter Roll Number to search: ");
            scanf("%d", &roll);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (s[i].rollNo == roll)
                {
                    printf("\nStudent Found!\n");
                    printf("Roll No : %d\n", s[i].rollNo);
                    printf("Name    : %s\n", s[i].name);
                    printf("Marks   : %.2f\n", s[i].marks);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Student record not found.\n");
            }
            break;

        case 4:
            printf("Exiting the program...\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}