#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define NUM_LETTERS ((int)26)
#define END_CHAR 97
#define line_size 1024
#define word_size 256

typedef enum {FALSE=0 ,TRUE=1} boolean;

typedef struct node{
    char letter;
    long unsigned int count;
    struct node* children [NUM_LETTERS];
} node;

node *getNode(void);
void insert(node *root, const char *key);
int suns(node *current);
void printR(node *root, char *str, int index);
void print(node *root, char * str, int index);
void free_trie(node* root);




#ifndef UNTITLED13_NODE_H
#define UNTITLED13_NODE_H

#endif //UNTITLED13_NODE_H
