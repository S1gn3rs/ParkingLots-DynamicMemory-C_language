/**
 * @file info.h
 * @brief This header file contains the declarations of the info structure
 * and related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Check if the header file has already been included
#ifndef INFO_H
#define INFO_H

// Include header file
#include "project.h"

// Forward declaration of structures
typedef struct parkingLot parkingLot;
typedef struct vehicle vehicle;
typedef struct parkedCars parkedCars;
typedef struct carHistory carHistory;
typedef struct entryAndExit entryAndExit;
typedef struct exitVehicle exitVehicle;

// Define constants to identify item types
#define ISPARKINGLOT 0
#define ISVEHICLE 1
#define ISPARKEDCARS 2
#define ISCARHISTORY 3
#define ISENTRYANDEXIT 4
#define ISEXITVEHICLE 5

/**
 * @struct info
 * @brief A structure to represent a generic item in a list. This structure
 * represents a generic item in a list with its type, details, and pointers to
 * the next and previous items.
 */
typedef struct info{
    unsigned char type; /**< The type of the item. */
    void *details; /**< A pointer to the details of the item. */
    struct info *nextItem; /**< A pointer to the next item. */
    struct info *previousItem; /**< A pointer to the previous item.*/
}info;

/**
 * @brief Creates a new info structure.
 * This function allocates memory for a new info structure and initializes it
 * with the given parameters. It sets the type of the info and assigns the
 * details pointer to the appropriate type based on the given type.
 * It also initializes the nextItem and previousItem pointers to NULL.
 * @param item A pointer to the item to be stored in the info structure.
 * @param type The type of the item.
 * @return info*: A pointer to the created info structure.
 */
info *createInfo(void *item, unsigned char type);

/**
 * @brief Retrieves the type of the info item.
 * @param item A pointer to the info item.
 * @return unsigned char: The type of the info item.
 */
unsigned char getInfoType(info *item);

/**
 * @brief Retrieves the parking lot information from an info item.
 * @param item A pointer to the info item.
 * @return parkingLot*: A pointer to the parking lot information if it exists,
 * NULL otherwise.
 */
parkingLot* getParkInfo(info *item);

/**
 * @brief Retrieves the vehicle information from an info item.
 * @param item A pointer to the info item.
 * @return vehicle*: A pointer to the vehicle information if it exists,
 * NULL otherwise.
 */
vehicle* getCarInfo(info *item);

/**
 * @brief Retrieves the parked cars information from an info item.
 * @param item A pointer to the info item.
 * @return parkedCars*: A pointer to the parked cars information if it exists,
 * NULL otherwise.
 */
parkedCars* getParkedCarsInfo(info *item);

/**
 * @brief Retrieves the car history information from an info item.
 * @param item A pointer to the info item.
 * @return carHistory*: A pointer to the car history information if it exists,
 * NULL otherwise.
 */
carHistory* getCarHistoryInfo(info *item);

/**
 * @brief Retrieves the entry and exit information from an info item.
 * @param item A pointer to the info item.
 * @return entryAndExit*: A pointer to the entry and exit information if it
 * exists, NULL otherwise.
 */
entryAndExit* getEntryAndExitInfo(info *item);

/**
 * @brief Retrieves the exit vehicle information from an info item.
 * @param item A pointer to the info item.
 * @return exitVehicle*: A pointer to the exit vehicle information if it exists,
 * NULL otherwise.
 */
exitVehicle* getExitVehicleInfo(info *item);

/**
 * @brief Retrieves the next item from an info item.
 * @param item A pointer to the info item.
 * @return info*: A pointer to the next info item if it exists, NULL otherwise.
 */
info *getNextItem(info *item);

/**
 * @brief Retrieves the previous item from an info item.
 * @param item A pointer to the info item.
 * @return info*: A pointer to the previous info item if it exists,
 * NULL otherwise.
 */
info *getPreviousItem(info *item);

/**
 * @brief Retrieves the identifier of an info item based on its type.
 * This function checks the type of the info item and returns the corresponding
 * identifier. If the info item is a vehicle, it returns the car registration.
 * If the info item is a parking lot, it returns the park name.
 * Otherwise, it returns the car history name (park name).
 * @param item A pointer to the info item.
 * @return char*: The identifier of the info item if it exists, NULL otherwise.
 */
char *getInfoIdentifier(info *item);

/**
 * @brief Changes the 'next' pointer of an info item to a new item.
 * @param item The current info item.
 * @param newNextItem The new item that should follow the current item.
 */
void changeNextItem(info *item, info *newNextItem);

/**
 * @brief Changes the 'previous' pointer of an info item to a new item.
 * @param item The current info item.
 * @param newPreviousItem The new item that should precede the current item.
 */
void changePreviousItem(info *item, info *newPreviousItem);

/**
 * @brief Frees the memory for the details of an info item based on its type.
 * The function identifies the type of the info item (vehicle, parking lot,
 * car history, parked cars list) and frees the memory allocated for the
 * corresponding details. Then calls the specific free function.
 * @param itemInfo The info item whose details are to be freed.
 */
void freeInfo(info*);

#endif
