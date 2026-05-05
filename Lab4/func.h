#ifndef FUNC_H
#define FUNC_H

typedef struct Node {
    char key[7];
    struct Node *left;
    struct Node *right;
    int height;
} Node;

Node* newNode(char* key);
Node* insert(Node* node, char* key);
Node* deleteNode(Node* root, char* key);
Node* search(Node* root, char* key);
int height(Node *N);
void freeTree(Node* root);
int getBalance(Node *N);

#endif
