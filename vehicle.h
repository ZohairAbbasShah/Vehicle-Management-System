#ifndef VEHICLE_H
#define VEHICLE_H

#define File_Name "Vehicle_data.txt"
#define MAX_VEHICLES 100

// Vehicle Information
struct vehicleinfo{
    char Registration_number[50];
    char Model[50];
    char Brand[50];

    int  year;
    int  price;
    int  mileage;            // km driven
    char fuel[15];
    char transmission[15];
    char city[30];
    char sellerName[50];
    char sellerPhone[20];
    char saleStatus[15];     // Available / Reserved / Sold
};

// Owner Information
struct Ownerinfo{
    int id;
    char Name[100];
    int phone_number;
};

// Maintenance Information
struct Maintenance{
    char description[500];
    int cost;
    char date[11];
};

// Vehicle Status
struct status{
    char status[50];
};

// CRUD Functions
void add_Vehicle(void);
void update_Vehicle(void);
void Search_Vehicle(void);
void delete_Vehicle(void);
void display_Vehicle(void);
void filter_Vehicle(void);      
void updateStatus(void);        
int  askNumber(char prompt[], int min, int max);  

// File Handling Functions
void saveVehicle(struct vehicleinfo list[],int num );
int loadVehicle(struct vehicleinfo list[]);

#endif