#include "../include/data_structures.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// INVENTORY MODULE
// This file handles storing and managing equipment inventory.


// Add new inventory record
void addInventory() {
    struct Equipment e;

    printf("\nEnter Equipment ID: ");
    scanf("%d", &e.id);

    printf("Enter Equipment Name: ");
    scanf("%s", e.name);

    printf("Enter Quantity: ");
    scanf("%d", &e.quantity);

    printf("Enter Price: ");
    scanf("%f", &e.price);

    printf("Enter Manufacturer Name: ");
    scanf("%s", e.manufacturer_name);

    FILE *fp = fopen("data/inventory.txt", "a");
    if (fp == NULL) {
        printf("Error opening inventory file!\n");
        return;
    }

    fprintf(fp, "%d %s %d %.2f %s\n",
            e.id, e.name, e.quantity, e.price, e.manufacturer_name);

    fclose(fp);

    printf("Inventory record added successfully!\n");
}



// View all inventory data
void viewInventory() {
    struct Equipment e;
    FILE *fp = fopen("data/inventory.txt", "r");

    if (fp == NULL) {
        printf("No inventory file found!\n");
        return;
    }

    printf("\n--- Inventory List ---\n");

    while (fscanf(fp, "%d %s %d %f %s",
                  &e.id, e.name, &e.quantity, &e.price, e.manufacturer_name) == 5) 
    {
        printf("ID: %d\n", e.id);
        printf("Name: %s\n", e.name);
        printf("Quantity: %d\n", e.quantity);
        printf("Price: %.2f\n", e.price);
        printf("Manufacturer: %s\n\n", e.manufacturer_name);
    }

    fclose(fp);
}



// Search inventory by ID
void searchInventory() {
    int searchID;
    struct Equipment e;
    int found = 0;

    printf("Enter Inventory Equipment ID to search: ");
    scanf("%d", &searchID);

    FILE *fp = fopen("data/inventory.txt", "r");
    if (fp == NULL) {
        printf("No inventory data found.\n");
        return;
    }

    while (fscanf(fp, "%d %s %d %f %s",
                  &e.id, e.name, &e.quantity, &e.price, e.manufacturer_name) == 5) 
    {
        if (e.id == searchID) {
            printf("\n--- Inventory Item Found ---\n");
            printf("Name: %s\n", e.name);
            printf("Quantity: %d\n", e.quantity);
            printf("Price: %.2f\n", e.price);
            printf("Manufacturer: %s\n", e.manufacturer_name);
            found = 1;
            break;
        }
    }

    fclose(fp);

    if (!found) {
        printf("Inventory item with ID %d not found.\n", searchID);
    }
}



// Update inventory quantity
void updateInventoryQuantity() {
    int targetID;
    struct Equipment e;
    int found = 0;

    printf("Enter Equipment ID to update quantity: ");
    scanf("%d", &targetID);

    FILE *fp = fopen("data/inventory.txt", "r");
    if (fp == NULL) {
        printf("No inventory file found.\n");
        return;
    }

    FILE *temp = fopen("data/temp_inventory.txt", "w");

    while (fscanf(fp, "%d %s %d %f %s",
                  &e.id, e.name, &e.quantity, &e.price, e.manufacturer_name) == 5) 
    {
        if (e.id == targetID) {
            found = 1;

            printf("Current Quantity: %d\n", e.quantity);
            printf("Enter New Quantity: ");
            scanf("%d", &e.quantity);

            fprintf(temp, "%d %s %d %.2f %s\n",
                    e.id, e.name, e.quantity, e.price, e.manufacturer_name);
        } 
        else {
            // Copy unchanged record
            fprintf(temp, "%d %s %d %.2f %s\n",
                    e.id, e.name, e.quantity, e.price, e.manufacturer_name);
        }
    }

    fclose(fp);
    fclose(temp);

    if (!found) {
        remove("data/temp_inventory.txt");
        printf("Equipment ID %d not found. No changes made.\n", targetID);
        return;
    }

    // Replace old file
    remove("data/inventory.txt");
    rename("data/temp_inventory.txt", "data/inventory.txt");

    printf("Inventory quantity updated successfully!\n");
}
