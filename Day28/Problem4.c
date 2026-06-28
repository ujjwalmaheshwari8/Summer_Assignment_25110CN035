// wap to create contact management system
#include <stdio.h>
#include <string.h>

struct Contact
{
    char name[50];
    char phone[15];
};

int main()
{
    struct Contact contact[100];
    int n = 0, choice, i, found;
    char searchName[50];

    do
    {
        printf("\n===== CONTACT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Contact\n");
        printf("2. Display All Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter Contact Name: ");
            scanf("%s", contact[n].name);

            printf("Enter Phone Number: ");
            scanf("%s", contact[n].phone);

            n++;
            printf("Contact added successfully!\n");
            break;

        case 2:
            if (n == 0)
            {
                printf("\nNo contacts available.\n");
            }
            else
            {
                printf("\n----- Contact List -----\n");
                printf("Name\t\tPhone Number\n");

                for (i = 0; i < n; i++)
                {
                    printf("%s\t\t%s\n",
                           contact[i].name,
                           contact[i].phone);
                }
            }
            break;

        case 3:
            if (n == 0)
            {
                printf("\nNo contacts available.\n");
                break;
            }

            printf("\nEnter Contact Name to Search: ");
            scanf("%s", searchName);

            found = 0;

            for (i = 0; i < n; i++)
            {
                if (strcmp(contact[i].name, searchName) == 0)
                {
                    printf("\nContact Found!\n");
                    printf("Name  : %s\n", contact[i].name);
                    printf("Phone : %s\n", contact[i].phone);
                    found = 1;
                    break;
                }
            }

            if (!found)
            {
                printf("Contact not found.\n");
            }
            break;

        case 4:
            printf("Thank you for using the Contact Management System.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 4);

    return 0;
}