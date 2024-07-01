/**
 * @file vehicleAndExitVehicle.c
 * @brief Implementation of vehicle and exit vehicle related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Include necessary libraries and header files.
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "vehicleAndExitVehicle.h"

vehicle* createCar(char* identifer, dateAndHour *entryTime, char* parkName){
    vehicle *newCar = (vehicle*) malloc(sizeof(vehicle));

    strcpy(newCar->registration, identifer);
    newCar->insidePark = parkName;
    newCar-> pastParked = createList();

    addItemInOrder(newCar->pastParked,
        createInfo(createCarHistory(entryTime, parkName), ISCARHISTORY));

    return newCar;
}

exitVehicle* createExitVehicle(vehicle *car, hours *logHours, double fee){
    exitVehicle *newExit = (exitVehicle*) malloc(sizeof(exitVehicle));

    newExit-> car = car;
    newExit-> exitHours = logHours;
    newExit-> payment = fee;
    return newExit;
}

char* getCarRegistration(vehicle *car){
    return car->registration;
}

char* getCarParkedParkName(vehicle *car){
    return car -> insidePark;
}

list* getCarPastParked(vehicle *car){
    return car->pastParked;
}

vehicle* getExitVehicleCar(exitVehicle *exit){
    return exit->car;
}

hours *getExitVehicleExitTime(exitVehicle *exit){
    return exit->exitHours;
}

double getExitVehiclePayment(exitVehicle *exit){
    return exit->payment;
}

dateAndHour *getCarLastEntryTime(vehicle *car){
    info *carHistorySection = searchForItem(getCarPastParked(car),
        getCarParkedParkName(car));

    return getCarHistoryLastEntry(getCarHistoryInfo(carHistorySection));
}

void changeCarParkedParkName(vehicle *car, char *parkName){
    car->insidePark = parkName;
}

void putNewEntryInCar(vehicle *car, dateAndHour *time, char* parkName){
    info* carHistorySection = searchForItem(getCarPastParked(car), parkName);

    if (carHistorySection == NULL){ // don't have a history in this park
        carHistorySection = createInfo(
            createCarHistory(time, parkName), ISCARHISTORY);

        addItemInOrder(getCarPastParked(car), carHistorySection);
    }
    else
        putNewEntryInCarHistory(getCarHistoryInfo(carHistorySection), time);
}

void putNewExitInCar(vehicle *car, dateAndHour *time, double fee){
    info *carHistorySection = searchForItem(getCarPastParked(car),
        getCarParkedParkName(car));

    putNewExitInCarHistory(getCarHistoryInfo(carHistorySection), time, fee);
}

int minutesParked(vehicle *car, dateAndHour *exitTime){
    dateAndHour *entryTime = getCarLastEntryTime(car);

    return differenceInMinutes(exitTime, entryTime);
}

int isCarParked(vehicle *car){
    return getCarParkedParkName(car) != NULL;
}

int isValidCarPlate(char *carPlate){
    int pos = 0, hasNumbers = FALSE, hasLetters = FALSE; // pos->position

    for(pos = 0; pos <= 6; pos += 3){ // carPlate is like : xx-xx-xx\0
        if (isdigit(*(carPlate + pos)) && isdigit(*(carPlate + pos + 1)))
            hasNumbers = TRUE;

        else if (isupper(*(carPlate + pos)) && isupper(*(carPlate + pos + 1)))
            hasLetters = TRUE;

        else return FALSE;
    }
    return hasNumbers && hasLetters; // FALSE if it has 3 equal type of pairs
}

void freeCar(vehicle *car){
    freeList(getCarPastParked(car));
    free(car);
}

void freeExitVehicle(exitVehicle *exit){
    free(getExitVehicleExitTime(exit));
    free(exit);
}
