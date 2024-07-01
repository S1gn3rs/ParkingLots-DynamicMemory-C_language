/**
 * @file list.c
 * @brief This file contains the implementation of a linked list.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Include necessaries library and header file
#include <stdlib.h>
#include <string.h>
#include "list.h"

list* createList(){
    list *listItems = (list*) malloc(sizeof(list));
    listItems->size = 0;
    listItems->firstItem = NULL;
    listItems->lastItem = NULL;
    return listItems;
}

info* getFirstItem(list* listItems){
    return listItems->firstItem;
}

info* getLastItem(list* listItems){
    return listItems->lastItem;
}

int getListSize(list* listItems){
    return listItems->size;
}

void changeFirstItem(list* listItems, info* newFirst){
    listItems->firstItem = newFirst;
}

void changeLastItem(list* listItems, info* newLast){
    listItems->lastItem = newLast;
}

void incOrDecrementListSize(list* listItems, int incOrDecr){
    listItems->size += incOrDecr;
}

int identityExists(list* listItems, char* identifier){
    return searchForItem(listItems, identifier) != NULL;
}

void addItem(list* listItems, info *item){

    if (getFirstItem(listItems) == NULL)
        changeFirstItem( listItems, item);

    else{
        changeNextItem( getLastItem(listItems), item);
        changePreviousItem(item, getLastItem(listItems));
    }
    changeLastItem(listItems, item);
    incOrDecrementListSize(listItems, 1);
}

void addItemInOrder(list* listItems, info *item){
    info *currentItem = getLastItem(listItems);

    if (getInfoType(item) == ISCARHISTORY || getInfoType(item) == ISPARKINGLOT){
        while(currentItem != NULL && strcmp(getInfoIdentifier(item),
            getInfoIdentifier(currentItem)) < 0){

            currentItem = getPreviousItem(currentItem);
        }

    }
    else if (getInfoType(item) == ISPARKEDCARS){
        date *dateToSearch = getParkedCarsDate(getParkedCarsInfo(item));
        while( currentItem != NULL &&
            dateIsNewerThen( getParkedCarsDate( getParkedCarsInfo(currentItem)),
                dateToSearch))

            currentItem = getPreviousItem(currentItem);
    }
    insertItemInList(listItems, currentItem, item);
}

void insertItemInList(list *listItems, info *currentItem, info *itemToInsert){

    if (getListSize(listItems) == 0){
        changeFirstItem(listItems, itemToInsert);
        changeLastItem(listItems, itemToInsert);
    }
    else if (currentItem == NULL){
        changeNextItem(itemToInsert, getFirstItem(listItems));
        changePreviousItem(getFirstItem(listItems), itemToInsert);
        changeFirstItem(listItems, itemToInsert);
    }
    else if (currentItem == getLastItem(listItems)){
        changePreviousItem(itemToInsert, currentItem);
        changeNextItem(currentItem, itemToInsert);
        changeLastItem(listItems, itemToInsert);
    }
    else{
        changeNextItem(itemToInsert, getNextItem(currentItem));
        changePreviousItem(getNextItem(currentItem), itemToInsert);
        changePreviousItem(itemToInsert, currentItem);
        changeNextItem(currentItem, itemToInsert);
    }
    incOrDecrementListSize(listItems, 1);
}

info *searchForItem(list *listItems, char *identifier){
    info *tempItem = getFirstItem(listItems);

    while(tempItem != NULL && strcmp(getInfoIdentifier(tempItem), identifier))
        tempItem = getNextItem(tempItem);

    return tempItem;
}

info* popItem(list* listItems, char* identifier){
    info *itemToPop = searchForItem(listItems, identifier);

    if (itemToPop == NULL) return NULL;
    if (getListSize(listItems) == 1){
        changeFirstItem(listItems, NULL);
        changeLastItem(listItems, NULL);
    }

    else if (getFirstItem(listItems) == itemToPop){
        changePreviousItem(getNextItem(itemToPop), NULL);
        changeFirstItem(listItems, getNextItem(itemToPop));
    }
    else if (getLastItem(listItems) == itemToPop){
        changeNextItem(getPreviousItem(itemToPop), NULL);
        changeLastItem(listItems, getPreviousItem(itemToPop));
    }
    else{
        changeNextItem(getPreviousItem(itemToPop), getNextItem(itemToPop));
        changePreviousItem(getNextItem(itemToPop), getPreviousItem(itemToPop));
    }
    incOrDecrementListSize(listItems, -1);
    return itemToPop;
}

void freeList(list* listItems){
    info* currentInfo;

    while ((currentInfo = getFirstItem(listItems)) != NULL){
        changeFirstItem(listItems, getNextItem(currentInfo));
        freeInfo(currentInfo);
    }
    free(listItems);
}

void freeParkedCarsEntries(list* parkHist, char* parkName){
    info *currDayHist;

    while((currDayHist = getFirstItem(parkHist)) != NULL){
        list* parkedVeh = getParkedCarsList(getParkedCarsInfo(currDayHist));

        // free entries of cars parked in the park
        freeCarEntries(parkedVeh, parkName);

        changeFirstItem(parkHist, getNextItem(currDayHist));
        freeInfo(currDayHist); // free the day of park history
    }
    free(parkHist);
}

void freeCarEntries(list* parkedVeh, char* parkName){
    info *currCarInfo;

    while ((currCarInfo = getFirstItem(parkedVeh)) != NULL){
        vehicle* currentCar = getCarInfo(currCarInfo);
        info* carHistSect; // car history section
        carHistSect = searchForItem(getCarPastParked(currentCar), parkName);

        if (carHistSect != NULL) // free the car history section
            freeInfo(popItem(getCarPastParked(currentCar), parkName));

        if (getCarParkedParkName(currentCar) != NULL &&
            strcmp(getCarParkedParkName(currentCar), parkName) == 0)
                changeCarParkedParkName(currentCar, NULL);

        changeFirstItem(parkedVeh, getNextItem(currCarInfo));

        if (getInfoType(currCarInfo) == ISEXITVEHICLE)
            freeExitVehicle(getExitVehicleInfo(currCarInfo));

        free(currCarInfo);
    }
}

void shallowFreeList(list *listItems){
    info *tempItem;

    while((tempItem = getFirstItem(listItems)) != NULL){
        changeFirstItem(listItems, getNextItem(tempItem));
        free(tempItem);
    }
    free(listItems);
}
