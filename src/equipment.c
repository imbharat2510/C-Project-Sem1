#include "../include/data_structures.h"
#include <stdio.h>
#include<string.h>
#include<stdlib.h>



void addEquipment(){
    struct Equipment e;
    printf("Enter Equipment ID: ");
    scanf("%d",&e.id);

    printf("Enter Equipment Name: ");
    scanf("%s",e.name);

    printf("Enter Quantity: ");
    scanf("%d",&e.quantity);

    printf("Enter Price: ");
    scanf("%f",&e.price);

    printf("Enter Manufacturer ID: ");
    scanf("%d",&e.manufacturer_id);

    FILE *fp=fopen("data/equipment.txt","a");
    if (fp==NULL){
        printf("Error opening equipment file!\n");
        return;
    }
    fprintf(fp,"%d %s %d %.2f %d\n",e.id,e.name,e.quantity,e.price,e.manufacturer_id);
    fclose(fp);

    printf("Equipement added successfully!\n");
}


void viewEquipment(){
    struct Equipment e;
    FILE *fp=fopen("data/equipment.txt","r");
    if (fp==NULL){
        printf("No equipment file found!\n");
        return;
    }
    printf("\n--- Equipment List ---\n");

    while (fscanf(fp, "%d %s %d %f %d",&e.id,e.name,&e.quantity,&e.price,&e.manufacturer_id)==5){
        printf("ID: %d\n",e.id);
        printf("Name: %s\n",e.name);
        printf("Quantity: %d\n",e.quantity);
        printf("Price: %.2f\n",e.price);
        printf("Manufacturer ID: %d\n\n",e.manufacturer_id);
    }
    fclose(fp);
}


void searchEquipment(){
    int searchid;
    struct Equipment e;
    int found=0;

    printf("Enter Equipment ID to search: ");
    scanf("%d",&searchid);

    FILE *fp=fopen("data/equipment.txt","r");

    if(fp==NULL){
        printf("No equipment data found.\n");
        return ;
    }
    while(fscanf(fp,"%d %s %d %f %d",&e.id,e.name,&e.quantity,&e.price,&e.manufacturer_id)==5){
        if(e.id==searchid){
            printf("\n--- Equipment Found ---\n");
            printf("Name: %s\n",e.name);
            printf("Quantity: %d\n",e.quantity);
            printf("Manufacturer ID: %d\n",e.manufacturer_id);
            found=1;
            break;
        }
    }
    fclose(fp);

    if(!found){
        printf("Equipment with ID %d not found.\n",searchid);
    }
}

void updateEquipment(){
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
    while(fscanf(fp,"%d %s %d %f %d",&e.id,e.name,&e.quantity,&e.price,&e.manufacturer_id)==5){
        if(e.id==targetid){
            found=1;
            printf("\nCurrent details: \n");
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\nManufacturer ID: %d\n\n",e.id,e.name,e.quantity,e.price,e.manufacturer_id);

            printf("Enter new name (no spaces): ");
            scanf("%s",e.name);
            printf("Enter new Quantity: ");
            scanf("%d",&e.quantity);
            printf("Enter new Price: ");
            scanf("%f",&e.price);
            printf("Enter new Manufacturer ID: ");
            scanf("%d",&e.manufacturer_id);
            

            fprintf(temp,"%d %s %d %.2f %d\n",e.id,e.name,e.quantity,e.price,e.manufacturer_id);
        }
        else{
            fprintf(temp,"%d %s %d %.2f %d\n",e.id,e.name,e.quantity,e.price,e.manufacturer_id);
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


void deleteEquipment(){
    int targetid;
    struct Equipment e;
    int found =0;
    printf("Enter Equipment ID to delete: ");
    if (scanf("%d",&targetid)!=1){
        printf("Invalid input.\n");
        return;
    }
    FILE *fp =fopen("data/equipment.txt","r");
    if(fp==NULL){
        printf("No equipment file found.\n");
        return;
    }

    FILE *temp=fopen("data/temp_equipment.txt","w");
    
    while(fscanf(fp,"%d %s %d %f %d",&e.id,e.name,&e.quantity,&e.price,&e.manufacturer_id)==5){
        if(e.id==targetid){
            found=1;
            continue;
        }
        else{
            fprintf(temp,"%d %s %d %.2f %d\n",e.id,e.name,e.quantity,e.price,e.manufacturer_id);
        }
    }
    fclose(fp);
    fclose(temp);

    if(!found){
        remove("data/temp_equipment.txt");
        printf("Equipment with ID %d not found, no deletion performed.\n",targetid);
        return;
    }

    remove("data/equipment.txt");

    rename("data/temp_equipment.txt","data/equipment.txt");

    printf("Equipment with ID %d deleted successfully.\n",targetid);
}
