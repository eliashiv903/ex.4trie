#define NUM_LETTERS ((int)26)


typedef enum {FALSE=0 ,TRUE=1} boolean;

typedef struct node{
    char letter;
    long unsigned int count;
    struct node* children [NUM_LETTERS];
} node;


node* getNode(void);
void insert(node **root,  char* key);
void printR(node *root, char *str, int index);
void print(node *root, char * str, int index);
void freem(node* root);
int suns(node *current);