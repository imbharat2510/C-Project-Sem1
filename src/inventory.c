#include "../include/data_structures.h"
#include "../include/equipment.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/borrower.h"


   

// View all inventory data
void viewInventory(){
    viewEquipment();
}



// Search inventory by ID
void searchInventory() {
    searchEquipment();
}
    


// Update inventory quantity
void updateInventoryQuantity() {
    int targetid;
    struct Equipment e;
    int found =0;
    printf("Enter Equipment ID to update: ");
    if (scanf("%d",&targetid)!=1){
        printf("Invalid input.\n");
        return;
    }

    FILE *fp=fopen("data/equipment.txt","r");
    if(fp==NULL){
        printf("No equipment file found.\n");
        return;
    }
    FILE *temp=fopen("data/temp_equipment.txt","w");
    while(fscanf(fp,"%d %s %d %f %s",&e.id,e.name,&e.quantity,&e.price,e.manufacturer_name)==5){
        if(e.id==targetid){
            found=1;
            printf("\nCurrent details: \n");
            printf("ID: %d\nName: %s\nQuantity: %d\n\n",e.id,e.name,e.quantity);

            printf("Enter new Quantity: ");
            scanf("%d",&e.quantity);
            

            fprintf(temp,"%d %s %d %.2f %s\n",e.id,e.name,e.quantity,e.price,e.manufacturer_name);
        }
        else{
            fprintf(temp,"%d %s %d %.2f %s\n",e.id,e.name,e.quantity,e.price,e.manufacturer_name);
        }
    }
    fclose(fp);
    fclose(temp);

    if(!found){
        remove("data/temp_equipment.txt");
        printf("Equipment with ID %d not found. No changes made.\n", targetid);
        return;
    }

    remove("data/equipment.txt");

    rename("data/temp_equipment.txt","data/equipment.txt");

    printf("Equipment with ID %d updated succesfully.\n",targetid);
}
