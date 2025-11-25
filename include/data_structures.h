#include<stdio.h>
#pragma once
#define MAX_NAME_LEN 100
#define MAX_CONTACT_LEN 100

#define EQUIPMENT_FILE "data/equipment.dat"
#define MANUFACTURER_FILE "data/manufacturer.dat"

struct Equipment{
    int id;
    char name[MAX_NAME_LEN];
    float price;
    char manufacturer_name[MAX_NAME_LEN];
    int quantity;
};

struct Borrower {
    int id;
    char name[100];            // Borrower's name
    int equipment_id;
    char borrow_date[20];      // Format: DD-MM-YYYY
    char return_date[20];      // Format: DD-MM-YYYY
    int isReturned;            // 0 = not returned, 1 = returned
};

