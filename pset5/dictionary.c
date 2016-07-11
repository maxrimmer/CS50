/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"


/**
 * Returns true if word is in dictionary else false.
 */
 unsigned long sizeOfDict = -1;
 
 typedef struct node
 {
     char word[LENGTH+1];
     struct node* next;
 }
 node;
 
 
 node* hashtable[65535];

 
 // Hashfunction djb2, http://www.cse.yorku.ca/~oz/hash.html
 unsigned long hash(const char *str)
    {
        unsigned long hash = 5381;
        int c;

        while ((c = *str++) != 0)
            hash = (((hash << 5) + hash) + c) % 65535; /* hash * 33 + c */

        return hash;
    }

 
bool check(const char* word)
{
    // TODO
    char wordCpy[strlen(word)+1];
    strcpy(wordCpy, word);
    for(int e = 0; e < strlen(wordCpy); e++) {
        wordCpy[e] = tolower(wordCpy[e]);
    }
    unsigned long bucket = hash(wordCpy);
    
    node* cursor = hashtable[bucket];
    while(cursor != NULL) {
        if (!strcmp(cursor->word, wordCpy)) {
            return true;
        }
        else {
            cursor=cursor->next;
        }
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // TODO
   
    FILE* dict = fopen(dictionary, "r");
    
    if(dict == NULL) {
        printf("File doesn't exist\n");
        return false;
    }
    
    while(!feof(dict)) {
        node* new_node = malloc(sizeof(node));
        fscanf(dict, "%s", new_node->word);
        unsigned long basket = hash(new_node->word);
        
        new_node -> next = hashtable[basket];
        hashtable[basket] = new_node;
        sizeOfDict++;
    }
    fclose(dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return sizeOfDict;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    for(int i = 0; i < 65535; i++) {
        node* cursor = hashtable[i];
        
        while (cursor != NULL) {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        
    }
    
    
    
    return true;
}
