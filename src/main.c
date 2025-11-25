#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/login.h"
#include "../include/equipment.h"
#include "../include/borrower.h"
#include "../include/inventory.h"

int main() {
    int role;
    printf("Select role:\n");
    printf("1. Admin\n");
    printf("2. Student\n");
    printf("Enter your choice: ");
    scanf("%d", &role);

    if (role == 1) {
        int adminStatus = admin();
        if (adminStatus != 1) {
            printf("Admin login failed.\n");
            return 0;
        }
        int choice;
        do {
            printf("\n--- Admin Menu ---\n");
            printf("1. Manage Equipment\n");
            printf("2. Manage Inventory\n");
            printf("3. View Borrowers\n");
            printf("4. Search Borrower by ID\n");
            printf("5. Search Equipment by ID\n");
            printf("6. Remove Equipment\n");
            printf("7. Logout/Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    int emChoice;
                    do {
                        printf("\n--- Manage Equipment ---\n");
                        printf("1. Add Equipment\n");
                        printf("2. View Equipment\n");
                        printf("3. Update Equipment\n");
                        printf("4. Back\n");
                        printf("Enter your choice: ");
                        scanf("%d", &emChoice);
                        switch (emChoice) {
                            case 1:
                                addEquipment();
                                break;
                            case 2:
                                viewEquipment();
                                break;
                            case 3:
                                updateEquipment();
                                break;
                            case 4:
                                break;
                            default:
                                printf("Invalid choice in Manage Equipment.\n");
                        }
                    } while (emChoice != 4);
                    break;
                }
                case 2: {
                    int invChoice;
                    do {
                        printf("\n--- Manage Inventory ---\n");
                        printf("1. Add Inventory\n");
                        printf("2. View Inventory\n");
                        printf("3. Search Inventory by ID\n");
                        printf("4. Update Inventory Quantity\n");
                        printf("5. Back\n");
                        printf("Enter your choice: ");
                        scanf("%d", &invChoice);
                        switch (invChoice) {
                            case 1:
                                addInventory();
                                break;
                            case 2:
                                viewInventory();
                                break;
                            case 3:
                                searchInventory();
                                break;
                            case 4:
                                updateInventoryQuantity();
                                break;
                            case 5:
                                break;
                            default:
                                printf("Invalid choice in Manage Inventory.\n");
                        }
                    } while (invChoice != 5);
                    break;
                }
                case 3:
                    viewBorrowers();
                    break;
                case 4:
                    searchBorrower();
                    break;
                case 5:
                    searchEquipment();
                    break;
                case 6:
                    deleteEquipment();
                    break;
                case 7:
                    printf("Logging out...\n");
                    break;
                default:
                    printf("Invalid choice in Admin Menu.\n");
            }
        } while (choice != 7);
    } else if (role == 2) {
        sign_in();
        int stuChoice;
        do {
            printf("\n--- Student Menu ---\n");
            printf("1. Search Equipment by ID\n");
            printf("2. Borrow Equipment\n");
            printf("3. Return Equipment\n");
            printf("4. Logout/Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &stuChoice);
            switch (stuChoice) {
                case 1:
                    searchEquipment();
                    break;
                case 2:
                    addBorrower();
                    break;
                case 3:
                    returnBorrowedItem();
                    break;
                case 4:
                    printf("Logging out...\n");
                    break;
                default:
                    printf("Invalid choice in Student Menu.\n");
            }
        } while (stuChoice != 4);
    } else {
        printf("Invalid role selected.\n");
    }

    return 0;
}

