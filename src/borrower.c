#include "../include/data_structures.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// BORROWER MODULE
// Handles borrowing and returning of equipment,
// and stores borrower data in borrowers.txt



// Check availability of equipment
int isEquipmentAvailable(int id, struct Equipment *out) {
    struct Equipment e;

    FILE *fp = fopen("data/equipment.txt", "r");
    if (fp == NULL) {
        printf("Equipment file not found!\n");
        return 0;
    }

    while (fscanf(fp, "%d %s %d %f %s",
                  &e.id, e.name, &e.quantity, &e.price, e.manufacturer_name) == 5) {

        if (e.id == id) {
            fclose(fp);
            *out = e;  // return the equipment details
            return (e.quantity > 0); // available if quantity > 0
        }
    }

    fclose(fp);
    return 0;
}


//Update the quantity of equipment
void updateEquipmentQuantity(int id, int change) {
    struct Equipment e;

    FILE *fp = fopen("data/equipment.txt", "r");
    if (fp == NULL) {
        printf("Equipment file not found!\n");
        return;
    }

    FILE *temp = fopen("data/temp_eq.txt", "w");

    while (fscanf(fp, "%d %s %d %f %s",
                  &e.id, e.name, &e.quantity, &e.price, e.manufacturer_name) == 5) {

        if (e.id == id) {
            e.quantity += change;
            if (e.quantity < 0) e.quantity = 0;
        }

        fprintf(temp, "%d %s %d %.2f %s\n",
                e.id, e.name, e.quantity, e.price, e.manufacturer_name);
    }

    fclose(fp);
    fclose(temp);

    remove("data/equipment.txt");
    rename("data/temp_eq.txt", "data/equipment.txt");
}



void addBorrower() {
    struct Borrower b;
    struct Equipment e;

    printf("\nEnter Borrower ID: ");
    scanf("%d", &b.id);

    printf("Enter Borrower Name: ");
    scanf("%s", b.name);

    printf("Enter Equipment ID to borrow: ");
    scanf("%d", &b.equipment_id);

    // Check availability
    if (!isEquipmentAvailable(b.equipment_id, &e)) {
        printf("Equipment NOT available or doesn't exist!\n");
        return;
    }

    printf("Enter Borrow Date (DD-MM-YYYY): ");
    scanf("%s", b.borrow_date);

    strcpy(b.return_date, "-");  // not returned yet
    b.isReturned = 0;

    FILE *fp = fopen("data/borrowers.txt", "a");
    if (fp == NULL) {
        printf("Error opening borrower file!\n");
        return;
    }

    fprintf(fp, "%d %s %d %s %s %d\n",
            b.id, b.name, b.equipment_id, b.borrow_date, b.return_date, b.isReturned);

    fclose(fp);

    // Reduce equipment quantity
    updateEquipmentQuantity(b.equipment_id, -1);

    printf("Borrower record added successfully!\n");
}



//View all borrowers
void viewBorrowers() {
    struct Borrower b;
    FILE *fp = fopen("data/borrowers.txt", "r");

    if (fp == NULL) {
        printf("No borrower file found!\n");
        return;
    }

    printf("\n--- Borrower List ---\n");

    while (fscanf(fp, "%d %s %d %s %s %d",
                  &b.id, b.name, &b.equipment_id,
                  b.borrow_date, b.return_date, &b.isReturned) == 6) {

        printf("Borrower ID: %d\n", b.id);
        printf("Name: %s\n", b.name);
        printf("Equipment ID: %d\n", b.equipment_id);
        printf("Borrow Date: %s\n", b.borrow_date);
        printf("Return Date: %s\n", b.return_date);
        printf("Returned: %s\n\n", b.isReturned ? "Yes" : "No");
    }

    fclose(fp);
}



void searchBorrower() {
    int searchID;
    struct Borrower b;
    int found = 0;

    printf("Enter Borrower ID to search: ");
    scanf("%d", &searchID);

    FILE *fp = fopen("data/borrowers.txt", "r");
    if (fp == NULL) {
        printf("No borrower data found.\n");
        return;
    }

    while (fscanf(fp, "%d %s %d %s %s %d",
                  &b.id, b.name, &b.equipment_id,
                  b.borrow_date, b.return_date, &b.isReturned) == 6) 
    {
        if (b.id == searchID) {
            printf("\n--- Borrower Found ---\n");
            printf("Name: %s\n", b.name);
            printf("Equipment ID: %d\n", b.equipment_id);
            printf("Borrow Date: %s\n", b.borrow_date);
            printf("Return Date: %s\n", b.return_date);
            printf("Returned: %s\n", b.isReturned ? "Yes" : "No");

            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found)
        printf("Borrower with ID %d not found.\n", searchID);
}




// Mark a borrowed item as returned

void returnBorrowedItem() {
    int targetID;
    struct Borrower b;
    int found = 0;

    printf("Enter Borrower ID to mark return: ");
    scanf("%d", &targetID);

    FILE *fp = fopen("data/borrowers.txt", "r");
    if (fp == NULL) {
        printf("No borrower file found!\n");
        return;
    }

    FILE *temp = fopen("data/temp_borrowers.txt", "w");

    while (fscanf(fp, "%d %s %d %s %s %d",
                  &b.id, b.name, &b.equipment_id,
                  b.borrow_date, b.return_date, &b.isReturned) == 6) 
    {
        if (b.id == targetID) {
            found = 1;

            if (b.isReturned == 1) {
                printf("This item is already returned.\n");
            } else {
                printf("Enter Return Date (DD-MM-YYYY): ");
                scanf("%s", b.return_date);
                b.isReturned = 1;

                // Increase equipment quantity back
                updateEquipmentQuantity(b.equipment_id, +1);

                printf("Item successfully marked as returned.\n");
            }
        }

        // Write updated or unchanged record
        fprintf(temp, "%d %s %d %s %s %d\n",
                b.id, b.name, b.equipment_id,
                b.borrow_date, b.return_date, b.isReturned);
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        remove("data/temp_borrowers.txt");
        printf("Borrower ID %d not found.\n", targetID);
        return;
    }

    remove("data/borrowers.txt");
    rename("data/temp_borrowers.txt", "data/borrowers.txt");
}
