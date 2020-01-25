#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "node.h"
#define maxword 26
int main(int argc , char* argv[]) {

    node *root = getNode();
    char *word = (char *) malloc(sizeof(char) * maxword);
    char bufer;
    boolean flag = FALSE;
    if (argc >= 2 && strcmp(argv[1], "r") == 0) {
        flag = TRUE;
    }

    int i = 0;
    while ((bufer = getc(stdin)) != EOF) {
        if ((bufer >= 'a' && bufer <= 'z') || (bufer >= 'A' && bufer <= 'Z')) {
            bufer = tolower(bufer);
            word[i] = bufer;
            i++;
        } else if (bufer == '\t' || bufer == ' ' || bufer == '\n' || bufer == '\0') {
            if (word[0] != '\0') {
                word[i] = '\0';
                insert( &root, word);
                memset(word, 0, sizeof(char) * maxword);
                i = 0;
            }
        }
    }
        char pword[maxword];
        if (flag) {
            printR(root, pword, 0);
        } else {
            print(root, pword, 0);
        }
        freem(root);
        return 0;
    }
