#ifndef VEHICLE_H
#define VEHICLE_H

#define File_Name "Vehicle_date.txt"
#define MAX_VEHICLES 100 

// Vehicle Information
struct vehicleinfo{
    char Registration_number[50];
    char Model[50];
    char Brand[50];
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


// Owner Functions
void addOwner();
void displayOwner();


// Status Functions
void updateStatus();
void displayStatus();


// Maintenance Functions
void addMaintenanceRecord();
void displayMaintenanceHistory();
void displayMaintenanceCost();


// File Handling Functions
void saveVehicle(struct Vehicle list[],int max );
int loadVehicle(struct Vehicle list[]);


#endif