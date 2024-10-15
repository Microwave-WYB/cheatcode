#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_SIZE 10000  // Maximum possible size of nums array
#define HASH_SIZE 20011 // A prime number larger than twice MAX_SIZE

typedef struct {
    int key;
    int value;
    bool used;
} HashEntry;

unsigned int hash(int key) { return (unsigned int)(key >= 0 ? key : -key) % HASH_SIZE; }

bool twoSum(const int* restrict nums, int numsSize, int target, int* restrict result) {
    HashEntry* hashTable = (HashEntry*)calloc(HASH_SIZE, sizeof(HashEntry));
    if (!hashTable)
        return false; // Memory allocation failed

    for (int i = 0; i < numsSize; ++i) {
        int complement = target - nums[i];
        unsigned int h = hash(complement);

        // Check if the complement exists in the hash table
        while (hashTable[h].used) {
            if (hashTable[h].key == complement) {
                result[0] = hashTable[h].value;
                result[1] = i;
                free(hashTable);
                return true;
            }
            h = (h + 1) % HASH_SIZE; // Linear probing
        }

        // Insert the current number into the hash table
        h = hash(nums[i]);
        while (hashTable[h].used && hashTable[h].key != nums[i]) {
            h = (h + 1) % HASH_SIZE; // Linear probing
        }
        hashTable[h].key = nums[i];
        hashTable[h].value = i;
        hashTable[h].used = true;
    }

    free(hashTable);
    return false;
}