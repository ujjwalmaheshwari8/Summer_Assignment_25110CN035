// wap to create mini employee management system.
#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 50
#define NAME_LENGTH 50
#define DEPT_LENGTH 30

// Structure to hold Employee Details
struct Employee {
    int id;
    char name[NAME_LENGTH];
    char department[DEPT_LENGTH];
    float salary;
};

// Function prototypes
void addEmployee(struct Employee empList[], int *count);
void displayEmployees(struct Employee empList[], int count);
void searchEmployee(struct Employee empList[], int count);
void updateSalary(struct Employee empList[], int count);

int main() {
    struct Employee empList[MAX_EMPLOYEES];
    int empCount = 0;
    int choice;

    // Seeding dummy data for quick evaluation
    empList[0] = (struct Employee){101, "John Doe", "Engineering", 75000.00};
    empList[1] = (struct Employee){102, "Jane Smith", "Marketing", 68000.50};
    empCount = 2;

    do {
        // Display Menu
        printf("\n=================================");
        printf("\n   EMPLOYEE MANAGEMENT SYSTEM    ");
        printf("\n=================================");
        printf("\n1. Add New Employee");
        printf("\n2. Display All Employees");
        printf("\n3. Search Employee by ID");
        printf("\n4. Update Employee Salary");
        printf("\n5. Exit");
        printf("\n---------------------------------");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(empList, &empCount);
                break;
            case 2:
                displayEmployees(empList, empCount);
                break;
            case 3:
                searchEmployee(empList, empCount);
                break;
            case 4:
                updateSalary(empList, empCount);
                break;
            case 5:
                printf("Exiting Employee Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// 1. Function to insert a new employee record
void addEmployee(struct Employee empList[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Database full! Cannot track more than %d employees.\n", MAX_EMPLOYEES);
        return;
    }

    int tempId, i;
    printf("Enter Employee ID (Integer): ");
    scanf("%d", &tempId);

    // Verify ID uniqueness
    for (i = 0; i < *count; i++) {
        if (empList[i].id == tempId) {
            printf("Error: An employee with ID %d already exists!\n", tempId);
            return;
        }
    }

    empList[*count].id = tempId;

    while (getchar() != '\n'); // Clear input buffer tailing newline

    printf("Enter Employee Name: ");
    scanf("%[^\n]", empList[*count].name);

    while (getchar() != '\n'); // Clear input buffer again

    printf("Enter Department: ");
    scanf("%[^\n]", empList[*count].department);

    printf("Enter Salary ($): ");
    scanf("%f", &empList[*count].salary);

    (*count)++; // Increment globally saved employee tracking size
    printf("Employee record created successfully!\n");
}

// 2. Function to display all employee profiles in a tabular view
void displayEmployees(struct Employee empList[], int count) {
    if (count == 0) {
        printf("The employee database roster is currently empty.\n");
        return;
    }

    printf("\n-----------------------------------------------------------------------\n");
    printf("%-8s %-25s %-20s %-12s\n", "Emp ID", "Employee Name", "Department", "Salary ($)");
    printf("-----------------------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%-8d %-25s %-20s %-12.2f\n", 
               empList[i].id, 
               empList[i].name, 
               empList[i].department, 
               empList[i].salary);
    }
    printf("-----------------------------------------------------------------------\n");
}

// 3. Function to find an employee using their ID
void searchEmployee(struct Employee empList[], int count) {
    int searchId, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (empList[i].id == searchId) {
            printf("\nEmployee Profile Found!");
            printf("\n---------------------------");
            printf("\nID          : %d", empList[i].id);
            printf("\nName        : %s", empList[i].name);
            printf("\nDepartment  : %s", empList[i].department);
            printf("\nSalary      : $%.2f\n", empList[i].salary);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
}

// 4. Function to modify the salary parameters of an employee
void updateSalary(struct Employee empList[], int count) {
    int searchId, found = 0;
    printf("Enter Employee ID to update compensation: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (empList[i].id == searchId) {
            found = 1;
            printf("Current salary details for %s: $%.2f\n", empList[i].name, empList[i].salary);
            printf("Enter new updated salary ($): ");
            scanf("%f", &empList[i].salary);
            printf("Success: Salary package updated for %s.\n", empList[i].name);
            break;
        }
    }

    if (!found) {
        printf("Employee with ID %d not found.\n", searchId);
    }
}