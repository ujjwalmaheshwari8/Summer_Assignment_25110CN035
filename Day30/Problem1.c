// wap to create student record system using arrays and strings.
#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define TITLE_LENGTH 100
#define AUTHOR_LENGTH 50

// Structure to represent a Book
struct Book {
    int accessionNo;
    char title[TITLE_LENGTH];
    char author[AUTHOR_LENGTH];
    int isIssued; // 0 = Available in Library, 1 = Issued Out
};

// Function prototypes
void addBook(struct Book library[], int *count);
void displayBooks(struct Book library[], int count);
void searchByAuthor(struct Book library[], int count);
void issueOrReturnBook(struct Book library[], int count, int ActionType);

int main() {
    struct Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    // Seeding dummy data for instant testing
    library[0] = (struct Book){1001, "The C Programming Language", "Dennis Ritchie", 0};
    library[1] = (struct Book){1002, "Clean Code", "Robert Martin", 1};
    bookCount = 2;

    do {
        // Display Menu
        printf("\n=================================");
        printf("\n     MINI LIBRARY SYSTEM         ");
        printf("\n=================================");
        printf("\n1. Add New Book");
        printf("\n2. Display All Books");
        printf("\n3. Search Books by Author");
        printf("\n4. Issue a Book");
        printf("\n5. Return a Book");
        printf("\n6. Exit");
        printf("\n---------------------------------");
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook(library, &bookCount);
                break;
            case 2:
                displayBooks(library, bookCount);
                break;
            case 3:
                searchByAuthor(library, bookCount);
                break;
            case 4:
                issueOrReturnBook(library, bookCount, 1); // 1 for Issue Action
                break;
            case 5:
                issueOrReturnBook(library, bookCount, 0); // 0 for Return Action
                break;
            case 6:
                printf("Exiting Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 6.\n");
        }
    } while (choice != 6);

    return 0;
}

// 1. Function to add a book to the library
void addBook(struct Book library[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Library Catalog is full! Cannot add more books.\n");
        return;
    }

    int tempAcc, i;
    printf("Enter Accession Number (Unique Integer): ");
    scanf("%d", &tempAcc);

    // Verify if Accession Number is unique
    for (i = 0; i < *count; i++) {
        if (library[i].accessionNo == tempAcc) {
            printf("Error: A book with Accession Number %d already exists!\n", tempAcc);
            return;
        }
    }

    library[*count].accessionNo = tempAcc;

    while (getchar() != '\n'); // Clear input buffer tailing newline

    printf("Enter Book Title: ");
    scanf("%[^\n]", library[*count].title);

    while (getchar() != '\n'); // Clear buffer again

    printf("Enter Author Name: ");
    scanf("%[^\n]", library[*count].author);

    library[*count].isIssued = 0; // Default state: Available in library

    (*count)++;
    printf("Book registered successfully!\n");
}

// 2. Function to list all books in tabular format
void displayBooks(struct Book library[], int count) {
    if (count == 0) {
        printf("The library catalog is currently empty.\n");
        return;
    }

    printf("\n---------------------------------------------------------------------------------------\n");
    printf("%-10s %-35s %-25s %-12s\n", "Acc No.", "Book Title", "Author", "Status");
    printf("---------------------------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-10d %-35s %-25s %-12s\n", 
               library[i].accessionNo, 
               library[i].title, 
               library[i].author, 
               (library[i].isIssued == 1) ? "Issued" : "Available");
    }
    printf("---------------------------------------------------------------------------------------\n");
}

// 3. Function to look up books written by a specific author
void searchByAuthor(struct Book library[], int count) {
    char searchName[AUTHOR_LENGTH];
    int found = 0;

    while (getchar() != '\n'); // Clear input buffer
    printf("Enter Author Name to search: ");
    scanf("%[^\n]", searchName);

    printf("\nSearch Results for Author: \"%s\"\n", searchName);
    printf("-------------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        // Case-sensitive comparison. Use strcasecmp if your compiler supports it for case-insensitivity.
        if (strcmp(library[i].author, searchName) == 0) {
            printf("Acc No: %d | Title: %s | Status: %s\n", 
                   library[i].accessionNo, library[i].title, 
                   (library[i].isIssued == 1) ? "Issued" : "Available");
            found = 1;
        }
    }

    if (!found) {
        printf("No books found matching this author.\n");
    }
}

// 4 & 5. Combined Function to handle Book Issuing and Returning
void issueOrReturnBook(struct Book library[], int count, int ActionType) {
    int targetAcc, found = 0;
    printf("Enter Book Accession Number: ");
    scanf("%d", &targetAcc);

    for (int i = 0; i < count; i++) {
        if (library[i].accessionNo == targetAcc) {
            found = 1;
            
            if (ActionType == 1) { // Issue processing
                if (library[i].isIssued == 0) {
                    library[i].isIssued = 1;
                    printf("Success: Book \"%s\" has been issued successfully.\n", library[i].title);
                } else {
                    printf("Failure: Book \"%s\" is already checked out/issued.\n", library[i].title);
                }
            } 
            else if (ActionType == 0) { // Return processing
                if (library[i].isIssued == 1) {
                    library[i].isIssued = 0;
                    printf("Success: Book \"%s\" has been returned to shelves.\n", library[i].title);
                } else {
                    printf("Notice: Book \"%s\" is already sitting in the library.\n", library[i].title);
                }
            }
            break;
        }
    }

    if (!found) {
        printf("Error: Book with Accession Number %d not found in catalog.\n", targetAcc);
    }
}