// wap to develop complete mini project using arrays, strings and functions.

// Bank Account Management System
#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

// Structure definition representing a Bank Account Record
struct Account {
    int accountNumber;
    char name[NAME_LEN];
    float balance;
};

// Function Prototypes (Modular Design)
void createAccount(struct Account bank[], int *totalAccounts);
void displayAllAccounts(struct Account bank[], int totalAccounts);
void searchAccount(struct Account bank[], int totalAccounts);
void depositMoney(struct Account bank[], int totalAccounts);
void withdrawMoney(struct Account bank[], int totalAccounts);
void transferMoney(struct Account bank[], int totalAccounts);
int findAccountIndex(struct Account bank[], int totalAccounts, int accNum);

int main() {
    struct Account bank[MAX_ACCOUNTS];
    int totalAccounts = 0;
    int choice;

    // Seeding mock database records for demonstration
    bank[0] = (struct Account){1001, "Alex Mercer", 5000.00};
    bank[1] = (struct Account){1002, "Sarah Connor", 12500.75};
    totalAccounts = 2;

    do {
        // Main Application Dashboard
        printf("\n=========================================");
        printf("\n     APEX MINI BANKING INTERFACE         ");
        printf("\n=========================================");
        printf("\n1. Open New Bank Account");
        printf("\n2. Display Active Account Roster");
        printf("\n3. Query Account Balance Ledger");
        printf("\n4. Cash Deposit Transaction");
        printf("\n5. Cash Withdrawal Transaction");
        printf("\n6. Inter-Account Fund Transfer");
        printf("\n7. Exit Application");
        printf("\n-----------------------------------------");
        printf("\nSelect operational module (1-7): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(bank, &totalAccounts);
                break;
            case 2:
                displayAllAccounts(bank, totalAccounts);
                break;
            case 3:
                searchAccount(bank, totalAccounts);
                break;
            case 4:
                depositMoney(bank, totalAccounts);
                break;
            case 5:
                withdrawMoney(bank, totalAccounts);
                break;
            case 6:
                transferMoney(bank, totalAccounts);
                break;
            case 7:
                printf("\nShutting down core banking systems safely. Goodbye!\n");
                break;
            default:
                printf("\n[Error] Invalid selection! Please reference the menu system (1-7).\n");
        }
    } while (choice != 7);

    return 0;
}

// 1. Function to create a unique new account record
void createAccount(struct Account bank[], int *totalAccounts) {
    if (*totalAccounts >= MAX_ACCOUNTS) {
        printf("\n[Error] System Overflow: Maximum database capacity reached.\n");
        return;
    }

    int tempAccNum;
    printf("\nEnter 4-Digit Unique Account Number: ");
    scanf("%d", &tempAccNum);

    // Assert Uniqueness Check using helper lookup function
    if (findAccountIndex(bank, *totalAccounts, tempAccNum) != -1) {
        printf("\n[Error] System Conflict: Account Number %d already exists.\n", tempAccNum);
        return;
    }

    bank[*totalAccounts].accountNumber = tempAccNum;

    while (getchar() != '\n'); // Clear text buffer streams

    printf("Enter Primary Account Holder Name: ");
    scanf("%[^\n]", bank[*totalAccounts].name);

    printf("Enter Initial Opening Deposit ($): ");
    scanf("%f", &bank[*totalAccounts].balance);

    if (bank[*totalAccounts].balance < 0) {
        printf("[Warning] Negative opening balances invalid. Setting default initialization to $0.00\n");
        bank[*totalAccounts].balance = 0.0f;
    }

    (*totalAccounts)++; // Persist state change to globally tracking value
    printf("\n[Success] Bank Account opened successfully!\n");
}

// 2. Function to print clean accounting tables
void displayAllAccounts(struct Account bank[], int totalAccounts) {
    if (totalAccounts == 0) {
        printf("\n[Notice] Active account tracking matrix is entirely empty.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-15s %-30s %-15s\n", "Account No.", "Account Holder Name", "Balance ($)");
    printf("-------------------------------------------------------------\n");
    for (int i = 0; i < totalAccounts; i++) {
        printf("%-15d %-30s %-15.2f\n", bank[i].accountNumber, bank[i].name, bank[i].balance);
    }
    printf("-------------------------------------------------------------\n");
}

// 3. Function to query individual status cards
void searchAccount(struct Account bank[], int totalAccounts) {
    int accNum;
    printf("\nEnter Account Number to query: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(bank, totalAccounts, accNum);

    if (index != -1) {
        printf("\n--- Account Profile Card ---");
        printf("\nAccount ID     : %d", bank[index].accountNumber);
        printf("\nHolder Name    : %s", bank[index].name);
        printf("\nCurrent Ledger : $%.2f\n", bank[index].balance);
    } else {
        printf("\n[Error] Record Lookup Fault: Account not found.\n");
    }
}

// 4. Function to process deposits safely
void depositMoney(struct Account bank[], int totalAccounts) {
    int accNum;
    float amount;
    printf("\nEnter Account Number for deposit: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(bank, totalAccounts, accNum);

    if (index != -1) {
        printf("Enter amount to credit ($): ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("\n[Error] Transaction Fault: Invalid credit allocation metrics.\n");
        } else {
            bank[index].balance += amount;
            printf("\n[Success] Account Credited. New Balance: $%.2f\n", bank[index].balance);
        }
    } else {
        printf("\n[Error] Record Lookup Fault: Account not found.\n");
    }
}

// 5. Function to process withdrawals with overdraft safety protection mechanisms
void withdrawMoney(struct Account bank[], int totalAccounts) {
    int accNum;
    float amount;
    printf("\nEnter Account Number for withdrawal: ");
    scanf("%d", &accNum);

    int index = findAccountIndex(bank, totalAccounts, accNum);

    if (index != -1) {
        printf("Enter amount to debit ($): ");
        scanf("%f", &amount);

        if (amount <= 0) {
            printf("\n[Error] Transaction Fault: Invalid debit allocation metrics.\n");
        } else if (amount > bank[index].balance) {
            printf("\n[Overdraft Protection Violation] Insufficient funds! Available: $%.2f\n", bank[index].balance);
        } else {
            bank[index].balance -= amount;
            printf("\n[Success] Account Debited. New Balance: $%.2f\n", bank[index].balance);
        }
    } else {
        printf("\n[Error] Record Lookup Fault: Account not found.\n");
    }
}

// 6. Double-ledger Fund Transfer system between two separate tracking blocks
void transferMoney(struct Account bank[], int totalAccounts) {
    int senderAcc, receiverAcc;
    float transferAmount;

    printf("\nEnter Sender Account Number: ");
    scanf("%d", &senderAcc);
    int senderIndex = findAccountIndex(bank, totalAccounts, senderAcc);

    if (senderIndex == -1) {
        printf("\n[Error] Transfer Fault: Sender account record missing.\n");
        return;
    }

    printf("Enter Target Recipient Account Number: ");
    scanf("%d", &receiverAcc);
    int receiverIndex = findAccountIndex(bank, totalAccounts, receiverAcc);

    if (receiverIndex == -1) {
        printf("\n[Error] Transfer Fault: Target recipient account record missing.\n");
        return;
    }

    if (senderIndex == receiverIndex) {
        printf("\n[Error] Identity Loop Fault: Cannot transfer assets to identical source targets.\n");
        return;
    }

    printf("Enter transactional balance shift volume ($): ");
    scanf("%f", &transferAmount);

    if (transferAmount <= 0) {
        printf("\n[Error] Quantitative validation error. Value metrics must be positive.\n");
    } else if (transferAmount > bank[senderIndex].balance) {
        printf("\n[Transfer Blocked] Insufficient balances inside sender entity.\n");
    } else {
        // atomic balancing operations pipeline
        bank[senderIndex].balance -= transferAmount;
        bank[receiverIndex].balance += transferAmount;
        printf("\n[Success] Transfer complete! shifted $%.2f from %s to %s.\n", 
               transferAmount, bank[senderIndex].name, bank[receiverIndex].name);
    }
}

// 7. Core Search Engine Helper (Linear Search over Structured Indices)
int findAccountIndex(struct Account bank[], int totalAccounts, int accNum) {
    for (int i = 0; i < totalAccounts; i++) {
        if (bank[i].accountNumber == accNum) {
            return i; // Target database entry index identified 
        }
    }
    return -1; // Flag returned if item doesn't exist inside active bounds
}