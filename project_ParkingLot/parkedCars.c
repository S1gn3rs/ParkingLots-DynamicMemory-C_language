/**
 * @file parkedCars.c
 * @brief Implementation of parked cars related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Include necessary library and header file
#include <stdlib.h>
#include "parkedCars.h"

parkedCars *createParkedCars(date *logDate){
    parkedCars *newPrkdCars = (parkedCars*) malloc(sizeof(parkedCars));
    newPrkdCars->parkedCars = createList();
    newPrkdCars->earnedFee = 0;
    newPrkdCars->parkingDate = logDate;
    return newPrkdCars;
}

date *getParkedCarsDate(parkedCars *parkedCars){
    return parkedCars->parkingDate;
}

double getParkedCarsEarnedFee(parkedCars *parkedCars){
    return parkedCars->earnedFee;
}

list *getParkedCarsList(parkedCars *parkedCars){
    return parkedCars->parkedCars;
}

void addToEarnedFee(parkedCars *parkedCars, double fee){
    parkedCars->earnedFee += fee;
}

parkedCars *searchForParkedCars(list *listPrkdCars, date *logDate){
    info *prkdCarsSect = getLastItem(listPrkdCars);
    // Iterate over the list until a parked cars section with the same
    //date is found or the list ends
    while (prkdCarsSect != NULL && !isSameDate(logDate,
        getParkedCarsDate(getParkedCarsInfo(prkdCarsSect))))
            prkdCarsSect = getPreviousItem(prkdCarsSect);

    return getParkedCarsInfo(prkdCarsSect);
}

void freeParkedCars(parkedCars *parkedCars){
    shallowFreeList(getParkedCarsList(parkedCars)); // Parked cars info that day
    freeDate(getParkedCarsDate(parkedCars));
    free(parkedCars);
}
