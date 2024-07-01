/**
 * @file hashingTable.h
 * @brief This header file contains the declarations of the hashTable structure
 * and related functions.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Check if the header file has already been included
#ifndef HASHINGTABLE_H
#define HASHINGTABLE_H

// Include header file
#include "project.h"

#define TABLE_SIZE 97 /**< The size of the Hash Table */

// Forward declaration of structure
typedef struct info info;

/**
 * @struct hashTable
 * @brief A structure to represent a hash table. This structure represents a
 * hash table with its count of items and an array of pointers to the items.
 */
typedef struct hashTable {
    int count; /**< The count of items in the hash table. */
    struct info *table[TABLE_SIZE]; /**< An array of pointers to
        the items in the hash table. */
} hashTable;

/**
 * @brief Hash function based on Peter Weinberger's method.
 * This function calculates the hash value of a string using Peter Weinberger's
 * method. It's used to determine the index for a string in the hash table.
 * @param strToHash The string to hash.
 * @return unsigned int: The hash value.
 */
unsigned int hashFuncPW(char *strToHash);

/**
 * @brief Creates a new hash table.
 * This function creates a new hash table and initializes all its
 * entries to NULL. It also sets the count of items in the table to 0.
 * @return hashTable*: A pointer to the created hash table.
 */
hashTable *createHashTable();

/**
 * @brief Gets the count of items in the hash table.
 * @param hTable The hash table.
 * @return int: The count of items.
 */
int getHashTableCount(hashTable *hTable);

/**
 * @brief Gets the item at a specific index in the hash table.
 * @param hTable The hash table.
 * @param index The index of the item.
 * @return info*: The item at the specified index.
 */
info *getHashTableItem(hashTable *hTable, unsigned int index);

/**
 * @brief Increases or decreases the count of items in the hash table.
 * @param hTable The hash table.
 * @param value The value to increase or decrease the count by.
 */
void incOrDecrHashTableCount(hashTable *hTable, int value);

/**
 * @brief Adds an item to the hash table.
 * @param hTable The hash table.
 * @param newInfo The item to add.
 */
void addInHashTable(hashTable *hTable, info *newInfo);

/**
 * @brief Searches for an item in the hash table.
 * @param hTable The hash table.
 * @param identifier The identifier of the item to search for.
 * @return info*: The item found or NULL if not found.
 */
info *searchInHashTable(hashTable *hTable, char *identifier);

/**
 * @brief Pops an item from the hash table.
 * This function pops an item from the hash table and adjusts the links
 * between items accordingly. If the item is not found, it returns NULL.
 * @param hTable The hash table.
 * @param identifier The identifier of the item to pop.
 * @return info*: The poped item or NULL if not found.
 */
info *popItemFromHashTable(hashTable *hTable, char *identifier);

/**
 * @brief Frees the hash table.
 * This function frees the memory allocated for the hash table
 * and all its items.
 * @param hTable The hash table.
 */
void freeHashTable(hashTable *hTable);

#endif
