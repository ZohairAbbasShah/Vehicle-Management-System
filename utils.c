#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vehicle.h"

int readInt(void) {
    char line[50];
    int number;

    while (1) {
        if (fgets(line, sizeof(line), stdin) == NULL) exit(0);
        if (sscanf(line, "%d", &number) == 1) return number;
        printf("Please enter a number: ");
    }
}

void readText(char text[], int size) {
    int c;

    if (fgets(text, size, stdin) == NULL) exit(0);

    if (strchr(text, '\n') == NULL) {
        while ((c = getchar()) != '\n' && c != EOF) { }
    } else {
        text[strcspn(text, "\n")] = '\0';
    }
}

void readNonEmpty(char text[], int size) {
    readText(text, size);
    while (text[0] == '\0') {
        printf("This cannot be empty. Try again: ");
        readText(text, size);
    }
}

int readRange(char prompt[], int min, int max) {
    int n;

    printf("%s", prompt);
    n = readInt();
    while (n < min || n > max) {
        printf("Enter a number from %d to %d: ", min, max);
        n = readInt();
    }
    return n;
}

/* Case-insensitive "is word inside text". Empty word matches everything. */
int containsText(char text[], char word[]) {
    char a[200], b[200];
    int i;

    for (i = 0; text[i] != '\0' && i < 199; i++) a[i] = tolower((unsigned char)text[i]);
    a[i] = '\0';
    for (i = 0; word[i] != '\0' && i < 199; i++) b[i] = tolower((unsigned char)word[i]);
    b[i] = '\0';

    return strstr(a, b) != NULL;
}

void chooseFuel(char fuel[]) {
    int c;

    printf("Fuel: 1.Petrol  2.Diesel  3.Hybrid  4.CNG  5.Electric\n");
    c = readRange("Choose fuel (1-5): ", 1, 5);

    if (c == 1)      strcpy(fuel, "Petrol");
    else if (c == 2) strcpy(fuel, "Diesel");
    else if (c == 3) strcpy(fuel, "Hybrid");
    else if (c == 4) strcpy(fuel, "CNG");
    else             strcpy(fuel, "Electric");
}

void chooseTransmission(char transmission[]) {
    int c = readRange("Transmission: 1.Manual  2.Automatic : ", 1, 2);

    if (c == 1) strcpy(transmission, "Manual");
    else        strcpy(transmission, "Automatic");
}

void printAdHeader(void) {
    printf("\n%-4s %-24s %-5s %-11s %-9s %-12s %-6s\n",
           "ID", "VEHICLE", "YEAR", "PRICE (Rs)", "KM", "CITY", "STATUS");
    printf("--------------------------------------------------------------------------\n");
}

void printAdRow(struct Ad a) {
    char name[70];

    sprintf(name, "%s %s", a.brand, a.model);
    printf("%-4d %-24.24s %-5d %-11d %-9d %-12.12s %-6s\n",
           a.adId, name, a.year, a.price, a.mileage, a.city,
           a.status == AD_SOLD ? "SOLD" : "Avail");
}