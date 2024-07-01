/**
 * @file project.h
 * @brief This header file contains the declarations of the functions and data
 * structures used in the project.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Check if the header file has already been included
#ifndef PROJECT_h
#define PROJECT_h

// Include header files
#include "dateAndHour.h"
#include "info.h"
#include "parkedCars.h"
#include "parkingLot.h"
#include "list.h"
#include "carHistoryAndEntryExit.h"
#include "vehicleAndExitVehicle.h"
#include "hashingTable.h"

#define MAXPARKS 20 /**< Maximum number of parks allowed */
#define TRUE 1      /**< Represents a boolean true value */
#define FALSE 0     /**< Represents a boolean false value */

// Forward declaration of structures
typedef struct info info;
typedef struct hashTable hashTable;

/**
 * @brief Executes a command.
 * This function takes a command and executes it based on its first character.
 * @param command The command to be executed.
 * @param allParks A pointer to the list of all parks.
 * @param allCars A pointer to the hash table of all cars.
 */
void doCommand(char *command, list *allParks, hashTable *allCars);

/**
 * @brief Processes the 'p' command.
 * This function checks if the command is 'p', if is just 'p' it prints all
 * existing parks. Otherwise, it processes the command.
 * @param command The command to be processed.
 * @param allParks A pointer to the list of all parks.
 */
void readCommandP(char *command,  list *allParks);

/**
 * @brief Prints all existing parks.
 * This function prints by order of creation all existing parks.
 * It prints the park's name, capacity, and number of free spaces.
 * @param allParks A pointer to the list of all parks.
 */
void printExistentParks(list *allParks);

/**
 * @brief Processes the 'p' command.
 * This function reads the parameters of the 'p' command, checks if the
 * parameters are valid. If they are, it creates a new park and adds it to the
 * list of all parks.
 * @param command The command to be processed.
 * @param allParks A pointer to the list of all parks.
 */
void processCommandP(char *command, list *allParks);

/**
 * @brief Processes the 'e' command.
 * This function reads the parameters of the 'e' command, checks if the
 * parameters are valid. If they are, it puts the car inside the specified park.
 * @param command The command to be processed.
 * @param allParks A pointer to the list of all parks.
 * @param allCars A pointer to the hash table of all cars.
 */
void readCommandE(char *command, list *allParks, hashTable* allCars);

/**
 * @brief Validates the arguments of the 'e' command.
 * This function checks if the park exists, if the park has free spaces,
 * if the car plate is valid, if the car is already parked, and if the date and
 * time are valid and later than the global time. If all checks pass, it returns
 * TRUE. Otherwise, it prints an error message and returns FALSE.
 * @param allParks A pointer to the list of all parks.
 * @param allCars A pointer to the hash table of all cars.
 * @param tempName The name of the park.
 * @param tempCarPlate The license plate of the car.
 * @param timeLog The date and time of the log.
 * @return int: TRUE if all arguments are valid, FALSE otherwise.
 */
int eArgumentsAreValid(list *allParks, hashTable *allCars, char *tempName,
    char *tempCarPlate, dateAndHour *timeLog);

/**
 * @brief Puts a car inside a park.
 * This function gets the park and car information from the list of all parks
 * and the hash table of all cars. If the car does not exist, it creates a car.
 * It then updates the car's status and the park's number of free spaces.
 * @param allParks A pointer to the list of all parks.
 * @param allCars A pointer to the hash table of all cars.
 * @param logTime The date and time of the log.
 * @param tempParkName The name of the park.
 * @param tempCarPlate The license plate of the car.
 */
void putCarInsidePark(list *allParks, hashTable *allCars, dateAndHour *logTime,
    char *tempParkName, char *tempCarPlate);

/**
 * @brief Processes the 's' command.
 * This function reads the parameters of the 's' command checks if the
 * parameters are valid. If they are, puts the car outside the specified park.
 * @param command The command to be processed.
 * @param allParks A pointer to the list of all parks.
 * @param allCars A pointer to the hash table of all cars.
 */
void readCommandS(char *command, list *allParks, hashTable *allCars);

/**
 * @brief Validates the arguments of the 's' command.
 * This function checks if the park exists, if the car plate is valid,
 * if the car is parked, and if the date and time are valid and later than the
 * global time. If all checks pass, it returns TRUE. Otherwise,
 * it prints an error message and returns FALSE.
 * @param allParks A pointer to the list of all parks.
 * @param allCars A pointer to the hash table of all cars.
 * @param tempName The name of the park.
 * @param tempCarPlate The license plate of the car.
 * @param tempDate The date and time of the log.
 * @return int: TRUE if all arguments are valid, FALSE otherwise.
 */
int sArgumentsAreValid(list *allParks, hashTable *allCars, char *tempName,
    char *tempCarPlate, dateAndHour *tempDate);

/**
 * @brief Puts a car outside a park.
 * This function gets the park and car information from the list of all parks
 * and the hash table of all cars. It then calculates the fee, moves the car to
 * the park's history, updates the car's status and prints the exit information.
 * @param allParks A pointer to the list of all parks.
 * @param allCars A pointer to the hash table of all cars.
 * @param exitTime The date and time of the exit.
 * @param tempParkName The name of the park.
 * @param tempCarPlate The license plate of the car.
 */
void putCarOutsidePark(list *allParks, hashTable *allCars,
    dateAndHour *exitTime, char *tempParkName, char *tempCarPlate);

/**
 * @brief Prints the exit information of a car from a park.
 * This function prints the car's license plate, the entry time, the exit time,
 * and the total fee paid.
 * @param car A pointer to the car.
 * @param exitTime The date and time of the exit.
 * @param totalPayed The total fee paid by the car.
 */
void printExitFromPark(vehicle *car, dateAndHour *exitTime, double totalPayed);

/**
 * @brief Processes the 'v' command.
 * This function reads the parameters of the 'v' command checks if the
 * parameters are valid. If they are, it gets the car's history.
 * @param command The command to be processed.
 * @param allCars A pointer to the hash table of all cars.
 */
void readCommandV(char *command, hashTable *allCars);

/**
 * @brief Validates the arguments of the 'v' command.
 * This function checks if the car plate is valid and if the car has a history
 * of entries and exits. If all checks pass, it returns TRUE.
 * Otherwise, it prints an error message and returns FALSE.
 * @param car A pointer to the car.
 * @param tempCarPlate The license plate of the car.
 * @return int: TRUE if all arguments are valid, FALSE otherwise.
 */
int vArgumentsAreValid(vehicle *car, char *tempCarPlate);

/**
 * @brief Prints the entries and exits of a car.
 * This function iterates through the car's history and prints each entry
 * and exit. It prints the park's name, the entry time, and the exit time.
 * @param carHist A pointer to the car's history.
 */
void printCarEntriesAndExits(info *carHist);

/**
 * @brief Processes the 'f' command.
 * This function reads the parameters of the 'f' command checks if the
 * parameters are valid. If they are, it prints the park's financial report.
 * @param command The command to be processed.
 * @param allParks A pointer to the list of all parks.
 */
void readCommandF(char *command, list *allParks);

/**
 * @brief Validates the arguments of the 'f' command.
 * This function checks if the park exists and if the date is valid and not
 * later than the global time. If all checks pass, it returns TRUE.
 * Otherwise, it prints an error message and returns FALSE.
 * @param park A pointer to the park.
 * @param logDate The date of the log.
 * @param tempParkName The name of the park.
 * @return int: TRUE if all arguments are valid, FALSE otherwise.
 */
int fArgumentsAreValid(parkingLot *park, date *logDate, char *tempParkName);

/**
 * @brief Prints the income of a parking lot for each day.
 * This function retrieves the parking lot with the given name from the list of
 * all parking lots. If the parking lot exists, it iterates over
 * its history and for each day, it prints the date and the earned fee.
 * @param allParks A pointer to the list of all parking lots.
 * @param tempParkName The name of the parking lot.
 */
void printParkIncome(list *allParks, char *tempParkName);

/**
 * @brief Prints the income from cars parked in a park on a specific date.
 * This function gets the park information from the list of all parks and the
 * date. It then checks if the arguments are valid. If they are,
 * it gets the park's history for the specified date and prints
 * the car's license plate, exit time, and fee paid.
 * @param allParks A pointer to the list of all parks.
 * @param tempParkName The name of the park.
 * @param dateLog The date of the log.
 */
void parkIncomeFromCars(list *allParks, char *tempParkName, char *dateLog);

/**
 * @brief Processes the 'r' command.
 * This function reads the park name from the 'r' command. It then retrieves the
 * park information from the list of all parks. If the park does not exist, it
 * prints an error message. If the park exists, it removes the park from the
 * list of all parks, frees the park's memory, and prints the names of the
 * remaining parks in alphabetical order.
 * @param command The command to be processed.
 * @param allParks A pointer to the list of all parks.
 */
void readCommandR(char *command, list *allParks);

/**
 * @brief Calculates and prints the total income of a park.
 * This function iterates over the history of parked cars in the park,
 * summing up the income from each day. It then prints the total income to the
 * standard output.
 * @param park A pointer to the park structure.
 */
void printParkTotalIncome(parkingLot *park);

/**
 * @brief Processes the 't' command.
 * This function reads the park name from the 't' command. It then retrieves the
 * park information from the list of all parks. If the park does not exist, it
 * prints an error message. If the park exists, it calculates and prints the
 * total income of the park.
 * @param command The command to be processed.
 * @param allParks A pointer to the list of all parks.
 */
void readCommandT(char *command, list *allParks);


#endif
