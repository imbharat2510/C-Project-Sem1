/* src/main.c
   Uses the functions implemented in your uploaded files:
     - login.c: admin(), sign_up(), sign_in() (as uploaded). See login.c. :contentReference[oaicite:1]{index=1}
     - borrower.c / equipment.c / inventory.c: functions declared in their headers
*/

#include <stdio.h>

#include "../include/login.h"
#include "../include/borrower.h"
#include "../include/equipment.h"
#include "../include/inventory.h"

int main(void) {
    int choice;

    while (1) {
        printf("\n====== SPORTS EQUIPMENT MANAGING SYSTEM ======\n");
        printf("============== LOGIN SYSTEM ==================\n");
        printf("1. Sign Up\n");
        printf("2. Sign In\n");
        printf("3. Admin Login\n");
        printf("4. Borrower Menu\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        if (scanf("%d", &choice) != 1) {
            int c; while ((c = getchar()) != '\n' && c != EOF) {}
            printf("Invalid input.\n");
            continue;
        }

        if (choice == 1) {
            sign_up();   /* from login.c (void) */
        }
        else if (choice == 2) {
            sign_in();   /* from login.c (void) — it prints success/failure itself */
        }
        else if (choice == 3) {
            int r = admin();  /* from login.c (returns int) */
            if (r == 1) {
                int achoice = 0;
                while (1) {
                    printf("\n--- ADMIN MENU ---\n");
                    printf("1. Add Equipment\n");
                    printf("2. View Equipment\n");
                    printf("3. Search Equipment\n");
                    printf("4. Update Equipment\n");
                    printf("5. Delete Equipment\n");
                    printf("6. Add Inventory\n");
                    printf("7. View Inventory\n");
                    printf("8. Search Inventory\n");
                    printf("9. Update Inventory Quantity\n");
                    printf("10. Back to Main Menu\n");
                    printf("Enter choice: ");
                    if (scanf("%d", &achoice) != 1) { int c; while ((c = getchar()) != '\n' && c != EOF) {} printf("Invalid input.\n"); continue; }

                    if (achoice == 1) addEquipment();
                    else if (achoice == 2) viewEquipment();
                    else if (achoice == 3) searchEquipment();
                    else if (achoice == 4) updateEquipment();
                    else if (achoice == 5) deleteEquipment();
                    else if (achoice == 6) addInventory();
                    else if (achoice == 7) viewInventory();
                    else if (achoice == 8) searchInventory();
                    else if (achoice == 9) updateInventoryQuantity();
                    else if (achoice == 10) break;
                    else printf("Invalid choice.\n");
                }
            } else {
                if (r == 0) printf("Wrong password.\n");
                else if (r == 2) printf("Incorrect passkey.\n");
                else if (r == 3) printf("Admin name not found.\n");
                else if (r == -1) printf("Admin file missing.\n");
                else printf("Unknown admin error code: %d\n", r);
            }
        }
        else if (choice == 4) {
            /* Borrower menu — sign_in() is void in your login.c,
               so main cannot auto-detect login success. We call the borrower functions directly.
               If you want main to require a successful sign-in before allowing borrowing,
               change sign_in() to return int and set current_user; I can do that. */
            int bchoice = 0;
            while (1) {
                printf("\n--- BORROWER MENU ---\n");
                printf("1. Borrow Equipment\n");
                printf("2. View Borrowers\n");
                printf("3. Search Borrower\n");
                printf("4. Return Borrowed Equipment\n");
                printf("5. Back to Main Menu\n");
                printf("Enter choice: ");
                if (scanf("%d", &bchoice) != 1) { int c; while ((c = getchar()) != '\n' && c != EOF) {} printf("Invalid input.\n"); continue; }

                if (bchoice == 1) addBorrower();
                else if (bchoice == 2) viewBorrowers();
                else if (bchoice == 3) searchBorrower();
                else if (bchoice == 4) returnBorrowedItem();
                else if (bchoice == 5) break;
                else printf("Invalid choice.\n");
            }
        }
        else if (choice == 5) {
            printf("Goodbye!\n");
            return 0;
        }
        else {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}

