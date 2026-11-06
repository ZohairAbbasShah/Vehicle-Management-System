#include <stdio.h>
#include "vehicle.h"

int loadAds(struct Ad list[]) {
    FILE *fp = fopen(ADS_FILE, "rb");
    int count = 0;

    if (fp == NULL) return 0;
    while (count < MAX_ADS && fread(&list[count], sizeof(struct Ad), 1, fp) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}

void saveAds(struct Ad list[], int num) {
    FILE *fp = fopen(ADS_FILE, "wb");

    if (fp == NULL) {
        printf("Could not save ads.\n");
        return;
    }
    fwrite(list, sizeof(struct Ad), num, fp);
    fclose(fp);
}

// favourite file functions
int loadFavorites(struct Favorite list[]) {
    FILE *fp = fopen(FAV_FILE, "rb");
    int count = 0;

    if (fp == NULL) {
        return 0;
    }

    while (count < MAX_FAV && fread(&list[count], sizeof(struct Favorite), 1, fp) == 1) {
        count++;
    }
    fclose(fp);
    return count;
}

void saveFavorites(struct Favorite list[], int num) {
    FILE *fp = fopen(FAV_FILE, "wb");

    if (fp == NULL) {
        printf("Could not save favorites.\n");
        return;
    }
    fwrite(list, sizeof(struct Favorite), num, fp);
    fclose(fp);
}