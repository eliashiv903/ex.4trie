#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

void printR(node *root, char *str, int index);
node* getNode(void)
{
    node *root = NULL;
    root = (node *)malloc(sizeof(node));
    if (root){
        int i;
        root->count = 0;
        for (i = 0; i < NUM_LETTERS; i++)
            root->children[i] = NULL;
    }
    return root;
}

void insert(node **root,  char* key)
{
    int level;
    int length = strlen(key);
    int index;
    node *run = *root;
    for (level = 0; level < length; level++)
    {
        index = key[level]-'a';
        if (!run->children[index])
            run->children[index] = getNode();
        run = run->children[index];
        run->letter=key[level];
    }
    run->count++;
}


int suns(node *current){
    boolean flag=FALSE;
    for (size_t i = 0; i < NUM_LETTERS; i++)
    {
        if(current->children[i])
            flag=TRUE;
    }
    return flag;
}

void printR(node *root, char *str, int index)
{

    for (int i = NUM_LETTERS - 1; i >= 0; i--)
    {
        if (root->children[i])
        {
            str[index] = root->children[i]->letter;
            printR(root->children[i], str, index + 1);
        }
    }

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

}

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
void freem(node* root) {
    int i;
    if (!root) return;
    for (i = 0; i < NUM_LETTERS; i++)
        freem(root->children[i]);
    free(root);
}