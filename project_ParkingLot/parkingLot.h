/**
 * @file parkingLot.h
 * @brief This header file contains the declarations of the parkingLot
 * structure and related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Check if the header file has already been included
#ifndef PARKINGLOT_H
#define PARKINGLOT_H

// Include header file
#include "project.h"

// Forward declaration of structures
typedef struct list list;
typedef struct vehicle vehicle;

/**
 * @struct parkingLot
 * @brief A structure to represent a parking lot. This structure represents a
 * parking lot with its name, capacity, fees, and lists of parked cars and
 * parking history.
 */
typedef struct parkingLot{
    char* name; /**< The name of the parking lot. */
    int capacity; /**< The capacity of the parking lot. */
    double initialFee; /**< The initial fee for parking. */
    double laterFee; /**< The fee for parking after the initial period. */
    double maxFee; /**< The maximum fee for parking. */
    struct list *parkHistory; /**< A list of the parking history. */
    struct list *carsIn; /**< A list of the cars currently in the parking lot.*/
}parkingLot;

/**
 * @brief Creates a new parkingLot structure.
 * This function allocates memory for a new parkingLot structure and initializes
 * it with the given parameters. It also creates two lists: one for the cars
 * currently in the parking lot and another for the parking history.
 * @param parkName The name of the parking lot.
 * @param capacity The capacity of the parking lot.
 * @param initialFee The initial fee for parking.
 * @param laterFee The fee for parking after the initial period.
 * @param maxFee The maximum fee for parking.
 * @return parkingLot*: A pointer to the created parkingLot structure.
 */
parkingLot *createPark(char *parkName, int capacity,
    double initialFee, double laterFee, double maxFee);

/**
 * @brief Gets the name of a parkingLot structure.
 * @param park A pointer to the parkingLot structure.
 * @return char*: The name of the parking lot.
 */
char *getParkName(parkingLot *park);

/**
 * @brief Gets the list of cars in a parkingLot structure.
 * @param park A pointer to the parkingLot structure.
 * @return list*: The list of cars in the parking lot.
 */
list *getParkCarsIn(parkingLot *park);

/**
 * @brief Gets the capacity of a parkingLot structure.
 * @param park A pointer to the parkingLot structure.
 * @return int: The capacity of the parking lot.
 */
int getParkCapacity(parkingLot *park);

/**
 * @brief Gets the initial fee of a parkingLot structure.
 * @param park A pointer to the parkingLot structure.
 * @return double: The initial fee of the parking lot.
 */
double getParkInitialFee(parkingLot *park);

/**
 * @brief Gets the later fee of a parkingLot structure.
 * @param park A pointer to the parkingLot structure.
 * @return double: The later fee of the parking lot.
 */
double getParkLaterFee(parkingLot *park);

/**
 * @brief Gets the maximum fee of a parkingLot structure.
 * @param park A pointer to the parkingLot structure.
 * @return double: The maximum fee of the parking lot.
 */
double getParkMaxFee(parkingLot *park);

/**
 * @brief Gets the parking history of a parkingLot structure.
 * @param park A pointer to the parkingLot structure.
 * @return list*: The parking history of the parking lot.
 */
list *getParkHistory(parkingLot *park);

/**
 * @brief Gets the number of free spaces in a parkingLot structure.
 * @param park A pointer to the parkingLot structure.
 * @return int: The number of free spaces in the parking lot.
 */
int getParkFreeSpaces(parkingLot *park);

/**
 * @brief Checks if the fees are valid.
 * @param initialFee The initial fee for parking.
 * @param laterFee The fee for parking after the initial period.
 * @param maxFee The maximum fee for parking.
 * @return int: TRUE if the fees are invalid, FALSE otherwise.
 */
int isInvalidFee(double initialFee, double laterFee, double maxFee);

/**
 * @brief Checks if the capacity of a parking lot is invalid.
 * @param park A pointer to the parkingLot structure.
 * @return int: TRUE if the capacity is invalid, FALSE otherwise.
 */
int isInvalidCapacity(parkingLot* park);

/**
 * @brief Checks if the arguments for a parking lot are valid.
 * @param listParks A list of all parks.
 * @param tempName The name of the parking lot.
 * @param capacity The capacity of the parking lot.
 * @param initialFee The initial fee for parking.
 * @param laterFee The fee for parking after the initial period.
 * @param maxFee The maximum fee for parking.
 * @return int: TRUE if the arguments are valid, FALSE otherwise.
 */
int pArgumentsAreValid(list *listParks, char *tempName, int capacity,
    double initialFee, double laterFee, double maxFee);

/**
 * @brief Transfers a vehicle from the parking lot to the parking history.
 * Creates an exit record for the vehicle, removes it from the lot,
 * and updates the parking history.
 * @param park A pointer to the parkingLot structure.
 * @param car A pointer to the vehicle structure.
 * @param logTime The date and hour of parking.
 * @param fee The fee for parking.
 */
void moveToParkHistory(parkingLot *park, vehicle *car,
    dateAndHour *logTime, double fee);

/**
 * @brief Calculates the fee for a parked vehicle.
 * This function calculates the fee based on the number of minutes the vehicle
 * was parked, the init fee, the later fee, and the max fee of the parking lot.
 * @param park A pointer to the parkingLot structure.
 * @param minutParked The number of minutes the vehicle was parked.
 * @return double: The calculated fee.
 */
double calculateFee(parkingLot *park, int minutParked);

/**
 * @brief Creates a shallow ordered copy of parks.
 * This function creates a new list and copies each park from the original list
 * of parks to the new list in order. The parks in the new list are shallow
 * copies of the original items.
 * @param listParks A pointer to the original list.
 * @return list*: A pointer to the new list.
 */
list* shallowOrderCopyParks(list* listParks);

/**
 * @brief Frees the memory allocated for a parkingLot structure.
 * This function frees the memory allocated for the car entries, parked cars
 * entries, the name of the parking lot, the list of cars in the parking lot,
 * and the parkingLot structure itself.
 * @param park A pointer to the parkingLot structure.
 */
void freePark(parkingLot *park);

#endif
