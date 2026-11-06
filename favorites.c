#include <stdio.h>
#include <string.h>
#include "vehicle.h"

void addFavorite(char phone[], int adId) {
    struct Favorite list[MAX_FAV];
    int count, i;

    count = loadFavorites(list);

    for (i = 0; i < count; i++) {
        if (strcmp(list[i].phone, phone) == 0 && list[i].adId == adId) {
            printf("It is already in your favorites.\n");
            return;
        }
    }

    if (count >= MAX_FAV) {
        printf("Favorites list is full.\n");
        return;
    }

    strcpy(list[count].phone, phone);
    list[count].adId = adId;
    count++;
    saveFavorites(list, count);

    printf("\n[OK] Added to favorites!\n");
}

void removeFavorite(char phone[]) {
    struct Favorite list[MAX_FAV];
    int count, i, j, adId;

    count = loadFavorites(list);

    adId = readRange("Enter Ad ID to remove: ", 0, 1000000);

    for (i = 0; i < count; i++) {
        if (strcmp(list[i].phone, phone) == 0 && list[i].adId == adId) {
            for (j = i; j < count - 1; j++) {
                list[j] = list[j + 1];
            }
            count--;
            saveFavorites(list, count);
            printf("\n[OK] Removed from favorites.\n");
            return;
        }
    }

    printf("[!] That ad is not in your favorites.\n");
}

void favoritesMenu(void) {
    struct Favorite list[MAX_FAV];
    struct Ad ad;
    int count, i, shown = 0, choice;
    char phone[20];

    count = loadFavorites(list);

    printf("\nEnter your phone number: ");
    readNonEmpty(phone, 20);

    printf("\n===== MY FAVORITES =====");
    printAdHeader();

    for (i = 0; i < count; i++) {
        if (strcmp(list[i].phone, phone) == 0) {
            ad = getAd(list[i].adId);
            if (ad.adId != 0) {
                printAdRow(ad);
                shown++;
            }
        }
    }

    if (shown == 0) {
        printf("You have no favorites yet.\n");
        return;
    }

    printf("\n1. Open an ad\n");
    printf("2. Remove from favorites\n");
    printf("0. Back\n");
    choice = readRange("Choose: ", 0, 2);

    if (choice == 1) {
        openAd();
    } else if (choice == 2) {
        removeFavorite(phone);
    }
}

void removeAdFavorites(int adId) {
    struct Favorite list[MAX_FAV];
    int count, i, kept = 0;

    count = loadFavorites(list);

    for (i = 0; i < count; i++) {
        if (list[i].adId != adId) {
            list[kept] = list[i];
            kept++;
        }
    }
    saveFavorites(list, kept);
}