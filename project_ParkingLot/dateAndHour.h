/**
 * @file dateAndHour.h
 * @brief This file contains the declaration of the
 * date and hour related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Check if the header file has already been included
#ifndef DATEANDHOUR_h
#define DATEANDHOUR_h

#define MESES 12  /**< The number of months in a year. */
#define TRUE 1    /**< Boolean TRUE value. */
#define FALSE 0   /**< Boolean FALSE value. */

/**
 * @struct date
 * @brief A structure to represent a date.
 * This structure represents a date with a year, month, and day.
 */
typedef struct date{
    int year;      /**< The year of the date. */
    short month;   /**< The month of the date. */
    short day;     /**< The day of the date. */
}date;

/**
 * @struct hours
 * @brief A structure to represent an hour.
 * This structure represents hours with a hour and minutes.
 */
typedef struct hours{
    short hour;    /**< The hour of the time. */
    short minutes; /**< The minutes of the time. */
}hours;

/**
 * @struct dateAndHour
 * @brief A structure to represent a date and an hour.
 * This structure represents a date and an hour with a
 * date object and an hours object.
 */
typedef struct dateAndHour{
    date *date;    /**< The date object. */
    hours *hour;   /**< The hours object. */
}dateAndHour;

/**
 * @brief Creates a date object from a string.
 * This function allocates memory for a new date object, parses the day, month,
 * and year from the input string, and returns the new date object. The input
 * string should be in the format "day-month-year".
 * @param dateString The string to parse the date from.
 * @return date*: A pointer to the newly created date object.
 */
date *createDate(char *dateString);

/**
 * @brief Creates an hours object from a string.
 * This function allocates memory for a new hours object, parses the hour and
 * minutes from the input string, and returns the new hours object. The input
 * string should be in the format "hour:minutes".
 * @param hourString The string to parse the time from.
 * @return hours*: A pointer to the newly created hours object.
 */
hours *createHours(char *hourString);

/**
 * @brief Creates a dateAndHour object from date and hour strings.
 * This function allocates memory for a new dateAndHour object, creates a date
 * object from the date string, creates an hours object from the hour string,
 * and returns the new dateAndHour object.
 * @param dateString The string to parse the date from.
 * @param hourString The string to parse the time from.
 * @return dateAndHour*: A pointer to the newly created dateAndHour object.
 */
dateAndHour *createDateAndHour(char *dateString, char *hourString);

/**
 * @brief Gets the day from a date object.
 * @param logDate The date object.
 * @return short: The day of the date.
 */
short getDateDay(date *logDate);

/**
 * @brief Gets the month from a date object.
 * @param logDate The date object.
 * @return short: The month of the date.
 */
short getDateMonth(date *logDate);

/**
 * @brief Gets the year from a date object.
 * @param logDate The date object.
 * @return int: The year of the date.
 */
int getDateYear(date *logDate);

/**
 * @brief Gets the hour from an hours object.
 * @param logHour The hours object.
 * @return short: The hour of the time.
 */
short getHoursHour(hours *logHour);

/**
 * @brief Gets the minutes from an hours object.
 * @param logHour The hours object.
 * @return short: The minutes of the time.
 */
short getHoursMinutes(hours *logHour);

/**
 * @brief Gets the date from a dateAndHour object.
 * @param logTime The dateAndHour object.
 * @return date*: The date of the log time.
 */
date *getDate(dateAndHour *logTime);

/**
 * @brief Gets the hours from a dateAndHour object.
 * @param logTime The dateAndHour object.
 * @return hours*: The hours of the log time.
 */
hours *getHours(dateAndHour *logTime);

/**
 * @brief Gets the day from a dateAndHour object.
 * @param logTime The dateAndHour object.
 * @return short: The day of the log time.
 */
short getDHDay(dateAndHour *logTime);

/**
 * @brief Gets the month from a dateAndHour object.
 * @param logTime The dateAndHour object.
 * @return short: The month of the log time.
 */
short getDHMonth(dateAndHour *logTime);

/**
 * @brief Gets the year from a dateAndHour object.
 * @param logTime The dateAndHour object.
 * @return int: The year of the log time.
 */
int getDHYear(dateAndHour *logTime);

/**
 * @brief Gets the hour from a dateAndHour object.
 * @param logTime The dateAndHour object.
 * @return short: The hour of the log time.
 */
short getDHHour(dateAndHour *logTime);

/**
 * @brief Gets the minutes from a dateAndHour object.
 * @param logTime The dateAndHour object.
 * @return short: The minutes of the log time.
 */
short getDHMinutes(dateAndHour *logTime);

/**
 * @brief Changes the date of a dateAndHour object.
 * @param timeToChange The dateAndHour object to change.
 * @param newDate The new date.
 */
void changeDate(dateAndHour *timeToChange, date *newDate);

/**
 * @brief Changes the hours of a dateAndHour object.
 * @param timeToChange The dateAndHour object to change.
 * @param newHours The new hours.
 */
void changeHours(dateAndHour *timeToChange, hours *newHours);

/**
 * @brief Copies the values from one date object to another.
 * @param dateToChange The date object to change.
 * @param newDate The date object to copy from.
 */
void copyDate(date *dateToChange, date *newDate);

/**
 * @brief Copies the values from one hours object to another.
 * @param hourToChange The hours object to change.
 * @param newHours The hours object to copy from.
 */
void copyHours(hours *hourToChange, hours *newHours);

/**
 * @brief Copies the values from one dateAndHour object to another.
 * @param TimeToChange The dateAndHour object to change.
 * @param newTime The dateAndHour object to copy from.
 */
void copyDateAndHour(dateAndHour *TimeToChange, dateAndHour *newTime);

/**
 * @brief Checks if a date is valid.
 * This function checks if the year, month, and day of a date object are within
 * valid ranges.
 * @param logDate The date to check.
 * @return int: TRUE if the date is valid, FALSE otherwise.
 */
int isValidDate(date *logDate);

/**
 * @brief Checks if an hours object is valid.
 * This function checks if the hour and minutes of an hours object are within
 * valid ranges.
 * @param logHour The hours object to check.
 * @return int: TRUE if the hours object is valid, FALSE otherwise.
 */
int isValidHour(hours *logHour);

/**
 * @brief Checks if an hours object is valid.
 * This function checks if the hour and minutes of an hours object are within
 * valid ranges.
 * @param logHour The hours object to check.
 * @return int: TRUE if the hours object is valid, FALSE otherwise.
 */
int isValidDateAndHour(dateAndHour *logHour);

/**
 * @brief Checks if a date is newer than another date.
 * This function compares two date objects and checks if the first date is newer
 * than the second date.
 * @param newDate The date to check if it's newer.
 * @param oldDate The date to compare with.
 * @return int: TRUE if newDate is newer than oldDate, FALSE otherwise.
 */
int dateIsNewerThen(date *newDate, date *oldDate);

/**
 * @brief Checks if an hours object is newer or equal to another hours object.
 * This function compares two hours objects and checks if the first hours object
 * is newer or equal to the second hours object.
 * @param newHour The hours object to check if it's newer or equal.
 * @param oldHour The hours object to compare with.
 * @return int: TRUE if newHour is newer/equal to oldHour, FALSE otherwise.
 */
int hourIsNewerOrEqualThen(hours *newHour, hours *oldHour);

/**
 * @brief Checks if a dateAndHour object is newer than another dateAndHour.
 * This function compares two dateAndHour objects and checks if the first
 * dateAndHour object is newer than the second dateAndHour object.
 * @param newLogTime The dateAndHour object to check if it's newer.
 * @param oldLogTime The dateAndHour object to compare with.
 * @return int: TRUE if newLogTime is newer than oldLogTime, FALSE otherwise.
 */
int isNewerThen(dateAndHour *newLogTime, dateAndHour *OldLogTime);

/**
 * @brief Checks if two dates are the same.
 * This function checks if the year, month, and day of two
 * date objects are the same.
 * @param logDate1 The first date to compare.
 * @param logDate2 The second date to compare.
 * @return int: True if the two dates are the same, FALSE otherwise.
 */
int isSameDate(date *logDate1, date *logDate2);

/**
 * @brief Checks if two hours are the same.
 * This function checks if the hour and minutes of two hours
 * objects are the same.
 * @param logHours1 The first hours object to compare.
 * @param logHours2 The second hours object to compare.
 * @return int: TRUE if the two hours objects are the same, FALSE otherwise.
 */
int isSameHour(hours *logHours1, hours *logHours2);

/**
 * @brief Checks if two dateAndHour objects are the same.
 * This function checks if the date and hours of two dateAndHour
 * objects are the same.
 * @param logTime1 The first dateAndHour object to compare.
 * @param logTime2 The second dateAndHour object to compare.
 * @return int: TRUE if the two dateAndHour are the same, FALSE otherwise.
 */
int isSameDateAndHour(dateAndHour *logTime1, dateAndHour *logTime2);

/**
 * @brief Prints a date.
 * This function prints the day, month, and year of a date object
 * in the format DD-MM-YYYY.
 * @param logDate The date to print.
 */
void printDate(date *logDate);

/**
 * @brief Prints an hours object.
 * This function prints the hour and minutes of an hours object
 * in the format HH:MM.
 * @param logHours The hours object to print.
 */
void printHours(hours *logHours);

/**
 * @brief Prints a dateAndHour object.
 * This function prints the date and hours of a dateAndHour object
 * in the format DD-MM-YYYY HH:MM.
 * @param logTime The dateAndHour object to print.
 */
void printDateAndHour(dateAndHour *logTime);

/**
 * @brief Calculates the total minutes since a given year.
 * This function calculates the total minutes from the start of a given year
 * to the date and hour in a dateAndHour object.
 * @param logTime The dateAndHour object.
 * @param oldYear The year to start counting from.
 * @return int: The total minutes since the start of oldYear to logTime.
 */
int totalMinutesSinceYear(dateAndHour *logTime, int oldYear);

/**
 * @brief Calculates the difference in minutes between two dateAndHour objects.
 * This function calculates the difference in minutes between the dates and
 * hours in two dateAndHour objects.
 * @param newLogTime The newer dateAndHour object.
 * @param oldLogTime The older dateAndHour object.
 * @return int: The difference in minutes between newLogTime and oldLogTime.
 */
int differenceInMinutes(dateAndHour *newLogTime, dateAndHour *oldLogTime);

/**
 * @brief Calculates the payment for a day.
 * This function calculates the payment for a given number of minutes, based on
 * an initial fee, a later fee, and a maximum fee.
 * @param minutes The number of minutes.
 * @param initFee The fee for the first 4 15-minute intervals.
 * @param laterFee The fee for each 15-minute interval after the first 4.
 * @param maxFee The maximum fee.
 * @return double: The calculated payment.
 */
double dayPayment(int minutes, double initFee, double laterFee, double maxFee);

/**
 * @brief Calculates the total payment.
 * This function calculates the total payment for a given number of minutes,
 * based on an initial fee, a later fee, and a maximum fee.
 * @param minutes The number of minutes.
 * @param initialFee The fee for the first 4 15-minute intervals.
 * @param laterFee The fee for each 15-minute interval after the first 4.
 * @param maxFee The maximum fee.
 * @return double: The calculated total payment.
 */
double payment(int minutes, double initialFee, double laterFee, double maxFee);

/**
 * @brief Frees a date object.
 * This function frees the memory allocated for a date object.
 * @param logDate The date object to free.
 */
void freeDate(date *logDate);

/**
 * @brief Frees an hours object.
 * This function frees the memory allocated for an hours object.
 * @param logHours The hours object to free.
 */
void freeHours(hours *logHours);

/**
 * @brief Frees a dateAndHour object.
 * This function frees the memory allocated for a dateAndHour
 * object and its components.
 * @param logTime The dateAndHour object to free.
 */
void freeDateAndHour(dateAndHour *logTime);

#endif
