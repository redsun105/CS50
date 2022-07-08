// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 1000;

// Hash table
node *table[N];

// counter dictionary size
unsigned int word_count;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO

    node* cursor = table[hash(word)];
    while(cursor != NULL){
    if(strcasecmp(word, cursor->word) == 0)
    return true;
    cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    long sum = 0;
    for(int i = 0; i < strlen(word); i++){
        sum += tolower(word[i]);
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char buffer[LENGTH];
    FILE* infile = fopen(dictionary, "r");
    if(infile == NULL){
        return false;
    }
    while(!(fscanf(infile, "%s", buffer) == EOF)){
        node* n = malloc(sizeof(node));
        if(n == NULL){
            return false;
        }
        strcpy(n->word, buffer);
        hash(n->word);
        n->next = table[hash(n->word)];
        table[hash(n->word)] = n;
        word_count ++;
    }

    fclose(infile);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    if(word_count > 0){
        return word_count;
    }
    else return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    node* cursor = NULL;
    for(int i = 0; i < N; i++){
        cursor = table[i];
        while(cursor != NULL){
            node* tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
        if(i == N -1 && cursor == NULL){
            return true;
        }
    }
    return false;
}
