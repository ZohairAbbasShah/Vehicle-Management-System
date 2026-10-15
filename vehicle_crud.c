#include <stdio.h>
#include <string.h>
#include "vehicle.h"

/* ---------- CREATE ---------- */
void add_Vehicle(void) {
    struct vehicleinfo list[MAX_VEHICLES];
    struct vehicleinfo v;
    int count, i;

    count = loadVehicle(list);

    if (count >= MAX_VEHICLES) {
        printf("Storage is full.\n");
        return;
    }

    printf("Registration number: ");
    scanf(" %49[^\n]", v.Registration_number);

    /* do not allow the same registration number twice */
    for (i = 0; i < count; i++) {
        if (strcmp(list[i].Registration_number, v.Registration_number) == 0) {
            printf("This registration number already exists.\n");
            return;
        }
    }

    printf("Model: ");
    scanf(" %49[^\n]", v.Model);
    printf("Brand: ");
    scanf(" %49[^\n]", v.Brand);

    list[count] = v;
    count++;
    saveVehicle(list, count);

    printf("Vehicle added!\n");
}

/* ---------- READ (show all) ---------- */
void display_Vehicle(void) {
    struct vehicleinfo list[MAX_VEHICLES];
    int count, i;

    count = loadVehicle(list);

    if (count == 0) {
        printf("No vehicles yet.\n");
        return;
    }

    printf("\n%-20s %-15s %-15s\n", "REGISTRATION", "MODEL", "BRAND");
    printf("--------------------------------------------------\n");
    for (i = 0; i < count; i++) {
        printf("%-20s %-15s %-15s\n",
               list[i].Registration_number, list[i].Model, list[i].Brand);
    }
}

/* ---------- SEARCH ---------- */
void Search_Vehicle(void) {
    struct vehicleinfo list[MAX_VEHICLES];
    int count, i;
    char reg[50];

    count = loadVehicle(list);

    printf("Enter registration number to search: ");
    scanf(" %49[^\n]", reg);

    for (i = 0; i < count; i++) {
        if (strcmp(list[i].Registration_number, reg) == 0) {
            printf("\nRegistration: %s\n", list[i].Registration_number);
            printf("Model       : %s\n", list[i].Model);
            printf("Brand       : %s\n", list[i].Brand);
            return;
        }
    }

    printf("Vehicle not found.\n");
}

/* ---------- UPDATE ---------- */
void update_Vehicle(void) {
    struct vehicleinfo list[MAX_VEHICLES];
    int count, i;
    char reg[50];

    count = loadVehicle(list);

    printf("Enter registration number to update: ");
    scanf(" %49[^\n]", reg);

    for (i = 0; i < count; i++) {
        if (strcmp(list[i].Registration_number, reg) == 0) {
            printf("New model: ");
            scanf(" %49[^\n]", list[i].Model);
            printf("New brand: ");
            scanf(" %49[^\n]", list[i].Brand);

            saveVehicle(list, count);
            printf("Vehicle updated!\n");
            return;
        }
    }

    printf("Vehicle not found.\n");
}

/* ---------- DELETE ---------- */
void delete_Vehicle(void) {
    struct vehicleinfo list[MAX_VEHICLES];
    int count, i, j;
    char reg[50];

    count = loadVehicle(list);

    printf("Enter registration number to delete: ");
    scanf(" %49[^\n]", reg);

    for (i = 0; i < count; i++) {
        if (strcmp(list[i].Registration_number, reg) == 0) {
            /* move every vehicle after it one step to the left */
            for (j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;

            saveVehicle(list, count);
            printf("Vehicle deleted!\n");
            return;
        }
    }

    printf("Vehicle not found.\n");
}
