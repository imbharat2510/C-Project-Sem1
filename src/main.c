#include <stdio.h>
#include "../include/equipment.h"

int main(){
print("Welcome to Sports managing system")
	while(1){
       		printf("\n1. Add Equipment\n");
        	printf("2. View Equipment\n");
        	printf("3. Search Equipment\n");
        	printf("4. Update Equipment\n");
        	printf("5. Delete Equipment\n");
        	printf("6. Exit\n\n");
        	printf("Enter choice: ");
       		scanf("%d",&choice);

        if(choice==1) addEquipment();
        	else if(choice==2) viewEquipment();
        	else if(choice==3) searchEquipment();
        	else if(choice==4) updateEquipment();
        	else if(choice==5) deleteEquipment();
        	else break;
    }

    return 0;
}
