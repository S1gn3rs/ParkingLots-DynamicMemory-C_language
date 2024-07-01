/**
 * @file parkingLot.c
 * @brief Implementation of parking lot related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Include necessaries library and header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parkingLot.h"

parkingLot* createPark(char* parkName, int capacity,
    double initialFee, double laterFee, double maxFee){

    parkingLot *park = (parkingLot*) malloc(sizeof(parkingLot));

    park->name = (char*) malloc(sizeof(char)*strlen(parkName)+ 1);
    strcpy(park->name, parkName);
    park->capacity = capacity;
    park->initialFee = initialFee;
    park->laterFee = laterFee;
    park->maxFee = maxFee;
    park->carsIn = createList();
    park->parkHistory = createList();
    return park;
}

char* getParkName( parkingLot *park){
    return park->name;
}

list* getParkCarsIn(parkingLot *park){
    return park->carsIn;
}

int getParkCapacity(parkingLot *park){
    return park->capacity;
}

double getParkInitialFee(parkingLot *park){
    return park->initialFee;
}

double getParkLaterFee(parkingLot *park){
    return park->laterFee;
}

double getParkMaxFee(parkingLot * park){
    return park->maxFee;
}

list* getParkHistory(parkingLot * park){
    return park->parkHistory;
}

int getParkFreeSpaces(parkingLot *park){
    return getParkCapacity(park) - getListSize(getParkCarsIn(park));
}

int isInvalidFee(double initialFee, double laterFee, double maxFee){
    if (initialFee <= 0 || laterFee <= 0 || maxFee <= 0) return TRUE;
    if (initialFee > laterFee || laterFee > maxFee) return TRUE;
    return FALSE;
}
int isInvalidCapacity(parkingLot* park){
    return (getParkCapacity(park) <= 0);
}

int pArgumentsAreValid(list *listParks, char *tempName, int capacity,
    double initialFee, double laterFee, double maxFee){

    if (identityExists(listParks, tempName))
        printf("%s: parking already exists.\n", tempName);

    else if (capacity <= 0)
        printf("%d: invalid capacity.\n", capacity);

    else if (isInvalidFee(initialFee, laterFee, maxFee))
        printf("invalid cost.\n");

    else if(getListSize(listParks) == MAXPARKS)
        printf("too many parks.\n");

    else return TRUE;

    return FALSE;
}

void moveToParkHistory(parkingLot *park, vehicle *car,
    dateAndHour *logTime, double fee){

    date *logDate = getDate(logTime);
    hours *logHours = getHours(logTime);
    parkedCars* prkdCarsSect; //section of parked cars
    info* carExit=createInfo(createExitVehicle(car,logHours,fee),ISEXITVEHICLE);

    free(popItem(getParkCarsIn(park), getCarRegistration(car)));

    if ((prkdCarsSect=searchForParkedCars(getParkHistory(park),logDate))==NULL){
        prkdCarsSect = createParkedCars(logDate);
        addItemInOrder(getParkHistory(park),
            createInfo(prkdCarsSect,ISPARKEDCARS));
    }
    else{ // in case the parked cars section with that date already exists
        free(logDate);
        // pointer to the date in the parked cars section
        changeDate(logTime, getParkedCarsDate(prkdCarsSect));
    }
    addToEarnedFee(prkdCarsSect, fee);
    addItem(getParkedCarsList(prkdCarsSect), carExit);
}

double calculateFee(parkingLot *park, int minutParked){
    return payment(minutParked, getParkInitialFee(park),
        getParkLaterFee(park), getParkMaxFee(park));
}

list* shallowOrderCopyParks(list* listParks){
    list* copy = createList();
    info *currentPark = getFirstItem(listParks);
    info *copyPark;

    while(currentPark != NULL){
        copyPark = createInfo(getParkInfo(currentPark), ISPARKINGLOT);
        addItemInOrder(copy, copyPark);
        currentPark = getNextItem(currentPark);
    }
    return copy;
}

void freePark(parkingLot *park){
    freeCarEntries(getParkCarsIn(park), getParkName(park));
    freeParkedCarsEntries(getParkHistory(park), getParkName(park));
    free(getParkName(park));
    freeList(getParkCarsIn(park));
    free(park);
}
