#include<stdio.h>

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

