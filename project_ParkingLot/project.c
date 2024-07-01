/**
 * @file project.c
 * @brief This file contains the main function and the command execution
 * function for the project.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Include necessary libraries and header files.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "project.h"

// Declare a pointer to the global dateAndHour structure.
static dateAndHour *globalTime;

/**
 * @brief The main function of the program.
 * This function initializes the global time, all parks, and all cars.
 * It then enters a loop to read and execute commands until the 'q' command is
 * received. Finally, it frees all allocated memory before exiting.
 */
int main(){
    char *command;
    list *allParks;
    hashTable *allCars;

    globalTime = createDateAndHour("00-00-0000", "00:00");
    allParks = createList();
    allCars = createHashTable();

    command = (char*) malloc(sizeof(char)*BUFSIZ);
    while ( *(fgets(command, BUFSIZ, stdin)) != 'q')
        doCommand(command, allParks, allCars);

    free(command);
    freeList(allParks);
    freeHashTable(allCars);
    freeDateAndHour(globalTime);
    return 0;
}

void doCommand(char *command, list *allParks, hashTable *allCars){
    switch(*command){
        case 'p':
            readCommandP(command, allParks);
            break;
        case 'e':
            readCommandE(command, allParks, allCars);
            break;
        case 's':
            readCommandS(command, allParks, allCars);
            break;
        case 'v':
            readCommandV(command, allCars);
            break;
        case 'f':
            readCommandF(command, allParks);
            break;
        case 'r':
            readCommandR(command, allParks);
            break;
        case 't':
            readCommandT(command, allParks);
            break;
    }
}

void readCommandP(char *command,  list *allParks){
    if (*(command + 2) == '\0') printExistentParks(allParks); //"p\n\0" by fgets
    else processCommandP(command, allParks);
}

void printExistentParks(list *allParks){
    info *tempPark = getFirstItem(allParks);

    while(tempPark != NULL){
        parkingLot *park = getParkInfo(tempPark);

        printf("%s %d %d\n", getParkName(park), getParkCapacity(park),
        getParkFreeSpaces(park));

        tempPark = getNextItem(tempPark);
    }

}

void processCommandP(char *command, list *allParks){
    char tempName[BUFSIZ];
    double initialFee, laterFee, maxFee;
    short capacity;
    parkingLot *park;

    if (*(command + 2) != '\"')
        sscanf(command, "p %s %hd %lf %lf %lf", tempName, &capacity,
            &initialFee, &laterFee, &maxFee);
    else
        sscanf(command, "p \"%[^\"]\" %hd %lf %lf %lf", tempName, &capacity,
            &initialFee, &laterFee, &maxFee);

    if (pArgumentsAreValid(allParks, tempName, capacity,
        initialFee, laterFee, maxFee)){

        park = createPark(tempName, capacity, initialFee, laterFee, maxFee);
        addItem(allParks, createInfo(park, ISPARKINGLOT));
    }
}

void readCommandE(char *command, list *allParks, hashTable *allCars){
    char tempParkName[BUFSIZ], tempCarPlate[CARPLATE],tempDate[20],tempHour[20];
    dateAndHour *logTime;

    if (*(command + 2) != '\"')
        sscanf(command, "e %s %s %s %s", tempParkName, tempCarPlate,
            tempDate, tempHour);
    else
        sscanf(command, "e \"%[^\"]\" %s %s %s", tempParkName, tempCarPlate,
            tempDate, tempHour);

    logTime = createDateAndHour(tempDate, tempHour);
    if (eArgumentsAreValid(allParks, allCars, tempParkName,
        tempCarPlate, logTime)){

        putCarInsidePark(allParks, allCars, logTime, tempParkName,tempCarPlate);
    }
    else freeDateAndHour(logTime);
}

int eArgumentsAreValid(list *allParks, hashTable *allCars, char *tempName,
    char *tempCarPlate, dateAndHour *timeLog){

    parkingLot *park = getParkInfo(searchForItem(allParks, tempName));
    vehicle *car = getCarInfo(searchInHashTable(allCars, tempCarPlate));

    if (park == NULL)
        printf("%s: no such parking.\n", tempName);

    else if(getParkFreeSpaces(park) == 0)
        printf("%s: parking is full.\n", tempName);

    else if (!isValidCarPlate(tempCarPlate))
        printf("%s: invalid licence plate.\n", tempCarPlate);

    else if (car != NULL && isCarParked(car))
        printf("%s: invalid vehicle entry.\n", tempCarPlate);

    else if (!isValidDateAndHour(timeLog) || !isNewerThen( timeLog, globalTime))
        printf("invalid date.\n");

    else return TRUE;

    return FALSE;
}

void putCarInsidePark(list *allParks, hashTable *allCars, dateAndHour *logTime,
char *tempParkName, char *tempCarPlate){

    parkingLot *park = getParkInfo(searchForItem(allParks, tempParkName));
    vehicle *car = getCarInfo(searchInHashTable(allCars, tempCarPlate));

    if (car == NULL){
        car = createCar(tempCarPlate, logTime, getParkName(park));
        addInHashTable(allCars, createInfo(car, ISVEHICLE));
    }
    else{
        putNewEntryInCar(car, logTime, getParkName(park));
        changeCarParkedParkName(car, getParkName(park));
    }

    addItem(getParkCarsIn(park), createInfo(car, ISVEHICLE));
    copyDateAndHour(globalTime, logTime);

    printf("%s %d\n", getParkName(park), getParkFreeSpaces(park));
}

void readCommandS(char *command, list *allParks, hashTable *allCars){
    char tempParkName[BUFSIZ], tempCarPlate[CARPLATE],tempDate[20],tempHour[20];
    dateAndHour *exitTime;

    if (*(command + 2) != '\"')
        sscanf(command, "s %s %s %s %s", tempParkName, tempCarPlate,
            tempDate, tempHour);
    else
        sscanf(command, "s \"%[^\"]\" %s %s %s", tempParkName, tempCarPlate,
            tempDate, tempHour);

    exitTime = createDateAndHour(tempDate, tempHour);
    if (sArgumentsAreValid(allParks, allCars, tempParkName,
        tempCarPlate, exitTime)){

        putCarOutsidePark(allParks,allCars,exitTime,tempParkName,tempCarPlate);
    }
    else freeDateAndHour(exitTime);
}

int sArgumentsAreValid(list *allParks, hashTable *allCars, char *tempName,
    char *tempCarPlate, dateAndHour *tempDate){

    parkingLot *park = getParkInfo(searchForItem(allParks, tempName));
    vehicle *car = getCarInfo(searchInHashTable(allCars, tempCarPlate));

    if(park == NULL)
        printf("%s: no such parking.\n", tempName);

    else if (!isValidCarPlate(tempCarPlate))
        printf("%s: invalid licence plate.\n", tempCarPlate);

    else if ( car == NULL || !isCarParked(car) ||
        strcmp(getCarParkedParkName(car), tempName) != 0)
            printf("%s: invalid vehicle exit.\n", tempCarPlate);

    else if (!isValidDateAndHour(tempDate) || !isNewerThen(tempDate,globalTime))
        printf("invalid date.\n");

    else return TRUE;

    return FALSE;
}

void putCarOutsidePark(list *allParks, hashTable *allCars,
    dateAndHour *exitTime, char *tempParkName, char *tempCarPlate){

    parkingLot *park = getParkInfo(searchForItem(allParks, tempParkName));
    vehicle *car = getCarInfo(searchInHashTable(allCars, tempCarPlate));
    float totalPayed;

    totalPayed = calculateFee(park, minutesParked(car, exitTime));

    moveToParkHistory(park, car, exitTime, totalPayed);
    putNewExitInCar(car, exitTime, totalPayed);

    copyDateAndHour(globalTime, exitTime);

    printExitFromPark(car, exitTime, totalPayed);
    changeCarParkedParkName(car, NULL);
}

void printExitFromPark(vehicle *car, dateAndHour *exitTime, double totalPayed){
    printf("%s ", getCarRegistration(car));
    printDateAndHour(getCarLastEntryTime(car));
    printf(" ");
    printDateAndHour(exitTime);
    printf(" %.2lf\n", totalPayed);
}

void readCommandV(char *command, hashTable *allCars){
    char tempCarPlate[CARPLATE];
    vehicle *car;
    sscanf(command, "v %s", tempCarPlate);
    car = getCarInfo(searchInHashTable(allCars, tempCarPlate));

    if (vArgumentsAreValid(car, tempCarPlate)){
        info *carHist = getFirstItem(getCarPastParked(car));

        printCarEntriesAndExits(carHist);
    }
}

int vArgumentsAreValid(vehicle *car, char *tempCarPlate){
    if (!isValidCarPlate(tempCarPlate))
        printf("%s: invalid licence plate.\n", tempCarPlate);

    else if(car == NULL || getListSize(getCarPastParked(car)) == 0)
        printf("%s: no entries found in any parking.\n", tempCarPlate);

    else return TRUE;

    return FALSE;
}

void printCarEntriesAndExits(info *carHist){
    while(carHist != NULL){ // for each parking the car was in
        info *ticket = getFirstItem(getCarInOutLog(getCarHistoryInfo(carHist)));

        while (ticket != NULL){ // for each entry and exit
            printf("%s ", getCarHistoryName(getCarHistoryInfo(carHist)));
            printDateAndHour( getEntry(getEntryAndExitInfo(ticket)));

            if (getExit(getEntryAndExitInfo(ticket)) != NULL){
                printf(" ");
                printDateAndHour( getExit(getEntryAndExitInfo(ticket)));
            }

            printf("\n");
            ticket = getNextItem(ticket);
        }
        carHist = getNextItem(carHist);
    }
}

void readCommandF(char *command, list *allParks){
    char tempParkName[BUFSIZ], dateLog[20];
    int numArgs;

    if (*(command + 2) != '\"')
        numArgs = sscanf(command, "f %s %s", tempParkName, dateLog);
    else
        numArgs = sscanf(command, "f \"%[^\"]\" %s", tempParkName, dateLog);

    if (numArgs == 1)
        printParkIncome(allParks, tempParkName);
    else
        parkIncomeFromCars(allParks, tempParkName, dateLog);
}

int fArgumentsAreValid(parkingLot *park, date *logDate, char *tempParkName){
    if (park == NULL){
        printf("%s: no such parking.\n", tempParkName);
        freeDate(logDate);
    }
    else if (!isValidDate(logDate) ||
        !(dateIsNewerThen(getDate(globalTime), logDate) ||
            isSameDate(logDate, getDate(globalTime)))){

        printf("invalid date.\n");
        freeDate(logDate);
    }
    else return TRUE;

    return FALSE;
}

void printParkIncome(list *allParks, char *tempParkName){
    parkingLot *park = getParkInfo(searchForItem(allParks, tempParkName));
    info *parkedCarsDay;

    if (park == NULL){
        printf("%s: no such parking.\n", tempParkName);
        return;
    }
    parkedCarsDay = getFirstItem(getParkHistory(park));
    while(parkedCarsDay != NULL){ // for each day in the park history
        printDate(getParkedCarsDate(getParkedCarsInfo(parkedCarsDay)));
        printf(" %.2lf\n", getParkedCarsEarnedFee(
            getParkedCarsInfo(parkedCarsDay)));

        parkedCarsDay = getNextItem(parkedCarsDay);
    }
}

void parkIncomeFromCars(list *allParks, char *tempParkName, char *dateLog){
    parkingLot *park = getParkInfo(searchForItem(allParks, tempParkName));
    date *dateToSearch = createDate(dateLog);
    parkedCars *parkHistory;
    info *exitCarInfo;
    exitVehicle *exitCar;

    if (fArgumentsAreValid(park, dateToSearch, tempParkName)){
        parkHistory = searchForParkedCars(getParkHistory(park), dateToSearch);
        freeDate(dateToSearch);

        if (parkHistory == NULL) // no cars parked in that day
            return;

        exitCarInfo = getFirstItem(getParkedCarsList(parkHistory));
        while ((exitCar = getExitVehicleInfo(exitCarInfo)) != NULL){
            printf("%s ", getCarRegistration(getExitVehicleCar(exitCar)));
            printHours(getExitVehicleExitTime(exitCar));
            printf(" %.2lf\n", getExitVehiclePayment(exitCar));

            exitCarInfo = getNextItem(exitCarInfo);
        }
    }
}

void readCommandR(char *command, list *allParks){
    parkingLot *park;
    list *copyOrdParks;
    info* parkInfo;
    char tempParkName[BUFSIZ];

    if (*(command + 2) != '\"')
        sscanf(command, "r %s", tempParkName);
    else
        sscanf(command, "r \"%[^\"]\"", tempParkName);

    if ((park = getParkInfo(searchForItem(allParks, tempParkName))) == NULL)
        printf("%s: no such parking.\n", tempParkName);
    else{
        free(popItem(allParks, tempParkName));
        freePark(park);

        copyOrdParks = shallowOrderCopyParks(allParks);
        parkInfo = getFirstItem(copyOrdParks);

        while (parkInfo != NULL){
            printf("%s\n", getParkName(getParkInfo(parkInfo)));
            parkInfo = getNextItem(parkInfo);
        }
        shallowFreeList(copyOrdParks);
    }
}

void readCommandT(char *command, list *allParks){
    char tempParkName[BUFSIZ];
    parkingLot *park;
    sscanf(command, "t %s", tempParkName);
    park = getParkInfo(searchForItem(allParks, tempParkName));
    if (park == NULL)
        printf("%s: no such parking.\n", tempParkName);
    else
        printParkTotalIncome(park);
}


void printParkTotalIncome(parkingLot *park){
    info *parkedCarsDay = getFirstItem(getParkHistory(park));
    double totalIncome = 0;

    while(parkedCarsDay != NULL){
        totalIncome += getParkedCarsEarnedFee(getParkedCarsInfo(parkedCarsDay));
        parkedCarsDay = getNextItem(parkedCarsDay);
    }
    printf("%.2lf\n", totalIncome);
}
