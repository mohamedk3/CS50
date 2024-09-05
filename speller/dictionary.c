// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open dictionary file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        return 1;
    }
    // Read string from file one at a time
    char word[LENGTH +1 ];
    while (fscanf(input, %s , word)!= EOF);
    {
        // Create a new node for each word
         char *p = malloc(sizeof(node));
         if (p == NULL)
     {
         return false ;
     }

     strcpy(p -> word , word);
     p -> next = NULL

     // Hash word to obtain a hash value
     int location = hash(word)

     //Insert node into hash table at that Location

     p -> next = table[location] -> next ;
     table[location] -> next = p ;
    }






    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
