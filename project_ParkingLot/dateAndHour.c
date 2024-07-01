/**
 * @file dateAndHour.c
 * @brief This file contains the implementation of the
 * date and hour related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Include necessary libraries and header file
#include <stdio.h>
#include <stdlib.h>
#include "dateAndHour.h"

/**
 * @brief The number of days in each month.
 * This array contains the number of days in each month of a non-leap year.
 * The index of the array corresponds to the month (0 for Jan, 1 for Feb, etc.).
 */
static int diasMes[MESES] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

date *createDate(char *dateString){
    date *newDate = (date*) malloc(sizeof(date));
    sscanf(dateString, "%hd-%hd-%d", &newDate->day, &newDate->month,
        &newDate->year);
    return newDate;
}

hours *createHours(char *hourString){
    hours *newHours = (hours*) malloc(sizeof(hours));
    sscanf(hourString, "%hd:%hd", &newHours->hour, &newHours->minutes);
    return newHours;
}

dateAndHour *createDateAndHour(char *dateString, char *hourString){
    dateAndHour *newLogTime = (dateAndHour*) malloc(sizeof(dateAndHour));
    newLogTime -> date = createDate(dateString);
    newLogTime -> hour = createHours(hourString);
    return newLogTime;
}

short getDateDay(date *logDate){
    return logDate->day;
}

short getDateMonth(date *logDate){
    return logDate->month;
}

int getDateYear(date *logDate){
    return logDate->year;
}

short getHoursHour(hours *logHour){
    return logHour->hour;
}

short getHoursMinutes(hours *logHour){
    return logHour->minutes;
}

date *getDate(dateAndHour *logTime){
    return logTime->date;
}

hours *getHours(dateAndHour *logTime){
    return logTime->hour;
}

short getDHDay(dateAndHour *logTime){
    return getDateDay(logTime->date);
}

short getDHMonth(dateAndHour *logTime){
    return getDateMonth(logTime->date);
}

int getDHYear(dateAndHour *logTime){
    return getDateYear(logTime->date);
}

short getDHHour(dateAndHour *logTime){
    return getHoursHour(logTime->hour);
}

short getDHMinutes(dateAndHour *logTime){
    return getHoursMinutes(logTime->hour);
}

void changeDate(dateAndHour *timeToChange, date *newDate){
    timeToChange->date = newDate;
}

void changeHours(dateAndHour *timeToChange, hours *newHours){
    timeToChange->hour = newHours;
}

void copyDate(date *dateToChange, date *newDate){
    dateToChange->day = newDate->day;
    dateToChange->month = newDate->month;
    dateToChange->year = newDate->year;
}

void copyHours(hours *hourToChange, hours *newHours){
    hourToChange->hour = newHours->hour;
    hourToChange->minutes = newHours->minutes;
}

void copyDateAndHour(dateAndHour *TimeToChange, dateAndHour *newTime){
    copyDate(getDate(TimeToChange), newTime->date);
    copyHours(getHours(TimeToChange), newTime->hour);
}

int isValidDate(date* logDate){
    if (getDateYear(logDate) < 0 || getDateMonth(logDate) < 1 ||
        getDateMonth(logDate) > 12 || getDateDay(logDate) < 1 ||
        getDateDay(logDate) > diasMes[getDateMonth(logDate) - 1])
            return FALSE;
    return TRUE;
}

int isValidHour(hours *logHour){
    if (getHoursHour(logHour) < 0 || getHoursHour(logHour) > 23 ||
        getHoursMinutes(logHour) < 0 || getHoursMinutes(logHour) > 59)
            return FALSE;
    return TRUE;
}
int isValidDateAndHour(dateAndHour *logTime){
    return isValidDate(getDate(logTime)) && isValidHour(getHours(logTime));
}

int dateIsNewerThen(date *newDate, date *oldDate){
    if (getDateYear(oldDate) < getDateYear(newDate) ||
        (getDateYear(oldDate) == getDateYear(newDate) &&
        getDateMonth(oldDate) < getDateMonth(newDate)) ||
        (getDateYear(oldDate) == getDateYear(newDate) &&
        getDateMonth(oldDate) == getDateMonth(newDate) &&
        getDateDay(oldDate) < getDateDay(newDate)))
            return TRUE;
    return FALSE;
}

int hourIsNewerOrEqualThen(hours *newHour, hours *oldHour){
    if (getHoursHour(oldHour) < getHoursHour(newHour) ||
        (getHoursHour(oldHour) == getHoursHour(newHour) &&
        getHoursMinutes(oldHour) <= getHoursMinutes(newHour)))
        return TRUE;
    return FALSE;
}

int isNewerThen(dateAndHour *newLogTime, dateAndHour *oldLogTime){
    if (dateIsNewerThen(getDate(newLogTime), getDate(oldLogTime)) ||
        (isSameDate(getDate(newLogTime), getDate(oldLogTime)) &&
        hourIsNewerOrEqualThen(getHours(newLogTime), getHours(oldLogTime))))
            return TRUE;
    return FALSE;
}

int isSameDate(date *logDate1, date *logDate2){
    return getDateYear(logDate1) == getDateYear(logDate2) &&
        getDateMonth(logDate1) == getDateMonth(logDate2) &&
        getDateDay(logDate1) == getDateDay(logDate2);
}

int isSameHour(hours *logHours1, hours *logHours2){
    return getHoursHour(logHours1) == getHoursHour(logHours2) &&
        getHoursMinutes(logHours1) == getHoursMinutes(logHours2);
}

int isSameDateAndHour(dateAndHour *logTime1, dateAndHour *logTime2){
    return isSameDate(getDate(logTime1), getDate(logTime2)) &&
        isSameHour(getHours(logTime1), getHours(logTime2));
}

void printDate(date *logDate){
    printf("%02d-%02d-%04d", getDateDay(logDate), getDateMonth(logDate),
        getDateYear(logDate));
}

void printHours(hours *logHours){
    printf("%02d:%02d", getHoursHour(logHours), getHoursMinutes(logHours));
}

void printDateAndHour(dateAndHour *logTime){
    printDate(getDate(logTime));
    printf(" ");
    printHours(getHours(logTime));
}

int totalMinutesSinceYear(dateAndHour *logTime, int oldYear){
    long totalMin = 0;
    int monthAux;

    totalMin += getDHMinutes(logTime) + getDHHour(logTime)* 60;

    for(; oldYear < getDHYear(logTime); oldYear++)
        totalMin += 365*24*60; // Minutes in a years

    totalMin += (getDHDay(logTime) - 1)* 24 * 60; // Minutes in days

    for(monthAux = getDHMonth(logTime) - 1; monthAux > 0; monthAux--)
        totalMin += diasMes[monthAux - 1] * 24 * 60; // Minutes in months

    return totalMin;
}

int differenceInMinutes(dateAndHour *newLogTime, dateAndHour *oldLogTime){
    int minutes = totalMinutesSinceYear(newLogTime, getDHYear(oldLogTime));
    return minutes - totalMinutesSinceYear(oldLogTime, getDHYear(oldLogTime));
}

double dayPayment(int minutes, double initFee, double laterFee, double maxFee){
    double money = 0;
    int count;
    count = minutes / (15);
    if (minutes% 15 != 0) count++;

    if (count > 4){ // Passed first hour
        money += laterFee * (count - 4);
        count = 4;
    }
    money += initFee * count;

    if (money > maxFee) money = maxFee; // Can't pay more than maxFee

    return money;
}

double payment(int minutes, double initialFee, double laterFee, double maxFee){
    double money = 0;
    int count;
    if (minutes == 0) return 0; // If  0 minutes, the fee is 0
    count = minutes / (24 * 60);
    money = count * maxFee;
    minutes %= (24 * 60);
    money += dayPayment(minutes, initialFee, laterFee, maxFee);
    return money;
}

void freeDate(date *logDate){
    free(logDate);
}

void freeHours(hours *logHours){
    free(logHours);
}

void freeDateAndHour(dateAndHour *logTime){
    freeDate(getDate(logTime));
    freeHours(getHours(logTime));
    free(logTime);
}
