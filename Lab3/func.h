#ifndef FUNC_H
#define FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef enum {
    NODE_OP,
    NODE_VAL
} NodeType;

typedef struct Node {
    NodeType type;
    int value;          
    char op;            
    struct Node *left;
    struct Node *right;
} Node;

Node* create_val_node(int val);
Node* create_op_node(char op, Node* left, Node* right);
void free_tree(Node* root);
Node* copy_tree(Node* root);
Node* build_tree_from_expr(const char* expr);
Node* transform_fractions(Node* root);
int evaluate(Node* root);
void print_tree(Node* t, int d);
void print_expr(Node* root);

#endif
