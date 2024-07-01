/**
 * @file carHistoryAndEntryExit.c
 * @brief This file contains the implementation of a car history
 * and entryAndExit logs.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Include necessary library and header file
#include <stdlib.h>
#include "carHistoryAndEntryExit.h"

// Functions implementation
carHistory *createCarHistory(dateAndHour *startTime, char *parkName){
    carHistory *newCarHist = (carHistory*) malloc(sizeof(carHistory));

    newCarHist->parkName = parkName;
    newCarHist -> carInOutLog = createList();
    addItem(newCarHist->carInOutLog,
        createInfo(createEntryAndExit(startTime), ISENTRYANDEXIT));

    return newCarHist;
}

entryAndExit *createEntryAndExit(dateAndHour *entry){
    entryAndExit *newEntryLog = (entryAndExit*) malloc(sizeof(entryAndExit));

    newEntryLog->entry = entry;
    newEntryLog->exit = NULL;
    newEntryLog->Payedfee = 0;
    return newEntryLog;
}

char *getCarHistoryName(carHistory *carHist){
    return carHist->parkName;
}

list *getCarInOutLog(carHistory *carHist){
    return carHist->carInOutLog;
}

dateAndHour *getEntry(entryAndExit *ticket){
    return ticket->entry;
}

dateAndHour *getExit(entryAndExit *ticket){
    return ticket->exit;
}

dateAndHour *getCarHistoryLastEntry(carHistory *carHist){
    info *ticket = getLastItem(getCarInOutLog(carHist));

    return getEntry(getEntryAndExitInfo(ticket));
}

double getPayedFee(entryAndExit *ticket){
    return ticket->Payedfee;
}

void putNewEntryInCarHistory(carHistory *carHist, dateAndHour *time){
    addItem(getCarInOutLog(carHist),
        createInfo(createEntryAndExit(time), ISENTRYANDEXIT));
}

void putNewExitInCarHistory(carHistory *carHist, dateAndHour *time, double fee){
    entryAndExit *ticket;

    ticket = getEntryAndExitInfo(getLastItem(getCarInOutLog(carHist)));
    ticket->exit = time;
    ticket->Payedfee = fee;
}

void freeCarHistory(carHistory *carHist){
    freeList(getCarInOutLog(carHist));
    free(carHist);
}

void freeEntryAndExit(entryAndExit *ticket){
    freeDateAndHour(getEntry(ticket));
    free(getExit(ticket));
    free(ticket);
}
