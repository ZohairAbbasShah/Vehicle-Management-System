#include<stdio.h>
#include "vehicle.h"

void saveVehicle(struct vehicleinfo list[],int num){
    FILE *fp=fopen(File_Name,"wb");
    if(fp==NULL){
        printf("Could not save to file. \n");
        return;
    }
    fwrite(list,sizeof(struct vehicleinfo),num,fp);
    fclose(fp);
}
int loadVehicle(struct vehicleinfo list[]){
    FILE *fp=fopen(File_Name,"rb");
    int count=0;
    if(fp==NULL){
        return 0;
    }
    while(count<MAX_VEHICLES && fread(&list[count],sizeof(struct vehicleinfo),1,fp)==1 ){
        count++;
    }
    fclose(fp);
    return count;
}