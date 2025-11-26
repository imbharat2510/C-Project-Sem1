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
            printf("2. View Borrowers\n");
            printf("3. Search Borrower by ID\n");
            printf("4. Search Equipment by ID\n");
            printf("5. Logout/Exit\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);

            switch (choice) {
                case 1: {
                    int z;
                    do {
                        printf("\n--- Manage Equipment ---\n");
                        printf("1. Add Equipment\n");
                        printf("2. View Equipment\n");
                        printf("3. Update Equipment\n");
			printf("4. Remove Equipment\n");
                        printf("5. Back\n");
                        printf("Enter your choice: ");
                        scanf("%d", &z);
                        if(z==1){
                                addEquipment();
                               }
                        else if(z==2){
                                viewEquipment();
                               }
                        else if(z==3){
                                updateEquipment();}
			else if(z==4){
				deleteEquipment();}
			else if(z==5){
                                break;}
			    else{
                                printf("Invalid choice in Manage Equipment.\n");}
                        
                    } while (1);
                    break;
                }
                case 2:
                    viewBorrowers();
                    break;
                case 3:
                    searchBorrower();
                    break;
                case 4:
                    searchEquipment();
                    break;
                case 5:
                    printf("Logging out...\n");
                    return 0;
                default:
                    printf("Invalid choice in Admin Menu.\n");
            }
        } while (choice != 7);
    } else if (role == 2) {
        int kop;
	printf("\n--- Student Login Menu ---\n");
	printf("1. Sign in\n");
	printf("2. Sign up (if new user)\n");
	scanf("%d",&kop);
	if (kop==1){
		if (sign_in()==1){
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
		}
		else if(sign_in()==3){
			printf("\nTry signing up :) \n");
			return 0;
		}
		else{
		return 0;
		}
		}
	else if (kop==2){
		sign_up();
	}
    }

    return 0;
}

