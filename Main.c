#include <stdio.h>
#include "vehicle.h"

int main(void) {
    int choice;

    do {
        printf("\n=========================================\n");
        printf("        VEHICLE MARKETPLACE\n");
        printf("     Buy and sell vehicles easily\n");
        printf("=========================================\n");
        printf("  --- Buy ---\n");
        printf("  [1] Browse vehicles for sale\n");
        printf("  [2] Search / filter vehicles\n");
        printf("  --- Sell ---\n");
        printf("  [3] Post a vehicle for sale\n");
        printf("  [4] My ads\n");
        printf("  [5] Edit my ad\n");
        printf("  [6] Delete my ad\n");
        printf("  [7] Mark my ad as sold\n");
        printf("  [8] My favorites\n");    
        printf("  [0] Exit\n");
        printf("-----------------------------------------\n");
        choice = readRange("Enter choice: ", 0, 8);

        switch (choice) {
            case 1: browseAds();  break;
            case 2: searchAds();  break;
            case 3: postAd();     break;
            case 4: showMyAds();  break;
            case 5: editAd();     break;
            case 6: deleteAd();   break;
            case 7: markSold();   break;
            case 8: favoritesMenu(); break;          
            case 0: printf("\nGoodbye!\n"); break;
        }
    } while (choice != 0);

    return 0;
}