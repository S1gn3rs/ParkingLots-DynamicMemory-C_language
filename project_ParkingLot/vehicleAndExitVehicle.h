/**
 * @file vehicleAndExitVehicle.h
 * @brief This header file contains the declarations of the vehicle and
 * exitVehicle structures.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Check if the header file has already been included
#ifndef VEHICLE_AND_EXITVEHICLE_H
#define VEHICLE_AND_EXITVEHICLE_H

// Include header file
#include "project.h"

#define CARPLATE 9 /**< Carplate length -> XX-XX-XX\0 */

/**
 * @struct vehicle
 * @brief A structure to represent a vehicle. This structure represents a
 * vehicle with its registration, the park it is currently in, and its
 * parking history.
 */
typedef struct vehicle{
    char registration[CARPLATE]; /**< The vehicle's registration. */
    char* insidePark; /**< The name of the park the vehicle is currently in. */
    struct list *pastParked; /**< A list of the vehicle's parking history. */
}vehicle;

/**
 * @struct exitVehicle
 * @brief A structure to represent a vehicle that has exited a park.
 * This structure represents a vehicle that has exited a park, with its vehicle
 * information, exit time, and payment.
 */
typedef struct exitVehicle{
    vehicle *car; /**< A pointer to the vehicle information. */
    hours *exitHours; /**< The time the vehicle exited the park. */
    double payment; /**< The payment made by the vehicle. */
} exitVehicle;

/**
 * @brief Creates a new vehicle structure.
 * This function allocates memory for a new vehicle structure and initializes it
 * with the given parameters. It also creates a list for the vehicle's parking
 * history and adds an entry for the current parking.
 * @param identifier The vehicle's registration identifier.
 * @param entryTime The date and hour of vehicle entry.
 * @param parkName The name of the parking lot.
 * @return vehicle*: A pointer to the created vehicle structure.
 */
vehicle *createCar(char *identifier, dateAndHour *entryTime, char *parkName);

/**
 * @brief Creates a new exitVehicle structure.
 * This function allocates memory for a new exitVehicle structure and
 * initializes it with the given parameters. The exitVehicle structure
 * represents a vehicle that has exited the parking lot.
 * @param car A pointer to the vehicle structure.
 * @param logHours The time of vehicle exit.
 * @param fee The fee for parking.
 * @return exitVehicle*: A pointer to the created exitVehicle structure.
 */
exitVehicle *createExitVehicle(vehicle *car, hours *logHours, double fee);

/**
 * @brief Retrieves the registration of a vehicle.
 * @param car A pointer to the vehicle structure.
 * @return char*: The registration of the vehicle.
 */
char* getCarRegistration(vehicle *car);

/**
 * @brief Retrieves the name of the parking lot where the vehicle is parked.
 * @param car A pointer to the vehicle structure.
 * @return char*: The name of the parking lot.
 */
char* getCarParkedParkName(vehicle *car);

/**
 * @brief Retrieves the past parking history of a vehicle.
 * @param car A pointer to the vehicle structure.
 * @return list*: A pointer to the list of past parking records.
 */
list* getCarPastParked(vehicle *car);

/**
 * @brief Retrieves the vehicle associated with an exit record.
 * @param exit A pointer to the exitVehicle structure.
 * @return vehicle*: A pointer to the vehicle structure.
 */
vehicle *getExitVehicleCar(exitVehicle *exit);

/**
 * @brief Retrieves the exit time from an exit record.
 * @param exit A pointer to the exitVehicle structure.
 * @return hours*: The exit time of the vehicle.
 */
hours* getExitVehicleExitTime(exitVehicle *exit);

/**
 * @brief Retrieves the payment from an exit record.
 * @param exit A pointer to the exitVehicle structure.
 * @return double: The payment made by the vehicle.
 */
double getExitVehiclePayment(exitVehicle *exit);

/**
 * @brief Retrieves the last entry time of a vehicle.
 * @param car A pointer to the vehicle structure.
 * @return dateAndHour*: The last entry time of the vehicle.
 */
dateAndHour* getCarLastEntryTime(vehicle *car);

/**
 * @brief Changes the name of the parking lot where the vehicle is parked.
 * @param car A pointer to the vehicle structure.
 * @param parkName The new name of the parking lot.
 */
void changeCarParkedParkName(vehicle *car, char *parkName);

/**
 * @brief Adds a new entry record to a vehicle's history.
 * This function searches for the car's history in the specified parking lot.
 * If it doesn't exist, it creates a new carHistory and adds it to the car's
 * history. Then, it adds a new entry record to the carHistory.
 * @param car A pointer to the vehicle structure.
 * @param time The date and hour of vehicle entry.
 * @param parkName The name of the parking lot.
 */
void putNewEntryInCar(vehicle *car, dateAndHour *time, char *parkName);

/**
 * @brief Adds a new exit record to a vehicle's history.
 * This function searches for the car's history in the parking lot where
 * it is currently parked and adds a new exit record to it.
 * @param car A pointer to the vehicle structure.
 * @param time The date and hour of vehicle exit.
 * @param fee The fee for parking.
 */
void putNewExitInCar(vehicle *car, dateAndHour *time, double fee);

/**
 * @brief Validates a car plate.
 * This function checks if a car plate is valid. A valid car plate has the
 * format xx-xx-xx, where x can be a digit or an uppercase letter.
 * It must contain at least one digit and one letter.
 * @param carPlate The car plate to validate.
 * @return int: Returns 1 if the car plate is valid, 0 otherwise.
 */
int isValidCarPlate(char *carPlate);

/**
 * @brief Checks if a vehicle is parked.
 * @param car A pointer to the vehicle structure.
 * @return int: Returns 1 if the vehicle is parked, 0 otherwise.
 */
int isCarParked(vehicle *car);

/**
 * @brief Calculates the number of minutes a vehicle has been parked.
 * This function calculates the difference in minutes between the vehicle's
 * last entry time and the specified exit time.
 * @param car A pointer to the vehicle structure.
 * @param exitTime The date and hour of vehicle exit.
 * @return int: The number of minutes the vehicle has been parked.
 */
int minutesParked(vehicle *car, dateAndHour *exitTime);

/**
 * @brief Frees the memory allocated for a vehicle structure.
 * This function frees the memory allocated for the vehicle's parking history
 * and the vehicle structure itself.
 * @param car A pointer to the vehicle structure.
 */
void freeCar(vehicle *car);

/**
 * @brief Frees the memory allocated for an exitVehicle structure.
 * This function frees the memory allocated for the exit time and the
 * exitVehicle structure itself.
 * @param exit A pointer to the exitVehicle structure.
 */
void freeExitVehicle(exitVehicle *exit);

#endif
