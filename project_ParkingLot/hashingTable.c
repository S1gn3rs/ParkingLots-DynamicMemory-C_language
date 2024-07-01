/**
 * @file hashingTable.c
 * @brief This file contains the implementation of a hash table.
 * @author Guilherme Silva ist1106823
 * @date 29/03/2024
 */

// Include necessary libraries and header file
#include <stdlib.h>
#include <string.h>
#include "hashingTable.h"

unsigned int hashFuncPW(char *strToHash){
    char *letter;
    unsigned int hashVal, tempVal;

    hashVal = 0;
    for(letter = strToHash; *letter!='\0'; letter++){
        hashVal = (hashVal << 4) + *letter;
        // shift the hash value 4 bits to the left.

        // If the most significant 4 bits of hashVal are not 0
        if ((tempVal = hashVal) & 0xF0000000){
            // XOR those bits into the least significant 4 bits of hashVal.
            hashVal ^= tempVal >>24;
            hashVal ^= tempVal;
            }
    }
    return hashVal % TABLE_SIZE;
}

hashTable *createHashTable(){
    hashTable *newTable = (hashTable*) malloc(sizeof(hashTable));
    unsigned int ind;

    newTable -> count = 0;
    for(ind = 0; ind < TABLE_SIZE; ind++)
        newTable->table[ind] = NULL;

    return newTable;
}

int getHashTableCount(hashTable *hTable){
    return hTable->count;
}

info *getHashTableItem(hashTable *hTable, unsigned int index){
    return hTable->table[index];
}

void incOrDecrHashTableCount(hashTable *hTable, int value){
    hTable->count += value;
}

void addInHashTable(hashTable *hTable, info *newInfo){
    int index = hashFuncPW(getInfoIdentifier(newInfo));
    info *currentItem = getHashTableItem(hTable, index);

    if (currentItem != NULL){ // If there is a collision
        changeNextItem(newInfo, currentItem);
        changePreviousItem(currentItem, newInfo);
    }
    hTable->table[index] = newInfo;
    incOrDecrHashTableCount(hTable, 1);
}

info *searchInHashTable(hashTable *hTable, char *identifier){
    int index = hashFuncPW(identifier);
    info *currentItem = getHashTableItem(hTable, index);

    while (currentItem != NULL &&
        strcmp(getInfoIdentifier(currentItem), identifier) != 0){
            currentItem = getNextItem(currentItem);
    }
    return currentItem;
}

info *popItemFromHashTable(hashTable *hTable, char *identifier){
    info *item = searchInHashTable(hTable, identifier);
    unsigned int index = hashFuncPW(identifier);

    if (item == NULL) return NULL; // If the item is not in the table
    if (getPreviousItem(item) == NULL){ // if it's the first item
        changePreviousItem(getNextItem(item), NULL);
        hTable->table[index] = getNextItem(item);
    }
    if (getNextItem(item) == NULL){ // if it's the last item
        changeNextItem(getPreviousItem(item), NULL);
    }
    else{
        changeNextItem(getPreviousItem(item), getNextItem(item));
        changePreviousItem(getNextItem(item), getPreviousItem(item));
    }

    incOrDecrHashTableCount(hTable, -1);
    return item;
}

void freeHashTable(hashTable *hTable){
    unsigned int ind = 0;
    info *currentItem, *freeItem;

    while (getHashTableCount(hTable) > 0){
        if ((currentItem = getHashTableItem(hTable, ind)) != NULL){

            while(currentItem != NULL){ // Free all items linked to the index
                freeItem = currentItem;
                currentItem = getNextItem(currentItem);
                freeInfo(freeItem);
                incOrDecrHashTableCount(hTable, -1);
            }
        }
        ind++;
    }
    free(hTable);
}
