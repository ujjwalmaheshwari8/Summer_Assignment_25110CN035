// wap to create inventory management system.
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

// Defining the Structure for an Item
struct Item {
    int id;
    char name[NAME_LENGTH];
    int quantity;
    float price;
};

// Function prototypes
void addItem(struct Item inventory[], int *count);
void displayInventory(struct Item inventory[], int count);
void searchItem(struct Item inventory[], int count);
void updateStock(struct Item inventory[], int count);

int main() {
    struct Item inventory[MAX_ITEMS];
    int itemCount = 0;
    int choice;

    // Seeding a couple of items for initialization
    inventory[0] = (struct Item){101, "Laptop", 15, 750.00};
    inventory[1] = (struct Item){102, "Mouse", 50, 25.50};
    itemCount = 2;

    do {
        // Display Menu
        printf("\n=================================");
        printf("\n   INVENTORY MANAGEMENT SYSTEM   ");
        printf("\n=================================");
        printf("\n1. Add New Item");
        printf("\n2. Display All Items");
        printf("\n3. Search Item by ID");
        printf("\n4. Update Item Stock (Sell/Restock)");
        printf("\n5. Exit");
        printf("\n---------------------------------");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
                displayInventory(inventory, itemCount);
                break;
            case 3:
                searchItem(inventory, itemCount);
                break;
            case 4:
                updateStock(inventory, itemCount);
                break;
            case 5:
                printf("Exiting system. Data cleared from volatile memory. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select an option between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}

// 1. Function to add a unique item to the inventory
void addItem(struct Item inventory[], int *count) {
    if (*count >= MAX_ITEMS) {
        printf("Inventory is full! Cannot add more items.\n");
        return;
    }

    int tempId, i;
    printf("Enter Item ID (Integer): ");
    scanf("%d", &tempId);

    // Check if ID already exists
    for (i = 0; i < *count; i++) {
        if (inventory[i].id == tempId) {
            printf("Error: An item with ID %d already exists!\n", tempId);
            return;
        }
    }

    inventory[*count].id = tempId;
    
    // Clear buffer and read name
    while (getchar() != '\n'); 
    printf("Enter Item Name: ");
    scanf("%[^\n]", inventory[*count].name);

    printf("Enter Quantity: ");
    scanf("%d", &inventory[*count].quantity);

    printf("Enter Price per unit: ");
    scanf("%f", &inventory[*count].price);

    (*count)++; // Increment total item count
    printf("Item added successfully!\n");
}

// 2. Function to display all inventory items in a tabular layout
void displayInventory(struct Item inventory[], int count) {
    if (count == 0) {
        printf("Inventory is currently empty.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-10s %-25s %-12s %-10s\n", "Item ID", "Item Name", "Quantity", "Price ($)");
    printf("-------------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-10d %-25s %-12d %-10.2f\n", 
               inventory[i].id, 
               inventory[i].name, 
               inventory[i].quantity, 
               inventory[i].price);
    }
    printf("-------------------------------------------------------------\n");
}

// 3. Function to search for an item using its ID
void searchItem(struct Item inventory[], int count) {
    int searchId, found = 0;
    printf("Enter Item ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == searchId) {
            printf("\nItem Found!");
            printf("\nID: %d\nName: %s\nStock Quantity: %d\nPrice: $%.2f\n", 
                   inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", searchId);
    }
}

// 4. Function to update stock levels (Restock or Deduct)
void updateStock(struct Item inventory[], int count) {
    int searchId, found = 0, updateChoice, amt;
    printf("Enter Item ID to update stock: ");
    scanf("%d", &searchId);

    for (int i = 0; i < count; i++) {
        if (inventory[i].id == searchId) {
            found = 1;
            printf("Current stock for %s is: %d\n", inventory[i].name, inventory[i].quantity);
            printf("1. Restock (Add)\n2. Sell (Deduct)\nSelect option (1-2): ");
            scanf("%d", &updateChoice);

            if (updateChoice == 1) {
                printf("Enter quantity to add: ");
                scanf("%d", &amt);
                inventory[i].quantity += amt;
                printf("Stock updated! New quantity: %d\n", inventory[i].quantity);
            } 
            else if (updateChoice == 2) {
                printf("Enter quantity to sell/remove: ");
                scanf("%d", &amt);
                if (amt <= inventory[i].quantity) {
                    inventory[i].quantity -= amt;
                    printf("Sale successful! Remaining quantity: %d\n", inventory[i].quantity);
                } else {
                    printf("Error: Insufficient stock! Only %d available.\n", inventory[i].quantity);
                }
            } else {
                printf("Invalid option selected.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Item with ID %d not found.\n", searchId);
    }
}