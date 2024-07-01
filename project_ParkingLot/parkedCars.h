/**
 * @file parkedCars.h
 * @brief This header file contains the declarations of the parkedCars
 * structure and related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Check if the header file has already been included
#ifndef PARKEDCARS_H
#define PARKEDCARS_H

// Include header file
#include "project.h"

// Forward declaration of structures
typedef struct list list;
typedef struct date date;
typedef struct entryAndExit entryAndExit;

/**
 * @struct parkedCars
 * @brief A structure to represent a record of cars parked on a specific date.
 * This structure represents a record of cars parked on a specific date with
 * the total fee earned.
 */
typedef struct parkedCars{
    struct date *parkingDate; /**< The date of parking. */
    double earnedFee; /**< The total fee earned from the parked cars. */
    struct list *parkedCars; /**< A list of the cars parked on this date. */
} parkedCars;

/**
 * @brief Creates a new parkedCars structure.
 * This function allocates memory for a new parkedCars structure and initializes
 * it with the given parameters. It also creates a list for the cars currently
 * parked and sets the earned fee to 0.
 * @param logDate The date of parking.
 * @return parkedCars*: A pointer to the created parkedCars structure.
 */
parkedCars *createParkedCars(date *logDate);

/**
 * @brief Gets the parking date from a parkedCars structure.
 * @param parkedCars A pointer to the parkedCars structure.
 * @return date*: The parking date.
 */
date *getParkedCarsDate(parkedCars *parkedCars);

/**
 * @brief Gets the earned fee from a parkedCars structure.
 * @param parkedCars A pointer to the parkedCars structure.
 * @return double: The earned fee.
 */
double getParkedCarsEarnedFee(parkedCars *parkedCars);

/**
 * @brief Gets the list of parked cars from a parkedCars structure.
 * @param parkedCars A pointer to the parkedCars structure.
 * @return list*: A pointer to the list of parked cars.
 */
list *getParkedCarsList(parkedCars *parkedCars);

/**
 * @brief Adds a fee to the total earned fee of a parkedCars structure.
 * @param parkedCars A pointer to the parkedCars structure.
 * @param fee The fee to be added.
 */
void addToEarnedFee(parkedCars *parkedCars, double fee);

/**
 * @brief Searches for a parkedCars structure in a list by a given date.
 * Iterates over the list of parkedCars structures to find a match
 * with the given date.
 * @param listPrkdCars A pointer to the list of parkedCars structures.
 * @param logDate The date to search for.
 * @return parkedCars*: A pointer to the matching parkedCars structure,
 * or NULL if not found.
 */
parkedCars *searchForParkedCars(list *listPrkdCars, date *logDate);

/**
 * @brief Frees the memory allocated for a parkedCars structure.
 * @param parkedCars A pointer to the parkedCars structure to be freed.
 */
void freeParkedCars(parkedCars *parkedCars);

#endif
