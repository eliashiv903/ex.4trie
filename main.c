#include <stdio.h>
#include "node.h"
    int main(int argc, char const *argv[]) {
        char bufer;
        int i = 0; // count word length
        int max = 0; // save longest word length
        node *root = getNode();
        node *temp = root; // pointer to root first, to any node needed afterthen

        //this loop read chars from standard input and inert it to the trie
        while ((bufer = getc(stdin)) != EOF) {
            if ((bufer >= 'a' && bufer <= 'z') || (bufer >= 'A' && bufer <= 'Z')) {
                insert(temp, tolower(bufer)); // insert the letter to the tree
                i++;
            } else if (bufer == ' ' || bufer == '\n' || bufer == '\t') {
                temp->count++;
                temp = root;
                if (i > max) max = i;
                i = 0;
            }
        }
        char cmon[max + 2];
        boolean flag = FALSE;
        if (argc >= 2 && strcmp(argv[1], "r") == 0) {
            flag = TRUE;
        }
        if (flag) {
            printR(root, cmon, 0);
        } else {
            print(root, cmon, 0);
        }
        free_trie(root);
    return 0;
}