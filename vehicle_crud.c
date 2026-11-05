#include <stdio.h>
#include <string.h>
#include "vehicle.h"

/* Seller must type the phone number used on the ad.
   Returns 1 if it matches, 0 if not. */
static int checkOwner(struct Ad *a) {
    char phone[20];

    printf("Enter your phone number (the one on the ad): ");
    readText(phone, 20);

    if (strcmp(a->sellerPhone, phone) != 0) {
        printf("[!] Phone number does not match. This is not your ad.\n");
        return 0;
    }
    return 1;
}

/* ================= SELLER SIDE ================= */

/* ---------- CREATE ---------- */
void postAd(void) {
    struct Ad list[MAX_ADS];
    struct Ad a;
    int count, i, nextId = 1;

    count = loadAds(list);

    printf("\n===== POST A VEHICLE FOR SALE =====\n");

    if (count >= MAX_ADS) {
        printf("Sorry, the website is full.\n");
        return;
    }

    printf("Your name             : ");
    readNonEmpty(a.sellerName, 50);
    printf("Your phone            : ");
    readNonEmpty(a.sellerPhone, 20);
    printf("Brand (e.g. Toyota)   : ");
    readNonEmpty(a.brand, 30);
    printf("Model (e.g. Corolla)  : ");
    readNonEmpty(a.model, 30);
    a.year    = readRange("Year                  : ", MIN_YEAR, MAX_YEAR);
    a.price   = readRange("Price (Rs)            : ", 1, 1000000000);
    a.mileage = readRange("Kilometers driven     : ", 0, 1000000);
    chooseFuel(a.fuel);
    chooseTransmission(a.transmission);
    printf("City                  : ");
    readNonEmpty(a.city, 30);
    printf("Description           : ");
    readText(a.description, 100);

    for (i = 0; i < count; i++) {
        if (list[i].adId >= nextId) nextId = list[i].adId + 1;
    }

    a.adId   = nextId;
    a.status = AD_ACTIVE;

    list[count] = a;
    count++;
    saveAds(list, count);

    printf("\n[OK] Your ad is live! Ad ID: %d (remember it to edit later)\n", a.adId);
}

/* ---------- READ: my ads (found by phone) ---------- */
void showMyAds(void) {
    struct Ad list[MAX_ADS];
    int count, i, shown = 0;
    char phone[20];

    count = loadAds(list);

    printf("\nEnter your phone number: ");
    readText(phone, 20);

    printf("\n===== MY ADS =====");
    printAdHeader();

    for (i = 0; i < count; i++) {
        if (strcmp(list[i].sellerPhone, phone) == 0) {
            printAdRow(list[i]);
            shown++;
        }
    }

    if (shown == 0) printf("No ads found for this phone number.\n");
}

/* ---------- UPDATE ---------- */
void editAd(void) {
    struct Ad list[MAX_ADS];
    int count, i, adId;

    count = loadAds(list);

    printf("\n===== EDIT AD =====\n");
    adId = readRange("Enter Ad ID (0 = back): ", 0, 1000000);
    if (adId == 0) return;

    for (i = 0; i < count; i++) {
        if (list[i].adId == adId) {
            if (!checkOwner(&list[i])) return;

            printf("Editing: %s %s (%d)\n", list[i].brand, list[i].model, list[i].year);
            list[i].price   = readRange("New price (Rs)        : ", 1, 1000000000);
            list[i].mileage = readRange("New kilometers driven : ", 0, 1000000);
            printf("New city              : ");
            readNonEmpty(list[i].city, 30);
            printf("New description       : ");
            readText(list[i].description, 100);

            saveAds(list, count);
            printf("\n[OK] Ad updated!\n");
            return;
        }
    }

    printf("[!] Ad not found.\n");
}

/* ---------- DELETE ---------- */
void deleteAd(void) {
    struct Ad list[MAX_ADS];
    int count, i, j, adId, sure;

    count = loadAds(list);

    printf("\n===== DELETE AD =====\n");
    adId = readRange("Enter Ad ID (0 = back): ", 0, 1000000);
    if (adId == 0) return;

    for (i = 0; i < count; i++) {
        if (list[i].adId == adId) {
            if (!checkOwner(&list[i])) return;

            sure = readRange("Are you sure? 1 = Yes, 0 = No : ", 0, 1);
            if (sure == 0) return;

            for (j = i; j < count - 1; j++) list[j] = list[j + 1];
            count--;
            saveAds(list, count);

            printf("\n[OK] Ad deleted.\n");
            return;
        }
    }

    printf("[!] Ad not found.\n");
}

/* ---------- Mark as sold ---------- */
void markSold(void) {
    struct Ad list[MAX_ADS];
    int count, i, adId;

    count = loadAds(list);

    printf("\n===== MARK AS SOLD =====\n");
    adId = readRange("Enter Ad ID (0 = back): ", 0, 1000000);
    if (adId == 0) return;

    for (i = 0; i < count; i++) {
        if (list[i].adId == adId) {
            if (!checkOwner(&list[i])) return;

            list[i].status = AD_SOLD;
            saveAds(list, count);
            printf("\n[OK] Marked as SOLD. It will no longer show in browse/search.\n");
            return;
        }
    }

    printf("[!] Ad not found.\n");
}

/* ================= BUYER SIDE ================= */

/* Browse all ads that are still for sale */
void browseAds(void) {
    struct Ad list[MAX_ADS];
    int count, i, shown = 0;

    count = loadAds(list);

    printf("\n===== VEHICLES FOR SALE =====");
    printAdHeader();

    for (i = 0; i < count; i++) {
        if (list[i].status == AD_ACTIVE) {
            printAdRow(list[i]);
            shown++;
        }
    }

    if (shown == 0) {
        printf("No vehicles for sale right now.\n");
        return;
    }

    printf("\n%d vehicle(s) found.\n", shown);
    openAd();
}

/* Search with filters */
void searchAds(void) {
    struct Ad list[MAX_ADS];
    int count, i, found = 0;
    int maxPrice, minYear;
    char keyword[50], city[30], name[70];

    count = loadAds(list);

    printf("\n===== SEARCH =====\n");
    printf("(press Enter to skip a text filter, type 0 to skip a number filter)\n");
    printf("Brand or model : ");
    readText(keyword, 50);
    printf("City           : ");
    readText(city, 30);
    maxPrice = readRange("Maximum price    : ", 0, 1000000000);
    minYear  = readRange("Minimum year     : ", 0, MAX_YEAR);

    printf("\n===== SEARCH RESULTS =====");
    printAdHeader();

    for (i = 0; i < count; i++) {
        if (list[i].status == AD_ACTIVE) {
            sprintf(name, "%s %s", list[i].brand, list[i].model);

            if (containsText(name, keyword) &&
                containsText(list[i].city, city) &&
                (maxPrice == 0 || list[i].price <= maxPrice) &&
                (minYear == 0 || list[i].year >= minYear)) {
                printAdRow(list[i]);
                found++;
            }
        }
    }

    if (found == 0) {
        printf("No vehicles match your search.\n");
        return;
    }

    printf("\n%d vehicle(s) found.\n", found);
    openAd();
}

/* Ask which ad to open, then show full details + seller contact */
void openAd(void) {
    struct Ad list[MAX_ADS];
    int count, i, adId;

    adId = readRange("\nEnter Ad ID to see details (0 = back): ", 0, 1000000);
    if (adId == 0) return;

    count = loadAds(list);

    for (i = 0; i < count; i++) {
        if (list[i].adId == adId) {
            printf("\n=========================================\n");
            printf("  %s %s (%d)\n", list[i].brand, list[i].model, list[i].year);
            printf("=========================================\n");
            printf("Price        : Rs %d\n", list[i].price);
            printf("Kilometers   : %d km\n", list[i].mileage);
            printf("Fuel         : %s\n", list[i].fuel);
            printf("Transmission : %s\n", list[i].transmission);
            printf("City         : %s\n", list[i].city);
            printf("Status       : %s\n", list[i].status == AD_SOLD ? "SOLD" : "Available");
            printf("Description  : %s\n", list[i].description);
            printf("-----------------------------------------\n");
            printf("Seller       : %s\n", list[i].sellerName);
            printf("Phone        : %s\n", list[i].sellerPhone);
            return;
        }
    }

    printf("[!] Ad not found.\n");
}