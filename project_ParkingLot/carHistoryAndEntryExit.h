/**
 * @file carHistoryAndEntryExit.h
 * @brief This header file contains the declarations of the carHistory and
 * entryAndExit structures and related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Check if the header file has already been included
#ifndef CARHISTORY_AND_ENTRYEXIT_H
#define CARHISTORY_AND_ENTRYEXIT_H

// Include header files
#include "dateAndHour.h"
#include "list.h"

/**
 * @struct carHistory
 * @brief A structure to represent a vehicle's parking history in a
 * specific park. This structure represents a vehicle's parking history in a
 * specific park with the total fee paid.
 */
typedef struct carHistory{
    char *parkName; /**< The name of the park. */
    list *carInOutLog; /**< A list of the vehicle's entry and exit
        times and fees for that park. */
    double payedFee; /**< The total fee paid by the vehicle for this park. */
}carHistory;

/**
 * @struct entryAndExit
 * @brief A structure to represent a vehicle's entry and exit times and the
 * fee paid for a specific parking. This structure represents a vehicle's entry
 * and exit times and the fee paid for a specific parking.
 */
typedef struct entryAndExit{
    dateAndHour *entry; /**< The entry time of the vehicle. */
    dateAndHour *exit; /**< The exit time of the vehicle. */
    double Payedfee; /**< The fee paid by the vehicle for this parking. */
}entryAndExit;

/**
 * @brief Creates a new carHistory structure.
 * This function allocates memory for a new carHistory structure and initializes
 * it with the given parameters. It also creates a list for the car's entry and
 * exit log and adds an entry for the current parking.
 * @param startTime The date and hour of vehicle entry.
 * @param parkName The name of the parking lot.
 * @return carHistory*: A pointer to the created carHistory structure.
 */
carHistory *createCarHistory(dateAndHour *startTime, char *parkName);

/**
 * @brief Creates a new entryAndExit structure.
 * This function allocates memory for a new entryAndExit structure and
 * initializes it with the given parameters. The exit time and the paid fee are
 * initially set to NULL and 0 respectively.
 * @param entry The date and hour of vehicle entry.
 * @return entryAndExit*: A pointer to the created entryAndExit structure.
 */
entryAndExit *createEntryAndExit(dateAndHour *entry);

/**
 * @brief Gets the name of the park in car history.
 * @param carHist The car history.
 * @return char*: The name of the park.
 */
char *getCarHistoryName(carHistory *carHist);

/**
 * @brief Gets the car in and out log of the car history.
 * @param carHist The car history.
 * @return list*: The car in and out log.
 */
list *getCarInOutLog(carHistory *carHist);

/**
 * @brief Gets the entry date and hour of the entry and exit log.
 * @param ticket The entry and exit log.
 * @return dateAndHour*: The entry date and hour.
 */
dateAndHour *getEntry(entryAndExit *ticket);

/**
 * @brief Gets the exit date and hour of the entry and exit log.
 * @param ticket The entry and exit log.
 * @return dateAndHour*: The exit date and hour.
 */
dateAndHour *getExit(entryAndExit *ticket);

/**
 * @brief Gets the last entry of the car history.
 * @param carHist The car history.
 * @return dateAndHour*: The last entry.
 */
dateAndHour *getCarHistoryLastEntry(carHistory *carHist);

/**
 * @brief Gets the payed fee of the entry and exit log.
 * @param ticket The entry and exit log.
 * @return double: The payed fee.
 */
double getPayedFee(entryAndExit *ticket);

/**
 * @brief Puts a new entry in the car history.
 * @param carHist The car history.
 * @param time The entry date and hour.
 */
void putNewEntryInCarHistory(carHistory *carHist, dateAndHour *time);

/**
 * @brief Updates the car history with a new exit time and fee.
 * This function updates the last entry in the car history with
 * the provided exit time and fee.
 * @param carHist The car history to update.
 * @param time The exit time.
 * @param fee The fee paid.
 */
void putNewExitInCarHistory(carHistory *carHist, dateAndHour *time, double fee);

/**
 * @brief Frees the memory allocated for the car history.
 * This function frees the memory allocated for the car history
 * and its associated in and out log.
 * @param carHist The car history to free.
 */
void freeCarHistory(carHistory *carHist);

/**
 * @brief Frees the memory allocated for the entry and exit ticket.
 * This function frees the memory allocated for the entry and exit
 * ticket and its associated dates.
 * @param ticket The entry and exit ticket to free.
 */
void freeEntryAndExit(entryAndExit *ticket);

#endif
