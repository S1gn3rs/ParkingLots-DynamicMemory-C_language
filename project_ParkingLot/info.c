/**
 * @file info.c
 * @brief This file contains the implementation of the info struct.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Include necessary library and header file
#include <stdlib.h>
#include "info.h"

info *createInfo(void *item, unsigned char type){
    info *newInfo = (info*) malloc(sizeof(info));

    newInfo->type = type;
    if (type == ISVEHICLE){
        newInfo->details = (vehicle*) item;
    }
    else if (type == ISPARKEDCARS){
        newInfo->details = (parkedCars*) item;
    }
    else if (type == ISCARHISTORY){
        newInfo->details = (carHistory*) item;
    }
    else if(type == ISEXITVEHICLE){
        newInfo->details= (exitVehicle*) item;
    }
    else if(type == ISENTRYANDEXIT){
        newInfo->details = (entryAndExit*) item;
    }
    else if (type == ISPARKINGLOT){
        newInfo->details = (parkingLot*) item;
    }


    newInfo->nextItem = NULL;
    newInfo->previousItem = NULL;
    return newInfo;
}

unsigned char getInfoType(info *item){
    return item->type;
}

parkingLot *getParkInfo(info *item){
    if (item == NULL) return NULL;
    return (parkingLot*) item->details;
}

vehicle *getCarInfo(info *item){
    if (item == NULL) return NULL;
    if (getInfoType(item) == ISVEHICLE) return (vehicle*) item->details;
    return getExitVehicleCar((exitVehicle*) item->details);
}

parkedCars *getParkedCarsInfo(info *item){
    if (item == NULL) return NULL;
    return (parkedCars*) item->details;
}

carHistory *getCarHistoryInfo(info *item){
    if (item == NULL) return NULL;
    return (carHistory*) item->details;
}

entryAndExit *getEntryAndExitInfo(info *item){
    if (item == NULL) return NULL;
    return (entryAndExit*) item->details;
}

exitVehicle *getExitVehicleInfo(info *item){
    if (item == NULL) return NULL;
    return (exitVehicle*) item->details;
}

info *getNextItem(info *item){
    return item->nextItem;
}

info *getPreviousItem(info *item){
    return item->previousItem;
}

char *getInfoIdentifier(info *item){
    if (getInfoType(item) == ISVEHICLE)
        return getCarRegistration(getCarInfo(item));

    else if (getInfoType(item) == ISPARKINGLOT)
        return getParkName(getParkInfo(item));

    else
        return getCarHistoryName(getCarHistoryInfo(item));
}

void changeNextItem(info *item, info *newNextItem){
    item->nextItem = newNextItem;
}

void changePreviousItem(info *item, info *newPreviousItem){
    item->previousItem = newPreviousItem;
}

void freeInfo(info *itemInfo){
    int infoType = getInfoType(itemInfo);

    if (itemInfo == NULL) return;
    if (infoType == ISVEHICLE)
        freeCar(getCarInfo(itemInfo));

    else if (infoType == ISPARKINGLOT)
        freePark(getParkInfo(itemInfo));

    else if (infoType == ISCARHISTORY)
        freeCarHistory(getCarHistoryInfo(itemInfo));

    else if (infoType == ISPARKEDCARS)
        freeParkedCars(getParkedCarsInfo(itemInfo));

    else if(infoType == ISENTRYANDEXIT)
        freeEntryAndExit(getEntryAndExitInfo(itemInfo));

    else if(infoType == ISEXITVEHICLE)
        freeExitVehicle(getExitVehicleInfo(itemInfo));

    free(itemInfo);
}
