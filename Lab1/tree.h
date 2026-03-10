#include <stdio.h>
#include <stdlib.h>

typedef struct c_node {
	struct c_node **ptr;
	size_t i;
	int key;
} c_node;

typedef struct b_node {
	struct b_node *l_ptr;
	struct b_node *r_ptr;
	int key;
} b_node;

b_node* createNode(int key);
void print_b_tree(b_node* t, int d);
b_node* add_b_node(b_node* t, int v);
b_node* del_b_node(b_node* t, int v);
int get_deg(b_node* t);
void clear_b(b_node* t);

c_node* add_c_node(c_node* tree, c_node* parent, int v);
c_node* del_c_node(c_node* tree, c_node* node);