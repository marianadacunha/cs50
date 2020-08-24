// Implements a dictionary's functionality
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Global variable that initializes counter for words in dictionary
int wordCounter = 0;

// Number of buckets in hash table
const unsigned int N = 26; // Total number of letters on the alphabet

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int key = hash(word);

    node *nodePointer = table[key];

    while (nodePointer != NULL)
    {
        // Compares lowercase and uppercase
        if (strcasecmp(nodePointer -> word, word) == 0)
        {
            return true;
        }
        nodePointer = nodePointer -> next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int value = 0;
    // Looping until it gets to the end of the string (\0)
    for (int i = 0; word[i] != '\0'; i++)
    {
        // Doing everything in lowercase now
        value += tolower(word[i]);
    }
    return value % N;
}

// Loads dictionary into memory, returning true if successful, false if unsuccessful
bool load(const char *dictionary)
{
    // Opening the dictionary
    FILE *filePointer = fopen(dictionary, "r");
    if (filePointer != NULL)
    {
        for (int i = 0; i < N; i++)
        {
            table[i] = NULL;
        }

        char tempWord[LENGTH + 1];

        // Reading one word at a time, while it's not the end of the file
        while (fscanf(filePointer, "%s\n", tempWord) != EOF)
        {
            // Creating a new node pointer
            node *tempNode = malloc(sizeof(node));

            // Copies word into node
            strcpy(tempNode -> word, tempWord);

            int key = hash(tempWord);

            if (table[key] == NULL)
            {
                tempNode -> next = NULL;
                table[key] = tempNode;
            }
            else
            {
                tempNode -> next = table[key];
                table[key] = tempNode;
            }

            wordCounter++;
        }

        fclose(filePointer);
        return true;
    }
    
    return false;
}

// Returns number of words in dictionary
unsigned int size(void)
{
    return wordCounter;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *nodePointer = table[i];

        while (nodePointer != NULL)
        {
            node *throwAway = nodePointer;
            nodePointer = nodePointer -> next;
            free(throwAway);
        }

        table[i] = NULL;
    }
    return true;
}