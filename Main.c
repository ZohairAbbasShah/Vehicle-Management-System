#include <stdio.h>
#include "vehicle.h"

int main(void) {
    int choice;

    do {
        printf("\n===== VEHICLE MANAGEMENT SYSTEM =====\n");
        printf("1. Add vehicle\n");
        printf("2. Show all vehicles\n");
        printf("3. Search vehicle\n");
        printf("4. Update vehicle\n");
        printf("5. Delete vehicle\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_Vehicle();     break;
            case 2: display_Vehicle(); break;
            case 3: Search_Vehicle();  break;
            case 4: update_Vehicle();  break;
            case 5: delete_Vehicle();  break;
            case 0: printf("Goodbye!\n"); break;
            default: printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
