#include<stdio.h>

#define MAX_NAME_LEN 100
#define MAX_CONTACT_LEN 100

#define EQUIPMENT_FILE "data/equipment.dat"
#define MANUFACTURER_FILE "data/manufacturer.dat"

struct Equipment{
    int id;
    char name[MAX_NAME_LEN];
    float price;
    int manufacturer_id;
    int quantity;
};

struct Manufacturer{
    int id;
    char name[MAX_NAME_LEN];
    char contact[MAX_CONTACT_LEN];
};

