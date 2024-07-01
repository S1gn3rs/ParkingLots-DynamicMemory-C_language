/**
 * @file list.h
 * @brief This header file contains the declarations of the list structure
 * and related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Check if the header file has already been included
#ifndef LIST_H
#define LIST_H

// Include header file
#include "info.h"

// Forward declaration of structure
typedef struct info info;

/**
 * @struct list
 * @brief A structure to represent a doubly linked list. This structure
 * represents a doubly linked list with its size and pointers to the first
 * and last items.
 */
typedef struct list{
    int size; /**< The size of the list. */
    struct info *firstItem; /**< A pointer to the first item in the list. */
    struct info *lastItem; /**< A pointer to the last item in the list. */
}list;

/**
 * @brief Creates a new linked list.
 * This function allocates memory for a new list, initializes its size to 0,
 * and sets its first and last items to NULL.
 * @return list*: A pointer to the newly created list.
 */
list* createList();

/**
 * @brief Retrieves the first item from a list.
 * @param listItems A pointer to the list.
 * @return info*: A pointer to the first item in the list.
 */
info* getFirstItem(list *listItems);

/**
 * @brief Retrives the last item from a list.
 * @param listItems A pointer to the list.
 * @return info*: A pointer to the last item in the list.
 */
info* getLastItem(list *listItems);

/**
 * @brief Retrieves the size of a list.
 * @param listItems A pointer to the list.
 * @return int: The size of the list.
 */
int getListSize(list *listItems);

/**
 * @brief Changes the first item of a list to a new item.
 * @param listItems A pointer to the list.
 * @param newFirst A pointer to the new first item.
 */
void changeFirstItem(list *listItems, info *newFirst);

/**
 * @brief Changes the last item of a list to a new item.
 * @param listItems A pointer to the list.
 * @param newLast A pointer to the new last item.
 */
void changeLastItem(list *listItems, info *newLast);

/**
 * @brief Increments or decrements the size of a list.
 * @param listItems A pointer to the list.
 * @param incOrDecr The amount to increment (positive value) or
 * decrement (negative value) the size by.
 */
void incOrDecrementListSize(list *listItems, int incOrDecr);

/**
 * @brief Checks if an identifier exists in a list.
 * @param listItems A pointer to the list of items.
 * @param identifier The identifier to check.
 * @return int: TRUE if the identifier exists in the list, FALSE otherwise.
 */
int identityExists(list* listItems, char* identifier);

/**
 * @brief Adds an item to a list.
 * This function adds an item to the end of a list.If the list is empty,
 * the item becomes the first item. The size of the list is incremented by 1.
 * @param listItems A pointer to the list.
 * @param item A pointer to the item to be added.
 */
void addItem(list* listItems, info *item);

/**
 * @brief Inserts an item into a sorted list.
 * This function inserts an item into a list while maintaining the list's order.
 * The order is determined by a comparison depending on the item's type.
 * @param listItems A pointer to the list.
 * @param item A pointer to the item to be inserted.
 */
void addItemInOrder(list* listItems, info *item);

/**
 * @brief Inserts an item into a list.
 *
 * This function inserts an item into a list at a specific position. The
 * position is determined by the current item. The size of the list is
 * incremented by 1.
 *
 * @param listItems A pointer to the list.
 * @param currentItem A pointer to the current item in the list.
 * @param itemToInsert A pointer to the item to be inserted.
 */
void insertItemInList(list *listItems, info *currentItem, info *itemToInsert);

/**
 * @brief Searches for an item in a list.
 * This function iterates over the list to find an item with the provided
 * identifier. It returns a pointer to the item if found, or NULL otherwise.
 * @param listItems A pointer to the list.
 * @param identifier The identifier of the item to be found.
 * @return info*: A pointer to the found item, or NULL if not found.
 */
info* searchForItem(list* listItems, char* identifier);

/**
 * @brief Pops an item from a list.
 * This function finds and pops an item from the list using the provided
 * identifier. It adjusts the list accordingly and decrements its size by 1.
 * @param listItems A pointer to the list.
 * @param identifier The identifier of the item to be poped.
 * @return info*: A pointer to the poped item, or NULL if not found.
 */
info* popItem(list* listItems, char* identifier);

/**
 * @brief Frees the memory allocated for a list and its items.
 * @param listItems The list to be freed.
 */
void freeList(list *listItems);

/**
 * @brief Frees memory for parked cars entries in a park history list.
 * Iterates over the park history list, freeing memory for each vehicle entry
 * that matches the provided park name. After processing all entries, it frees
 * the memory for the park history list itself.
 * @param parkHist A pointer to the park history list.
 * @param parkName The name of the park for which to free parked car entries.
 */
void freeParkedCarsEntries(list *parkHist, char *parkName);

/**
 * @brief Frees memory for car entries in a vehicles list.
 * Iterates over the vehicles list. For each vehicle, if it has a history
 * section matching the provided park name, that section is freed. After
 * processing all vehicles, it frees the memory for the vehicles list.
 * @param parkedVeh A pointer to the list of parked vehicles.
 * @param parkName The name of the park for which to free car entries.
 */
void freeCarEntries(list *parkedVeh, char *parkName);


/**
 * @brief Performs a shallow free operation on a list.
 * This function iterates over the list and frees the memory allocated for
 * each item's info structure, but not the data referenced by the info. After
 * processing all items, it frees the memory for the list itself.
 * @param listItems A pointer to the list to be shallow freed.
 */
void shallowFreeList(list *listItems);
#endif
