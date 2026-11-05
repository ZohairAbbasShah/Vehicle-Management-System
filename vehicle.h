#ifndef VEHICLE_H
#define VEHICLE_H

#define ADS_FILE   "ads.dat"
#define MAX_ADS    200
#define MIN_YEAR   1980
#define MAX_YEAR   2030
#define AD_ACTIVE  1
#define AD_SOLD    2

struct Ad {
    int  adId;
    char sellerName[50];
    char sellerPhone[20];
    char brand[30];
    char model[30];
    int  year;
    int  price;
    int  mileage;
    char fuel[15];
    char transmission[15];
    char city[30];
    char description[100];
    int  status;
};

/* file_handler.c */
int  loadAds(struct Ad list[]);
void saveAds(struct Ad list[], int num);

/* utils.c */
int  readInt(void);
void readText(char text[], int size);
void readNonEmpty(char text[], int size);
int  readRange(char prompt[], int min, int max);
int  containsText(char text[], char word[]);
void chooseFuel(char fuel[]);
void chooseTransmission(char transmission[]);
void printAdHeader(void);
void printAdRow(struct Ad a);

/* vehicle_crud.c: seller side */
void postAd(void);
void showMyAds(void);
void editAd(void);
void deleteAd(void);
void markSold(void);

/* vehicle_crud.c: buyer side */
void browseAds(void);
void searchAds(void);
void openAd(void);

#endif