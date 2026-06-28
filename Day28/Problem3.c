// wap to create ticket booking system
#include <stdio.h>

int main()
{
    int totalTickets = 100;
    int bookedTickets = 0;
    int choice, tickets;

    do
    {
        printf("\n===== TICKET BOOKING SYSTEM =====\n");
        printf("1. View Available Tickets\n");
        printf("2. Book Tickets\n");
        printf("3. Cancel Tickets\n");
        printf("4. Booking Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nAvailable Tickets: %d\n", totalTickets - bookedTickets);
            break;

        case 2:
            printf("\nEnter number of tickets to book: ");
            scanf("%d", &tickets);

            if (tickets <= 0)
            {
                printf("Invalid number of tickets.\n");
            }
            else if (bookedTickets + tickets > totalTickets)
            {
                printf("Sorry! Only %d tickets are available.\n",
                       totalTickets - bookedTickets);
            }
            else
            {
                bookedTickets += tickets;
                printf("%d ticket(s) booked successfully!\n", tickets);
            }
            break;

        case 3:
            printf("\nEnter number of tickets to cancel: ");
            scanf("%d", &tickets);

            if (tickets <= 0)
            {
                printf("Invalid number of tickets.\n");
            }
            else if (tickets > bookedTickets)
            {
                printf("You have only %d booked ticket(s).\n", bookedTickets);
            }
            else
            {
                bookedTickets -= tickets;
                printf("%d ticket(s) cancelled successfully!\n", tickets);
            }
            break;

        case 4:
            printf("\nBooked Tickets    : %d\n", bookedTickets);
            printf("Available Tickets : %d\n", totalTickets - bookedTickets);
            break;

        case 5:
            printf("Thank you for using the Ticket Booking System.\n");
            break;

        default:
            printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}