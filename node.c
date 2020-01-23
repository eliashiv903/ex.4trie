#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"





// Returns new trie node (initialized to NULLs)
node* getNode(void) {
    node *pNode = NULL;
    pNode = (node*)malloc(sizeof(node));
    if (pNode)
    {
        int i;
        pNode->count = 0;
        for (i = 0; i < NUM_LETTERS; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}

// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(node *root, const char *key) {
    int level;
    int length = strlen(key);
    int index;

    node *pCrawl = root;

    for (level = 0; level < length; level++) {
        index = key[level]-'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl->letter=key[level];
    }
    // mark last node as leaf
    pCrawl->count++;
}
int suns(node *current){
    boolean sun=FALSE;
    for (size_t i = 0; i < NUM_LETTERS; i++)
    {
        if(current->children[i])
            sun=TRUE;
    }
    return sun;
}
void printR(node *root, char *str, int index)
{
    if (suns(root) == FALSE)
    {
        str[index] = '\0';
        printf("%s\t%ld\n", str, root->count);
        return;
    }

    if (root->count > 0 )
    {
        str[index] = '\0';
        printf("%s\t%ld\n", str, root->count);
    }

    for (int i = NUM_LETTERS - 1; i >= 0; i--)
    {
        if (root->children[i])
        {
            str[index] = root->children[i]->letter;
            printR(root->children[i], str, index + 1);
        }
    }
}

///print the words in trie sorted by a declining lexicographic order
void print(node *root, char * str, int index) {
    if(suns(root)==FALSE)
    {
        str[index]='\0';
        printf("%s\t%ld\n",str,root->count);
        return;
    }
    if (root->count>0){
        str[index]='\0';
        printf("%s\t%ld\n" , str,root->count);
    }
    for (size_t i = 0; i <NUM_LETTERS; i++)
    {
        if(root->children[i]){
            str[index]=root->children[i]->letter;
            print(root->children[i],str,index+1);
        }
    }
}

//free the memory of all the nodes in the root
void free_trie(node* root)
{
    int i;
    if(!root) return;   // safe guard including root node.

    // recursive case (go to end of trie)
    for (i = 0; i < NUM_LETTERS; i++)
        free_trie(root->children[i]);


    // base case
    free(root);
}

